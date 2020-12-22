//
//  Object.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 22/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <string>

#include "Teleport.hpp"
#include "Script.hpp"

class Object {
    
private:
    // Object location
    int x;
    int y;
    
    // Object type and state
    std::string type;
    bool running;
    
    // Teleport object
    Teleport* teleport;
    
    // Script object
    Script* script;
    
public:
    // Main constructor
    Object(int x, int y, std::string type);
    
    // Location
    int getX();
    int getY();
    
    // Type
    std::string getType();
    
    // State
    bool isRunning();
    void setRunning();
    void finish();
    
    // Teleport object
    Object(int x, int y, Teleport teleport);
    Teleport* getTeleport();
    
    // Script object
    Object(int x, int y, Script script);
    Script* getScript();
    
};

#endif /* Object_hpp */
