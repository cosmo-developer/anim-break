#include <animbreak/log.hpp>
#include <cstdio>
#include <chrono>
#include <spdlog/spdlog.h>
#include <spdlog/cfg/env.h>
#include <spdlog/fmt/ostr.h>

namespace anim{
	#ifdef anim_log__load_levels_const_int_argc__const_char_pp_argv
	void anim_log::load_levels(const int argc,const char** argv){
		//spdlog::cfg::load_argv_levels(argc, argv);
	}
	#endif
	
	void anim_log::load_levels(){
		spdlog::cfg::load_env_levels();
	}
}