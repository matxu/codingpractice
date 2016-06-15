# programmed by Hossein Siadati
def rotate_matrix(matrix):
	N = len(matrix)
	M = len(matrix[0])
	if M != N:
		raise "Can not rotate. number of rows and columns are different"

	for i in range(N/2):
		for j in range(i, N-i-1):
			temp = matrix[i][j]
			matrix[i][j] = matrix[N-j-1][i]
			matrix[N-j-1][i] = matrix[N-i-1][N-j-1]
			matrix[N-i-1][N-j-1] = matrix[j][N-i-1]
			matrix[j][N-i-1] = temp
	
	return matrix

def print_matrix(m):
	for i in range(len(m)):
		for j in range(len(m[0])):
			print m[i][j],
		print 

def test2():
	m =[[1,2,3, 10],
            [4,5,6, 20],
            [7,8,9, 30],
	    [40, 50, 60, 70]]
        n = rotate_matrix(m)
        print n
        print_matrix(n)
	
def test1():
	m =[[1,2,3],
	    [4,5,6],
	    [7,8,9]]
	n = rotate_matrix(m)
	print n
	print_matrix(n)

if __name__=="__main__":
	test2() 
