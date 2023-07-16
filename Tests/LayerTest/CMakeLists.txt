add_executable(LayerTest main.cpp)

add_subdirectory(composite)
add_subdirectory(principal)
add_subdirectory(recurrent)

target_link_libraries(LayerTest PRIVATE composite principal recurrent)

target_include_directories(LayerTest PRIVATE ${CMAKE_CURRENT_LIST_DIR})