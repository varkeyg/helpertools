add_executable(helpertools_test helpertools_test.cpp)

target_link_libraries(helpertools_test PUBLIC helpertools spdlog::spdlog spdlog::spdlog_header_only)

