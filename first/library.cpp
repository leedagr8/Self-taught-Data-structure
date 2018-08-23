#include <iostream>
#include "library.h"

using namespace std;

library::library(){
	length =0;
	start = null;
}

//O(n)
void library::MakeEmpty(){

	node* temp = new node;

	while(start != null){
		temp = start; // sets your temporary node to whatever start is
		start = start -> next; // will move your node to the next 
		delete temp; //finally it deletes it
	}
}
//O(1)

//Since this can only be full whenever we run out of memory we need to check and
//make sure there is space for us to continue allocate a new node.
bool library::Isfull const(){

	node* location; //

	try{
		location = new node; // so try to create a new node
		delete location; // Making sure you have room to create a new node.
		return false;
	}

	catch (bad_alloc exception){
		return true;
	}
}
//O(1)
void library::InsertItem(int item){
	node* temp = new node; //create a temporay node 

	temp -> data = item; // the temporay node will hold the data being passed
	temp -> next = start; // now point the start node to this temp.

	start = temp;

	length++;
}
//O(N)
void library::Show(){
	//using a temp variable to travel my list. Dont want to lose access to my start

	node* temp = start;

	while(temp != null){
		
		cout << temp->data << endl;
		temp = temp -> next;
	}
}

int library::GetLength() const{
	return length;
}

library::~library(){
	MakeEmpty();
}

void library::DeleteItem(int item){
	if (start != null){ //Make sure we even have a list to look through
		//Now creating a first temp pointer that will transverse through the list.
		node* temp = start;
		if(item == start -> data){ //If user wants to delete the first node
			start = start -> next; // The start node goes to the next one
			delete temp; // then delete this item
			length --; // now decrease your length
		}
	}
	else
	{
		while(temp -> next != null && (item != temp -> next -> data)){
			//while the next node does not equal null and the next item
			//is not the target. Traverse through the loop
				temp = temp->next; // now I'm going to go to the next one
	}
	node* target = temp -> next; // you found your target node
	if (target != null){
		temp -> next = target -> next;// change the temp -> next that you're
		//currently on to the target -> next. You want to delete the taret
		//-> next not your temp.
		delete target;
		length --;
	}
}
}