cmake_minimum_required(VERSION 3.5.0)
project(Projet_Info_Snoopy VERSION 0.1.0 LANGUAGES C)

if (UNIX)
    find_package(Curses REQUIRED)
    include_directories(${CURSES_INCLUDE_DIR})
    add_executable(
            game main.c
            utils/color.h utils/color.c utils/size.h utils/size.c utils/keysHandler.h utils/keysHandler.c Snoopy/snoopyMovement.c Snoopy/snoopyMovement.h
    )
    target_link_libraries(game ${CURSES_LIBRARIES})
endif()

if (WIN32)
    add_executable(
            game main.c
            utils/color.h utils/color.c utils/size.h utils/size.c utils/keysHandler.h utils/keysHandler.c Snoopy/snoopyMovement.c Snoopy/snoopyMovement.h
    )

endif ()