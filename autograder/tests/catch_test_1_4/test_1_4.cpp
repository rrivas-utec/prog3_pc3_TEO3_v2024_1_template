//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "find_shortest_distance.h"
using namespace std;

static void test_1_4() {
  int result = find_shortest_distance(5, 11,
                                      {[](int x) { return x + 2; },
                                       [](int x) { return x - 1; },
                                       [](int x) { return x * 3; }});
    
  // Debería imprimir 3 ((5 - 1) * 3 - 1)
  std::cout << result << std::endl;
  
  result = find_shortest_distance(10, 1, {[](int x) { return x - 1; },
                                              [](int x) { return x / 2; }});

  // Debería imprimir 3 (10 / 2 / 2 - 1)
  std::cout << result << std::endl;

}

TEST_CASE("Question #1.4") {
    execute_test("test_1_4.in", test_1_4);
}