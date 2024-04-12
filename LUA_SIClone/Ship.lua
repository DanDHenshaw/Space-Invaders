-- Ship Script

-------- Ship movement Start --------
-- move down
function down( y, currentFrame )

  currentFrame = currentFrame + 1;

  y = y + 10;

  if(currentFrame > 1.9) then
    currentFrame = 0
  end

  return y, currentFrame
end
-------- Ship movement End --------

-- Player Script

lives = 50

startpos = { x = 500, y=625 }

-------- Player movement Start --------
-- move right
function right( x, currentFrame )
	x = x + 50

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
  x = x - 50

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
function setPlayerScore()
  CDispatcher("setScore", 5000)
end