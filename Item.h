//boulder.h

#include <string>
#include <iostream>
#ifndef ITEM_H
#define ITEM_H
#include "Grid.h"

using namespace std;

class Item {
	public:
		Item(int price, string des){
			this -> price = price;
			this -> des = des;
		};
		virtual void use(Grid* g){
			cout << "Item used!" << endl;
		};
		int getPrice(){
			return price;
		};
		string getDes(){
			return des;
		}
	private:
		int price;
		string des;
};

#endif
