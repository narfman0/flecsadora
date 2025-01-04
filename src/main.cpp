#include <iostream>

#include "flecs.h"

float FPS = 6.0f;

struct Position
{
    float x, y;
};

struct Velocity
{
    float x, y;
};

int main(int argc, char *argv[])
{
    std::cout << "Initializing flecs\n";
    flecs::world ecs;
    ecs.set<flecs::Rest>({});
    ecs_set_target_fps(ecs, FPS);

    ecs.system<Position, const Velocity>()
        .each([](Position &p, const Velocity &v)
              {
      p.x += v.x;
      p.y += v.y; });

    ecs.entity()
        .insert([](Position &p, Velocity &v)
                {
      p = {10, 20};
      v = {1, 2}; });

    while (ecs.progress())
    {
        std::cout << "FLECS progressed\n";
    }
    std::cout << "Exiting\n";
}