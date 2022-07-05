#include <iostream>
#include <fstream>
#include <string.h>


using namespace std;

void login();
void registering();
void forgot_password();

int main()
{
    int choice;
    cout<<"\n\t=== Menu Service ===\n";
    cout<<"\n\t 1) Register.\n\t 2) Login \n\t 3) Forgot Password";
    cout<<"\n\tEnter Choice: ";
    cin>>choice;
    system("cls");


switch (choice)
{
case 1:
    registering();
    break;
case 2:
    login();
    break;
case 3:
    forgot_password();
    break;
default:
    system("cls");
    cout<<"\t\t Enter a valid Option...\n\n";
    main();
}
}
void registering()
{
    string rusername,rpassword,ruid,rpass;

    cout<<"\n\tEnter Username: ";
    cin>>rusername;
    cout<<"\n\tEnter Password: ";
    cin>>rpassword;
    ofstream input("records.txt", ios::app);
    input<<rusername<<' '<<rpassword;
    system("cls");
    cout<<"Registration Successful...";
    main();


}
void login()
{
    int counter;
    string username,password,uid,pwd;
    cout<<"\n\tEnter Username: ";
    cin>>username;
    cout<<"\tEnter Password: ";
    cin>>password;
    system("cls");

    ifstream input("records.txt");
    while(input>>uid>>pwd)
    {
        if(username==uid && password == pwd)
        {
            counter=1;
            system("cls");
        }
    }
     input.close();
     if(counter==1)
     {
         cout<<"\n\t "<<username<<" You have Successfully logged In. Thank you....\n";
         main();
     }
     else{cout<<"\n\tInvalid Login entries. ";}

}
void forgot_password()
{
    int counter=0,choice;
    string uid,upass,username;

    system("cls");
    cout<<"\n\tSelect from the Options below: \n\t 1) Search User name: \n\t 2) Return to menu:  ";
    cin>>choice;

    switch (choice)
    {
    case 1:
        {
        cout<<"\n\tEnter User Id: ";
        cin>>username;
        ifstream reader("records.txt");
        while(reader>>uid>>upass)
        {
            if(uid==username)
            {
                counter=1;
            }
        }reader.close();
        if(counter==1)
        {
            system("cls");
            cout<<"\n\tUsername Found! ";
            cout<<"\n\tYour Password is: "<<upass;
            main();
        }
        else{
        system("cls");
        cout<<"We are Sorry No username "<<uid<<" Found";
        main();
        }
        break;
        }
    case 2:
        main();
        break;
    default:
        cout<<"Invalid Input. Please try again.";
    }

}

