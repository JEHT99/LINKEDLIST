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