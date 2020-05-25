#include "Core/Debug.hpp"
#ifdef YZ_Point2D_DEBUG
#define POINT_INFO_D(...) INFO_D("Point_Debug: ", __VA_ARGS__)
#define POINT_SUCCESS_D(...) SUCCESS_D("Point_Debug: ", __VA_ARGS__)
#define POINT_WARNING_D(...) WARNING_D("Point_Debug: ", __VA_ARGS__)
#define POINT_ERROR_D(...) ERROR_D("Point_Debug: ", __VA_ARGS__)
#else
#define POINT_INFO_D(...) {}
#define POINT_SUCCESS_D(...) {}
#define POINT_WARNING_D(...) {}
#define POINT_ERROR_D(...) {}
#endif