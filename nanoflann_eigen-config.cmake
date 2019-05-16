get_filename_component(SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
include(${SELF_DIR}/nanoflann_eigen-targets.cmake)
get_filename_component(nanoflann_eigen_INCLUDE_DIRS "${SELF_DIR}/../../include/nanoflann_eigen" ABSOLUTE)
