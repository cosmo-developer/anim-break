#include <doctest/doctest.h>
#include <animbreak/ui/window_manager.hpp>
#include <string>

DOCTEST_TEST_CASE("WindowManager"){
	
	SUBCASE("Initializing"){
		REQUIRE(anim::anim_window::initialize()==1);
	}
	
	SUBCASE("Checking Creation Of Window"){
			WHEN("CreatingWindow"){
				anim::anim_window* window=anim::anim_window::create_anim_window("Hello",300,200,600,500,nullptr);
				REQUIRE(window!=nullptr);
				WHEN("Window Created"){
					THEN("Check Size"){
						REQUIRE(window->get_width()==600);
						REQUIRE(window->get_height()==500);
					}
					THEN("Check Coord"){
						REQUIRE(window->get_x()==300);
						REQUIRE(window->get_y()==200);
					}
					THEN("Main Window(parent should be nullptr)"){
						REQUIRE(window->get_parent()==nullptr);
					}
					THEN("Check Title"){
						char* title=new char[1024];
						window->get_title(&title);
						REQUIRE(std::string(title)==std::string("Hello"));
						delete title;
					}
					delete[] window;
				}
			}
	}
	
	SUBCASE("Finalizing"){
		anim::anim_window::finalize();
	}
}