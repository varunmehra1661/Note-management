#include <bits/stdc++.h>
// #include <E:\sem 3\work\Data structures\project\welcomescreen.h>
#include <conio.h>
#include <Windows.h>
#include"welcomescreen.h"
// #include <stdio.h>
// #include <string.h>

using namespace std;

struct node
{
    string str;
    node *next;
};

// 410      410
// 1 2 3 4 5
//   1: top
// Main class for note Making.

class Notes
{
private:
    node *top = NULL;

public:
    void push(string);
    void search(string);
    void del(string);
    void display();
    void self_exit();
};

void Notes::self_exit()
{
    cout << "\n\tThank you for using notes...\n";
    exit(1);
}
void Notes::push(string text)
{
    node *temp;
    temp = new node;  // Created a temporary pointer in heap Memory.[dynamic Allocation]
                      //420
    temp->str = text; //
    temp->next = NULL;
    if (top == NULL)
    {
        //top =NULL
        top = temp;
        //top=420.
        return;
    }

    temp->next = top; //   
    top = temp;
}

void Notes::search(string text)
{
    if (top == NULL)
    {
        cout << "The list is Empty...Please add one!" << endl;
        return;
    }

    node *ptr = top;
    while (ptr->next != NULL) //traversing till th end
    {
        if (ptr->str == text)
        {
            cout << ptr->str << endl;
            // ptr=ptr->next;
            return;
        }
        ptr = ptr->next;
    }
    if (ptr->next == NULL && top->str == text)
    {
        //base case.
        // "saksham"-> NULL.
        cout << ptr->str << endl;
        //ptr=ptr->next;
    }
    else
    {
        cout << "404 error...Not found!!" << endl;
    }
}

void Notes::del(string text)
{
    if (top == NULL)
    {
        cout << "The list is Empty...Please add one!" << endl;
        return;
    }
    if (top->str == text)
    {
        node *temp = top;
        top = top->next;
        delete temp;
        cout << "Note Deleted Successfully..." << endl;
        return;
    }
    node *curr = top;
    while (curr->next != NULL && curr->next->str != text)
        curr = curr->next;

    if (curr->next == NULL)
    {
        cout << "\n\tNotes Not found !..";
        return;
    }

    node *temp = curr->next;
    curr->next = temp->next;
    delete temp;

    cout << "\n\tNotes Deleted...";
}

void Notes::display()
{
    if (top == NULL)
    {
        cout << "The list is Empty...Please add one!..";
    }
    else
    {
        // 1,2,3,4,5
        node *ptr = top;
        while (ptr != NULL)
        {
            cout << ptr->str << endl;
            ptr = ptr->next;
        }
    }
}
void start()
{
    system("Color 0B");
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t----------------------------\n";
    cout << "\t\t\t\t\t\t----------------------------\n";
    cout << "\t\t\t\t\t\tNOTE MAKING APP\n";
    cout << "\t\t\t\t\t\t----------------------------\n\n";
    cout << "\t\t\t\t\tLoading ";
    char x = 219;
    for (int i = 0; i < 35; i++)
    {
        cout << x;
        if (i < 10)
            Sleep(300);
        if (i >= 10 && i < 20)
            Sleep(150);
        if (i >= 10)
            Sleep(25);
    }
    system("cls");
}
int main()
{
    int choice, choice1 = 1;
    system("cls");
    Notes notes;
    // welcome();
    system("cls");
    // start();
    cout << "Press Enter to continue";
    char ch = getch();
    system("Color 0A");
    while (choice1)
    {
        // cout<<"\n\n1."<<endl;
        // cout<<"2. Search Note"<<endl;
        // cout<<"3. Delete Note"<<endl;
        // cout<<"4. See All Notes"<<endl;
        // cout<<"5. Exit";
        cout << "\n\n\n\n\n";
        cout << "\t\t\t\t\t--------------------------------------------\n";
        cout << "\t\t\t\t\t--------------------------------------------\n";
        cout << "\t\t\t\t\t|          NOTE MAKING APP                 |\n";
        cout << "\t\t\t\t\t--------------------------------------------\n";
        cout << "\t\t\t\t\t|                                          |\n";
        cout << "\t\t\t\t\t|       [1]  Add a Note                    |\n";
        cout << "\t\t\t\t\t|       [2]  Search Note                   |\n";
        cout << "\t\t\t\t\t|       [3]  Delete Note                   |\n";
        cout << "\t\t\t\t\t|       [4]  See All Notes                 |\n";
        cout << "\t\t\t\t\t|       [5]  Exit                          |\n";
        cout << "\t\t\t\t\t--------------------------------------------\n";
        cout<<"Enter choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
        {
            string text, temp;
            cout << "Create a note: ";
            //	 use cin.ignore();
            //      or
            // 	getline(cin,temp);
            fflush(stdin);
            getline(cin, text);
            fflush(stdin);
            notes.push(text);
            break;
        }

        case 2:
        {
            string text;
            cout << "Enter note you want to search: ";
            fflush(stdin);
            getline(cin, text);
            fflush(stdin);
            //scanf("%s",text);
            // cin >> text;
            notes.search(text);
            break;
        }

        case 3:
        {
            string text;
            cout << "Enter note you want to delete: ";
            fflush(stdin);
            getline(cin, text);
            //scanf("%s",text);
            // cin >> text;
            notes.del(text);
            break;
        }

        case 4:
        {
            notes.display();
            break;
        }

        case 5:
        {
            notes.self_exit();
            break;
        }

        default:
        {
            cout << "Invalid choice...";
            break;
        }
        }
        cout << "WANT TO CONTINUE? (1 for yes || 0 for no : )";
        cin >> choice1;
        system("CLS");
        fflush(stdin);
    }
    return 0;
}