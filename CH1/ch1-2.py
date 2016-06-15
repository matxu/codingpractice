def reverse(instr):
	# Strings in python are immutable (unchanging over time)
	# 
	instr = list(instr)
	front = 0
	end   = len(instr) - 1
	
	while(front<end):
		temp = instr[front]
		instr[front] = instr[end]
		instr[end] = temp
		front += 1
		end   -= 1
	return "".join(instr)

def test1():
	tcases = ["abcd", "", "1"]
	for t in tcases:
		print t, reverse(t)

if __name__ == "__main__":
	test1() 
	
	
	
