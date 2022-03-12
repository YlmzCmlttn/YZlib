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

set (OPENBLAS_INCLUDE_DIRS ../3rd_Party/OpenBLAS-0.3.13/Linux/include)
set (OPENBLAS_LIBS_DIR ../3rd_Party/OpenBLAS-0.3.13/Linux/lib)
set (OPENBLAS_LIBRARIES openblas)

set (FFMPEG_INCLUDE_DIRS ../3rd_Party/FFmpeg-4.2.3/Linux/include)
set (FFMPEG_LIBS_DIR ../3rd_Party/FFmpeg-4.2.3/Linux/lib)
set (FFMPEG_LIBRARIES avcodec avfilter avutil swresample avdevice avformat postproc swscale)

set (SDL_INCLUDE_DIRS ../3rd_Party/SDL2-2.0.12/Linux/include)
set (SDL_LIBS_DIR ../3rd_Party/SDL2-2.0.12/Linux/lib)
set (SDL_LIBRARIES SDL2 SDL2main)

set (GLFW_INCLUDE_DIR ../3rd_Party/Glfw-3.3.1/Linux/include)
set (GLFW_LIBS_DIR ../3rd_Party/Glfw-3.3.1/Linux/lib)
set (GLFW_LIBS glfw3 GL GLU X11 Xxf86vm Xrandr pthread Xi dl Xinerama Xcursor)

set (GLAD_INCLUDE_DIR ../3rd_Party/Glad-0.1.33/Linux/include)
set (GLAD_LIBS_DIR ../3rd_Party/Glad-0.1.33/Linux/lib)
set (GLAD_LIBS glad)

set (GLEW_INCLUDE_DIR ../3rd_Party/Glew-2.1.0/Linux/include)
set (GLEW_LIBS_DIR ../3rd_Party/Glew-2.1.0/Linux/lib)
set (GLEW_LIBS GLEW)

find_package(Eigen3 3.3.9 REQUIRED PATHS "../3rd_Party/Eigen-3.3.9" NO_MODULE)

include_directories(${FFMPEG_INCLUDE_DIRS} ${SDL_INCLUDE_DIRS} ${CUDA_INCLUDE_DIRS} ${OPENBLAS_INCLUDE_DIRS} ${GLFW_INCLUDE_DIR} ${GLAD_INCLUDE_DIR} ${GLEW_INCLUDE_DIR})
link_directories("/usr/local/cuda/lib64" "/usr/local/lib" ${FFMPEG_LIBS_DIR} ${SDL_LIBS_DIR} ${OPENBLAS_LIBS_DIR} ${GLFW_LIBS_DIR} ${GLAD_LIBS_DIR} ${GLEW_LIBS_DIR})

add_definitions(-DYZ_MATRIX_DEBUG)
add_definitions(-DYZ_IMAGE_DEBUG)
add_subdirectory(../YZlib YZlib_build)

macro(add_example name)
add_executable(${name} ${name}.cpp)
set_property(TARGET ${name} PROPERTY CUDA_SEPARABLE_COMPILATION ON)
target_link_libraries(${name} YZlib pthread Eigen3::Eigen ${FFMPEG_LIBRARIES} ${SDL_LIBRARIES}  ${CUDA_LIBS} ${OPENBLAS_LIBRARIES} ${GLFW_LIBS} ${GLAD_LIBS} ${GLEW_LIBS})
endmacro()

add_example(Test)
add_example(Image)
add_example(Renderer)
add_example(Video)
add_example(Modern_C++)
add_example(C1W2)