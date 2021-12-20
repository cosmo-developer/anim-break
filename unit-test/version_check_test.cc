#include <doctest/doctest.h>
#include <animbreak.hpp>

TEST_CASE("CheckingVersion")
{
	SUBCASE("MajorVersion"){
		REQUIRE(REQUIRED_ANIM_BREAK_STUDIO_MAJOR_VERSION==anim::get_major_version());
	}
	SUBCASE("MinorVersion"){
		REQUIRE(REQUIRED_ANIM_BREAK_STUDIO_MINOR_VERSION==anim::get_minor_version());
	}
	SUBCASE("PatchVersion"){
		REQUIRE(REQUIRED_ANIM_BREAK_STUDIO_PATCH_VERSION==anim::get_patch_version());
	}
}