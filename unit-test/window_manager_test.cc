#include <doctest/doctest.h>
#include <animbreak/ui/window_manager.hpp>
#include <string>

DOCTEST_TEST_CASE("WindowManager"){
	SUBCASE("Checking Intialization and Creation Of Window"){
		WHEN("Initializing"){
			REQUIRE(anim::anim_window::initialize()==1);
			THEN("CreatingWindow"){
				anim::anim_window* window=anim::anim_window::create_anim_window("Hello",0,0,600,500,nullptr);
				REQUIRE(window!=nullptr);
				WHEN("Window Created"){
					THEN("Check Size"){
						REQUIRE(window->get_width()==600);
						REQUIRE(window->get_height()==500);
					}
					THEN("Check Coord"){
						REQUIRE(window->get_x()==0);
						REQUIRE(window->get_y()==0);
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
				}
			}
			anim::anim_window::finalize();
		}
	}
}