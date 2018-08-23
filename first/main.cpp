#include "library.h"

#include <iostream>

using namespace std;

//Linked LIST implementation

int main(){

library lib;

lib.InsertItem(4);
lib.InsertItem(7);
lib.InsertItem(23);
lib.InsertItem(8);

cout << "length: " <<lib.Getlength() << endl;

lib.DeleteItem(8);


lib.Show();
	return 0;
}