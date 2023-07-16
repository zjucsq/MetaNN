add_library(model "")
file(GLOB_RECURSE sources "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
target_sources(model PRIVATE ${sources})