FetchContent_Declare(
  catch
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v2.9.1)
FetchContent_MakeAvailable(catch)

set(unit_tests
  tests-main
  tests-helloworld
)

add_executable(testlib ${unit_tests})
target_compile_features(testlib PRIVATE cxx_std_14)

target_link_libraries(testlib PRIVATE examplelib Catch2::Catch2)

add_test(NAME test_all COMMAND testlib)
