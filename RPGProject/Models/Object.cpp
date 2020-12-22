//
//  Object.cpp
//  RPGProject
//
//  Created by Nathan FALLET on 22/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#include "Object.hpp"

// Main constructor
Object::Object(int x, int y, std::string type) {
    this->x = x;
    this->y = y;
    this->type = type;
    this->running = false;
}

// Location
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
Object::Object(int x, int y, Teleport teleport) : Object::Object(x, y, "teleport") {
    this->teleport = new Teleport(teleport);
}

Teleport* Object::getTeleport() {
    return teleport;
}

// Script object
Object::Object(int x, int y, Script script) : Object::Object(x, y, "script") {
    this->script = new Script(script);
}

Script* Object::getScript() {
    return script;
}
