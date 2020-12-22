//
//  Player.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 19/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include "Entity.hpp"

class Player : public Entity {
    
public:
    Player();
    
    void update(float deltaTime, MapData &map, bool canStartMoving);
    
};

#endif /* Player_hpp */
