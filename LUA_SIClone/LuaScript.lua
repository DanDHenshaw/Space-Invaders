-- a simple int variable
level = 1
lives = 1

-- a simple vector2 object
startpos = { x = 500, y=625 }

-- random number
math.randomseed(os.time())

function randomNumber()
    return math.random(1, 10000)
end

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