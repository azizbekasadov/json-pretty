#pragma once

#include <map>
#include <string>
#include <utility>
#include <variant>
#include <vector>

namespace json_pretty {

using namespace std;

struct JsonValue {
  using array_t = vector<JsonValue>;
  using object_t = map<string, JsonValue>;
  using storage_t = variant<monostate, bool, double, string, array_t, object_t>;

  storage_t value;

  // initializers
  JsonValue() : value(monostate{}) {}
  JsonValue(nullptr_t) : value(monostate{}) {}
  JsonValue(bool b) : value(b) {}
  JsonValue(double n) : value(n) {}
  JsonValue(string s) : value(std::move(s)) {}
  JsonValue(const char *s) : value(string{s}) {}
  JsonValue(array_t a) : value(std::move(a)) {}
  JsonValue(object_t o) : value(std::move(o)) {}

  // API
  [[nodiscard]] bool is_null() const noexcept {
    return std::holds_alternative<std::monostate>(value);
  }

  [[nodiscard]] bool is_bool() const noexcept {
    return std::holds_alternative<bool>(value);
  }

  [[nodiscard]] bool is_number() const noexcept {
    return std::holds_alternative<double>(value);
  }

  [[nodiscard]] bool is_string() const noexcept {
    return std::holds_alternative<std::string>(value);
  }

  [[nodiscard]] bool is_array() const noexcept {
    return std::holds_alternative<array_t>(value);
  }

  [[nodiscard]] bool is_object() const noexcept {
    return std::holds_alternative<object_t>(value);
  }

  [[nodiscard]] const bool &as_bool() const { return std::get<bool>(value); }

  [[nodiscard]] const double &as_number() const {
    return std::get<double>(value);
  }

  [[nodiscard]] const std::string &as_string() const {
    return std::get<std::string>(value);
  }

  [[nodiscard]] const array_t &as_array() const {
    return std::get<array_t>(value);
  }

  [[nodiscard]] const object_t &as_object() const {
    return std::get<object_t>(value);
  }
};

} // namespace json_pretty

// const nonexcept -> It specifies that a function will not throw an exception
// or at least not one that can be caught and recovered from