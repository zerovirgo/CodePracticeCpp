#include <iostream>
// cradit : http://www.sourcetricks.com/2008/07/c-singly-linked-lists.html#.VsHsOPl96Uk
using namespace std;

// Node class
class Node{
    int data;
    Node* next;

    public:
    Node() {};
    void SetData(int aData) { data = aData ; };
    void SetNext(Node* aNext) { next = aNext; };
    int Data() { return data; };
    Node* Next() { return next; };
};

// List class
class List{
    Node *head;
    public:
        List() { head = NULL ; };
        void Print();
        void PrintPointer();
        void Append(int data);
        void Delete(int data);
};

/*
    Print the contents of the list
*/

void List::Print(){
    // Temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL ) {
        cout << "This node is empty!!" << endl;
        return ;
    }

    // One node in the list
    if ( tmp->Next() == NULL ) {
        cout << tmp->Data() ;
        cout << " --> " ;
        cout << "NULL" << endl ;
    }
    else {
        do {
            cout << tmp->Data() ;
            cout << " --> " ;
            tmp = tmp->Next();
        }
        while (tmp != NULL );
        cout << "NULL" << endl ;
    }
}

/*
    Print the pointers of the list
*/

void List::PrintPointer(){
    // Temp pointer
    Node *tmp = head;

    // No nodes
    if ( tmp == NULL ) {
        cout << "This node is empty!!" << endl;
        return ;
    }

    // One node in the list
    if ( tmp->Next() == NULL ) {
        cout << tmp ;
        cout << " --> " ;
        cout << "NULL" << endl ;
    }
    else {
        do {
            cout << tmp ;
            cout << " --> " ;
            tmp = tmp->Next();
        }
        while (tmp != NULL );
        cout << "NULL" << endl ;
    }
}
/*
    Append a node to the linked list
 */
void List::Append(int data){
    // Create a new node
    Node* newNode = new Node();
    newNode->SetData(data);
    newNode->SetNext(NULL);

    // Create a temp pointer
    Node *tmp = head ;
    if ( tmp != NULL ) {
        // Nodes already present in the list
        // Parse to end of list
        while ( tmp->Next() != NULL ){
            tmp = tmp->Next();
        }

        // Point the last node to the new node
        tmp->SetNext(newNode);
    }
    else {
        // First node in the list
        head = newNode;
    }
}

/*
    Append a node to the linked list
 */
void List::Delete(int data){

    // Create a temp pointer
    Node *tmp = head ;
    
    // No nodes
    if ( tmp == NULL) // do nothing
        return ;
        
    // Last node of the list
    if ( tmp->Next() == NULL ) {
        delete tmp;
        head = NULL ;
    }
    else {
        // Parse thru the nodes
        Node *prev;
        do {
            cout << "try to find " << data << " for  " << tmp->Data();
            cout << " with pointer " << tmp <<  endl ;
            if ( tmp->Data() == data) break ;
            prev = tmp ;
            tmp = tmp->Next();
        } while ( tmp != NULL) ;

        // Adjust the pointerss, or we say: bridge the 
        // breaking chain
        prev->SetNext(tmp->Next());

        // Delete the current node
        delete tmp ;
    }
}

int main()
{
    // New list
    List list;

    // Append nodes to the list
    list.Append(100);
    list.Print();
    list.Append(200);
    list.Print();
    list.Append(300);
    list.Print();
    list.Append(400);
    list.Print();
    list.Append(500);
    list.Print();
    list.PrintPointer();

    // Delete nodes from the list
    list.Delete(400);
    list.Print();
    list.Delete(300);
    list.Print();
    list.Delete(200);
    list.Print();
    list.Delete(500);
    list.Print();
    list.Delete(100);
    list.Print();
}
