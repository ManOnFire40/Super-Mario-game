cmake_minimum_required(VERSION 3.23)
project(Game)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Game
        include/Champion.h
        include/game.h
        include/Map.h
        include/Point.h
        src/Champion.cpp
        src/game.cpp
        src/Map.cpp
        src/Point.cpp
        main.cpp src/Cell.cpp include/Cell.h include/obstacle.h include/Mario.h include/Luigi.h)
