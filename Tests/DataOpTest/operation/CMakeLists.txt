add_library(operation "")
file(GLOB_RECURSE sources "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
target_sources(operation PRIVATE ${sources})