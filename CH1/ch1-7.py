# programmed by Hossein Siadati
def rowcolumn_zero(matrix):

	rows = [False] * len(matrix)
	cols = [False] * len(matrix[0])

	for i in range(len(rows)):
		for j in range(len(cols)):
			if matrix[i][j] == 0:
				rows[i] = True
				cols[j] = True
	
	for i in range(len(rows)):
                for j in range(len(cols)):
			if rows[i]==True or cols[j]==True:
				matrix[i][j] = 0
	return matrix

def test1():
	matrix = [[0,2,3,4],
		[6,5,7,8],
		[9,10,0,12]]
	print rowcolumn_zero(matrix)

if __name__ == "__main__":
	test1()
