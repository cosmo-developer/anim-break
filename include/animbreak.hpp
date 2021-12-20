#pragma once
#include <cstdio>
#include <chrono>
#include <spdlog/spdlog.h>
#include <spdlog/cfg/env.h>
#include <spdlog/fmt/ostr.h>

namespace anim{
	int get_major_version();
	int get_minor_version();
	int get_patch_version();
}