#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next = NULL;
    node *pre = NULL;
};
class dbllinkedlist
{
public:
    int n;
    node *head = NULL;
    node *tail = NULL;
    node *temp = NULL;
    node *ptr = NULL;
    node *newNode;
    void creation()
    {
        cout << "How many nodes do you want in doubly linked list" << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            node *newNode = new node;
            if (head == NULL && tail == NULL)
            {
                head = newNode;
                tail = newNode;
            }
            /*          else if (head != NULL && tail == NULL)
                        {
                            head->next = newNode;
                            tail = newNode;
                            tail->pre = head;
                        }
            */
            else
            {
                tail->next = newNode;
                newNode->pre = tail;
                tail = newNode;
            }
        }
        cout << "Your Doubly Linked list is created successfully" << endl;
    }
    void insertion()
    {
        if (head == NULL && tail == NULL)
        {
            cout << "Doubly linked list is empty" << endl;
        }
        else
        {
            int cins;
            cout << "How do you want to perform insertion\n1.from begining\n2.from Ending\n.3.Anywhere in ll" << endl;
            cin >> cins;
            temp = new node;
            if (cins == 1)
            {
                temp->next = head;
                head->pre = temp;
                head = temp;
                cout << "1 node is added in beginning" << endl;
                n += 1;
            }
            else if (cins == 2)
            {
                tail->next = temp;
                temp->pre = tail;
                tail = temp;
                cout << "1 node is added in last" << endl;
                n += 1;
            }
            else if (cins == 3)
            {
                temp = head;
                int m;
                cout << "Which node do you want to add" << endl;
                cin >> m;
                for (int i = 1; i < m; i++)
                {
                    temp = temp->next;
                }
                temp->next = ptr;
                newNode->next = temp->next;
                ptr->pre = newNode;
                newNode->pre = temp;
                temp->next = newNode;
                cout << "1 node is inserted at " << m << " position" << endl;
                n += 1;
            }
        }
    }
    void getdata()
    {
        cout << "Enter the data from 1st to " << n << "th node" << endl;
        temp = head;
        if (head == NULL && tail == NULL)
        {
            cout << "Empty linked list" << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cin >> temp->data;
                temp = temp->next;
            }
        }
    }
    void changedata()
    {
        int c;
        cout << "Data of which node do you want to change" << endl;
        cin >> c;
        temp = head;
        for (int i = 1; i < c; i++)
        {
            temp = temp->next;
        }
        cin >> temp->data;
    }
    void deletion()
    {
        int choice;
        cout << "How do you want to delete data:\n1. Specific node\n2. All nodes" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Which node do you want to delete" << endl;
            cin >> choice;
            if (choice < n - 1 && choice > 1)
            {
                temp = head;
                for (int i = 1; i < choice; i++)
                {
                    temp = temp->next;
                }
                temp->next = temp->next->next;
                temp->next->pre = temp;
                n -= 1;
            }
            else if (choice == 1)
            {
                node *nextNode = head->next;
                delete head;
                head = nextNode;
                n -= 1;
            }
            else if (choice == n)
            {
                node *preNode = tail->pre;
                delete tail;
                tail = preNode;
                n -= 1;
            }
        }
        else if (choice == 2)
        {
            temp = head;
            for (int i = 0; i < n; i++)
            {
                node *nextNode = temp->next;
                delete temp;
                temp = nextNode;
                n-=1;
            }
        }
    }
    int display()
    {
        temp = head;
        if (head == NULL && tail == NULL)
        {
            cout << "Empty linked list" << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }
};
int main()
{
    dbllinkedlist dll;
    int choice;
    //cout << "What do you want to do with linked list\n1.creation\n2.insertion\n3.updation\n4.deletion\n5.display\n0.exit" << endl;
    cout<<"For creating a doubly linked list Enter 0"<<endl;
    cin >> choice;
    do
    {
        if (choice==0)
        {
            dll.creation();
        }
        else if (choice == 1)
        {
            dll.getdata();
        }
        else if (choice == 2)
        {
            dll.insertion();
        }
        else if (choice == 3)
        {
            int cc;
            cout << "How do you want to perform updation\n1.Changing data of whole nodes\n2.Updating data of specific node" << endl;
            cin >> cc;
            if (cc == 1)
            {
                dll.getdata();
            }
            else if (cc == 2)
            {
                dll.changedata();
            }
        }
        else if (choice == 4)
        {
            dll.deletion();
        }
        else if (choice == 5)
        {
            dll.display();
        }
        cout << "What do you want to do with linked list\n1.Input data\n2.insertion\n3.updation\n4.deletion\n5.display\n0.exit" << endl;
        cin >> choice;
    } while (choice != 0);

    return 0;
}