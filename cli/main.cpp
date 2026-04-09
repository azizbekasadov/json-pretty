#include "json_pretty/value.hpp"
#include <cstdlib>
#include <iostream>

int main() {
  json_pretty::JsonValue value{};
  (void)value;

  std::cout << "json-pretty: project is set up" << std::endl;

  return EXIT_SUCCESS;
}