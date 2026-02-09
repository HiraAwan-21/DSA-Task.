#include<iostream>
using namespace std;

struct Song
{
    int id;
    string title;
    string artist;
    int duration;
    Song* n;
    Song* p;
};

class Playlist
{
private:
    Song* start;
    Song* last;
    Song* node;
    Song* cur;

public:
    Playlist()
    {
        start=NULL;
        last=NULL;
        node=NULL;
        cur=NULL;
    }

    void insert()
    {
    	cout<<"Enter song ID"<<endl;
        node=new Song;
        cin>>node->id;
        cout<<"Enter song name"<<endl;
        cin>>node->title;
        cout<<"Enter Artist Name"<<endl;
        cin>>node->artist;
        cout<<"Enter duration"<<endl;
        cin>>node->duration;
        node->n=NULL;
        node->p=NULL;

        if(start==NULL)
            start=last=cur=node;
        else
        {
            last->n=node;
            node->p=last;
            last=node;
        }
    }

    void search()
    {
        string key;
        cout<<"Enter song Title or artist to search"<<endl;
        cin>>key;
        node=start;
        while(node!=NULL)
        {
            if(node->title==key || node->artist==key)
            {
                cout<<node->title<<" "<<node->artist<<" "<<node->duration<<endl;
                return;
            }
            node=node->n;
        }
        cout<<"Not found"<<endl;
    }

    void modify()
    {
        int id;
        cout<<"Enter song ID to modify"<<endl;
        cin>>id;
        node=start;
        while(node!=NULL)
        {
            if(node->id==id)
            {
                cin>>node->title;
                cin>>node->artist;
                cin>>node->duration;
                return;
            }
            node=node->n;
        }
        cout<<"Not found"<<endl;
    }

    void display()
    {
        int c=0,sum=0;
        node=start;
        while(node!=NULL)
        {
            cout<<node->id<<" "<<node->title<<" "<<node->artist<<" "<<node->duration<<endl;
            c++;
            sum+=node->duration;
            node=node->n;
        }
        cout<<c<<endl;
        cout<<sum<<endl;
    }

    void playNext()
    {
        if(cur!=NULL && cur->n!=NULL)
        {
            cur=cur->n;
            cout<<cur->title<<endl;
        }
        else
            cout<<"No next"<<endl;
    }

    void playPrevious()
    {
        if(cur!=NULL && cur->p!=NULL)
        {
            cur=cur->p;
            cout<<cur->title<<endl;
        }
        else
            cout<<"No previous"<<endl;
    }
};

int main()
{
    Playlist p;
    int choice;
    do
    {
        cout<<"1 Insert\n2 Search\n3 Modify\n4 Display\n5 Play Next\n6 Play Previous\n0 Exit\n";
        cin>>choice;

        switch(choice)
        {
            case 1: p.insert(); break;
            case 2: p.search(); break;
            case 3: p.modify(); break;
            case 4: p.display(); break;
            case 5: p.playNext(); break;
            case 6: p.playPrevious(); break;
            case 0: break;
            default: cout<<"Invalid\n";
        }
    }while(choice!=0);
}
