# Problem 1.1
# Written by Hossein Siadati
def has_all_unique(instr):
	exists = [False]*256  #[False for i in range(256)]
	for i in range(len(instr)):
		#print "check ", instr[i]
		if exists[ ord(instr[i]) ] == True:
			return False
		exists[ ord(instr[i]) ] = True
	return True


def test1():
        tcases = ["tes", "test1", "  ", "''"]
	for t in tcases:
        	print t, has_all_unique(t)

if __name__ == "__main__":
	test1()

