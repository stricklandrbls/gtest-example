#pragma once

class MyFuncClass {
public:
    MyFuncClass(int);
    int get_v();
private:
    int _v {0};
};

/**
 * @brief Test function to use in an example unit test. Should return 69.
*/
int my_func();
int my_func(MyFuncClass);
