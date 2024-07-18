//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "lazy_hash_table.h"
using namespace std;

static void test_2_2() {
  LazyHashTable<std::string> table(5);
  
  // Añadir elementos
  std::cout << std::boolalpha << table.add("apple") << std::endl;  // true
  std::cout << std::boolalpha << table.add("banana") << std::endl; // false (colisión)
  std::cout << std::boolalpha << table.add("cherry") << std::endl; // false (colisión)
  std::cout << std::boolalpha << table.add("date") << std::endl;   // true
  std::cout << std::boolalpha << table.add("fig") << std::endl;    // true
  std::cout << std::boolalpha << table.add("grape") << std::endl;  // false (colisión)
  
  // Buscar elementos
  std::cout << table.find("banana") << std::endl; // false
  std::cout << table.find("kiwi") << std::endl;   // false

  // Reestructurar la tabla
  std::cout << table.reshape(10) << std::endl; // true

}

TEST_CASE("Question #2.2") {
    execute_test("test_2_2.in", test_2_2);
}