cmake_minimum_required(VERSION 3.0.2)
# Allow setting PROJECT_VERSION through project():
cmake_policy(SET CMP0048 NEW)

project(
	once
	VERSION 0.1.0
	DESCRIPTION "Header-only framework implementing QObject::connect() fire-once-and-disconnect"
	LANGUAGES CXX
	)

find_package(
	Qt5
	REQUIRED
	COMPONENTS
		Core
	CONFIG
	)

add_library(${PROJECT_NAME} INTERFACE)
target_sources(${PROJECT_NAME}
	INTERFACE
		"${CMAKE_CURRENT_SOURCE_DIR}/include/once/once.h"
	)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_11)
target_link_libraries(${PROJECT_NAME} INTERFACE Qt5::Core)
target_include_directories(${PROJECT_NAME}
	INTERFACE
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	)
