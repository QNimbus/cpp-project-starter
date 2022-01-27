# Sets the minimum required version of cmake for a project.
# See: https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html
cmake_minimum_required(VERSION 3.20...3.22)

# Uncomment to set a default CXX standard for the external tools like clang-tidy and cppcheck
# and the targets that do not specify a standard.
# If not set, the latest supported standard for your compiler is used
# You can later set fine-grained standards for each target using `target_compile_features`
set(CMAKE_CXX_STANDARD 17)

# Add project_options v0.1.1 - https://github.com/qnimbus/cpp-project-options
# See: https://cmake.org/cmake/help/latest/module/FetchContent.html
include(FetchContent)
FetchContent_Declare(_project_options URL https://github.com/QNimbus/cpp-project-options/archive/refs/tags/v0.1.1.zip)
FetchContent_MakeAvailable(_project_options)
include(${_project_options_SOURCE_DIR}/Index.cmake)

# ************************   CHANGE ME   ************************
# Set the project name and language
# See: https://cmake.org/cmake/help/latest/command/project.html
project(myproject
        HOMEPAGE_URL https://github.com/qnimbus/cpp-starter-project
        LANGUAGES CXX
        DESCRIPTION "My project description")
# ************************ / CHANGE ME   ************************

# Initialize project_options variable related to this project
# This overwrites `project_options` and sets `project_warnings`
# uncomment the options to enable them:
project_options(
      ENABLE_PCH
      ENABLE_CONAN
      # PCH_HEADERS
      # CONAN_OPTIONS
      )

target_compile_features(project_options INTERFACE cxx_std_17)

# Adding the src folder ('start' project):
add_subdirectory(src)

# Make 'start' project the Visual Studio startup project
# See: https://cmake.org/cmake/help/latest/prop_dir/VS_STARTUP_PROJECT.html
set_property(GLOBAL PROPERTY VS_STARTUP_PROJECT start)
