CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(LFUCache)
SET(LIBRARY_OUTPUT_PATH  ${PROJECT_SOURCE_DIR})
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
ADD_DEFINITIONS(
    -g
    -std=c++0x
    -O2
    #-O0
    -Wall
    -Werror
    -fpermissive
    -Wno-write-strings
    -Wno-literal-suffix
    -Wno-ignored-qualifiers
    -Wno-unused-local-typedefs
    -Wno-invalid-offsetof
    -Wno-unused-parameter
    -Wno-unused-function
    -Wno-narrowing
    -D_GLIBCXX_HAVE_GTHR_DEFAULT
    -Wno-strict-aliasing
    -Wno-parentheses
    -Wno-unused-but-set-variable
    -Wno-conversion
    -Wno-deprecated
)
SET(WORK_ROOT_DIR ${PROJECT_SOURCE_DIR})
INCLUDE_DIRECTORIES()
LINK_DIRECTORIES()

AUX_SOURCE_DIRECTORY(. SRC_LIST)

SET(LIB )

ADD_EXECUTABLE(main ${SRC_LIST})
TARGET_LINK_LIBRARIES(main ${LIB})

ADD_LIBRARY(lfucache STATIC ${SRC_LIST})
TARGET_LINK_LIBRARIES(lfucache ${LIB})
