//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "find_shortest_distance.h"
using namespace std;

static void test_1_1() {
  int result = find_shortest_distance(2, 9,
                                      {
                                          [](int x) { return x + 1; },
                                          [](int x) { return x * 2; },
                                          [](int x) { return x - 1; }
                                      });
    
  // Debería imprimir 3 ( 2 * 2 * 2 + 1)
  std::cout << result << std::endl;
}

TEST_CASE("Question #1.1") {
    execute_test("test_1_1.in", test_1_1);
}