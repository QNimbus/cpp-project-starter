#include <iostream>

#include <fmt/format.h>

int main() {
  std::vector<std::string> vec = { "This", "vector", "of", "strings" };

  for (auto s : vec) {
    fmt::print("{} ", s);
  }

  fmt::print("was made possible by precompiled headers!");

  std::cin.get();

  return 0;
}
