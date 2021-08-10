cmake_minimum_required(VERSION VERSION 3.18 FATAL_ERROR)

project(stdfilesystem-test LANGUAGES NONE)


# Handle the CXXSTD option
set(CXXSTD "${CXXSTD}" CACHE STRING "Select the C++ standard to use. Choose between 14 and 17." FORCE)

if(CXXSTD STREQUAL "")
    message(STATUS "Using default CXXSTD=17")
    set(CXXSTD 17)
endif()

if(CXXSTD STREQUAL "14" OR CXXSTD STREQUAL "17")
    set(CMAKE_CXX_EXTENSIONS OFF)
    set(CMAKE_CXX_STANDARD_REQUIRED true)
    set(CMAKE_CXX_STANDARD ${CXXSTD})
    message(STATUS "Using CXXSTD ${CXXSTD}")
else()
    message(FATAL_ERROR "CMake option CXXSTD must be 14 or 17. '${CXXSTD}' provided")
endif()

# Test that the compiler supports c++XX
include(CheckLanguage)
check_language(CXX)
if(CMAKE_CXX_COMPILER)
    enable_language(CXX)
else()
    message(FATAL_ERROR "CXX Compiler does not work with CMAKE_CXX_STANDARD ${CXXSTD}")
endif()

# Set the defualt CMAKE BUILD TYPE to Release (for make-like generators)
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
        "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Set the binary output location
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIG>)

# Export compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "Control the output of compile_commands.json")

# List source files
set(SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

# Create the executable target
add_executable(${PROJECT_NAME} ${SRC})


# GCC < 9.1 needs linking with  -lstdc++fs for c++17
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(${PROJECT_NAME} stdc++fs)
endif()


# LLVM < 9.0 needs linking with -lc++fs


