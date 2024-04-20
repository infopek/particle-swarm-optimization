cmake_minimum_required(VERSION 3.16..3.24)

project(Core	
    VERSION 1.0.0
    DESCRIPTION "Particle swarm optimization implementation"
    LANGUAGES CXX
    )  

add_library(Core 
    src/pso/particle_swarm_optimization.cpp
    src/pso/parameter.cpp
    src/pso/function_approximation.cpp
  	)
add_library(Core::Core ALIAS Core)

target_include_directories(
    Core 
		PUBLIC 	
			$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:include>
	)