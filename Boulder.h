//item.h

#include <string>
#ifndef BOULDER_H
#define BOULDER_H
#include "Item.h"
#include "Grid.h"

using namespace std;

class Boulder : public Item {
	public:
		Boulder() : Item(2, "The boulder is used to clear an entire column."){};
		void use(Grid* g){
			cout << "What column would you let to smash > ";
			int i;
			cin >> i;
			g -> clear(i);
		};
};

#endif
