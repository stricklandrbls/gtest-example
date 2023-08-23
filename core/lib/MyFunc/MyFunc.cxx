#include <MyFunc.h>

MyFuncClass::MyFuncClass(int x): _v { x }{}

int MyFuncClass::get_v() { return _v; }


int my_func() { return 69; }
int my_func(MyFuncClass mfc) {
    return mfc.get_v() + 69;
}

