//this is MorphItem header file and implementation
#include "Item.h"
#include "Grid.h"
using namespace std;

class Blocker: public Item //functions inside Item parent class are shared
{
public:
       Blocker(): Item(2,"this is item allows players to change opposing players marker into their own"){};
       
       void use(Grid *g)//this class's own version of the use() declared by Item class
       {
       string block = "X";
       //insert blockers vertically
       
       
       
       
       };
      
      
      
};
