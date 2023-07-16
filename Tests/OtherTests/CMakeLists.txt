add_executable(OtherTest main.cpp)

add_subdirectory(facilities)
add_subdirectory(model)
add_subdirectory(policies)

target_link_libraries(OtherTest PRIVATE facilities model policies)

target_include_directories(OtherTest PRIVATE ${CMAKE_CURRENT_LIST_DIR})