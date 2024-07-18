//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "lazy_hash_table.h"
using namespace std;

static void test_2_4() {
  LazyHashTable<double> table3(8);
  
  // Añadir elementos
  std::cout << std::boolalpha << std::endl;
  std::cout << table3.add(1.1) << std::endl;  // true
  std::cout << table3.add(2.2) << std::endl;  // true
  std::cout << table3.add(3.3) << std::endl;  // true
  std::cout << table3.add(4.4) << std::endl;  // true
  std::cout << table3.add(5.5) << std::endl;  // true
  std::cout << table3.add(6.6) << std::endl;  // true
  std::cout << table3.add(7.7) << std::endl;  // true
  std::cout << table3.add(8.8) << std::endl;  // true
  std::cout << table3.add(9.9) << std::endl;  // false (colisión)
  
  // Buscar elementos
  std::cout << table3.find(4.4) << std::endl; // true
  std::cout << table3.find(10.1) << std::endl; // false

  // Reestructurar la tabla
  std::cout << table3.reshape(16) << std::endl; // true o false dependiendo de si la reestructuración fue exitosa

}

TEST_CASE("Question #2.4") {
    execute_test("test_2_4.in", test_2_4);
}