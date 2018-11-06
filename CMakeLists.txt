cmake_minimum_required(VERSION 3.12)
project(GoFish)

set(CMAKE_CXX_STANDARD 14)

add_executable(GoFish main.cpp card.h deck.h player.h card.cpp deck.cpp)