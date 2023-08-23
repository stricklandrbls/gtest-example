#include <gmock/gmock.h>
#include <ByteBuffer.h>

class ByteBufferMock: public ::testing::Test {
protected:
    ByteBuffer _bbuffer;
};

TEST(ByteBufferRAII, Construction_is_valid_length) {
    ByteBuffer _b0;
    ASSERT_EQ(_b0.capacity(), ByteBuffer::byte_capacity);

    ByteBuffer _b1 { 500 };
    ASSERT_EQ(_b1.capacity(), 500);
}

TEST(ByteBufferRAII, Cannot_construct_over_capacity) {
    ASSERT_ANY_THROW(ByteBuffer _b0{ 2000 });
}