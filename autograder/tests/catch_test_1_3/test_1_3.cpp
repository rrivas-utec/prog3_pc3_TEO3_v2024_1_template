//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "redirect_io.h"
#include "find_shortest_distance.h"
using namespace std;

static void test_1_3() {
  int result = find_shortest_distance(1, 1024, {[](int x) { return x * 2; }});
    
  // Debería imprimir 10 ( 1 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 * 2 )
  std::cout << result << std::endl;
}

TEST_CASE("Question #1.3") {
    execute_test("test_1_3.in", test_1_3);
}