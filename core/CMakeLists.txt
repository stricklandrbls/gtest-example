add_library(
    MyFunc
    SHARED ./lib/MyFunc/MyFunc.cxx
)
target_include_directories(
    MyFunc
    PUBLIC ./lib/MyFunc
)

add_library(
    MyQueue
    SHARED ./lib/Queue/MyQueue.cxx
)
target_include_directories(
    MyQueue
    PUBLIC ./lib
)