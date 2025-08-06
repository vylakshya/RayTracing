#include<SDL2/SDL.h>
#include<vector>
class Ray{
   
    protected:
    float x,y;
    
    float c = 35;
   
    public:
    
    void GenRay(SDL_Renderer *ren,int x0, int y0, int x1, int y1, double r, int x_o, int y_o){
        std::vector<std::pair<float, float>> base_hyperbola;
        std::vector<std::pair<float,float>> obj;
    for (float t = 0.3; t < 50; t += 0.01)
    
    base_hyperbola.push_back({c * t, c / t});

for (float angle = 0; angle <= 2*PI; angle += 0.05) {
    for (auto [x, y] : base_hyperbola) {
        float x_rot = x * cos(angle) - y * sin(angle);
        float y_rot = x * sin(angle) + y * cos(angle);
        
        double dis = (x0 + x_rot - x_o)*(x0 + x_rot - x_o) + (y0 + y_rot - y_o)*(y0 + y_rot - y_o);
        if(dis >= r*r) 
        SDL_RenderDrawPoint(ren, x0 + x_rot, y0 + y_rot);
    }
}

        }

};
