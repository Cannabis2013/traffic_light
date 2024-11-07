cmake_minimum_required(VERSION 3.16)

project(TrafficLight LANGUAGES C)

add_executable(TrafficLight main.c
    wait.h
    wait.c
    controller.h
    ard_m328p_ports.h
    controller_imp1.c
    controller_imp2.c
)



include(GNUInstallDirs)
install(TARGETS TrafficLight
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
