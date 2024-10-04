//********************************************************************************
//********************************************************************************
template <class T>
class LinkedList;

template <class T>
class Node{
    private:
        Node<T> *last;
        int id;
        T data;
        Node<T> *next;
    public:
        Node(int nodeId, T nodeData);
        friend class LinkedList<T>;
};
//********************************************************************************
//********************************************************************************
template <class T>
class LinkedList {
    private:
        int counter;
        Node<T> *head;
        Node<T> *tail; 
    protected:
        Node<T> *search(int target);
        bool isEmpty();
        void clearList();
    public:
        LinkedList();
        LinkedList(const LinkedList<T> &);
        ~LinkedList();
        bool addNew(T data);
        bool addNextTo(int target, T data);
        bool edit(int target, T data);
        bool erase(int target);
        void show();
};
//********************************************************************************
//********************************************************************************
template <class T>
Node<T>::Node(int nodeId, T nodeData){
    last = nullptr;
    id = nodeId;
    data = nodeData;
    next = nullptr;
}
//********************************************************************************
//********************************************************************************
template <class T>
LinkedList<T>::LinkedList(){
    counter = 0;
    head = nullptr;
    tail = nullptr;
}
//********************************************************************************
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &main){
    counter = 0;
    head = nullptr;
    tail = nullptr;

    Node<T> *currentNode = main.head;
    while(currentNode != nullptr){
        if(addNew(currentNode->data) == false){
            clearList();
            break;
        }
        currentNode = currentNode->next;
    }
}
//********************************************************************************
template <class T>
LinkedList<T>::~LinkedList(){
    clearList();
}
//********************************************************************************
template <class T>
Node<T>* LinkedList<T>::search(int target){ 
    if (isEmpty())
        return nullptr;

    Node<T> *currentNode = head;
    while(currentNode != nullptr){
        if(currentNode->id == target)
            break;
        currentNode = currentNode->next;
    }

    return currentNode;
}
//********************************************************************************
template <class T>
bool LinkedList<T>::isEmpty(){
    return(head == nullptr)?true:false;
}
//********************************************************************************
template <class T>
void LinkedList<T>::clearList(){
    Node<T> *currentNode = tail;
    Node<T> *lastNode = nullptr;

    while(currentNode != nullptr){
        lastNode = currentNode;
        currentNode = currentNode->last;
        delete lastNode;
    }
}
//********************************************************************************
template <class T>
void LinkedList<T>::show(){
    Node<T> *currentNode = head;

    while(currentNode != nullptr){
        std::cout<<currentNode->id<<" | "<<currentNode->data<<std::endl;
        currentNode = currentNode->next;
    }
}
//********************************************************************************
template <class T>
bool LinkedList<T>::addNew(T data){
    Node<T> *newNode = new Node<T>(counter, data);

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
template <class T>
bool LinkedList<T>::addNextTo(int target, T data){
    Node<T> *newNode = new Node<T>(counter, data);
    Node<T> *targetNode = search(target);

    if(newNode == nullptr || targetNode == nullptr)
        return false;

    if(targetNode == tail){
        targetNode->next = newNode;
        newNode->last = targetNode;
        tail = newNode;
    }
    else{
        newNode->next = targetNode->next;
        newNode->last = targetNode;
        targetNode->next->last = newNode;
        targetNode->next = newNode;
    }

    counter++;
    return true;
}
//********************************************************************************
template <class T>
bool LinkedList<T>::edit(int target, T data){
    Node<T> *targetNode = search(target);

    if(targetNode == nullptr)
        return false;

    targetNode->data = data;
    return true;
}
//********************************************************************************
template <class T>
bool LinkedList<T>::erase(int target) {
    Node<T> *targetNode = search(target);

    if(targetNode == nullptr)
        return false;

    // Unique node
    if(targetNode == head && targetNode == tail){
        head = nullptr;
        tail = nullptr;
        delete targetNode;
        return true;
    }

    // It is the head
    if(targetNode == head){
        head = targetNode->next;
        head->last = nullptr;
        delete targetNode;
        return true;
    }

    // It is the tail
    if(targetNode == tail){
        tail = targetNode->last;
        tail->next = nullptr;
        delete targetNode;
        return true;
    }

    //Between two nodes
    targetNode->last->next = targetNode->next;
    targetNode->next->last = targetNode->last;
    delete targetNode;
    return true;
}
//********************************************************************************