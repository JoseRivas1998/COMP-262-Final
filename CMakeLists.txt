cmake_minimum_required(VERSION 3.14)
project(OpenMPTest C)

set(CMAKE_C_STANDARD 99)

include(FindOpenMP)
if(OPENMP_FOUND)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
else (OPENMP_FOUND)
    message("ERROR: OpenMP could not be found.")
endif (OPENMP_FOUND)

SET(SOURCE_FILES
        src/main.c)

SET(TEST_FILES
        src/hello.c)

add_executable(COMP_262_Final ${SOURCE_FILES})
add_executable(COMP_262_Final_TEST ${TEST_FILES})
