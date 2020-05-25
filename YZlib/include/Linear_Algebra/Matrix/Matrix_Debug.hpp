#include "Core/Debug.hpp"
#ifdef YZ_MATRIX_DEBUG
#define MATRIX_INFO_D(...) INFO_D("Matrix_Debug: ", __VA_ARGS__)
#define MATRIX_SUCCESS_D(...) SUCCESS_D("Matrix_Debug: ", __VA_ARGS__)
#define MATRIX_WARNING_D(...) WARNING_D("Matrix_Debug: ", __VA_ARGS__)
#define MATRIX_ERROR_D(...) ERROR_D("Matrix_Debug: ", __VA_ARGS__)
#else
#define MATRIX_INFO_D(...) {}
#define MATRIX_SUCCESS_D(...) {}
#define MATRIX_WARNING_D(...) {}
#define MATRIX_ERROR_D(...) {}
#endif