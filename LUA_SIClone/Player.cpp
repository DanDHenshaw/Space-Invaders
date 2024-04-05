/*
Space invaders game
Author:		Philip Alassad
Filename:	Player.cpp
Date:		14/10/2015
Last Updated:	__/__/____

Description: Source file for Player class
*/

#include "Player.h"
#include <stdio.h>

//Constructor
Player::Player(float xPos, float yPos, int lives, string filename)
	:Ship(xPos, yPos, filename)
{
	m_lives = lives;
	m_score = 0;

  luaState = luaL_newstate();

  // open main libraries for scripts
  luaL_openlibs(luaState);

  // Load and parse the lua File
  if(!LUA::IsOK(luaState, luaL_dofile(luaState, "LuaScript.lua")))
    assert(false);
}

Player::~Player()
{
	//al_destroy_bitmap(m_Ship_image);

  lua_close(luaState);
}

//Methods
int Player::getScore()//gets the current score
{
	return m_score;
}

void Player::reduceLives()
{
	m_lives -= 1;
}

void Player::increaseLives()
{
	m_lives += 1;
}

int Player::getLives()
{
	return m_lives;
}

void Player::setScore(int score)
{
	m_score = m_score + score;
}

void Player::kill()
{
	m_lives = 0;
}

void Player::reset_lives()
{
	m_lives = 3;
}

void Player::reset_score()
{
	m_score = 0;
}

void Player::right(void)
{
  LUA::CallMoveRight(luaState, "right", m_xpos, m_current_frame);
}
