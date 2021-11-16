#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    int key;
    Node *next, *prev;
    Node()
    {
        data = 0;
        key = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int d, int k)
    {
        data = d;
        key = k;
        next = NULL;
        prev = NULL;
    }
};
class DoublyLinkedList
{
public:
    Node *head;
    DoublyLinkedList()
    {
        head = NULL;
    }
    DoublyLinkedList(Node *n)
    {
        head = n;
    }
    // check if node exist
    Node *nodeExist(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
                return temp;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    // append a node to the list
    void appendNode(Node *n)
    {
        if (nodeExist(n->key) != NULL)
        {
            cout << "Node already exist\n";
        }
        else
        {
            if (head == NULL)
            {
                head = n;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node appended\n";
            }
        }
    }
    // prepend a node to the list
    void prependNode(Node *n)
    {
        if (nodeExist(n->key) != NULL)
        {
            cout << "Node already exist\n";
        }
        else
        {
            head->prev = n;
            n->next = head;
            head = n;
        }
    }
    // Insert the node after
    void InsertNodeAfter(Node *n, int k)
    {
        Node *ptr = nodeExist(k);
        if (ptr == NULL)
        {
            cout << "No node exists with key value: " << k << endl;
        }
        else
        {
            if (nodeExist(n->key) != NULL)
            {
                cout << "Node already exist\n";
            }
            else
            {
                n->next = ptr->next;
                ptr->next->prev = n;
                ptr->next = n;
                n->prev = ptr;
                cout << "Node Inserted" << endl;
            }
        }
    }
    // Delete the node
    void DeleteNode(int k)
    {
        Node *ptr = nodeExist(k);
        if (ptr == NULL)
        {
            cout << "No node exist with this key" << endl;
        }
        else
        {
            // delete at the begining
            if (head->key == k)
            {
                head = head->next;
                cout << "node unlinked at start" << endl;
            }
            else
            {
                Node *nextNode = ptr->next;
                Node *prevNode = ptr->prev;
                // delete at the end
                if (nextNode == NULL)
                {
                    prevNode->next = NULL;
                    cout << "node unlinked at end" << endl;
                }
                // deleting in between
                else
                {
                    prevNode->next = nextNode;
                    nextNode->prev = prevNode;
                    cout << "Node deleted in between" << endl;
                }
            }
        }
    }
    // update node
    void updateNode(int k, int d)
    {
        Node *ptr = nodeExist(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Node updated" << endl;
        }
        else
        {
            cout << "Node does not exist" << endl;
        }
    }
    // printing list
    void printList()
    {
        if (head == NULL)
        {
            cout << "No node in the linked list." << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "( " << temp->key << ", " << temp->data << " ) <-->";
                temp = temp->next;
            }
        }
    }
};
int main()
{
    DoublyLinkedList obj;
    int option;
    int key1, k1, data1;
    do
    {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. print()" << endl;
        cout << "7. Clear Screen" << endl
             << endl;

        cin >> option;
        Node *n1 = new Node();
        //Node n1;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            obj.appendNode(n1);
            //cout<<n1.key<<" = "<<n1.data<<endl;
            break;

        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1 -> key = key1;
            n1 -> data = data1;
            obj.prependNode(n1);
            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1 -> key = key1;
            n1 -> data = data1;

            obj.InsertNodeAfter(n1, k1);
            break;

        case 4:

            cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
            cin >> k1;
            obj.DeleteNode(k1);

            break;
        case 5:
            cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            obj.updateNode(key1, data1);

            break;
        case 6:
            obj.printList();

            break;
        case 7:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);
    return 0;
}