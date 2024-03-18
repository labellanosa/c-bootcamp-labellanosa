FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable (
    token_tests
    token_tests.cc
    token.c
    int_stack.c)

target_link_libraries(
  token_tests
  gtest_main
  -lpthread
)

add_executable(
  RForth
  main.c
  token.c
  int_stack.c
  function.c
)

add_executable(
  stackDemo
  int_stack_demo.c
  int_stack.c
)

target_link_libraries(
  stackDemo 
  -lm
)

include(GoogleTest)
gtest_discover_tests(token_tests)