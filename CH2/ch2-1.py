# programmed by Hossein Siadati
class LinkedList:

	def __init__(self):
		self.head = Node()
		self.end  = Node()
		return

	def addListOfNodes(self, value):
		for v in value:
			self.addNode(v)
		return
	# adds a node to the end of the list
	def addNode(self, value):
		n = Node()
		n.setValue(value) 
		if self.head.getNext() == None:
			self.head.setNext(n)
			self.end = n
		else:
			self.end.setNext(n)
			self.end = n
			#find the las node and append
		return

	def removeNode(self, value):
		return

	def removeEnd(self, value):
		return

	def buildFromValues(self, values):
		return

	def removeDuplicated_usehmap(self):
		unqvals = {}
		prev  = self.head
		cnode = self.head.getNext()

		while cnode != None:
			v = cnode.getValue()
			if not v in unqvals:
				unqvals[v] = True
				prev = cnode
				cnode = cnode.getNext()
			else:
				prev.setNext( cnode.getNext() )
				cnode = prev.getNext()

		return

	def removeDuplicated(self):
		if self.head.getNext() == None:
			return
		
		if self.head.getNext() == self.end:
			return

		current = self.head.getNext().getNext()
		runner  = self.head.getNext()
		prev    = self.head

		while not current == None:
			
			while not runner == current:
				if runner.getValue() == current.getValue():
					prev.setNext( runner.getNext() )
					runner = runner.getNext()
				else:
					prev = runner
					runner = runner.getNext()
			
			current = current.getNext()
			runner  = self.head.getNext()
			prev    = self.head


	def printList(self):
		if self.head.getNext() == None:
			print "List is empty"
		cnode = self.head.getNext() 
		while cnode!=None:
			print cnode.getValue()
			cnode = cnode.getNext()
		return
class Node:
	def __init__(self):
		self.next = None
		self.value = None
		return
	def setValue(self, d):
		self.value = d

	def getValue(self):
		return self.value

	def getNext(self):
		return self.next

	def setNext(self, node):
		self.next = node

def test1():
  l = LinkedList()
  l.addNode(10)
  l.addNode(20)
  l.addNode(10)
  l.addNode(30)
  l.removeDuplicated_usehmap()
  l.printList()

def test2():
	l = LinkedList()
	l.addListOfNodes([1,2,3,1,4,5,1,6,2,2,2,0,3,3])
	l.printList()
	l.removeDuplicated()
	print "Unique nodes"
	l.printList()

if __name__ == "__main__":
	test2()
