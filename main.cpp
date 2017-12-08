//Author: Yousif.dafalla
//Author: Class
//11/26/17
#include <cstdlib>
#include <iostream>
#include"Grid.h"
#include "Boulder.h"

using namespace std;

int main(int argc, char *argv[])
{
    Grid game = Grid(6,7);
    Boulder b;
    bool in, won;
    string str;
=======
    bool in, won = false;
>>>>>>> e6d91e177333500e28368474f038e50590c80dc6
    int col, at, bt;
    at = bt = 0;
    cout <<game.view();
    do
    {
         cout <<"Player A, enter a column: "
			  <<"You have " << bt << " points to spend!" << endl;
         cin >> col;
         cin >> str;
         if (str == "boulder")
         	b.use(&game);
         in = game.insert('A', col);  
         if (!in)
         	continue;
         cout <<game.view();
         at = at + game.win('A');
         system("CLS");
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
	             cout <<"Player B, enter a column... "
				 	  <<"You have " << bt << " points to spend!" << endl;
	             cin >> col;
	             in = game.insert('B', col);
	         }while(!in);
             system("CLS");
             cout <<game.view();
             bt = bt + game.win('B');
             if (won)
                cout <<"Player B won!\n";
             else
             {	 
             	system("CLS");
<<<<<<< HEAD
=======
    	 		cout << "Player A has " << at << " points." << endl
    	 	  		 << "Player B has " << bt << " points." << endl
    	 	  		 << "DON't hit enter" << endl;
    	 		Sleep(2000);
                 system("CLS");
>>>>>>> e6d91e177333500e28368474f038e50590c80dc6
                 cout <<game.view();
             }
         }
         
         
    }while(!won);
    
    if (!in)
       cout <<"Game ended after column was filled!\n";

    system("PAUSE");
    return EXIT_SUCCESS;
}
