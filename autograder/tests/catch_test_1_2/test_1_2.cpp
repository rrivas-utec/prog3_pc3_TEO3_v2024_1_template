//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "find_shortest_distance.h"
using namespace std;

static void test_1_2() {
  int result = find_shortest_distance(20, 5,
                                      {
                                          [](int x) { return x - 3; },
                                          [](int x) { return x / 2; }
                                      });
    
  // Debería imprimir 2 (20 / 2 / 2)
  std::cout << result << std::endl;
}

TEST_CASE("Question #1.2") {
    execute_test("test_1_2.in", test_1_2);
}