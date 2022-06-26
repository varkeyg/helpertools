The package glog provides CMake targets:

    find_package(glog CONFIG REQUIRED)
    target_link_libraries(main PRIVATE glog::glog)

The package gtest provides CMake targets:

    find_package(GTest CONFIG REQUIRED)
    target_link_libraries(main PRIVATE GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

The package tinyxml2 provides CMake targets:

    find_package(tinyxml2 CONFIG REQUIRED)
    target_link_libraries(main PRIVATE tinyxml2::tinyxml2)