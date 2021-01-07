//
//  Object.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 22/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "Object.hpp"

// Main constructor
Object::Object() {
    this->running = false;
}

Object::~Object() {
    if (teleport != nullptr) {
        delete teleport;
    }
    if (script != nullptr) {
        delete script;
    }
}

// Location
void Object::setLocation(int x, int y) {
    this->x = x;
    this->y = y;
}

int Object::getX() {
    return x;
}

int Object::getY() {
    return y;
}

// Type
std::string Object::getType() {
    return type;
}

// State
bool Object::isRunning() {
    return running;
}

void Object::setRunning() {
    running = true;
}

void Object::finish() {
    running = false;
}

// Teleport object
void Object::setTeleport(Teleport teleport) {
    this->type = "teleport";
    this->teleport = new Teleport(teleport);
}

Teleport* Object::getTeleport() {
    return teleport;
}

// Script object
void Object::setScript(Script script) {
    this->type = "script";
    this->script = new Script(script);
}

Script* Object::getScript() {
    return script;
}
