# Find a package (usually provided by something external to the project), and load its package-specific details.
# See: https://cmake.org/cmake/help/latest/command/find_package.html?highlight=find_package
find_package(spdlog)

# Add executable target
# See: https://cmake.org/cmake/help/latest/command/add_executable.html?highlight=add_executab#command:add_executable
add_executable(main main.cpp)

# -- e.g. Debug-Windows-x64
# outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"   -- https://premake.github.io/docs/Tokens/
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE}-${CMAKE_SYSTEM_NAME}-${CMAKE_CXX_COMPILER_ARCHITECTURE_ID})

# See: https://cmake.org/cmake/help/latest/command/target_link_libraries.html
target_link_libraries(
  main
  PUBLIC spdlog::spdlog)
