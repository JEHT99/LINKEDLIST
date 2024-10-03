#include <string>
using namespace std;
//********************************************************************************
class Node{
    private:
        Node *last;
        int id;
        string data;
        Node *next;
    public:
        Node::Node(int, string);
        Node::~Node();
        friend class LinkedList;
};
//********************************************************************************
//********************************************************************************
Node::Node(int nodeId, string nodeData){
    last = nullptr;
    id = nodeId;
    data = nodeData;
    next = nullptr;
}
//********************************************************************************
Node::~Node(){}
//********************************************************************************
//********************************************************************************
class LinkedList{
    private:
        int counter;
        Node *head;
        Node *tail;
    protected:
        Node *search(int target);
        bool isEmpty();
        void clearList();
    public:
        LinkedList();
        ~LinkedList();
        bool addNew(string data);
        bool addNextTo(int target, string data);
        bool edit(int target, string data);
        bool delete(int target);
        void show();
};
//********************************************************************************
//********************************************************************************
LinkedList::LinkedList(){
    counter = 0;
    head = nullptr;
    tail = nullptr;
}
//********************************************************************************
LinkedList::~LinkedList(){
    clearList();
}
//********************************************************************************
Node* LinkedList::search(int target){
    if(isEmpty())
        return nullptr;

    Node *currentNode = head;
    while(currentNode != nullptr){
        if(currentNode->id == target)
            break;
        currentNode = currentNode->next;
    }

    return currentNode;
}
//********************************************************************************
bool LinkedList::isEmpty(){
    return (head == nullptr)?true:false;
}
//********************************************************************************
void LinkedList::clearList(){
    Node *currentNode = tail;
    Node *lastNode = nullptr;

    while(currentNode != nullptr){
        lastNode = currentNode;
        currentNode = currentNode->last;
        delete lastNode;
    }
}
//********************************************************************************
void LinkedList::show(){
    Node *currentNode = head;

    while(currentNode != nullptr){
        cout<<currentNode->id<<" | "<<currentNode->data<<endl;
        currentNode = currentNode->next;
    }
}
//********************************************************************************
bool LinkedList::addNew(string data){
    Node *newNode = new Node(counter, data);

    if(newNode == nullptr)
        return false;

    if(isEmpty()){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        newNode->last = tail;
        tail = newNode;
    }

    counter++;
    return true;
}
//********************************************************************************
