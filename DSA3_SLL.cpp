#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *head = 0;

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
        while(temp->next != 0){
            temp = temp->next;
        }
        temp->next = newnode;
        // temp = newnode;
    }
    // temp->next = head;
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
        }while(temp != 0);
        // cout<<"( "<<temp->data<<" )-->";
        cout << "NULL" << endl;
    }
}
int main()
{
    int choice;
    do
    {

        cout << "1.Append()" << endl;
        cout << "2.Display()" << endl;
        cout << "3.clear Screen()" << endl;
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
            display();
            break;
        case 3:
            system("cls");
        default:
            cout<<head->data<<endl;
            break;
        }
    } while (choice != 0);
    return 0;
}