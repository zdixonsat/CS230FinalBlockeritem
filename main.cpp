//Author: Class
//11/26/17
#include <cstdlib>
#include <iostream>
#include <string>
#include"Grid.h"
#include "Boulder.h"
#include "Blocker.h"

using namespace std;

Grid game = Grid(6,7);
Boulder b;
Blocker blocker;

int storeMenu(){
	int choice;
	system("CLS");
	cout << "     Item Shop:" << endl
		 << "====================" << endl
		 << "1) Boulder" << endl
		 << "     Price: " << b.getPrice() << endl
		 << "     Description: " << b.getDes() << endl
		 << "2) Missile" << endl
		 << "     Price: " << endl    
		 << "     Description: " << endl    
		 << "3) Swap" << endl
		 << "     Price: " << endl
		 << "     Description: " << endl
		<< "4) Blocker" << endl
		 << "     Price: " << blocker.getPrice() << endl
		 << "     Description: " << blocker.getDes() << endl
		 << endl 
		 << "Enter your choice > ";
	cin >> choice;
	return choice;
}

int store(int tot){
	int choice;
	choice = storeMenu();
	switch (choice){
		case 1: 
			//call boulder
			if (tot - b.getPrice() >= 0){
				b.use(&game);
				tot -= b.getPrice();
			} else {
				cout << "Not enough points!" << endl;
				Sleep(1000);
				system("CLS");
			}
			break;
		case 2:
			//call missile
			break;
		case 3:
			//call swap
			break;
		case 4: 
			//call blocker
			if (tot - blocker.getPrice() >= 0){
				blocker.use(&game);
				tot -= blocker.getPrice();
			}else{
				cout << "Not enough points!" << endl;
				Sleep(1000);
				system("CLS");
			}
			break;
		default:
			break;
	}
	cout << "Thank you and come again!" << endl;
	system("PAUSE");
	system("CLS");
	return tot;
}

int main()
{
    bool in, won = false;
    int at, bt;
    string choice;
    at = bt = 0;
    cout <<game.view();
    do
    {
         cout << "Player A: You have " << at << " points to spend!" << endl
		 	  << "Enter 'store' or a column number > ";
         cin >> choice;
         while (choice == "store"){
         	at = store(at);
         	cout << game.view();
         	cout << "Player A: You have " << at << " points to spend!" << endl
		 	     << "Enter 'store' or a column number > ";
         	cin >> choice;
		 }
         in = game.insert('A', atoi(choice.c_str()));  
         if (!in)
         	continue;
         cout <<game.view();
         at = at + game.win('A');
         system("CLS");
         //WIN CHECK
         if (at >= 5)
         	won = true;
         if (won)
         {
            cout <<game.view();
            cout <<"Player A won!\n";
         }
         else
         {
             cout <<game.view();
             do
             {
	            cout << "Player B: You have " << bt << " points to spend!" << endl
		 			 << "Enter 'store' or a column number > ";
         		cin >> choice;
         		while (choice == "store"){
         			bt = store(bt);
         			cout << "Player B: You have " << bt << " points to spend!" << endl
		 	     		 << "Enter 'store' or a column number > ";
         			cin >> choice;
		 		}
	            in = game.insert('B', atoi(choice.c_str()));
	         }while(!in);
             system("CLS");
             cout <<game.view();
             bt = bt + game.win('B');
            //WIN CHECK
            if (at >= 5)
         		won = true;
             if (won)
                cout <<"Player B won!\n";
             else
             {
                 system("CLS");
                 cout <<game.view();
             }
         }
         
         
    }while(!won);
    
    if (!in)
       cout <<"Game ended after column was filled!\n";

    system("PAUSE");
    return EXIT_SUCCESS;
}
