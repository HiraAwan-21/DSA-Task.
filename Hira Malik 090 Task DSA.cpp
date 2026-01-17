#include <iostream>
using namespace std;
struct Node{
    string task;
    int done;        
    Node* link;
};
class List{
private:
    Node* start;
public:
    List(){
        start = NULL;
    }
    void addTask()
    {
        Node* cur = new Node;
        cout << "Enter task: ";
        cin >> cur->task;
        cur->done = 0;
        cur->link = NULL;

        if (start == NULL){
            start = cur;
        }
        else{
            Node* temp = start;
            while (temp->link != NULL)
                temp = temp->link;
            temp->link = cur;
        }
        cout << "Task added"<<endl;
    }
    void display(){
        if (start == NULL){
            cout << "No tasks available"<<endl;
            return;
        }
        Node* temp = start;
        int i = 1;
        while (temp != NULL){
            cout << i << ". " << temp->task;
            if (temp->done == 1)
                cout << "Completed";
            cout << endl;
            temp = temp->link;
            i++;
        }
    }
    void markDone(){
        int pos, i = 1;
        cout << "Enter position: ";
        cin >> pos;
        Node* temp = start;
        while (temp != NULL && i < pos){
            temp = temp->link;
            i++;
        }
        if (temp == NULL)
            cout << "Invalid position\n";
        else{
            temp->done = 1;
            cout << "Task marked completed"<<endl;
        }
    }
    void deleteTask(){
        int pos;
        cout << "Enter position: ";
        cin >> pos;
        if (start == NULL){
            cout << "List empty"<<endl;
            return;
        }
        if (pos == 1){
            Node* temp = start;
            start = start->link;
            delete temp;
            cout << "Task deleted"<<endl;
            return;
        }

        Node* cur = start;
        Node* temp = NULL;
        int i = 1;
        while (cur != NULL && i < pos){
            temp = cur;
            cur = cur->link;
            i++;
        }

        if (cur == NULL)
            cout << "Invalid position"<<endl;
        else{
            temp->link = cur->link;
            delete cur;
            cout << "Task deleted"<<endl;
        }
    }
    void updateTask(){
        int pos, i = 1;
        cout << "Enter position: ";
        cin >> pos;
        Node* temp = start;
        while (temp != NULL && i < pos){
            temp = temp->link;
            i++;
        }
        if (temp == NULL)
            cout << "Invalid position\n";
        else{
            cout << "Enter new task: ";
            cin >> temp->task;
            cout << "Task updated"<<endl;
        }
    }
    void searchTask(){
        string key;
        cout << "Enter task to search: ";
        cin >> key;
        Node* temp = start;
        int pos = 1;
        while (temp != NULL){
            if (temp->task == key){
                cout << "Task found at position " << pos << endl;
                return;
            }
            temp = temp->link;
            pos++;
        }
        cout << "Task not found"<<endl;
    }
};

int main()
{
    List t;
    int choice;
    cout << "\n1.Add\n2.Display\n3.Mark Done\n4.Delete\n5.Update\n6.Search\n7.Exit\n";
    do{
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice){
        case 1: t.addTask(); break;
        case 2: t.display(); break;
        case 3: t.markDone(); break;
        case 4: t.deleteTask(); break;
        case 5: t.updateTask(); break;
        case 6: t.searchTask(); break;
        case 7: cout << "Exit\n"; break;
        default: cout << "Invalid choice"<<endl;
        }
    }
	while (choice != 7);

    return 0;
}
