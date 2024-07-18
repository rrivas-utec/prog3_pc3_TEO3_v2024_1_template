//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "lazy_hash_table.h"
using namespace std;

static void test_2_1() {
  LazyHashTable<int> table(10);
  
  // Añadir elementos
  std::cout << std::boolalpha << table.add(5) << std::endl;  // true
  std::cout << std::boolalpha << table.add(15) << std::endl; // true (colisión si no se maneja correctamente)
  std::cout << std::boolalpha << table.add(5) << std::endl;  // false (ya está presente)
  
  // Buscar elementos
  std::cout << table.find(5) << std::endl;  // true
  std::cout << table.find(10) << std::endl; // false

  // Reestructurar la tabla
  std::cout << table.reshape(20) << std::endl; // true o false dependiendo de si la reestructuración fue exitosa
}

TEST_CASE("Question #2.1") {
    execute_test("test_2_1.in", test_2_1);
}