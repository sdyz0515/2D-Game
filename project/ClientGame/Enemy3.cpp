//
//  Enemy3.cpp
//
//  Created by Xun Liu
//

#include "Enemy3.h"
#include "BangManager.h"
#include "Player.h"
#include "EnemyBullet.h"
#include "EnemyLBullet.h"
#include "EnemyRBullet.h"

Enemy3::Enemy3(Vector2 position)
{
    SetName("Enemy3");
    Tag("enemy");
    
    _HP=7;
    
    SetPosition(position);
    
    _bullet_cd = -1.0f;
    
    SetSprite("./Resources/Images/enemy3.png");
    SetSize(2.0f);
    
    SetDensity(1.0f);
    SetShapeType(PhysicsActor::SHAPETYPE_BOX);
    SetFixedRotation(true);
    SetIsSensor(true);
    InitPhysics();
    theWorld.Add(this);
    
    _enemyExplodes  = theSound.LoadSample("./Resources/Sounds/enemyExplode.wav", false);
    
    ApplyLinearImpulse(Vector2(0, -3.0f), Vector2::Zero);
    
    theSwitchboard.SubscribeTo(this, "CollisionStartWith" + GetName());
}

void Enemy3::Update(float dt){
    
    if(_HP==0){
        ((BangManager*)theWorld.GetGameManager())->AddPoint();
        ((BangManager*)theWorld.GetGameManager())->AddPoint();
        ((BangManager*)theWorld.GetGameManager())->AddPoint();
        Explode();
    }
    
    if (true){
        
        _bullet_cd-=dt;
        
        if ( _bullet_cd <= 0.0f)
        {
            
            _bullet_cd =  2.0f;
            
            new EnemyBullet(this);
            new EnemyLBullet(this);
            new EnemyRBullet(this);

        }
    }
    
    PhysicsActor::Update(dt);
}

void Enemy3::ReceiveMessage(Message* message){
    
    if (message->GetMessageName() == "CollisionStartWith" + GetName())
    {
        PhysicsActor* hitter = (PhysicsActor*)message->GetSender();
        
        if (!hitter->IsDestroyed())
        {
            if (hitter->IsTagged("superBullet"))
            {
                
                hitter->Destroy();
                
                _HP = 0;
                
            }
            else if (hitter->GetName() == "Player")
            {
                ((Player *)(hitter))->Explode();
            }
            
            else if (hitter->IsTagged("bullet"))
            {
                _HP--;
                
                hitter->Destroy();
            }
            
        }
    }
}
