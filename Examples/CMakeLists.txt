cmake_minimum_required(VERSION 3.8 FATAL_ERROR)
project(YZlib_Test LANGUAGES CXX CUDA)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#######CUDA########
find_package(CUDA REQUIRED)
if(NOT CUDA_FOUND)
    message(ERROR "CUDA is not found")
    set(CUDA_SUPPORT false)
    return()
else()
    add_definitions(-DCUDA_ENABLED)
    set(CUDA_SUPPORT true)
endif()
###################

set (LAPACK_INCLUDE_DIRS ../3rd_Party/Lapack-3.9.0/Linux/include)
set (LAPACK_LIBS_DIR ../3rd_Party/Lapack-3.9.0/Linux/lib)
set (LAPACK_LIBRARIES cblas blas lapack gfortran)

set (GLFW_INCLUDE_DIR ../3rd_Party/Glfw-3.3.1/Linux/include)
set (GLFW_LIBS_DIR ../3rd_Party/Glfw-3.3.1/Linux/lib)
set (GLFW_LIBS glfw3 GL GLU X11 Xxf86vm Xrandr pthread Xi dl Xinerama Xcursor)

set (GLAD_INCLUDE_DIR ../3rd_Party/Glad-0.1.33/Linux/include)
set (GLAD_LIBS_DIR ../3rd_Party/Glad-0.1.33/Linux/lib)
set (GLAD_LIBS glad)

set (GLEW_INCLUDE_DIR ../3rd_Party/Glew-2.1.0/Linux/include)
set (GLEW_LIBS_DIR ../3rd_Party/Glew-2.1.0/Linux/lib)
set (GLEW_LIBS GLEW)

include_directories(${CUDA_INCLUDE_DIRS} ${LAPACK_INCLUDE_DIRS} ${GLFW_INCLUDE_DIR} ${GLAD_INCLUDE_DIR} ${GLEW_INCLUDE_DIR})
link_directories("/usr/local/cuda/lib64" "/usr/local/lib" ${LAPACK_LIBS_DIR} ${GLFW_LIBS_DIR} ${GLAD_LIBS_DIR} ${GLEW_LIBS_DIR})

add_definitions(-DYZ_MATRIX_DEBUG)
add_definitions(-DYZ_IMAGE_DEBUG)
add_subdirectory(../YZlib YZlib_build)

macro(add_example name)
add_executable(${name} ${name}.cpp)
set_property(TARGET ${name} PROPERTY CUDA_SEPARABLE_COMPILATION ON)
target_link_libraries(${name} YZlib pthread ${CUDA_LIBS} ${LAPACK_LIBRARIES} ${GLFW_LIBS} ${GLAD_LIBS} ${GLEW_LIBS})
endmacro()

add_example(Test)
add_example(Image)
add_example(Renderer)