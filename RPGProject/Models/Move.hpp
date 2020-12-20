//
//  Move.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 20/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef Move_hpp
#define Move_hpp

#include <stdio.h>

class Move {
private:
    int fromX;
    int toX;
    int fromY;
    int toY;
    
    float interpolation(int start, int end, float progress);
    
public:
    Move(int fromX, int toX, int fromY, int toY);
    
    float getX(float progress);
    float getY(float progress);
    
    void cancelMove();
    
};

#endif /* Move_hpp */
