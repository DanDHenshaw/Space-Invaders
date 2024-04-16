/*
Space invaders game
Author:		Philip Alassad
Filename:	Mothership.h
Date:		14/10/2015
Last Updated:	25/10/2015

Description: Header file for Mothership class
*/

#pragma once

//includes go here
#include "Ship.h"


using namespace std;

class Mothership : public Ship
{
public:
	//constructor
	Mothership(lua_State* luaState, float xPos, float yPos, string filename);
	~Mothership(void);

	//methods
	void left();
	void right();
	int getLives();

};