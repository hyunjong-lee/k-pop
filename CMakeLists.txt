cmake_minimum_required(VERSION 3.14...3.16 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)

# ---- Declare project ----

project(
    kpop
    VERSION
        0.1
    DESCRIPTION
        "Find k nearest neighbors instantly and approximately"
    LANGUAGES
        CXX
)

# ---- Add dependencies ----

include(FetchContent)

FetchContent_Declare(
  fmtlib
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG 7.0.3
)
FetchContent_MakeAvailable(fmtlib)

# ---- Add source files ----

enable_testing()

add_subdirectory(src)
add_subdirectory(apps)
add_subdirectory(tests)
