cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(GeoProcessing_Project)

find_package(GDAL)

include_directories(${GDAL_INCLUDE_DIRS})
link_directories(${GDAL_LIBRARY_DIRS})
add_definitions(${GDAL_DEFINITIONS})

aux_source_directory(. DIR_SRCS)

add_executable(GeoProcessing ${DIR_SRCS})
target_link_libraries (GeoProcessing ${GDAL_LIBRARIES})
