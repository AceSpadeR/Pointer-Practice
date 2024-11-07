#include <iostream>
#include <string>
using namespace std;

template <class Type>
struct Node
{
    Type data;
    Node *next;
};

template <class Type>
class list;

template <class Type>
ostream &operator<<(ostream &, const list<Type> &);

template <class Type>
class list {
    private: 
    Node<Type> *top;
    Node<Type> *current;
    Node<Type>* getMiddle(Node<Type>* head);
    Node<Type>* merge(Node<Type>* left, Node<Type>* right);
    Node<Type>* mergeSort(Node<Type>* head);

    public:
    list();
    list(const list<Type> &other);    
    ~list();

    void push(Type data);
    void deleteAll();
    void swap();
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    void mergeSort();
    list<Type> createTempList();

    bool isEmpty();
    friend ostream &operator<< <>(ostream &, const list<Type> &);
};

template <class Type> 
list<Type>::list(){
    top = nullptr;
}


template <class Type>
list<Type>::~list(){
    if(top != nullptr){
        deleteAll();
    }
}

template <class Type>
list<Type>::list(const list<Type> &other) {
    top = nullptr;
    if (other.top != nullptr) {
        top = new Node<Type>;
        top->data = other.top->data;
        Node<Type> *currentOther = other.top->next;
        Node<Type> *currentThis = top;
        while (currentOther != nullptr) {
            currentThis->next = new Node<Type>;
            currentThis = currentThis->next;
            currentThis->data = currentOther->data;
            currentOther = currentOther->next;
        }
        currentThis->next = nullptr;
    }
}

template <class Type>
void list<Type>::push(Type data){
    Node<Type> *toAdd = new Node<Type>;
    toAdd->data = data;
    if (top == nullptr) {
        top = toAdd;
        toAdd->next = nullptr;
    }
    else {
        toAdd->next = top;
        top = toAdd;
    }
}

template <class Type>
void list<Type>::deleteAll(){
    while(!isEmpty()){
        Node<Type> *toDelete = top;
        top = top->next;
        delete toDelete;
    }
}

template <class Type>
void list<Type>::swap()
{
    Type temp = current->data;
    current->data = current->next->data;
    current->next->data = temp;
}

template <class Type>
bool list<Type>::isEmpty(){
    return top == nullptr;
}

template <class Type>
list<Type> list<Type>::createTempList() {
    return list<Type>(*this);
}

template <class Type>
void list<Type>::bubbleSort(){
    if(!isEmpty()){
        bool changed;
        do
        {
            changed = false;
            current = top;
            while (current->next != nullptr)
            {
                if(current->data > current->next->data){
                    swap();
                    changed = true;
                }
                current = current->next;
            }
        } while (changed);
    }
     current = nullptr;
}

template <class Type>
void list<Type>::selectionSort() {
    if (!isEmpty()) {
        current = top;
        while (current != nullptr) {
            Node<Type>* min = current;
            Node<Type>* nextNode = current->next;
            while (nextNode != nullptr) {
                if (nextNode->data < min->data) {
                    min = nextNode;
                }
                nextNode = nextNode->next;
            }
            if (min != current) {
                Type temp = current->data;
                current->data = min->data;
                min->data = temp;
            }
            current = current->next;
        }
    }
     current = nullptr;
}

template <class Type>
void list<Type>::insertionSort() {
    if (!isEmpty()) {
        Node<Type>* sorted = nullptr;
        current = top;
        while (current != nullptr) {
            Node<Type>* next = current->next;
            if (sorted == nullptr || sorted->data >= current->data) {
                current->next = sorted;
                sorted = current;
            } else {
                Node<Type>* temp = sorted;
                while (temp->next != nullptr && temp->next->data < current->data) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
        top = sorted;
    }
     current = nullptr;
}

template <class Type>
Node<Type>* list<Type>::getMiddle(Node<Type>* head) {
    if (head == nullptr) return head;
    Node<Type>* slow = head;
    Node<Type>* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template <class Type>
Node<Type>* list<Type>::merge(Node<Type>* left, Node<Type>* right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;
    if (left->data < right->data) {
        left->next = merge(left->next, right);
        return left;
    } else {
        right->next = merge(left, right->next);
        return right;
    }
}

template <class Type>
Node<Type>* list<Type>::mergeSort(Node<Type>* head) {
    if (head == nullptr || head->next == nullptr) return head;
    Node<Type>* middle = getMiddle(head);
    Node<Type>* nextToMiddle = middle->next;
    middle->next = nullptr;
    Node<Type>* left = mergeSort(head);
    Node<Type>* right = mergeSort(nextToMiddle);
    return merge(left, right);
}

template <class Type>
void list<Type>::mergeSort() {
    top = mergeSort(top);
}



template <class Type>
ostream &operator<<(ostream &out, const list<Type> &list){
    Node<Type> *currentNode = list.top;
    int count= 0;
    while(currentNode != nullptr){
        count++;
        //out << currentNode->data << " ";
        currentNode = currentNode->next;
    }
    out << count;
    return out;
}
