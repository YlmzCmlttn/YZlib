#ifndef YZLIB_GUI_WINDOW_H
#define YZLIB_GUI_WINDOW_H
#include <string>
#include <variant>
#include <SDL2/SDL.h>
#include "Geometry/Rectangle.h"
#include "GUI/Window_Settings.h"

namespace YZlib{
    class Window
    {
    private:
        struct _Window_Settings{
            std::string name;
            Rectangle<int> Rect;
            SDL_WindowFlags flags;
            SDL_Window *window;
        }Window_Settings;
        struct _Render_Settings{
            SDL_Renderer *renderer;
            SDL_Rect Rect;
            SDL_WindowFlags flags;
        }Render_Settings;
        WINDOW_TYPE Type;
        bool have_texture;
    public:
        Window(/* args */);
        Window(const WINDOW_TYPE&);
        ~Window();
        static uint getNumberofScreen();
        void setWindowBoundswithScreen(uint ScreenID);
        void setWindowBounds(Rectangle<int> _Rect);
        void createWindow(std::string name);
        void createRenderer();
        void showWindow();
        void RGB2Texture(void* img,int width,int height, int depth,int pitch);
        void render();
    };
    typedef SDL_Event Window_Event;
    std::variant<char,bool> Event_Handler(Window_Event &event);    
}
#endif