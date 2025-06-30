

cmake_minimum_required(VERSION 3.0)
project(01)


#搜索头文件
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#搜索源文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC)

#设置可执行文件的输出路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

#创建可执行文件
add_executable(01 ${SRC})








