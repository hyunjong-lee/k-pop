set(
    HEADER_LIST
    "${kpop_SOURCE_DIR}/include/hnsw/hnsw.h"
)

add_library(
    kpoplib
    hnsw.cpp
    ${HEADER_LIST}
)

target_include_directories(
    kpoplib
    PUBLIC
    ../include
)

source_group(
    TREE "${PROJECT_SOURCE_DIR}/include"
    PREFIX "Header Files"
    FILES ${HEADER_LIST}
)