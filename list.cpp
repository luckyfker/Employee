#include "list.h"

Node::Node(Employee *e) 
{
    // TODO
    emp = e;
    next = NULL;
}
Node::Node() 
{
    // TODO
    emp = NULL;
    next = NULL;
}
Node::~Node() 
{
    cout << "delete [" << emp->getID() << "]" << endl;
    if (next != NULL) {
    	delete next;
	}
	if (emp != NULL) {
		delete emp;
	}
    // TODO: delete next if next != NULL
}

LList::LList()
{
	head = NULL;
    // TODO
}
bool LList::isEmpty() const 
{
	return head == NULL ? true : false;
    // TODO
}
void LList::insert(Employee *e)
{
    // TODO
    // create a new Node n with key
    Node* n = new Node(e);

    // if empty list then head = n
    if (isEmpty()) {
    	head = n;
	} else { // else get last Node m, assign next of m to n
		Node *m = last();
		m->next = n;
	}
}

Node* LList::remove()
{
    // if 0 element
    if (isEmpty()) throw "Error: Delete empty list!";
    // if 1 element
    if (head->next == NULL)
    {
        Node *n = head;
        head = NULL;
        return n;
    }
    // more than 1 element
    // find n - the node before the last
    Node *n = head;
    while (n->next->next != NULL) n = n->next;

    // TODO: release the last node m from n
    Node *m = n->next;
    n->next = NULL;
    return m;
}

Node* LList::last() const
{
    // TODO:
    // throw error if list is empty
    if (isEmpty()) throw "List is empty!";

    Node *n = head;
    // loop until n->next == NULL then return n
    while (n->next != NULL) n = n->next;
    return n;
}

void LList::print() const 
{
    // if empty, print []
    if (isEmpty()) cout << "[]" << endl;
    else {
    	Node *n = head;
    // TODO: print n->key, loop until n->next == NULL
	    while (n != NULL) {
	    	cout << "[" << n->emp->getID() << "]" << "->";
			n = n->next; 
		}
	}
	//cout << "[]" << endl;
    
    // Output should be something like this: [1]->[2]->[5]->[]
}

void LList::remove(int id)
{
	if (isEmpty()) {
		//return;
		throw "List is empty!";
		return;
	}
	Node *n = head;
	
	//Delete first element
	if (head->emp->getID() == id) {
		cout << "Found!" << endl;
		head = head->next;
		return;
	}
	
	while (n->next != NULL) {
		if (n->next->emp->getID() == id) {
			cout << "Found!" << endl;
			break;
		}
		n = n->next;
	}
	if (n->next == NULL)
	{
		throw "Throw Not found id";
		return;
	}
	n->next = n->next->next;
}

Node* LList::search(string name)
{
	Node *n = head;
	while (n != NULL) {
		if (n->emp->getName() == name) {
			return n;
		}
		n = n->next;
	}
	throw "Not found name";
}

Node* LList::search(int id)
{
	Node *n = head;
	while (n != NULL) {
		if (n->emp->getID() == id) {
			return n;
		}
		n = n->next;
	}
	cout << "Not found ID: " << id << endl;
	throw "Not found id";
}

LList::~LList()
{
    // delete head if it is not NULL then set head to NULL
    if (head->next != NULL) {
    	delete head;
    	head->next = NULL;
	}
}

