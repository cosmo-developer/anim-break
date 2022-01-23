#include <iostream>
#include <animbreak/ui/window_manager.hpp>
using namespace anim;
int main(const int argc,const char** argv){
	anim_window::initialize();
	anim_window* window=anim_window::create_anim_window("Hello",100,100,800,600);
	anim_window::finalize();
	return 0;
}