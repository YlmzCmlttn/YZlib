cmake_minimum_required(VERSION 3.5)
if(CUDA_SUPPORT)
    project(YZlib LANGUAGES CXX CUDA)
    set(CUDA_SRC
        src/Cuda/Test_Kernel.cu
        src/Cuda/Matrix/Kernel/cuMatrix_Kernel.cu
        src/Cuda/Matrix/cuMatrix_Functions.cu
    )
else()
    project(YZlib LANGUAGES CXX)
endif()
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_library(
    YZlib
    src/YZlib.cpp
#CORE
    src/Core/Timer.cpp
    src/Core/Print.cpp
    src/Core/Size.cpp
    src/Core/Assert.cpp
#LINEAR_ALGEBRA
    src/Linear_Algebra/Matrix/Matrix_.cpp
    src/Linear_Algebra/Matrix/Matrix_Blas.cpp
#THREAD
    src/Thread/Thread_Function.cpp
#IMAGE
    src/Image/Image.cpp
    src/Image/Image_Functions.cpp
    src/Image/Image_Methods.cpp
    src/Image/Image_Operators.cpp  
    src/Image/Png_Operations.cpp
    src/Image/Jpeg_Operations.cpp
    src/Image/Bmp_Operations.cpp
#GUI
    src/GUI/Window.cpp
#VIDEO
    src/Video/VideoReader.cpp
)
target_link_libraries(YZlib png jpeg ${FFMPEG_LIBRARIES} ${LAPACK_LIBRARIES} ${GLFW_LIBS} ${GLAD_LIBS} ${CUDA_LIBS})
target_include_directories(YZlib PUBLIC ${FFMPEG_INCLUDE_DIRS} ${CUDA_INCLUDE_DIRS} "${CMAKE_CURRENT_SOURCE_DIR}/include" "/usr/local/include")
if(CUDA_SUPPORT)
    set_target_properties(YZlib PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
endif()
