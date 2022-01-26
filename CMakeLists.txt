# Sets the minimum required version of cmake for a project. 
# See: https://cmake.org/cmake/help/latest/command/cmake_minimum_required.html?highlight=cmake_minimum_required
cmake_minimum_required(VERSION 3.20...3.22)

# Add project_options v0.1.0
# https://github.com/qnimbus/cpp-project-options
include(FetchContent)
FetchContent_Declare(_project_options URL https://github.com/cpp-best-practices/project_options/archive/refs/tags/v0.12.3.zip)
FetchContent_MakeAvailable(_project_options)
include(${_project_options_SOURCE_DIR}/Index.cmake)

# **************   CHANGE ME   ************** 
# Set the project name and language
# See: https://cmake.org/cmake/help/latest/command/project.html?highlight=project
project(myproject
        HOMEPAGE_URL https://github.com/qnimbus/cpp-starter-project
        LANGUAGES CXX
        DESCRIPTION "My project description")
# ************** / CHANGE ME   ************** 

# Initialize project_options variable related to this project
# This overwrites `project_options` and sets `project_warnings`
# uncomment the options to enable them:
project_options(
      ENABLE_CONAN
      # CONAN_OPTIONS
)

# Adding the src folder:
add_subdirectory(src)

# Organize default targets into subfolder for better organization in IDE's (e.g. MSVC)
# set_property(GLOBAL PROPERTY USE_FOLDERS ON)                    # See: https://cmake.org/cmake/help/latest/prop_gbl/USE_FOLDERS.html
# set_property(GLOBAL PROPERTY VS_STARTUP_PROJECT main)           # See: https://cmake.org/cmake/help/latest/prop_dir/VS_STARTUP_PROJECT.html
# set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake") # See: https://cmake.org/cmake/help/latest/prop_gbl/PREDEFINED_TARGETS_FOLDER.html

# Add our CMake modules to the search path.
# set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Includes
# include(Utilities)
# include(BuildType)
