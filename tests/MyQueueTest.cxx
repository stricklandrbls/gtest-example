#include <gmock/gmock.h>
#include <Queue/MyQueue.h>

class MyQueueTest: public ::testing::Test {
protected:
    void SetUp() override {
        _q0;
    }
    void increment(int iterations){
        int x = 100;
        for(int i = 0; i < iterations; i++)
            _q0.Enqueue(x);
    }
    void decrement(int increment_iterations, int decrement_iterations){
        increment(increment_iterations);

        int* x { nullptr };

        for(int i = 0; i < decrement_iterations; i++)
            x = _q0.Dequeue();
            
    }
    MyQueue _q0 { 10 };
};

TEST_F(MyQueueTest, ConstructionWorks) {
    EXPECT_EQ(_q0.size(), 0);
    EXPECT_EQ(_q0.capacity(), 10);
}

TEST_F(MyQueueTest, Size_is_Accurate_On_Increment) {
    const int ITERATIONS = 5;
    increment(ITERATIONS);
    
    EXPECT_EQ(_q0.size(), ITERATIONS);
}

TEST_F(MyQueueTest, Size_is_Accurate_On_Decrement) {
    decrement(5, 1);
    ASSERT_EQ(_q0.size(), (5-1));
}

TEST_F(MyQueueTest, Non_Null_Dequeue) {
    increment(2);
    auto x = _q0.Dequeue();

    ASSERT_NE(x, nullptr);
}