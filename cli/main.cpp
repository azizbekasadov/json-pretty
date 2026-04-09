#include "json_pretty/error.hpp"
#include "json_pretty/parser.hpp"
#include "json_pretty/value.hpp"

#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  const std::string input = R"({"name":"Aziz", "age":28})";
  auto result = json_pretty::parse_json(input);

  if (std::holds_alternative<json_pretty::ParseError>(result)) {
    const auto &error = std::get<json_pretty::ParseError>(result);

    std::cout << "Parse failed" << std::endl;
    std::cout << "message: " << error.message << std::endl;
    std::cout << "line: " << error.line << ", column: " << error.column
              << std::endl;
    return 0;
  }

  std::cout << "Parse succeeded\n";

  return EXIT_SUCCESS;
}