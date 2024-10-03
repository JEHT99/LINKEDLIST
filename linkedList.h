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
    Node(int, string);
    ~Node();
};
//********************************************************************************