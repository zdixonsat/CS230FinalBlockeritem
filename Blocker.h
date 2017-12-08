//this is MorphItem header file and implementation
#include <string>
#ifndef BLOCKER_H
#define BLOCKER_H
#include "Item.h"
#include "Grid.h"
using namespace std;

class Blocker: public Item //functions inside Item parent class are shared
{
public:
       Blocker(): Item(2,"this is item allows players to block columns off from being used"){};
       
	       void use(Grid *g)//this class's own version of the use() declared by Item class
		   {	
				system("CLS");
				int b;
				cout << g->view();
				cout << "What column do you want to block > ";
				cin >> b;
				system("CLS");
				g->block(b);
	       };
      
      
      
};

#endif
