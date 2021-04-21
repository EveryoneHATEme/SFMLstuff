cmake_minimum_required(VERSION 3.19)
project(SFMLCrap)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SFMLCrap
        Block.cpp
        Block.hpp
        Game.cpp
        Game.hpp
        main.cpp
        Map.cpp
        Map.hpp
        Utils.cpp
        Utils.hpp)

target_link_libraries(SFMLCrap -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network)