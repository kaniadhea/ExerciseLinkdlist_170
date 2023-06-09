#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void dhea();
	bool search(int rollno, Node** kania, Node** dhea);
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::dhea() { //write your answer here
}
bool CircularLinkedList::search(int rollno, Node** kania, Node** dhea) {
	*kania = LAST->next;
	*dhea = LAST->next;
	while (*dhea != LAST) {
		if (rollno == (*dhea)->rollNumber) {
			return true;
		}
		*kania = *dhea;
		*dhea = (*dhea)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		Node* dhea = LAST->next;
		LAST->next = dhea;
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

//menghapus dhea//
bool CircularLinkedList::delNode() { 

}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.dhea();
				break;
			}
			case '2': {
				obj.delNode();
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}