//
// Created by antho on 2/11/2023.
//

#ifndef NGUENGINE_ENTITY_H
#define NGUENGINE_ENTITY_H
#include <vector>
#include <string>

class Component;
class EntityManager;

class Entity
{
private:
    EntityManager &manager;
    bool isActive;
    std::vector<Component*> components;

public:
    std::string name;
    Entity(EntityManager &manager);
    Entity(EntityManager &manager, std::string name);
    void Update(float deltaTime);
    void Render();
    void Destroy();
    bool IsActive() const;
};


#endif //NGUENGINE_ENTITY_H
