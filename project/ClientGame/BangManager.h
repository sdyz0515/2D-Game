//
//  BangManager.hpp
//
//  Created by Yajun Shi
//
//  The manager of the game, controls game flow.
//  Records points, generates enemies and bullet packages.
//

#include "stdafx.h"

class BangManager : public GameManager {
public:
    BangManager();
    void Reset();
    void GameOver();
    virtual void Update(float dt);
    void AddPoint();
    
private:
    FullScreenActor* _gameOverScreen;
    
    bool _initialSetup;
    bool _gameOver;
    
    int _points;
    TextActor *_PointBoard;
    
    float _enemyCooldown;
    float _Enemy3CD;
};
