add_executable(hnsw hnsw.cpp)

target_link_libraries(
    hnsw
    PRIVATE
    kpoplib
    fmt::fmt
)