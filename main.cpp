#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

struct Vect2 {
    float v1;
    float v2;
};

class Object
{
public:
    Vect2 position;
    Vect2 velocity;
    int radius;

    Object(Vect2 pos, Vect2 vel, int r) {
        this->position = pos;
        this->velocity = vel;
        this->radius = r;
    }

    void accelerate(Vect2 acc) {
        this->velocity.v1 += acc.v1;
        this->velocity.v2 += acc.v2;
    }

    void updatePos() {
        this->position.v1 += velocity.v1;
        this->position.v2 += velocity.v2;
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
    Object({100, 100}, {0, 0}, 30),
    Object({200, 50}, {0, 0}, 30)
};


int main() {
    SDL_Init(SDL_INIT_EVERYTHING);

    Vect2 screenSize;
    screenSize.v1 = 800;
    screenSize.v2 = 600;

    SDL_Window* window = SDL_CreateWindow(
        "Physics Engine",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        screenSize.v1,
        screenSize.v2,
        SDL_WINDOW_SHOWN
    );
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    Vect2 pos = {50, 50};
    Vect2 vel = {0, 0};
    int radius = 20;

    SDL_Event event;
    bool running = true;

    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

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
            obj.accelerate({0, 0.7}); // Gravity
            obj.updatePos();
            obj.drawCircle(renderer, obj.position.v1, obj.position.v2, obj.radius);

            // Bottom
            if (obj.position.v2 + obj.radius > screenSize.v2) {
                obj.position.v2 = screenSize.v2 - obj.radius;
                obj.velocity.v2 *= -0.95f;
            }

            // Top
            if (obj.position.v2 - obj.radius < 0) {
                obj.position.v2 = obj.radius;
                obj.velocity.v2 *= -0.95f;
            }

            if (obj.position.v1 - obj.radius < 0) {
                obj.position.v1 = obj.radius;
                obj.velocity.v1 *= -0.95f;
            }
            if (obj.position.v1 + obj.radius > screenSize.v1) {
                obj.position.v1 = screenSize.v1 - obj.radius;
                obj.velocity.v1 *= -0.95f;
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
