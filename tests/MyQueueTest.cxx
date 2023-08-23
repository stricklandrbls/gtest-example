#include <gmock/gmock.h>
#include <Queue/MyQueue.h>

class MyQueueTest: public ::testing::Test {
protected:
    void SetUp() override {
        _q0;
    }

    MyQueue _q0 { 10 };
};

TEST_F(MyQueueTest, ConstructionWorks) {
    EXPECT_EQ(_q0.size(), 0);
    EXPECT_EQ(_q0.capacity(), 10);
}