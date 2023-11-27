cmake_minimum_required(VERSION 3.0.0)
project(Prueba VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Prueba 1_estructuras.h 2_menuPrincipal.cpp 3_login.cpp 4_pacientes.cpp 5_citasProgramadas.cpp 6_UT.cpp 7_UP.cpp 8_SE.cpp 9_UM.cpp 10_diagPresc.cpp)

find_package(unofficial-libharu CONFIG REQUIRED)
target_link_libraries(Prueba PRIVATE unofficial::libharu::hpdf)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
