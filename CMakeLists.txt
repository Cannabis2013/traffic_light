cmake_minimum_required(VERSION 3.16)

project(TrafficLight LANGUAGES C)

add_executable(TrafficLight main.c
    wait.h
    wait_imp_1.c
    traffic_controller.h
    ard_m328p_defines.h
    traffic_controller_imp1.c
    traffic_controller_imp2.c
    roll_controller.h
    roll_controller_imp1.c
    wait_imp_2.c
    test.h
    test.c
    iom328p.h
)



include(GNUInstallDirs)
install(TARGETS TrafficLight
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
