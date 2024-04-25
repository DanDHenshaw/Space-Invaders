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
Player::Player(lua_State* luaState, float xPos, float yPos, int lives, string filename)
	:Ship(luaState, xPos, yPos, filename)
{
	m_lives = lives;
	m_score = 0;
}

Player::~Player()
{
	//al_destroy_bitmap(m_Ship_image);
}

void Player::Init(LUA::Dispatcher& disp)
{
  // tell the dispatcher we have a function from Lua
  LUA::Dispatcher::Command::voidintfunc vif{ [this](int score) { return setScore(score); } };
  disp.Register("setScore", LUA::Dispatcher::Command{ vif });

  vif = { [this](int lives) { return reset_lives(lives); } };
  disp.Register("resetPlayerLives", LUA::Dispatcher::Command{ vif });

}

//Methods
int Player::getScore()//gets the current score
{
	return m_score;
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

void Player::reset_lives(int lives)
{
	m_lives = lives;
}

void Player::reset_score()
{
	m_score = 0;
}

void Player::right()
{
  LUA::CallMovement(luaState, "right", 10, m_xpos, m_current_frame);
}

void Player::left()
{
  LUA::CallMovement(luaState, "left", 10, m_xpos, m_current_frame);
}
