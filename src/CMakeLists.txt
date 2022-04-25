add_subdirectory(cls)

add_executable(
  home_test
  home_test.cpp
)
target_link_libraries(home_test
  cls
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(home_test)


add_custom_target(test_memcheck
    COMMAND ${CMAKE_CTEST_COMMAND} 
        --force-new-ctest-process --test-action memcheck
    COMMAND cat "${CMAKE_BINARY_DIR}/Testing/Temporary/MemoryChecker.*.log"
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}")


add_executable(automata main.cpp)


target_link_libraries(automata
  PRIVATE
    cls
  )