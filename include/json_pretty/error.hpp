#pragma once

#include <cstddef>
#include <string>

namespace json_pretty {

using namespace std;

struct ParseError {
  string message;
  size_t position = 0;
  size_t line = 1;
  size_t column = 1;
};

} // namespace json_pretty
