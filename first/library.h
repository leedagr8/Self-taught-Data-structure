#include "node.h"
class library{

private:
int length;
node* start; 

public:
	library();
	void MakeEmpty();
	bool IsFull() const;
	int Getlength() const;
	void InsertItem(int item);
	void DeleteItem(int item); 
	void Show();
	~library();

};