#define SDL_MAIN_HANDLED
#include<iostream>
#include<SDL2/SDL.h>
#include "planet.h"
// #include "orbit.h"
#include "ray.h"
#define Win_width 900
#define Win_height 800
using namespace std;
#define PI 3.1415
int main(){

    int ini = SDL_Init(SDL_INIT_EVERYTHING);

    if (ini < 0)
    {
        cout << "Error in Initializing :" << SDL_GetError() << endl;
    }
    
    SDL_Window *win = SDL_CreateWindow("Ray Tracing", 
                                        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                        Win_width,Win_height,
                                         SDL_WINDOW_RESIZABLE);
    
    if (!win)
    {
        cout << "Error in creating Window :" << SDL_GetError() << endl;
    }
    SDL_Renderer *ren = SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);
    bool running = true;
    SDL_Event e;
    float m1 = 100;
    float r1 = 70;
    float d = 350;
    float m2 = 40;
    float r2 = 20;
    planet P(m1, r1), E(m2,r2);
    Ray r;
    int x = 599;
    int y = 599;
    double ecc = 0.2;
    double th = 0; 
    double a = d/(1 + ecc);
        double b = a * sqrt(1-(ecc*ecc));
        double x0 = 400 + (a*ecc);
        double y0 = 400;
    while (running)
    {
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT)
        {
            running = false;
            break;
        }
        double x = a * cos(th) + x0;
        double y = b * sin(th) + y0;
            if (th <= 2 * PI )
            {
                SDL_SetRenderDrawColor(ren,0,0,0,255);
                SDL_RenderClear(ren);
                SDL_SetRenderDrawColor(ren,255,255,0,255);
                // P.Body(ren,p,q);
                P.Body(ren,400 - (a*ecc),400);
                SDL_SetRenderDrawColor(ren,255,0,0,255);
                E.Body(ren,x,y);
                SDL_SetRenderDrawColor(ren,255,255,0,150);
                r.GenRay(ren,400 - (a*ecc),400,x,y,r2,x,y,400 - (a*ecc),400);
            }
                th = th + 0.01;
            if (th >= 2 * PI)
            {
                th = 0;
            }
            SDL_Delay(4);
      SDL_RenderPresent(ren);
    }
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();


    return 0;
}

