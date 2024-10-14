#include <iostream>
#include <ctime>
using namespace std;

class Goat{
private:
        int age;
        string name;
        string color;
        static string names[15];
        static string colors[15];
        
public:
    // constructor
    Goat(int a, string n, string c) {
            age = a; 
            name =n;
            color = c;
        }
        Goat(){
        
            age = rand()%20 +1;
            name = names[rand()%15];
            color = colors[rand()%15];

        }
         void print(){
        cout << name << "(" << age << " ," << color << ")";
    }
};
string Goat::names[15] = {"Alice", "Bob", "Charlie", "David", "Eva", "Fiona", "George", "Hannah", "Isaac", "Julia", "Kevin", "Lily", "Mason", "Nina", "Oliver"};
string Goat::colors[15] = {"Red", "Blue", "Green", "Yellow", "Purple", "Orange", "Pink", "Black", "White", "Gray", "Teal", "Magenta", "Cyan", "Brown", "Lavender"};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(Goat val, Node* p = nullptr, Node* n = nullptr) : data(val), prev(p), next(n) {}
    };

    Node* head;
    Node* tail;

public:
    // Constructor
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(Goat value) {
        Node* newNode = new Node(value);
        if (!tail)  
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat value) {
        Node* newNode = new Node(value);
        if (!head)  
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        while (current) {
            current->data.print();
            cout << "\n";
            current = current->next;
        }
    
    }

    void print_reverse() {
        if (!tail) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = tail;
        while (current) {
            current->data.print();
            cout << "\n";
            current = current->prev;
        }

    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    srand(time(0));
    DoublyLinkedList list;
    int size = rand() % (20-5+1) + 5;

    for (int i = 0; i < size; ++i)
        list.push_back(Goat());
    cout << "List forward: ";
    list.print();

    cout << "\nList backward: ";
    list.print_reverse();

   
    list.~DoublyLinkedList();


    return 0;
}
