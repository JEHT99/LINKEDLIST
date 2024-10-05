#include <iostream>
#include <cstdlib>
#include "linkedList.h"
using namespace std;

int main(){
    LinkedList<std::string> myList;
    std::string option;

    bool stat = true;
    while(stat){
        system("clear");

        cout<<"1. Add new element"<<endl;
        cout<<"2. Add next to element"<<endl;
        cout<<"3. Edit element"<<endl;
        cout<<"4. Erase element"<<endl;
        cout<<"5. Show content"<<endl;
        cout<<"6. Exit"<<endl;
        
        cout<<"\n>>";
        cin>>option;

        switch(atoi(option.c_str())){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                stat = false;
                break;
            default:
                cout<<"\nBad input"<<endl;
                break;
        }

    cout<<"\nPress Enter to continue...";
    cin.ignore();
    cin.get();
    }
    
return 0;
}
