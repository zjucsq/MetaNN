add_executable(DataOpTest main.cpp)

add_subdirectory(data)
add_subdirectory(operation)

target_link_libraries(DataOpTest PRIVATE data operation)

target_include_directories(DataOpTest PRIVATE ${CMAKE_CURRENT_LIST_DIR})