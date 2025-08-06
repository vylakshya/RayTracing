#include <SDL2/SDL.h>
#define PI 3.1415
class planet{
    protected:
    float mass;
    float radius;
    public:
    planet(float m, float r){
        mass = m;
        radius = r;
    }
    void Body(SDL_Renderer *ren, double x, double y){
        for (int i = x - radius; i < x + radius; i++)
        {
            for (int j = y - radius; j < y + radius; j++)
            {
                float dis = sqrt(((i-x)*(i-x)) + ((j-y)*(j-y)));
                if (dis <= radius)
                {
                    SDL_RenderDrawPoint(ren,i,j);
                }
            }
        }
        // for (double i = 0; i < 2 * PI; i += 0.05)
        // {
        //     double x0 = x + (radius * cos(i));
        //     double y0 = y + (radius * sin(i));

        //     SDL_RenderDrawPoint(ren,x0,y0);
        // }
        
    }
    void Revolution(SDL_Renderer *ren, double r1, double e, int p, int q){

        double a = r1/(1+e);
        double b = a * sqrt(1-(e*e));
        double x0 = p + (a*e);
        double y0 = q ;
        for (double th = 0; th < 2 * PI; th = th + 0.001)
        {
            double x = a * cos(th);
            double y = b * sin(th);
            Body(ren,x,y);
            SDL_Delay(4);
        }
    }   
};
