cmake_minimum_required(VERSION 3.0)

project(Tiny)

add_library(tinyLexer Tiny_Lexer.cpp Tiny_Lexer.hpp Tiny_Signal.cpp Tiny_Signal.hpp)

add_executable(testLexer tinylexertest.cpp)

target_link_libraries(testLexer tinyLexer)
include_directories(./)