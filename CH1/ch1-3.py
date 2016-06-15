# programmed by Hossein Siadati
# Interesting differece between c and python loop: 
# The counter i for loop for i in range(10)
# will have value 9 after the loop
def removeduplicate(instr):
	if len(instr)<=1:
		return instr
	instr = list(instr)
	
	tail = 1
	for i in range(1, len(instr)):
		found = False
		for j in range(tail):
			if instr[i] == instr[j]:
				found = True
		if not found:
			instr[tail] = instr[i]
			tail += 1
	
	return "".join(instr[:tail])

def test1():
	tcases = ["abbbc", "aabbbbaa", "abcdef", "", "l;''';'", "0000000"]
	for t in tcases: 
		print t, removeduplicate(t)
def test2():
	t = "abbbac"
	print removeduplicate(t)
if __name__ == "__main__":
	test1()
			
