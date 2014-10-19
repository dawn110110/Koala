if(UNIX)
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")
endif()

SET(KOALA_SOURCES
    "main.cc"
    "style_sample.cc")

INCLUDE_DIRECTORIES(${KOALA_VM_SOURCE_DIR}/include)
ADD_EXECUTABLE(koala ${KOALA_SOURCES})
ADD_LIBRARY(koala_lib ${KOALA_SOURCES})
