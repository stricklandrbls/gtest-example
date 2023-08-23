#pragma once

#include <cstdint>

class ByteBuffer {
public:
    static constexpr uint16_t byte_capacity = 1024;

    explicit ByteBuffer(uint16_t capacity);
    ByteBuffer();
    ~ByteBuffer();

    constexpr uint16_t capacity() const { return _capacity; }
private:
    uint16_t _capacity  { 0 };
    uint8_t *_data{ nullptr };
};