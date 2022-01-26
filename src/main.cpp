#include <iostream>

#include <fmt/format.h>
#include <spdlog/spdlog.h>

#ifndef CMAKEMACROSAMPLE
#   define CMAKEMACROSAMPLE "NO SYSTEM NAME"
#endif

auto sum(int a, int b) {
  return a + b;
}

int main() {
  std::cout << "Hello CMake!\n";

  std::cout << CMAKEMACROSAMPLE << '\n';

  std::cout << "Sum of 3 + 4 : " << sum(3, 4) << '\n';

  std::cin.get();

  return 0;
}
