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
<h3>Overview</h3>
A common mistake in TDD is focusing on testing member functions, ie. "Why have an `add()` member function. Let's write `TEST(MyObjTest, Add)`". The `add()` functionality
could be quite code intensive to test every scenario of when `add()` would be called. 

*Instead*, focus on behaviors or **cases** that describe behaviors.
- What happens when you `add` something you've already added?
- What if a client passes empty data to `add`?

These can easily translate to the following `TEST` functions:
- `TEST(MyObjTest, IgnoreDuplicateAdd)`
- `TEST(MyObjTest, IgnoreEmptyAddParameter)`

<h3>Using Tests to Descbribe Behavior</h3>
Tests should describe, or document, the behavior of the system. The full understanding of a well-written test is best gleaned by combining two things:
- The test name (Summarizes the exhibited behavior)
- The test statements (Demonstrate the summarized behavior)

**Example**
```c++
TEST_F(RetweetCollection, IgnoresDuplicateTweetAdded) {
    Tweet t("msg", "@user");
    Tweet duplicate(t);

    collection.add(tweet);
    collection.add(duplicate);

    ASSERT_THAT(collection.size(), Eq(1u));
}
```
</details>

<details><summary><h2><i>Test-driving</i> VS <i>Testing</i></h2></summary>

Is there a difference? **Yes**.

Using testing technique, you would seek to exhaustively analyze the specification in question (and possibly the code) and devise tests that exhaustively cover the behavior. TDD is instead a technique for **driving the design of the code**. Meaning, tests primarily serve the purpose of specifying the behavior of what you will build.

Another explanation would be that, with a *testing* mentality, you seek to create tests that cover a breadth of concerns, ie. you create tests for five cases: zero, one, many, boundary, and exceptional cases. With a *test-driving* mentatlity, you write tests in order to drive in code that you believe meets desired specifications. Yes, TDD and a test-driving mentality generate unit tests but more so as a by-product of development.

## In Regards to `Soundex` Example
This topic arose when determining whether to write test assertions for each individual `std::pair<>` within the unordered map in
the `encodedDigit` member function.

Typically, when scenarios like this arise, it's easiest to ask, "Would having the additional assertions provide an increased understanding of how the feature works?".
</details>

<details><summary><h2>Getting Green On Red</h2></summary>
The first rule of TDD requires you to first demonstrate test failure before you can write any code. If you write only just enough code to make a test pass, another test
for additional functionality should fail automatically.

Tests that pass right off the bat are referred to as *premature passes*.

</details>