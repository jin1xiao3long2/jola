cmake_minimum_required(VERSION 3.0)

project(pName)



add_subdirectory(tcode)
add_executable(code test.cpp)
add_executable(test calc-lang.cpp)
add_executable(test1 calc-lang-plus.cpp)
add_executable(lang-debug calc-lang-debug.cpp)
add_executable(5_31_algo_C 5_31algo_C.cpp)
add_executable(5_31_algo_E 5_31algo_E.cpp)
add_executable(Huffman HuffmanTree.cpp HuffmanTree.hpp)
add_executable(OS OS/BitMap.hpp OS/Directory.hpp OS/FileSystem.hpp OS/OCtest.cpp)
add_executable(OS1 OS/BitMap.h OS/BitMap.cpp OS/Directory.h OS/Directory.cpp OS/FileSystem.h OS/FileSystem.cpp OS/main.cpp)
add_executable(AD_1 AD/t1.cpp)
add_executable(AD_2 AD/t2.cpp)
add_executable(AD_3 AD/t3.cpp)
add_executable(AD_4 AD/t4.cpp)
add_executable(AD_5 AD/t5.cpp)
add_executable(AD_6 AD/t6.cpp)
add_executable(AD_7 AD/t7.cpp)
add_executable(AD_8 AD/t8.cpp)
add_executable(AD_9 AD/t9.cpp)
add_executable(AD_10 AD/t10.cpp)
add_executable(play play.cpp)
add_executable(playground playground.cpp)
add_executable(relearn relearn.cpp)
add_executable(mb mb.cpp)
add_executable(lexer clexer.cpp)
add_executable(random random.cpp)
add_executable(delnbsp delnbsp.cpp)

add_subdirectory(Compiler)

#add_subdirectory(mozart)
#include_directories(mozart/mpp_core)
#include_directories(mozart/mpp_foundation)
#include_directories(mozart/mpp_system)
#include_directories(mozart/mpp_string)
#target_link_libraries(play mpp_core mpp_foundation mpp_system mpp_string)

add_library(lib lib.cpp)
target_link_libraries(code lib)
