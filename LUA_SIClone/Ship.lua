-- Ship Script

move_speed = 10

-------- Ship movement Start --------
-- move down
function down( y, currentFrame )

  currentFrame = currentFrame + 1;

  y = y + move_speed;

  if(currentFrame > 1.9) then
    currentFrame = 0
  end

  return y, currentFrame
end
-------- Ship movement End --------

-- Player Script

lives = 3

start_pos = { x = 500, y=625 }

-------- Player movement Start --------
-- move right
function right( x, currentFrame )
	x = x + move_speed

  if(x > 910) then
    x = 910
  end

  if(currentFrame > 1.9) then
    currentFrame = 0
  end
  
  return x, currentFrame
end

-- move left
function left( x, currentFrame )
  x = x - move_speed

  if(x < -5) then
    x = -5
  end

  if(currentFrame > 1.9) then
    currentFrame = 0
  end

  return x, currentFrame
end

-------- Player movement End --------

-- set player score
function setPlayerScore( score )
  CDispatcher("setScore", score)
end

-- reset player lives
function resetPlayerLives( )
  CDispatcher("reset_lives", lives)
end

-- Mothership Script

function reduceLives( lives )
  lives = lives - 1

  return lives
end