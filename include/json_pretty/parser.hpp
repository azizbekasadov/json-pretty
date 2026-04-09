#pragma once

#include <string_view>

#include "json_pretty/result.hpp"
#include "json_pretty/value.hpp"
#include "value.hpp"

namespace json_pretty {

class Parser {
public:
  explicit Parser(std::string_view input);

  [[nodiscard]] Result<JsonValue> parse();

private:
  std::string_view input_;
  std::size_t pos = 0;
  std::size_t line_ = 1;
  std::size_t column_ = 1;
};

[[nodiscard]] Result<JsonValue>
parse_json(std::string_view input); // static method for convenience purposes
} // namespace json_pretty
