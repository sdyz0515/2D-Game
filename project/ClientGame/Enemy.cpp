//
//  Enemy.cpp
//
//  Created by Yajun Shi
//

#include "Enemy.h"
#include "BangManager.h"
#include "Player.h"

Enemy::Enemy(){
    _enemyExplode  = theSound.LoadSample("./Resources/Sounds/enemyExplode.wav", false);
}

Enemy::Enemy(Vector2 position){

    Tag("enemy");
        
    SetPosition(position);
    
    SetSprite("./Resources/Images/enemy1.png");
    SetSize(1.8f);
    
    SetDensity(1.0f);
    SetShapeType(PhysicsActor::SHAPETYPE_CIRCLE);
    SetFixedRotation(true);
    SetIsSensor(true);
    InitPhysics();
    theWorld.Add(this);
    
    _enemyExplode  = theSound.LoadSample("./Resources/Sounds/enemyExplode.wav", false);
    
    ApplyLinearImpulse(Vector2(0, -15.0f), Vector2::Zero);
    
    theSwitchboard.SubscribeTo(this, "CollisionStartWith" + GetName());
}

void Enemy::Update(float dt){
    
    PhysicsActor::Update(dt);
    
    if (GetPosition().Y < theCamera.GetWorldMinVertex().Y){
        Destroy();
    }
}

void Enemy::ReceiveMessage(Message* message){
    
    if (message->GetMessageName() == "CollisionStartWith" + GetName()){
        
        PhysicsActor* hitter = (PhysicsActor*)message->GetSender();
        
        if (!hitter->IsDestroyed()){
            
            if (hitter->IsTagged("bullet") || hitter->IsTagged("superBullet")){
                Explode();
                hitter->Destroy();
                ((BangManager*)theWorld.GetGameManager())->AddPoint();
                
            } else if (hitter->GetName() == "Player"){
                ((Player *)(hitter))->Explode();
            }
        }
    }
}

void Enemy::Explode(){
    theSound.PlaySound(_enemyExplode, 0.5f);
    Destroy();
}
