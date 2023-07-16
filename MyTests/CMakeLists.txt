add_executable(MyTest main.cpp)

link_directories(${CMAKE_SOURCE_DIR}/Tests/DataOpTest/data)
link_directories(${CMAKE_SOURCE_DIR}/Tests/DataOpTest/operation)

target_link_libraries(MyTest PRIVATE data operation)

target_include_directories(MyTest PRIVATE ${CMAKE_SOURCE_DIR}/Tests/DataOpTest)