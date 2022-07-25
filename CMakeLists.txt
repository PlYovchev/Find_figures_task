cmake_minimum_required(VERSION 3.10)

project(FindFigures VERSION 1.0)

find_package(nlohmann_json 3.2.0 REQUIRED)

FILE(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
file(COPY "resources" DESTINATION ".")

add_executable(FindFigures ${SOURCES})