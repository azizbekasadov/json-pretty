#pragma once

#include "json_pretty/error.hpp"
#include <variant>

namespace json_pretty {

template <typename T> using Result = std::variant<T, ParseError>;

} // namespace json_pretty
