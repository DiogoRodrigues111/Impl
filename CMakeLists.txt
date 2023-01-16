cmake_minimum_required(VERSION 3.5)

project(impl LANGUAGES C)

add_executable(impl
    main.c
    impl.h
)

install(TARGETS impl
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
