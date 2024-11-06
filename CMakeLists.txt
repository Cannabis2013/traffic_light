cmake_minimum_required(VERSION 3.16)

project(TrafficLight LANGUAGES C)

add_executable(TrafficLight main.c
    wait.h
    wait.c)

include(GNUInstallDirs)
install(TARGETS TrafficLight
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
