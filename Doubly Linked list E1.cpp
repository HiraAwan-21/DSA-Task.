#include <iostream>
using namespace std;

struct Book {
    string isbn;
    string title;
    string author;
    int year;

    Book* p;
    Book* n;   
};
class Library{
	private:
	Book*start,*cur,*temp;
	public:
	library(){
		Book* start = NULL;
	}
void insert() {
    Book* temp = new Book();
    cout << "Enter ISBN: ";
    cin >> temp->isbn;
    cout << "Enter Title: ";
    cin >> temp->title;
    cout << "Enter Author: ";
    cin >> temp->author;
    cout << "Enter Year: ";
    cin >> temp->year;
    temp->p = NULL;
    temp->n = start;
    if (start != NULL)
        start->p = temp;
    start = temp;

    cout << "Book inserted\n";
}

void search() {
    if (start == NULL) {
        cout << "No books\n";
        return;
    }
    string key;
    cout << "Enter ISBN or Title: ";
    cin >> key;
    Book* cur = start;
    while (cur != NULL) {
        if (cur->isbn == key || cur->title == key) {
            cout << "\nBook Found\n";
            cout << "ISBN: " << cur->isbn << endl;
            cout << "Title: " << cur->title << endl;
            cout << "Author: " << cur->author << endl;
            cout << "Year: " << cur->year << endl;
            return;
        }
        cur = cur->n;
    }
    cout << "Book not found\n";
}
void modify() {
    if (start == NULL) {
        cout << "No books\n";
        return;
    }
    string isbn;
    cout << "Enter ISBN to modify: ";
    cin >> isbn;
    Book* cur = start;
    while (cur != NULL) {
        if (cur->isbn == isbn) {
            cout << "Enter new Title: ";
            cin >> cur->title;
            cout << "Enter new Author: ";
            cin >> cur->author;
            cout << "Enter new Year: ";
            cin >> cur->year;
            cout << "Book updated\n";
            return;
        }
        cur = cur->n;
    }
    cout << "Book not found\n";
}

void display() {
    if (start == NULL) {
        cout << "No books\n";
        return;
    }

    Book* cur = start;
    int i = 0;
    while (cur != NULL) {
        cout << "ISBN: " << cur->isbn << endl;
        cout << "Title: " << cur->title << endl;
        cout << "Author: " << cur->author << endl;
        cout << "Year: " << cur->year << endl;
        i++;
        cur = cur->n;
    }
    cout << "Total Books: " <<i<< endl;
}
};

int main() {
	Library L1;
    int choice;
    do {
        cout << "1. Insert Book"<<endl;
        cout << "2. Search Book"<<endl;
        cout << "3. Modify Book"<<endl;
        cout << "4. Display Books"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter choice:"<<endl;
        cin >> choice;
        switch (choice) {
            case 1:
                L1.insert();
                break;
            case 2:
                L1.search();
                break;
            case 3:
                L1.modify();
                break;
            case 4:
                L1.display();
                break;
            case 5:
                cout << "Program Ended"<<endl;
                break;
            default:
                cout << "Invalid choice"<<endl;
        }

    } while (choice != 5);

    return 0;
}
