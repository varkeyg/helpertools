add_library(helpertools STATIC helpertools.h helpertools.cpp)
target_include_directories(helpertools PUBLIC ${CURL_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(helpertools PUBLIC ${CURL_LIBRARIES} GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main spdlog::spdlog spdlog::spdlog_header_only)
