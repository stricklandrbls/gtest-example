#include <ByteBuffer.h>

ByteBuffer::ByteBuffer(uint16_t capacity):
    _capacity{ capacity }
{
    if(_capacity > ByteBuffer::byte_capacity)
        throw "Cannot exceed byte buffer capacity"; // Would be ByteBufferException thrown.
    
    _data = new uint8_t[_capacity];
}
ByteBuffer::ByteBuffer():
    _capacity{ ByteBuffer::byte_capacity },
    _data{ new uint8_t[_capacity] }
{}

ByteBuffer::~ByteBuffer(){
    if( _data ) delete[] _data;
}