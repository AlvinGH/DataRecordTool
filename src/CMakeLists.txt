include_directories( ${PROJECT_SOURCE_DIR}/hdr)
message("Source dir is ${PROJECT_SOURCE_DIR}")
add_executable(hello 
               main.cc
               dataRecord.cc)
