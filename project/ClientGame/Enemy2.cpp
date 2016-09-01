//
//  Enemy2.cpp
//
//  Created by Xun Liu
//

#include "Enemy2.h"
#include "BangManager.h"
#include "Player.h"
#include "EnemyBullet.h"

Enemy2::Enemy2(Vector2 position)
{
    SetName("Enemy2");
    Tag("enemy");    
    
    SetPosition(position);
    
    _enemyExplode  = theSound.LoadSample("./Resources/Sounds/enemyExplode.wav", false);
    
    _bullet_cd = 0.0f;
    
    SetSprite("./Resources/Images/enemy2.png");
    SetSize(1.8f);
    
    SetDensity(1.0f);
    SetShapeType(PhysicsActor::SHAPETYPE_BOX);
    SetFixedRotation(true);
    SetIsSensor(true);
    InitPhysics();
    theWorld.Add(this);
    
    ApplyLinearImpulse(Vector2(0, -10.0f), Vector2::Zero);
    
    theSwitchboard.SubscribeTo(this, "CollisionStartWith" + GetName());
}

void Enemy2::Update(float dt){
    
    if (true){
        
        _bullet_cd-=dt;
        
        if ( _bullet_cd <= 0.0f)
        {
            
            _bullet_cd =  2.0f;
            
            new EnemyBullet(this);
        }
        
    }
    
    PhysicsActor::Update(dt);
    
    if (GetPosition().Y < theCamera.GetWorldMinVertex().Y)
    {
        Destroy();
    }
}
