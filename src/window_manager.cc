#include <animbreak/ui/window_manager.hpp>
#include <spdlog/spdlog.h>
#include <cstdlib>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <glfw/glfw3.h>
#include <animbreak/log.hpp>
#include <string>
#include <thread>

namespace anim{
	class anim_window_impl:public anim_window{
		anim_window_impl* parent;
		GLFWwindow* winpointer;
		char* title;
		int width,height,x,y;
		std::thread thread_worker[1];
		void get_size_property(){
			glfwGetWindowSize(winpointer,&width,&height);
			glfwGetWindowPos(winpointer,&x,&y);
		}
		static void anim_window_thread_worker(anim_window_impl* pointer){
			
			GLFWwindow* window=pointer->winpointer;
			while (!glfwWindowShouldClose(window)){
				int width,height;
				glfwGetWindowSize(window,&width,&height);
				glClearColor(.1,.2,0,1);
				glClear(GL_COLOR_BUFFER_BIT);
				ImGui_ImplOpenGL3_NewFrame();
				ImGui_ImplGlfw_NewFrame();
				ImGui::NewFrame();
				ImGui::Begin("ArmSimulator",NULL);
				//entry point to window
				ImGui::End();
				// Renders the ImGUI elements
				ImGui::Render();
				ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
				// Swap the back buffer with the front buffer
				glfwSwapBuffers(window);
				// Take care of all GLFW events
				glfwPollEvents();
			}
			
		}
		public:
				anim_window_impl(const char* title,const int x,const int y,const int width,const int height,anim_window* parent=nullptr){
					this->parent=dynamic_cast<anim_window_impl*>(parent);
					this->winpointer=nullptr;
					this->winpointer = glfwCreateWindow(width, height, title, NULL, NULL);
					if (this->winpointer==nullptr){
						spdlog::warn("Can't create Window");
						anim_window::finalize();
					}else{
						set_pos(x,y);
						this->title=new char[1024];
						strcpy(this->title,title);
						glfwMakeContextCurrent(this->winpointer);
						glViewport(0, 0, width, height);
						IMGUI_CHECKVERSION();
						ImGui::CreateContext();
						ImGui::StyleColorsDark();
						ImGui_ImplGlfw_InitForOpenGL(this->winpointer, true);
						ImGui_ImplOpenGL3_Init("#version 330");
						anim_window_thread_worker(this);
						//thread_worker[0]=std::thread(anim_window_thread_worker,this);
					}
				}
				void get_title(char** title){
					strcpy(*title,this->title);
				}
				const int get_x(){
					get_size_property();
					return x;
				}
				const int get_y(){
					get_size_property();
					return y;
				}
				const int get_width(){
					get_size_property();
					return width;
				}
				const int get_height(){
					get_size_property();
					return height;
				}
				
				void set_title(const char* title){
					strcpy_s(this->title,strlen(title),title);
					glfwSetWindowTitle(winpointer,this->title);
				}
				void set_x(const int x){
					get_size_property();
					glfwSetWindowPos(winpointer,x,y);
					get_size_property();
				}
				void set_y(const int y){
					get_size_property();
					glfwSetWindowPos(winpointer,x,y);
					get_size_property();
				}
				void set_width(const int width){
					get_size_property();
					glfwSetWindowSize(winpointer,width,height);
					get_size_property();
				}
				void set_height(const int height){
					get_size_property();
					glfwSetWindowSize(winpointer,width,height);
					get_size_property();
				}
				
				void set_pos(const int x,const int y){
					set_x(x);
					set_y(y);
				}
				void set_size(const int width,const int height){
					set_width(width);
					set_height(height);
				}
				
				const anim_window* get_parent(){
					return dynamic_cast<anim_window*>(parent);
				}
				~anim_window_impl(){
					//thread_worker[0].join();
					delete [] title;
					glfwDestroyWindow(this->winpointer);
					ImGui_ImplOpenGL3_Shutdown();
					ImGui_ImplGlfw_Shutdown();
					ImGui::DestroyContext();
				}
				
	};
	
	anim_window::~anim_window(){
		//Do nothing
	}
	
	anim_window* anim_window::create_anim_window(const char* title,
			const int x,const int y,
			const int width,const int height,
			anim_window* parent){
		
		return dynamic_cast<anim_window*>(new anim_window_impl(title,x,y,width,height,parent));
	}
	int anim_window::initialize(){
		int code=1;
		anim_log::load_levels();
		spdlog::info("Intializing GLFW");
		const int ret_code=glfwInit();
		if (ret_code==GL_FALSE){
			spdlog::warn("Failed to Initialize GLFW");
			code=0;
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		return code;
	}
	
	void anim_window::finalize(){
		spdlog::info("Finalizing everything");
		glfwTerminate();
	}
}