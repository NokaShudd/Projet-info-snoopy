cmake_minimum_required(VERSION 3.5.0)
project(Projet_Info_Snoopy VERSION 0.1.0 LANGUAGES C)


add_executable(
    game main.c 
    utils/color.h utils/color.c utils/size.h utils/size.c utils/keysHandler.h utils/keysHandler.c 
)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(game PRIVATE Threads::Threads)