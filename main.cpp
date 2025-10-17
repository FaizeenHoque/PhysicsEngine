#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

const int FPS = 60;
const int frameDelay = 1000 / FPS;

const float dt = 1.0 / FPS;
const float gravity = 9.81f * 100; // pixels per second squared

struct Vec2 {
    float x;
    float y;

    Vec2 operator+(const Vec2& other) const { return {x + other.x, y + other.y}; }
    Vec2 operator-(const Vec2& other) const { return {x - other.x, y - other.y}; }
    Vec2 operator*(float scalar) const { return {x * scalar, y * scalar}; }
    Vec2& operator+=(const Vec2& other) { x += other.x; y += other.y; return *this; }
    float length() const { return std::sqrt(x*x + y*y); }
    Vec2 normalize() const { float len = length(); return len ? Vec2{x/len, y/len} : Vec2{0,0}; }
};

class Object
{
public:
    Vec2 position;
    Vec2 velocity;
    int radius;
    float mass;

    Object(Vec2 pos, Vec2 vel, int r, int m) {
        this->position = pos;
        this->velocity = vel;
        this->radius = r;
        this->mass = m; 
    }

    void accelerate(Vec2 acc) {
        this->velocity.x += acc.x * dt;
        this->velocity.y += acc.y * dt;
    }

    void updatePos() {
        this->position.x += velocity.x * dt;
        this->position.y += velocity.y * dt;
    }

    void drawCircle(SDL_Renderer* renderer, int centerX, int centerY, int radius) {
        for (int w = 0; w < radius * 2; w++) {
            for (int h = 0; h < radius * 2; h++) {
                int dx = radius - w;
                int dy = radius - h;
                if ((dx*dx + dy*dy) <= (radius * radius)) {
                    SDL_RenderDrawPoint(renderer, centerX + dx, centerY + dy);
                }
            }
        }
    }
};

std::vector<Object> objs = {
    Object({100, 100}, {0, 0}, 30, 7.34767309 * pow(10, 22)),
    Object({700, 100}, {0, 0}, 30, 7.34767309 * pow(10, 22))
};


int main() {
    SDL_Init(SDL_INIT_EVERYTHING);

    Vec2 screenSize;
    screenSize.x = 800;
    screenSize.y = 600;

    SDL_Window* window = SDL_CreateWindow(
        "Physics Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        screenSize.x,
        screenSize.y,
        SDL_WINDOW_SHOWN
    );
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    Vec2 pos = {50, 50};
    Vec2 vel = {0, 0};
    int radius = 20;

    SDL_Event event;
    bool running = true;

    while (running) {
        Uint32 frameStart = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        for (auto& obj : objs) {
            obj.accelerate({0, gravity});
            obj.updatePos();
            obj.drawCircle(renderer, obj.position.x, obj.position.y, obj.radius);

            // Y-axis
            if (obj.position.y - obj.radius < 0) {
                obj.position.y = obj.radius;
                obj.velocity.y *= -0.95f;
            } else if (obj.position.y + obj.radius > screenSize.y) {
                obj.position.y = screenSize.y - obj.radius;
                obj.velocity.y *= -0.95f;
            }

            // X-axis
            if (obj.position.x - obj.radius < 0) {
                obj.position.x = obj.radius;
                obj.velocity.x *= -0.95f;
            } else if (obj.position.x + obj.radius > screenSize.x) {
                obj.position.x = screenSize.x - obj.radius;
                obj.velocity.x *= -0.95f;
            }
        }

        SDL_RenderPresent(renderer);

        Uint32 frameTime = SDL_GetTicks() - frameStart;
        if (frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
