cmake_minimum_required(VERSION 3.5)

project(my-sdl2-game LANGUAGES C)

find_package (SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(my-sdl2-game main.c)
target_link_libraries(my-sdl2-game ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
include(GNUInstallDirs)
install(TARGETS my-sdl2-game
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
