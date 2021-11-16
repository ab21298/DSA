#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *head = 0;
struct Node *last = 0;
void append()
{
    int data;
 
    // Initialize a new node
    struct Node* temp;
    temp = (struct Node*)malloc(sizeof(struct Node));
 
    // Input data
    printf("\nEnter data to be inserted : \n");
    scanf("%d", &data);
 
    // If the new node is the
    // only node in the list
    if (last == NULL) {
        temp->data = data;
        temp->next = temp;
        last = temp;
    }
 
    // Else the new node will be the
    // last node and will contain
    // the reference of head node
    else {
        temp->data = data;
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}
void display()
{
   if (last == NULL)
        printf("\nList is empty\n");
 
    // Else print the list
    else {
        struct Node* temp;
        temp = last->next;
        do {
            printf("\nData = %d",temp->data);
            temp = temp->next;
        } while (temp != last->next);
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