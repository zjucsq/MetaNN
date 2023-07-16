add_library(composite "")
file(GLOB_RECURSE sources "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
target_sources(composite PRIVATE ${sources})