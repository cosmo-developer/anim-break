#pragma once

namespace anim{
	class anim_window{
		public:
			static int initialize();
			static anim_window* create_anim_window(const char* title,const int x,
					const int y,const int width,
					const int height,
					anim_window* parent=nullptr);
			virtual ~anim_window();
			virtual void get_title(char**)=0;
			virtual const int get_x()=0;
			virtual const int get_y()=0;
			virtual const int get_width()=0;
			virtual const int get_height()=0;
			
			virtual void set_title(const char*)=0;
			virtual void set_x(const int x)=0;
			virtual void set_y(const int y)=0;
			virtual void set_width(const int width)=0;
			virtual void set_height(const int height)=0;
			
			virtual void set_pos(const int x,const int y)=0;
			virtual void set_size(const int width,const int height)=0;
			
			virtual const anim_window* get_parent()=0;
			static void finalize();
	};
}