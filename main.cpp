#include <iostream>
#include <cstdlib>
#include "linkedList.h"
using namespace std;
//********************************************************************************
//********************************************************************************
void options(){
    system("clear");

    cout<<"1. Add new element"<<endl;
    cout<<"2. Add next to element"<<endl;
    cout<<"3. Edit element"<<endl;
    cout<<"4. Erase element"<<endl;
    cout<<"5. Show content"<<endl;
    cout<<"6. Exit"<<endl;
}
//********************************************************************************
bool add(LinkedList<std::string> &origin){
    system("clear");
    bool out;
    std::string data;
    cout<<"\nType your data: ";
    cin>>data;

    out = origin.addNew(data);
    return out;
}
//********************************************************************************
bool addNextTo(LinkedList<std::string> &origin){
    system("clear");
    bool out;
    int realTarget;
    std::string target;
    std::string data;

    while(true){
        cout<<"\nType your target: ";
        cin>>target;

        realTarget = atoi(target.c_str());
        if(realTarget != 0)
            break;
    }
    
    cout<<"\nType your data: ";
    cin>>data;

    out = origin.addNextTo(realTarget, data);
    return out;
}
//********************************************************************************
bool edit(LinkedList<std::string> &origin){
    system("clear");
    bool out;
    int realTarget;
    std::string target;
    std::string data;

    while(true){
        cout<<"\nType your target: ";
        cin>>target;

        realTarget = atoi(target.c_str());
        if(realTarget != 0)
            break;
    }
    
    cout<<"\nType your data: ";
    cin>>data;

    out = origin.edit(realTarget, data);
    return out;
}
//********************************************************************************
bool erase(LinkedList<std::string> &origin){
    system("clear");
    bool out;
    int realTarget;
    std::string target;

    while(true){
        cout<<"\nType your target: ";
        cin>>target;

        realTarget = atoi(target.c_str());
        if(realTarget != 0)
            break;
    }

    out = origin.erase(realTarget);
    return out;
}
//********************************************************************************
int main(){
    // Set up
    LinkedList<std::string> myList;
    std::string option;
    bool stat = true;
    bool out = true;

    // LinkedList class implementation
    while(stat){
        options();        
        cout<<"\n>> ";
        cin>>option;

        switch(atoi(option.c_str())){
            case 1:
                out = add(myList);
                break;
            case 2:
                out = addNextTo(myList);
                break;
            case 3:
                out = edit(myList);
                break;
            case 4:
                out = erase(myList);
                break;
            case 5:
                cout<<endl;
                myList.show();
                break;
            case 6:
                stat = false;
                break;
            default:
                break;
    }
    
    (out)?cout<<"\nSuccess\n":cout<<"\nFailed\n";
    //cout<<"\nPress Enter to continue...\n";
    cin.ignore();
    cin.get();
    }
    
return 0;
}
//********************************************************************************
//********************************************************************************