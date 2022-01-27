# Find a package (usually provided by something external to the project), and load its package-specific details.
# See: https://cmake.org/cmake/help/latest/command/find_package.html
find_package(spdlog)

# Add executable target
# See: https://cmake.org/cmake/help/latest/command/add_executable.html
add_executable(start main.cpp)

# See: https://cmake.org/cmake/help/latest/command/target_link_libraries.html
target_link_libraries(
  start
  PRIVATE project_options
          fmt::fmt
          spdlog::spdlog)
