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
        Node *searchNode(int);
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