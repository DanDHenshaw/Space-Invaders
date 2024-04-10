-- a simple int variable
level = 1

-- random number
math.randomseed(os.time())

function randomNumber()
    return math.random(1, 10000)
end

-- display_message
function winMessage()
	display_message("You Win!!!")
end

function nextLevelMessage()
	display_message("Next Level...")
end
