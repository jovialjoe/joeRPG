CMAKE_MINIMUM_REQUIRED(VERSION 3.15)

SET(CMAKE_CXX_FLAGS "-O0")
SET(CMAKE_C_FLAGS "-O0")

set(SOURCE_FILES
    ../src/equipment/armor.cpp
    ../src/equipment/weapon.cpp

    ../src/enemy.cpp
    ../src/fightEncounter.cpp
    ../src/fightSystem.cpp
    ../src/game.cpp
    ../src/helperFunctions.cpp
    ../src/player.cpp
    ../src/prompter.cpp)

add_executable(valgrind ../main.cpp ${SOURCE_FILES})

target_include_directories(valgrind PUBLIC ../header)