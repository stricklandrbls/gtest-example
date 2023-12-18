
add_compile_options(-Weffc++)
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

add_library(
    ByteBuffer
    SHARED ./lib/ByteBuffer/ByteBuffer.cxx
)
target_include_directories(
    ByteBuffer
    PUBLIC ./lib/ByteBuffer
)

# add_library(
#     Soundex
#     SHARED ./lib/Soundex.cxx
# )
# target_include_directories(
#     Soundex
#     PUBLIC ./lib/Soundex
# )