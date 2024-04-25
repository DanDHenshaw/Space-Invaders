# Space-Invaders-Lua

## Main.lua
- level - used to select which level to start the game on
- start_time - how long it takes for the game to start

### Lua Functions 
- randomNumber - generates a random number between 1 and 10000
- winMessage - displays the message "You Win!!!"
- nextLevelMessage - displays the message "Next Level..."

## Ship.lua
- lives - used to define how many lives the player has when the game starts
- start_pos - used to define the starting position of the player

### Lua Functions
- left - takes in a move_speed, x position and currentFrame and moves the ship left
- right - takes in a move_speed, x position and currentFrame and moves the ship right
- down - takes in a move_speed, y position and currentFrame and moves the ship down
- reduceLives - takes in a lives variable and reduces it by 1

### C++ Functions
- setPlayerScore - calls the setScore function on the player
- resetPlayerLives - calls the reset_lives function on the player
