#include "json_pretty/value.hpp"
#include <cstdlib>
#include <ios>
#include <iostream>

using namespace std;

int main() {
  using json_pretty::JsonValue;

  JsonValue null_value;
  JsonValue bool_value = true;
  JsonValue number_value = 42.5;
  JsonValue string_value = "test test";

  JsonValue::array_t skills = {JsonValue("C++"), JsonValue("Swift"),
                               JsonValue("iOS")};

  JsonValue array_value = skills;

  JsonValue::object_t person = {{"name", JsonValue("Aziz")},
                                {"age", JsonValue(25.0)},
                                {"active", JsonValue(true)}};
  JsonValue object_value = person;

  cout << boolalpha;
  cout << "null_value.is_null(): " << null_value.is_null() << endl;
  cout << "bool_value.as_bool(): " << bool_value.as_bool() << endl;
  cout << "number_value.as_number(): " << number_value.as_number() << endl;
  cout << "string_value.as_string(): " << string_value.as_string() << endl;
  cout << "array_value.is_array(): " << array_value.is_array() << endl;
  cout << "object_value.is_object(): " << object_value.is_object() << endl;
  cout << "person[name]: " << object_value.as_object().at("name").as_string()
       << endl;

  return EXIT_SUCCESS;
}