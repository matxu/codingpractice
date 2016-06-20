# programmed by Hossein Siadati

def replace_space(instr):
	if len(instr) == 0:
		return instr
	
	instr = list(instr)
	instrlen = len(instr)
	blankcount = 0
	for i in range(len(instr)):
		if instr[i] == ' ':
			blankcount += 1
	if blankcount == 0:
		return "".join(instr)

	instr = instr + [' '] * 2 * blankcount
	
	loc = len(instr) - 1
	for i in range(instrlen-1, -1, -1):
		if instr[i] != ' ':
			instr[loc] = instr[i]
			loc -= 1
		else:
			instr[loc] = '0'
			instr[loc-1] = '2'
			instr[loc-2] = '%'
			loc -= 3
	return "".join(instr)

def test2():
	t = " "
	d = replace_space(t)
	print t, d
	print "h"

def test1():
	tcase = ["ab cdef", "abc", "  ", " a"]
	for t in tcase:
		print t, replace_space(t)

if __name__ == "__main__":
	test1()
