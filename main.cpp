#include "Test.h"

void menu();

int main()
{
    int num, z, data;
    List<int> list;
    do
    {
        menu();
        cin >> num;
        cout << endl;
        switch(num)
        {
            case 1:
            {
                cout << "Enter the number of items >> ";
                cin >> z;
                cout << "Where to add an item?" << endl;
                cout << "1. To the top of the list" << endl;
                cout << "2. To a certain position" << endl;
                cout << "3. At the end of the list" << endl;
                cout << ">> ";
                cin >> num;
                cout << "Enter values:" << endl;
                if (num == 1)
                {
                    for (int i = 0; i < z; i++)
                    {
                        cin >> data;
                        list.insertFirst(data);
                    }
                }
                if (num == 2)
                {
                    for (int i = 0; i < z; i++)
                    {
                        cin >> data;
                        list.insertAtPos(data);
                    }
                }
                if (num == 3)
                {
                    for (int i = 0; i < z; i++)
                    {
                        cin >> data;
                        list.insertLast(data);
                    }
                }
                break;
            }
            case 2:
            {
                cout << "Enter the number of items >> ";
                cin >> z;
                cout << "Where to remove the item from?" << endl;
                cout << "1. From the top of the list" << endl;
                cout << "2. From a certain position" << endl;
                cout << "3. From the end of the list" << endl;
                cout << ">> ";
                cin >> num;
                if (num == 1)
                {
                    for (int i = 0; i < z; i++)
                    {
                        list.deleteFirst();
                    }
                }
                if (num == 2)
                {
                    for (int i = 0; i < z; i++)
                    {
                        list.deleteAtPos();
                    }
                }
                if (num == 3)
                {
                    for (int i = 0; i < z; i++)
                    {
                        list.deleteLast();
                    }
                }
                break;
            }
            case 3:
            {
                list.Print();
                break;
            }
            case 4:
            {
                list.Clear();
                break;
            }
        }
    } while (num != 5);
    return 0;
}


void menu()
{
    cout << endl;
    cout << "1. Add an item to the list" << endl;
    cout << "2. Remove item from list" << endl;
    cout << "3. View full list" << endl;
    cout << "4. Clear all list" << endl;
    cout << "5. Exit" << endl;
    cout << ">> ";
}
