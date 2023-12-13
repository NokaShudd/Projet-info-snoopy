cmake_minimum_required(VERSION 3.5.0)
project(game C)

set(CMAKE_C_STANDARD 99)

add_executable(
    game main.c
    utils/color.h utils/color.c utils/size.h utils/size.c 
    utils/keysHandler.h utils/keysHandler.c utils/sleep.h utils/sleep.c
    Snoopy/snoopyMovement.c Snoopy/snoopyMovement.h
    elements/elements.c elements/elements.h
        stockage/save.h
        stockage/save.c
        score/score.h
        score/score.c
)
