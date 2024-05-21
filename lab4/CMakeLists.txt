cmake_minimum_required(VERSION 3.27)
project(lab4)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab4 App.cpp
        "Source Files/Map.cpp"
        "Source Files/MapIterator.cpp"
        "Source Files/ShortTest.cpp"
        "Source Files/ExtendedTest.cpp"
)
