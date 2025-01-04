#include <iostream>

#include "flecs.h"

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
    std::cout << "Initializing flecs!\n";
    flecs::world ecs;
    ecs.set<flecs::Rest>({});

    ecs.system<Position, const Velocity>()
        .each([](Position &p, const Velocity &v)
              {
      p.x += v.x;
      p.y += v.y; });

    auto e = ecs.entity()
                 .insert([](Position &p, Velocity &v)
                         {
      p = {10, 20};
      v = {1, 2}; });

    while (ecs.progress())
    {
    }
    std::cout << "Done with flecs!\n";
}