//
//  TeleportObject.hpp
//  RPGProject
//
//  Created by Nathan FALLET on 20/12/2020.
//  Copyright © 2020 Nathan FALLET. All rights reserved.
//

#ifndef TeleportObject_hpp
#define TeleportObject_hpp

class TeleportObject {

private:
    int x;
    int y;
    int targetMap;
    int targetX;
    int targetY;
    
    bool running;
    
public:
    TeleportObject(int x, int y, int targetMap, int targetX, int targetY);
    
    bool isRunning();
    void setRunning();
    void finish();
    
    friend class MapData;
    friend class TileMap;
    
};

#endif /* TeleportObject_hpp */
