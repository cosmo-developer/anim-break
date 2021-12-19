#include <doctest/doctest.h>
#include <animbreak.hpp>

TEST_CASE("CheckingVersion")
{
	SUBCASE("MajorVersion"){
		REQUIRE(ANIM_BREAK_STUDIO_MAJOR_VERSION==get_major_version());
	}
	SUBCASE("MinorVersion"){
		REQUIRE(ANIM_BREAK_STUDIO_MINOR_VERSION==get_minor_version());
	}
	SUBCASE("PatchVersion"){
		REQUIRE(ANIM_BREAK_STUDIO_MAJOR_VERSION==get_patch_version());
	}
}