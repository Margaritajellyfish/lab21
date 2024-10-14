#include <iostream>
#include <ctime>
using namespace std;

class Goat{
private:
    struct Node {
        int age;
        string name;
        string color;
        string names[15] = {"Alice", "Bob", "Charlie", "David", "Eva", "Fiona", "George", "Hannah", "Isaac", "Julia", "Kevin", "Lily", "Mason", "Nina", "Oliver"};
        string colors[15] = {"Red", "Blue", "Green", "Yellow", "Purple", "Orange", "Pink", "Black", "White", "Gray", "Teal", "Magenta", "Cyan", "Brown", "Lavender"};

        Node* prev = nullptr;
        Node* next = nullptr;
        

    };

    Node* head;
    Node* tail;

public:
    // constructor
    Goat(int a, string n, string c) {
            age = a; 
            name =n;
            color = c;
        }
        Goat(){
        
            age = rand()%15;
            name = names[rand()%15];
            color = colors[rand()%15];

        }
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(Goat goat) {
        Node* newNode = new Node(goat);
        if (!tail)  // if there's no tail, the list is empty
            head = tail = newNode;
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat goat) {
        Node* newNode = new Goat(gaot);
        if (!head)  // if there's no head, the list is empty
            head = tail = newNode;
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insert_after(int value, int position) {
        if (position < 0) {
            cout << "Position must be >= 0." << endl;
            return;
        }

        Node* newNode = new Goat(value);
        if (!head) {
            head = tail = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position && temp; ++i)
            temp = temp->next;

        if (!temp) {
            cout << "Position exceeds list size. Node not inserted.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next)
            temp->next->prev = newNode;
        else
            tail = newNode; // Inserting at the end
        temp->next = newNode;
    }

    void delete_node(int value) {
        if (!head) return; // Empty list

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) return; // Value not found

        if (temp->prev) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next; // Deleting the head
        }

        if (temp->next) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev; // Deleting the tail
        }

        delete temp;
    }

    void print() {
        Node* current = head;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() {
        Node* current = tail;
        if (!current) return;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() {
    srand(time(0));
    DoublyLinkedList list;
    int size = rand() % (20-5+1) + 5;

    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (20-5+1) + 5);
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}
