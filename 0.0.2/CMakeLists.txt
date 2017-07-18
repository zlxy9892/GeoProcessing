cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

project(GeoProcessing_Project)

set(BOOST_INCLUDE_DIRS C:/dev/boost/include)
set(BOOST_LIBRARY_DIRS C:/dev/boost/lib)

set(GDAL_INCLUDE_DIRS C:/dev/gdal/include)
set(GDAL_LIBRARY_DIRS C:/dev/gdal/lib)
set(GDAL_LIBRARIES gdal_i.lib)

set(EIGEN_INCLUDE_DIRS C:/dev/eigen/include)

set(GLOG_INCLUDE_DIRS C:/dev/glog/include)
set(GLOG_LIBRARY_DIRS C:/dev/glog/lib)
set(GLOG_LIBRARIES libglog.lib)

set(CERES_INCLUDE_DIRS C:/dev/ceres-solver/include)
set(CERES_LIBRARY_DIRS C:/dev/ceres-solver/lib)
set(CERES_LIBRARIES ceres.lib)

include_directories(${GDAL_INCLUDE_DIRS} ${BOOST_INCLUDE_DIRS} ${EIGEN_INCLUDE_DIRS} ${GLOG_INCLUDE_DIRS} ${CERES_INCLUDE_DIRS})
link_directories(${GDAL_LIBRARY_DIRS} ${BOOST_LIBRARY_DIRS} ${GLOG_LIBRARY_DIRS} ${CERES_LIBRARY_DIRS})

aux_source_directory(. DIR_SRCS)

file(GLOB_RECURSE CURRENT_HEADERS  *.h *.hpp)
source_group("Header Files" FILES ${CURRENT_HEADERS})

add_executable(GeoProcessing ${DIR_SRCS} ${CURRENT_HEADERS})
target_link_libraries (GeoProcessing ${GDAL_LIBRARIES} ${GLOG_LIBRARIES} ${CERES_LIBRARIES})
