cmake_minimum_required(VERSION 3.16)

project(luogu_practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

file(GLOB problem_sources CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/problems/*.cpp"
)

if(NOT problem_sources)
    message(FATAL_ERROR "No problem source files found in problems/")
endif()

foreach(problem_source IN LISTS problem_sources)
    get_filename_component(problem_name "${problem_source}" NAME_WE)
    add_executable("${problem_name}" "${problem_source}")
    target_include_directories("${problem_name}" PRIVATE "${CMAKE_SOURCE_DIR}/include")

    if(MSVC)
        target_compile_options("${problem_name}" PRIVATE /W4)
    else()
        target_compile_options("${problem_name}" PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endforeach()
