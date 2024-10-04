#include <iostream>
#include "linkedList.h"
using namespace std;

int main(){
    LinkedList *myList = new LinkedList();
    /*myList->addNew("HELLO");
    myList->addNew("HELLO2");
    myList->addNew("HELLO3");
    myList->addNextTo(1,"HELLO 4");
    myList->show();
    cout<<endl;
    myList->edit(0,"NOW IS HELLO 5");
    myList->show();*/

    myList->addNew("1");
    myList->addNew("2");
    myList->addNew("3");
    myList->erase(1);
    myList->addNextTo(1,"4");
    myList->addNew("HELLO2");
    myList->addNew("HELLO3");
    myList->addNextTo(1,"HELLO 4");
    //myList->addNew("2");

    LinkedList *myList2 = new LinkedList(*myList);
    myList->show();
    cout<<endl;
    myList2->show();

}
