//
//  BangManager.cpp
//
//  Created by Yajun Shi
//

#include "BangManager.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Package1.h"
#include "Package2.h"

BangManager::BangManager(){
    _initialSetup = false;
    _gameOver = false;
    _enemyCooldown = 1.0f;
    _Enemy3CD = 10.0f;
    
    _gameOverScreen = new FullScreenActor();
    
    FullScreenActor *background = new FullScreenActor();
    background->SetSprite("./Resources/Images/background.png");
    theWorld.Add(background, -1);
    
    theWorld.SetupPhysics(Vector2(0.0f, 0.0f));
    
    Vector2 botLeft  = theCamera.GetWorldMinVertex();
    Vector2 topRight = theCamera.GetWorldMaxVertex();

    // Blockers
    PhysicsActor *upBlocker = new PhysicsActor();
    upBlocker->SetPosition(0.0f, topRight.Y);
    upBlocker->SetSize(2*topRight.X, 0.1f);
    upBlocker->SetAlpha(0.0f);
    upBlocker->SetDensity(0.0f);
    upBlocker->InitPhysics();
    theWorld.Add(upBlocker);
    
    PhysicsActor *downBlocker = new PhysicsActor();
    downBlocker->SetPosition(0.0f, botLeft.Y);
    downBlocker->SetSize(2*topRight.X, 0.1f);
    downBlocker->SetAlpha(0.0f);
    downBlocker->SetDensity(0.0f);
    downBlocker->InitPhysics();
    theWorld.Add(downBlocker);
    
    PhysicsActor *leftBlocker = new PhysicsActor();
    leftBlocker->SetPosition(botLeft.X, 0.0f);
    leftBlocker->SetSize(0.1f, 2*topRight.Y);
    leftBlocker->SetAlpha(0.0f);
    leftBlocker->SetDensity(0.0f);
    leftBlocker->InitPhysics();
    theWorld.Add(leftBlocker);
    
    PhysicsActor *rightBlocker = new PhysicsActor();
    rightBlocker->SetPosition(topRight.X, 0.0f);
    rightBlocker->SetSize(0.1f, 2*topRight.Y);
    rightBlocker->SetAlpha(0.0f);
    rightBlocker->SetDensity(0.0f);
    rightBlocker->InitPhysics();
    theWorld.Add(rightBlocker);
    
    // points record
    _points = 0;
    _PointBoard = new TextActor("Console", "0 points",TXT_Right);
    _PointBoard->SetColor(1.0f, 1.0f, 1.0f);
    _PointBoard->SetPosition(12.0f,9.0f);
    theWorld.Add(_PointBoard);
    
}

void BangManager::Reset(){
    
    if (_gameOver)
        theWorld.Remove(_gameOverScreen);
    _gameOver = false;
    
    // clear enemies
    ActorSet enemies = theTagList.GetObjectsTagged("enemy");
    ActorSet::iterator it = enemies.begin();
    while (it != enemies.end()){
        (*it)->Destroy();
        it++;
    }
    
    // clear enemy bullets
    ActorSet bullets = theTagList.GetObjectsTagged("EnemyBullet");
    ActorSet::iterator bit = bullets.begin();
    while (bit != bullets.end()){
        (*bit)->Destroy();
        bit++;
    }
    
    // clear packages
    ActorSet packages = theTagList.GetObjectsTagged("package");
    ActorSet::iterator pit = packages.begin();
    while (pit != packages.end()){
        (*pit)->Destroy();
        pit++;
    }

    // player
    Player* player = (Player*)Actor::GetNamed("Player");
    if (player == NULL){
        new Player();
        
    } else{
        player->Reset();
    }
    
    // points records
    _points = 0;
    _PointBoard->SetDisplayString("0 points");
    
    _Enemy3CD = 10.0f;
}

void BangManager::GameOver(){
    
    _gameOverScreen->SetSprite("./Resources/Images/game_over.png");
    theWorld.Add(_gameOverScreen, 5);
    _gameOver = true;
}

void BangManager::Update(float dt){
    
    GameManager::Update(dt);
    
    if (!_initialSetup){
        Reset();
        _initialSetup = true;
    }
    
    if (_gameOver && theInput.IsKeyDown(ANGEL_KEY_R)){
        Reset();
    }
    
    // generate enemies
    if (_enemyCooldown > 0.0f){
        _enemyCooldown -= dt;
        
    } else if (_enemyCooldown <= 0.0f){
        Vector2 enemyPos1 = MathUtil::RandomVector(Vector2(-12.0f,10.0f),Vector2(12.0f, 10.0f));
        Vector2 enemyPos2 = MathUtil::RandomVector(Vector2(-12.0f,10.0f),Vector2(12.0f, 10.0f));
        new Enemy(enemyPos1);
        new Enemy2(enemyPos2);
        
        _enemyCooldown = 1.0f;
    }
    
    // generate super enemy
    if(_Enemy3CD >0.0f){
        _Enemy3CD -= dt;
        
    } else if (_Enemy3CD <= 0.0f){
        Vector2 EnemyPos = MathUtil::RandomVector(Vector2(-12.0f,10.0f),Vector2(12.0f, 10.0f));

        new Enemy3(EnemyPos);
        
        _Enemy3CD = 10.0f;        
    }
}

void BangManager::AddPoint(){
    _points += 1;
    
    // generate a random package every 10 points
    if (_points % 10 == 0){
        Vector2 PackPos = MathUtil::RandomVector(Vector2(-12.0f,10.0f),Vector2(12.0f, 10.0f));
        
        int random = rand() % 2;
        
        if(random == 0){
            new Package1(PackPos);
        } else {
            new Package2(PackPos);
        }
    }
    
    int point = _points;
    String temp= "";
    String text = "";
    while (point > 0){
        temp += point % 10 + 48;
        point /= 10;
    }
    for (int i=0; i < temp.length(); i++){
        text += temp[temp.length() - i - 1];
    }
    
    _PointBoard->SetDisplayString(text.append(" points"));
}
