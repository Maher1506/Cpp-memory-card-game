cmake_minimum_required(VERSION 3.27)
project(MemoryCardGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(MemoryCardGame main.cpp
        PenaltyCard.h
        Card.h
        BonusCard.h
        Deck.h
        Game.h
        Player.h
        StandardCard.h
        StandardCard.cpp
        Player.cpp
        PenaltyCard.cpp
        Game.cpp
        Deck.cpp
        Card.cpp
        BonusCard.cpp)
