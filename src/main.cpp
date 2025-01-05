#include <ctime>
#include <iostream>

#include "flecs.h"

const float FPS = 2.0f;
const int WIDTH = 100;

struct Position
{
    float x, y;
};

enum EntityType { predator, prey };

void createEntity(const flecs::world &ecs, const EntityType &entityType){
    ecs.entity()
        .insert([](Position &p, EntityType &entityType)
                {
      p = {(float)(std::rand() % WIDTH), (float)(std::rand() % WIDTH)};
      entityType = entityType;});
}

int main(int argc, char *argv[])
{
    std::cout << "initializing...\n";
    std::srand(std::time(nullptr));

    flecs::world ecs;
    ecs.set<flecs::Rest>({});
    ecs_set_target_fps(ecs, FPS);
    for(int i=0; i<10; i++){
        createEntity(ecs, predator);
    }
    for(int i=0; i<100; i++){
        createEntity(ecs, prey);
    }

    while (ecs.progress()){
        std::cout << "flecs progress()\n";
    }
    std::cout << "exiting\n";
}