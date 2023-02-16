#ifndef NGUENGINE_ENTITYMANAGER_H
#define NGUENGINE_ENTITYMANAGER_H

#include "Entity.h"
#include "Component.h"
#include <vector>

class EntityManager
{
private:
    std::vector<Entity*> entities;

public:
    void ClearData();
    void Update(float deltaTime);
    void Render();
    bool HasNoEntites();
    Entity& AddEntity(std::string entityName);
    std::vector<Entity*> GetEntities() const;
    unsigned int GetEntityCount();
};

#endif //NGUENGINE_ENTITYMANAGER_H
