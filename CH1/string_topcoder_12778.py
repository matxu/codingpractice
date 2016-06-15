# programmed by Hossein Siadati
def matchgrammer(instr):
	if len(instr) == 0:
		return True

	wcount = 0
	i = 0
	while i < len(instr):
		if instr[i] == 'w':
			wcount += 1
			i += 1
		elif instr[i] == 'o':
			break
		else:
			return False

	#check if the same number of o, l, and f follows
	loc = i
	if i == 0:
		return False
	
	# check if the length of the remaining string is enough for a 
	# correct pattern
	if len(instr) - loc < 3 * loc:
		return False
	r = 0
	for c in ["o", "l", "f"]:
		for j in range(loc):
			if instr[loc+r*loc+j] != c:
				return False
		r += 1
	return matchgrammer(instr[4*loc:])

def test1():
	tcase = ["wolf", "wwolfolf", "wolfwwoollffwwwooolllfffwwwwoooollllffff",
		"flowolf"]
	for t in tcase:
		print t, matchgrammer(t)

if __name__=="__main__":
	test1()
	

