cmake_minimum_required(VERSION 3.9)
project(GoFish)

set(CMAKE_CXX_STANDARD 14)

add_executable(GoFish go_fish.cpp card.h deck.h player.h card.cpp deck.cpp player.cpp)