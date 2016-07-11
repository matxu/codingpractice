// Add two numbers Version 2: numbers stored in forward order in linked list

int nthToLast(ListNode *head, int n) {
	// write your code here
	if (head == nullptr) return -1;
	if (head->next == NULL) {
		if (n == 1) return head->val;
		else
			return -1;
	}

	ListNode *slow = head, *fast = head;
	int count = 1;
	while (count<n) {
		
		fast = fast->next;
		if (fast == NULL) return -1;
		count++;
	}

	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next;
	}

	return slow->val;
}


ListNode *addLists2(ListNode *l1, ListNode *l2) {
	// write your code here
	// If either l1 or l2 is empty
	if (l1->next == NULL) return l2;
	if (l2->next == NULL) return l1;
	// Method 1: reverse two lists and add them

	// Method 2: Find the last node, add, find the second to last node, add...
	int k = 1, val1 = 0, val2 = 0, curval = -1, carryover = 0;
	ListNode *temp, *dummy = new ListNode(-1);
	ListNode *p=new ListNode(-1);

	val1 = nthToLast(l1, k);
	val2 = nthToLast(l2, k);


	while (val1 != -1 && val2 != -1) {
		curval = val1 + val2 + carryover;
		if (curval >= 10) {
			carryover = 1;
			curval -= 10;
		}
		else
			carryover = 0;

		temp = new ListNode(curval);
		if (dummy->next == NULL) {// first node
			dummy->next = temp;
			p = temp;
		}
		else {
			dummy->next = temp;
			temp->next = p;
			p = temp;
		}
		k++;
		val1 = nthToLast(l1, k);
		val2 = nthToLast(l2, k);
	}

	if (val1 == -1) { // l1 is done
		if (val2 == -1) { // l2 is done
			if (carryover == 1) {
				temp = new ListNode(1);
				dummy->next = temp;
				temp->next = p;
				p = temp;
			}
		}
		else {// l2 is not done
			while (val2 != -1) {
				curval = val2 + carryover;
				if (curval >= 10) {
					carryover = 1;
					curval -= 10;
				}
				else
					carryover = 0;

				temp = new ListNode(curval);

				dummy->next = temp;
				temp->next = p;
				p = temp;

				k++;
				val2 = nthToLast(l2, k);
			}
		}

	}
	else { // l1 is not done
		while (val1 != -1) {
			curval = val1 + carryover;
			if (curval >= 10) {
				carryover = 1;
				curval -= 10;
			}
			else
				carryover = 0;

			temp = new ListNode(curval);

			dummy->next = temp;
			temp->next = p;
			p = temp;

			k++;
			val1 = nthToLast(l1, k);
		}
	}

	return dummy->next;
}
