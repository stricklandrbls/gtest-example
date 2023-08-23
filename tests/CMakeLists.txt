enable_testing()
find_package(GTest REQUIRED)
include_directories(/usr/local/include/gtest)

add_executable(
    MyFuncTest
    ./MyFuncTest.cxx
)
target_include_directories(
    MyFuncTest
    PUBLIC ${CMAKE_SOURCE_DIR}/core/lib/MyFunc
)
target_link_libraries(
    MyFuncTest
    MyFunc
    pthread
    GTest::gtest_main
)


add_executable(
    MyQueueTest
    ./MyQueueTest.cxx
)
target_include_directories(
    MyQueueTest
    PUBLIC ${CMAKE_SOURCE_DIR}/core/lib/
)
target_link_libraries(
    MyQueueTest
    MyQueue
    pthread
    GTest::gtest_main
)
include(GoogleTest)
gtest_discover_tests(MyFuncTest)