include(FindPackageHandleStandardArgs)

set(GLOG_ROOT_DIR "/pkg/glog/0.3.3")

find_path(GLOG_INCLUDE_DIR glog/logging.h PATHS ${GLOG_ROOT_DIR})

find_library(GLOG_LIBRARY glog PATHS ${GLOG_ROOT_DIR} PATH_SUFFIXES lib lib64)

set(GLOG_INCLUDE_DIR "/pkg/glog/0.3.3/include")

find_package_handle_standard_args(Glog DEFAULT_MSG GLOG_INCLUDE_DIR GLOG_LIBRARY)

if(GLOG_FOUND)
  set(GLOG_INCLUDE_DIRS ${GLOG_INCLUDE_DIR})
  set(GLOG_LIBRARIES ${GLOG_LIBRARY})
  message(STATUS "Found glog (include: ${GLOG_INCLUDE_DIR}, library: ${GLOG_LIBRARY})")
  mark_as_advanced(GLOG_ROOT_DIR GLOG_LIBRARY_RELEASE GLOG_LIBRARY_DEBUG
                                 GLOG_LIBRARY GLOG_INCLUDE_DIR)
endif()