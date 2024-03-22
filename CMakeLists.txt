cmake_minimum_required(VERSION 3.27)
project(tema_7)

set(CMAKE_CXX_STANDARD 17)

add_executable(tema_7 main.cpp
        node.h
        node.cpp
        DoubleLinkedList.cpp
        DoubleLinkedList.h
        DoubleLinkedListTest.h
        NodeTest.h
        NodeTest.cpp
        DoubleLinkedListTest.cpp)
