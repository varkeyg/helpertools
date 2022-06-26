cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_TOOLCHAIN_FILE $ENV{HOME}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
#On apple silicon, vcpkg version of curl doesn't work as of now. So giving path.
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/curl" ${CMAKE_PREFIX_PATH})
set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/boost/1.78.0_1" ${CMAKE_PREFIX_PATH})
project(helpertools CXX)



find_package(tinyxml2 CONFIG REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(CURL REQUIRED)
find_package(glog CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS date_time program_options REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

add_subdirectory(src)
add_subdirectory(test)

add_executable(testenv src/testenv.cpp)


include(GNUInstallDirs)
# install(TARGETS helpertools
#     EXPORT helpertools
#     INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#     ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
# )


install(TARGETS helpertools DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES src/helpertools.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})