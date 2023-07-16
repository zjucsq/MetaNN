add_library(recurrent "")
file(GLOB_RECURSE sources "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
target_sources(recurrent PRIVATE ${sources})