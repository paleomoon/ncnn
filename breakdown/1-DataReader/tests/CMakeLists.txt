include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../src)
add_executable(DataReaderTest DataReaderTest.cpp)
target_link_libraries(DataReaderTest PRIVATE DataReader)