# gtest-example
Working through "Modern C++ Programming with Test Driven Development"

# Project Structure

```
gtest-example/
├─  CMakeLists.txt
├─  core/
│   ├─  CMakeLists.txt
│   ├─  lib/
│   │   └── MyFunc/
│   │   │   ├─ MyFunc.cxx
│   │   │   └─ MyFunc.h
├─  tests/
│   ├─  CMakeLists.txt
│   ├─  MyFuncTest.cxx
```

<hr style="width:85%">

> Directory symbols: ` │ ├─ └─ ` 

# GTest TEST Macro Types

### `TEST()`

Generic test function that takes 2 arguments: Test Suite Name, Test Function Name

### `TEST_F()`

Test function for running fixtures in GMock. This macro takes two arguments: Class, Test Function Name.

The `Class` argument is the class name of the desired class to test *(See `tests/MyQueueTest.cxx`)*. 

# GTest Assertion Types

The two main types of assertions are `ASSERT_*` and `EXPECT_*`.

Two rules of thumb are:
- Use `EXPECT_*` when you want to test to continue to reveal more errors after the assertion failure.
- Use `ASSERT_*` when continuing after failure doesnt make sense.


# TDD Notes

<details><summary><h2>Test Behavior, Not Methods</h2></summary>
A common mistake in TDD is focusing on testing member functions, ie. "Why have an `add()` member function. Let's write `TEST(MyObjTest, Add)`". The `add()` functionality
could be quite code intensive to test every scenario of when `add()` would be called. 

*Instead*, focus on behaviors or **cases** that describe behaviors.
- What happens when you `add` something you've already added?
- What if a client passes empty data to `add`?

These can easily translate to the following `TEST` functions:
- `TEST(MyObjTest, IgnoreDuplicateAdd)`
- `TEST(MyObjTest, IgnoreEmptyAddParameter)`

</details>

<details><summary><h2>Getting Green On Red</h2></summary>
The first rule of TDD requires you to first demonstrate test failure before you can write any code. If you write only just enough code to make a test pass, another test
for additional functionality should fail automatically.

Tests that pass right off the bat are referred to as *premature passes*.

</details>