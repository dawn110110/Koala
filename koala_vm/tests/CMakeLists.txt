if(UNIX)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
endif()

SET(KOALA_TESTS_SOURCES
    "tests_main.cc"
    "test_style_sample.cc")

INCLUDE_DIRECTORIES("${KOALA_VM_SOURCE_DIR}/deps/gtest-1.7.0/include")
INCLUDE_DIRECTORIES("${KOALA_VM_SOURCE_DIR}/include")

ADD_EXECUTABLE(tests_koala ${KOALA_TESTS_SOURCES})
TARGET_LINK_LIBRARIES(tests_koala
    "gtest"
    "gtest_main"
    "koala_lib")

