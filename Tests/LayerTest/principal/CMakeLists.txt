add_library(principal "")
file(GLOB_RECURSE sources "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
target_sources(principal PRIVATE ${sources})