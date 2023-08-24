# entr example script

ls tests/*.cxx | entr -s 'clear && cmake --build build --config Debug --target MyFuncTest -j 14 && ./build/tests/MyFuncTest'
