# programmer: Hossein Siadati
# find if a string is permutation of the othe one

def ispermutation(str1, str2):
	charcount = [0]*256

	if len(str1)!=len(str2):
		return False

	if len(str1)==0:
		return True	

	for i in range(len(str1)):
		charcount[ord(str1[i])] += 1
	for j in range(len(str2)):
		if charcount[ord(str2[j])]==0:
			return False
		charcount[ord(str2[j])] -= 1
	return True

def test1():
	tcase1 = ["abcd", "ac"  , "aaaaaaa"]
	tcase2 = ["bcdd", "acvv", "aaaaaaa"]
	for i in range(len(tcase1)):
		t1 = tcase1[i]
		t2 = tcase2[i]
		print t1, t2, ispermutation(t1, t2)

if __name__ == "__main__":
	test1()
