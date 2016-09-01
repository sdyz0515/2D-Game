//
//  Player.cpp
//
//  Created by Yajun Shi
//

#include "Player.h"
#include "Bullet.h"
#include "BangManager.h"
#include "SuperBullet.h"
#include "Package1.h"
#include "Package2.h"
#include "LeftBullet.h"
#include "RightBullet.h"

Player::Player(){
    SetName("Player");
    
    SetPosition(Vector2(0.0f, -7.0f));

    _bulletCooldown = -1.0f;
    _bulletMode = 0;
    
    SetSprite("./Resources/Images/ship.png");
    SetSize(1.75f);
    
    SetDensity(1.0f);
    SetShapeType(PhysicsActor::SHAPETYPE_CIRCLE);
    SetFixedRotation(true);
    InitPhysics();
    
    _bulletSound  = theSound.LoadSample("./Resources/Sounds/bullet.wav", false);
    _explodeSound = theSound.LoadSample("./Resources/Sounds/explode.wav", false);
    
    theWorld.Add(this);
    
    theSwitchboard.SubscribeTo(this, "CollisionStartWith" + GetName());
}

void Player::Update(float dt){
    
    if (IsDestroyed()){
        return;
    }
    
    if (_bulletCooldown > 0.0f){
        _bulletCooldown -= dt;
    }
    
    if (_bulletduration > 0.0f){
        _bulletduration -= dt;
    }
    
    if (_bulletduration<=0){
        
        _bulletMode=0;
        
    }

    // move
    b2Vec2 currentVelocity = GetBody()->GetLinearVelocity();
        
    float xVel = 0.0f;
    float yVel = 0.0f;
        
    if (theInput.IsKeyDown(ANGEL_KEY_RIGHTARROW)){
        xVel = 10.0f;
    }
    if (theInput.IsKeyDown(ANGEL_KEY_LEFTARROW)){
        xVel = -10.0f;
    }
    if (theInput.IsKeyDown(ANGEL_KEY_UPARROW)){
        yVel = 10.0f;
    }
    if (theInput.IsKeyDown(ANGEL_KEY_DOWNARROW)){
        yVel = -10.0f;
    }
    
    float xVelChange = xVel - currentVelocity.x;
    float yVelChange = yVel - currentVelocity.y;
        
    ApplyLinearImpulse(Vector2(xVelChange, yVelChange), Vector2::Zero);
    
    // fire
    if (theInput.IsKeyDown(ANGEL_KEY_SPACE)){
        
        if (_bulletCooldown <= 0.0f){
            
            theSound.PlaySound(_bulletSound, 0.5f);
            
            if (_bulletMode == 0) {
                _bulletCooldown = 0.3f;
                new Bullet(this);
                
            } else if (_bulletMode == 1){
                _bulletCooldown = 0.3f;
                new Bullet(this);
                new LeftBullet(this);
                new RightBullet(this);
                
            } else if (_bulletMode == 2){
                _bulletCooldown = 0.8f;
                new SuperBullet(this);
            }
        }
    }
    PhysicsActor::Update(dt);
}

void Player::ReceiveMessage(Message* message){
    
    if (message->GetMessageName() == "CollisionStartWith" + GetName()) {
        
        PhysicsActor* hitter = (PhysicsActor*)message->GetSender();
        
        if (!hitter->IsDestroyed()){
            
            if (hitter->IsTagged("enemyBullet")){
                this->Explode();
                hitter->Destroy();
            }
            else if (hitter->GetName() == "Package1"){
                _bulletMode = 1;
                hitter->Destroy();
                _bulletduration = 10.0f;
            }
            else if (hitter->GetName() == "Package2"){
                _bulletMode = 2;
                hitter->Destroy();
                _bulletduration = 10.0f;
            }
        }
    }
}

void Player::Explode(){
    
    theSound.PlaySound(_explodeSound, 0.5f);
    Destroy();
    ((BangManager*)theWorld.GetGameManager())->GameOver();
}

void Player::Reset(){
    _bulletMode = 0;
}
