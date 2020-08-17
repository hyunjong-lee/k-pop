file(GLOB SRCS *.cpp)

if(WIN32)
    set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:msvcrtd")
endif()

ADD_EXECUTABLE(test_hnsw ${SRCS})

TARGET_LINK_LIBRARIES(test_hnsw
    libgtest
    libgmock
)

add_test(NAME test_hnsw
         COMMAND test_hnsw)