#include "GUI/Window.h"
namespace YZlib{
    Window::Window(/* args */):Type(WINDOWED),have_texture(false){

    }
    Window::Window(const WINDOW_TYPE& _t):Type(_t),have_texture(false)
    {
        if(Type == FULLSCREEN){
            SDL_ShowCursor(SDL_DISABLE);
        }
    }
    void Window::render(){
        SDL_RenderPresent(Render_Settings.renderer);
    }    
    void Window::setWindowBoundswithScreen(uint ScreenID){
        if(ScreenID >= getNumberofScreen()){
            std::cerr<<"Screen ID must be less than maximum Screen size"<<std::endl;
        }else{
            SDL_Rect bounds;
            SDL_GetDisplayBounds((int)ScreenID, &bounds);
            Window_Settings.Rect=Rectangle<int>(bounds.x,bounds.y,bounds.w,bounds.h);
        }
    }
    void Window::setWindowBounds(Rectangle<int> _Rect){
        Window_Settings.Rect=_Rect;
    }
    uint Window::getNumberofScreen(){
        return SDL_GetNumVideoDisplays();
    }
    void Window::showWindow(){
        SDL_ShowWindow((SDL_Window*)Window_Settings.window);
    }
    void Window::createRenderer(){
        Render_Settings.renderer = SDL_CreateRenderer(this->Window_Settings.window, -1, SDL_RENDERER_SOFTWARE);
    }
    std::variant<char,bool> Event_Handler(Window_Event &event){
        std::variant<char,bool> ret;
        ret = true;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT){
                ret = false;
            }
            if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE){
                ret = false;
            }
            if(event.type == SDL_KEYDOWN){
                auto key = event.key.keysym.sym;
                if(key==SDLK_q)return 'q';
                if(key==SDLK_w)return 'w';
                if(key==SDLK_e)return 'e';
                if(key==SDLK_r)return 'r';
                if(key==SDLK_t)return 't';
                if(key==SDLK_y)return 'y';

                if(key==SDLK_a)return 'a';
                if(key==SDLK_s)return 's';
                if(key==SDLK_d)return 'd';
                if(key==SDLK_f)return 'f';
                if(key==SDLK_g)return 'g';
                if(key==SDLK_h)return 'h';

                if(key==SDLK_z)return 'z';
                if(key==SDLK_x)return 'x';
                if(key==SDLK_c)return 'c';
                if(key==SDLK_v)return 'v';
                if(key==SDLK_b)return 'b';
                if(key==SDLK_n)return 'n';
            }
            SDL_Delay(1);
        }            
        return ret;
    }
    void Window::createWindow(std::string name){
        Window_Settings.name = name;
        if(Type == FULLSCREEN){
            Window_Settings.flags = SDL_WINDOW_FULLSCREEN;
        }else{
            Window_Settings.flags = SDL_WINDOW_OPENGL;
        }
        this->Window_Settings.window = SDL_CreateWindow(Window_Settings.name.c_str(), Window_Settings.Rect.x, Window_Settings.Rect.y, Window_Settings.Rect.width, Window_Settings.Rect.height, Window_Settings.flags);
    }
    void Window::RGB2Texture(void* img,int width,int height, int depth,int pitch){        
        SDL_Surface *frameSurface = SDL_CreateRGBSurfaceFrom(img, width, height, depth, (int)pitch, 0xff0000, 0x00ff00, 0x0000ff, 0);            
        if(frameSurface == NULL){
            SDL_Log("Couldn't convert Surface.");        
            SDL_FreeSurface(frameSurface);
        }
        SDL_Texture *texture = SDL_CreateTextureFromSurface(this->Render_Settings.renderer, frameSurface);
        this->Render_Settings.Rect = {0,0,width,height};
        if (texture == NULL){
            SDL_Log("Couldn't convert to Texture (converted to surface).");
            SDL_FreeSurface(frameSurface);
            have_texture = false;		
        }else
        {
            SDL_FreeSurface(frameSurface);
            SDL_RenderClear(Render_Settings.renderer);
            SDL_RenderCopy(Render_Settings.renderer, texture, NULL, &Render_Settings.Rect);
            SDL_DestroyTexture(texture);
            have_texture = true;
        }
    }
    Window::~Window()
    {    
        SDL_DestroyRenderer(Render_Settings.renderer);
        SDL_DestroyWindow(Window_Settings.window);
        SDL_Quit();
    }
}