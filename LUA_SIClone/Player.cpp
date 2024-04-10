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
	:Ship(xPos, yPos, filename), luaState(luaState)
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
  LUA::Dispatcher::Command::voidintfunc f{ [this](int score) { return setScore(score); } };
  disp.Register("setScore", LUA::Dispatcher::Command{ f });
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

void Player::right()
{
  LUA::CallMovement(luaState, "right", m_xpos, m_current_frame);
}

void Player::left()
{
  LUA::CallMovement(luaState, "left", m_xpos, m_current_frame);
}
