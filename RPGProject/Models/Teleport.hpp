//
//  Teleport.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 22/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef Teleport_hpp
#define Teleport_hpp

struct Teleport {
    
    int targetMap;
    int targetX;
    int targetY;
    
    Teleport(int targetMap, int targetX, int targetY);
    
};

#endif /* Teleport_hpp */
