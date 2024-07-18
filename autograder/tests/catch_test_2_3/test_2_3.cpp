//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "lazy_hash_table.h"
using namespace std;

static void test_2_3() {
  LazyHashTable<std::string> lh(5);
  std::vector<std::string> v {"Jose", "Juan", "Maria", "Raul", "Tong", "Rosa"};
  for (const auto& value: v) {
    if (lh.add(value))
      std::cout << value << " was added\n";
    else
      std::cout << value << " was not added\n";
  }
  lh.reshape(7);
  std::cout << std::endl;
  for (const auto& [has_added, value]: lh) {
    if (has_added)
      std::cout << value << " ";
  }
  std::cout << std::endl;
  std::cout << std::boolalpha << lh.find("brian") << std::endl;
  
}

TEST_CASE("Question #2.3") {
    execute_test("test_2_3.in", test_2_3);
}