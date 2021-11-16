#include <iostream>
using namespace std;
void append(void);
void prepend(void);
struct Node
{
    int data;
    struct Node *next;
} *head = 0, *tail = 0;
int getLength()
{
    int i = 0;
    struct Node *temp;
    if (head == 0)
    {
        return 0;
    }
    else
    {
        temp = head;
        do
        {
            temp = temp->next;
            i++;
        } while (temp != head);
        return i;
    }
}
void insert(int pos)
{
    struct Node *temp, *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    int l = getLength(), i = 1;
    if (pos <= 0 || pos > l + 1)
    {
        cout << "Invalid Position" << endl;
    }
    else
    {
        if (pos == 1)
        {
            prepend();
        }
        else
        {
            if (pos == l + 1)
            {
                append();
            }
            else
            {
                temp = head;
                cout << "Enter the data you want to insert: ";
                cin >> newnode->data;
                newnode->next = 0;

                while (i < pos - 1)
                {

                    temp = temp->next;
                    i++;
                }
                newnode->next = temp->next;
                temp->next = newnode;
            }
        }
    }
}
void Delete(int pos)
{
    int l = getLength();
    int i = 1;
    struct Node *temp;
    if (pos <= 0 || pos > l)
    {
        cout << "Invalid Postion" << endl;
    }
    else
    {
        if (pos == 1)
        {
            temp = head;
            head = temp->next;
            tail->next = head;
            free(temp);
        }
        else
        {
            struct Node *prev;
            temp = head;
            while (i < pos)
            {
                prev = temp;
                temp = temp->next;
                i++;
            }
            if (pos == l)
            {
                tail = prev;
            }
            prev->next = temp->next;
            free(temp);
        }
    }
}
void append()
{
    struct Node *newnode;
    struct Node *temp = head;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    cout << "Enter the data you want to insert: ";
    cin >> newnode->data;
    newnode->next = 0;
    if (head == 0)
    {
        head = temp = newnode;
    }
    else
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        temp = newnode;
    }
    temp->next = head;
    tail = newnode;
}
void prepend()
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    cout << "Enter the data you want to insert: ";
    cin >> newnode->data;
    newnode->next = 0;
    if (head == 0)
    {
        head = newnode;
        head->next = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
        tail->next = newnode;
    }
}
void display()
{
    struct Node *temp;
    if (head == 0)
    {
        cout << "List is Empty" << endl;
    }
    else
    {
        temp = head;
        do
        {
            cout << "( " << temp->data << " )-->";
            temp = temp->next;
        } while (temp != head);
        // cout<<"( "<<temp->data<<" )-->";
        cout << tail->next->data << endl;
    }
}
int main()
{
    int choice;
    do
    {
        cout << "1.Append()" << endl;
        cout << "2.Prepend() " << endl;
        cout << "3.Display()" << endl;
        cout << "4.clearScreen()" << endl;
        cout << "5.getLength()" << endl;
        cout << "6.insert()" << endl;
        cout << "7.Delete() " << endl;
        cout << "0.Exit()" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:
            append();
            break;
        case 2:
            prepend();
            break;
        case 3:
            display();
            break;
        case 4:
            system("cls");
            break;
        case 5:
            int l;
            l = getLength();
            cout << "Length = " << l << endl;
            break;
        case 6:
            int pos;
            cout << "Enter the positon you want to insert: ";
            cin >> pos;
            insert(pos);
            break;
        case 7:
            int pos1;
            cout << "Enter the position you want to delete: ";
            cin >> pos1;
            Delete(pos1);
            break;
        default:
            cout << head->data << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}
