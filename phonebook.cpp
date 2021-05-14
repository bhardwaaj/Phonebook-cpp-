#include<stdio.h>
#include<iostream>
#include<string.h>
#include<fstream>
static int choice;
using namespace std;
class phonebook
{
    public:
    int no;
    long long int number=0;
    char name1[10];
void Welcome()
{
    cout<<"\n*************************************************************************************************\n";
    printf("1) Show Phonebook.\n"
           "2) Add Contact Phonebook.\n"
           "3) Search Number \n"
           "4) Delete Contact\n"
           "5) Exit\n"
           ""
           "Enter your choice:\n");
    cin>>choice;
}
void Add_num();
void Search();
void delete1();
};
void phonebook::Add_num()
{
    cout<<"Enter Your Contact name :\n";
    cin>>name1;
    cout<<"Enter Your Contact Number:\n";
    cin>>number;
}
void phonebook::Search()
{
    cout<<"Enter name :\n";
    cin>>name1;
}
void phonebook::delete1()
{
    cout<<"Enter the Contact no , like:(0,1,2,3,etc):"<<endl;
    cin>>no;
}

void delete_line(const char *file_name, int n) 
{
    ifstream is(file_name);
    ofstream ofs; 
    ofs.open("temp.txt", ofstream::out);
    char c; 
    int line_no = 1; 
    while (is.get(c)) 
    { 
        if (c == '\n') 
        line_no++; 
        if (line_no != n) 
            ofs << c; 
    }
    ofs.close();
    is.close();
    remove(file_name); 
    rename("temp.txt", file_name); 
} 


int main()
{
    string text;
    string deleting;
    phonebook S;
    fstream file,file1;
    file.open("Database.txt",ios::app);
    if(!file)
    {
        cout<<"Unabel to creat database.\n";
        cout<<"Run Again.";
    }
    else
    {
        cout<<"Database Booted Sucsessfully.";
    }
    Repeat:
    S.Welcome();
    if(choice == 1)
    {
        fstream file1;
        file1.open("Database.txt",ios::in);
        cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        while(getline(file1,text))
        {
            cout<<text<<endl;
        }
        goto Repeat;
    }
    if(choice==2)
    {
        S.Add_num();
        file<<S.name1<<" "<<S.number<<endl;
        cout<<"Added sucessfully."<<endl; 
        goto Repeat;       
    }
    if(choice==3)
    {
        S.Search();
        fstream file1;
        file1.open("Database.txt",ios::in);
        cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
        while(getline(file1,text))
        {
            if(text[0]==S.name1[0] && text[1]==S.name1[1] && text[2]==S.name1[2])
            {
                cout<<"Contact Found !\n";
                cout<<"-> "<<text<<endl;
                goto Repeat;
            }
        }
        cout<<"\nContact not found !"<<endl;
        goto Repeat;

    }
    if(choice == 4)
    {
        S.delete1();
        delete_line("Database.txt",S.no);
        goto Repeat;
    }
    if(choice!=1 && choice!=2 && choice!=3 && choice!=4)
    {
        cout<<"Closing all files........."<<endl;
        return 0;
        file.close();
        file1.close();
    }
    file.close();
    file1.close();
    return 0; 
}
