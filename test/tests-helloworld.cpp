#include <catch2/catch.hpp>

#include <examplelib.hpp>

template <typename _StringType = std::string>
using hello_world = examplelib::hello_world<_StringType>;

SCENARIO("hello_world structs can be initialized and changed",
         "[hello_world]") {
  GIVEN("A hello_world object") {
    hello_world<std::string> hello{};

    REQUIRE(hello.message == "Hello World!");

    WHEN("the message is assigned a new value") {
      hello.message = "Hallo Welt!";

      THEN("the message contains that new value") {
        REQUIRE(hello.message == "Hallo Welt!");
      }
    }
  }
}
