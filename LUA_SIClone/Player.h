/*
Space invaders game
Author:		Philip Alassad
Filename:	Player.h
Date:		14/10/2015
Last Updated:	__/__/____

Description: Header file for Player class
*/

#pragma once

//includes go here
#include "Ship.h"

using namespace std;

class Player: public Ship
{
private:
	//members
	int m_score;

public:
	//constructor
	Player(lua_State* luaState, float xPos, float yPos, int lives, string filename);
	~Player(void);

  void Init(LUA::Dispatcher& disp);

	//methods
	void increaseLives();
	int getLives();
	int getScore();
	void kill();
	void reset_lives();
	void reset_score();

  // movement
  void right();
  void left();

private:
  void setScore(int score);
};