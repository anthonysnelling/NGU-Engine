//
// Created by antho on 2/11/2023.
//

#ifndef NGUENGINE_COMPONENT_H
#define NGUENGINE_COMPONENT_H

class Entity;

class Component
{
public:
    Entity* owner;
    virtual ~Component(){};
    virtual void Initialize(){};
    virtual void Update(float deltaTime) {};
    virtual void Render() {};
};

#endif //NGUENGINE_COMPONENT_H
