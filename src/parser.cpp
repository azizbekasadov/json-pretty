#include "json_pretty/parser.hpp"

#include <string_view>
#include <utility>

namespace json_pretty {

Parser::Parser(std::string_view input) : input_(input) {}

Result<JsonValue> Parser::parse() {
  return ParseError{.message = "Parser is not implemented yet",
                    .position = pos_,
                    .line = line_,
                    .column = column_};
}

Result<JsonValue> parse_json(std::string_view input) {
  Parser parser(input);
  return parser.parse();
}
} // namespace json_pretty