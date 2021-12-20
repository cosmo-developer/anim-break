#pragma once

namespace anim{
	class anim_window{
		anim_window* parent;
		public:
			anim_window(const char* title,int x,int y,anim_window* parent=nullptr);
			virtual ~anim_window();
			const char* get_title();
			const int get_x();
			const int get_y();
			const anim_window* get_parent();
	};
}