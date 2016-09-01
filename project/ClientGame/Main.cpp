//
//  Main.cpp
//
//  Created by Yajun Shi
//
//  The main class for running the game

#include "stdafx.h"
#include "BangManager.h"

int main(int argc, char* argv[])
{

	theWorld.Initialize(1024, 768, "Bang!");
	
	theWorld.SetGameManager(new BangManager());

	theWorld.StartGame();
	
	theWorld.Destroy();
	
	return 0;
}
