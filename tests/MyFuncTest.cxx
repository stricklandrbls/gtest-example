#include <MyFunc.h>
#include <gtest/gtest.h>

TEST(MyFuncTest, Returns69) {
    EXPECT_EQ(my_func(), 69);
}
TEST(MyFuncTest, CanInstantiateClass) {
    MyFuncClass mfc { 10 };
}
TEST(MyFuncTest, Returns79) {
    MyFuncClass mfc { 10 };
    EXPECT_EQ(my_func(mfc), 79);
}
