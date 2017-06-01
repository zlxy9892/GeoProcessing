cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(GeoProcessing_Project)

find_package(GDAL)

include_directories(${GDAL_INCLUDE_DIRS})
link_directories(${GDAL_LIBRARY_DIRS})
add_definitions(${GDAL_DEFINITIONS})

aux_source_directory(. DIR_SRCS)

file(GLOB_RECURSE CURRENT_HEADERS  *.h *.hpp)
source_group("Header Files" FILES ${CURRENT_HEADERS})

add_executable(GeoProcessing ${DIR_SRCS} ${CURRENT_HEADERS})
target_link_libraries (GeoProcessing ${GDAL_LIBRARIES})
