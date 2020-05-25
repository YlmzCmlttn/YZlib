#include "Core/Debug.hpp"
#ifdef YZ_IMAGE_DEBUG
#define IMAGE_INFO_D(...) INFO_D("Image_Debug: ", __VA_ARGS__)
#define IMAGE_SUCCESS_D(...) SUCCESS_D("Image_Debug: ", __VA_ARGS__)
#define IMAGE_WARNING_D(...) WARNING_D("Image_Debug: ", __VA_ARGS__)
#define IMAGE_ERROR_D(...) ERROR_D("Image_Debug: ", __VA_ARGS__)
#else
#define IMAGE_INFO_D(...) {}
#define IMAGE_SUCCESS_D(...) {}
#define IMAGE_WARNING_D(...) {}
#define IMAGE_ERROR_D(...) {}
#endif