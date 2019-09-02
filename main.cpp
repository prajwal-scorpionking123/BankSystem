#include<iostream>
#include<windows.h>
#include<mysql.h>
#include<stdio.h>
#include<sstream>
using namespace std;
class accounts
{
public:
    void createAccount();
    void displayDetails();
    void checkBalance(string acc);
    void widrawl();
    void deposit();
};
//create accounts
void accounts::createAccount()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate;
     conn = mysql_init(0);
     conn = mysql_real_connect(conn,"localhost","root","","bank",3306,NULL,0);
     if(conn)
        cout<<"OUR AGENTS ARE READY TO GET YOUR INFORMATION CREATE YOUR ACCOUNT:"<<endl;
     else
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
//
 if(conn)
    {
        cout<<"CONNECTED TO ASSISTENT:"<<endl;

        string fname,actype,mname,lname,aadhar,state,city,gen;
        string mob;
        cout<<"ENTER YOUR FIRST NAME: "; cin>>fname;cout<<endl;
        cout<<"ENTER YOUR MIDDLE NAME :"; cin>>mname;cout<<endl;
        cout<<"ENTER YOUR LAST NAME:"; cin>>lname;cout<<endl;
        cout<<"ENTER YOUR GENDER:"; cin>>gen;cout<<endl;
        cout<<"ENTER YOUR ACCOUNT TYPE: LIKE SAVING OR LOAN:"; cin>>actype;cout<<endl;
        cout<<"ENTER YOUR MOBILE NO:"; cin>>mob; cout<<endl;
        cout<<"ENTER YOUR AADHAR ID:"; cin>>aadhar;cout<<endl;
        cout<<"ENTER YOUR STATE:";  cin>>state;cout<<endl;
        cout<<"ENTER YOUR CITY:";   cin>>city;cout<<endl;
        string query="insert into accounts(FNAME,MNAME,LNAME,GENDER,TYPE,MOB_NO,AADHAR,STATE,CITY) values('"+fname+"','"+mname+"','"+lname+"','"+gen+"','"+actype+"','"+mob+"','"+aadhar+"','"+state+"','"+city+"')";
        const char* q = query.c_str();
        qstate = mysql_query(conn,q);

        if(!qstate)
        {
         cout<<"ACCOUNT CREATED successfully..."<<endl;
        }
        else
        {
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
         string data="select * from accounts where MOB_NO="+mob+"";
           const char* d = data.c_str();
           int dstate = mysql_query(conn,d);
            if(!dstate)
        {
            res = mysql_store_result(conn);
            while((row=mysql_fetch_row(res)))
            {
                cout<<"ACCOUNT NO: "<<row[0]<<endl;
                cout<<"NAME: "<<row[1]<<""<<row[2]<<""<<row[3]<<endl;
                cout<<"GENDER"<<row[4]<<endl;
                cout<<"ACCOUNT TYPE: "<<row[5]<<endl;
                cout<<"MOBILE:"<<row[6]<<endl;
                cout<<"AADHAR:"<<row[7]<<endl;
                cout<<"STATE:"<<row[8]<<endl;
                cout<<"CITY:"<<row[9]<<endl;
                cout<<"BALANCE:"<<row[10]<<endl;
            }
        }
}
else
{
cout<<"connection problem: "<<mysql_error(conn)<<endl;
}
mysql_close(conn);

}
//Display
void accounts::displayDetails()
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
    int qstate;
     conn = mysql_init(0);
     conn = mysql_real_connect(conn,"localhost","root","","bank",3306,NULL,0);
     if(conn)
        cout<<"CONNECTED TO SYSTEM: "<<endl;
     else
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
//
 if(conn)
    {
        string acc_no;
        cout<<"ENTER YOUR ACCOUNT NO:"<<endl;
        cin>>acc_no;
        string query="select * from accounts where ACCOUNT_NUMBER="+acc_no+"";
           const char* q = query.c_str();
            qstate = mysql_query(conn,q);
        if(!qstate)
        {
            res = mysql_store_result(conn);
            while((row=mysql_fetch_row(res)))
            {
                cout<<"ACCOUNT NO: "<<row[0]<<endl;
                cout<<"NAME: "<<row[1]<<row[2]<<row[3]<<endl;
                cout<<"ACCOUNT TYPE:"<<row[4]<<endl;
                cout<<"GENDER: "<<row[5]<<endl;
                cout<<"MOBILE:"<<row[6]<<endl;
                cout<<"AADHAR:"<<row[7]<<endl;
                cout<<"STATE:"<<row[8]<<endl;
                cout<<"CITY:"<<row[9]<<endl;
                cout<<"BALANCE:"<<row[10]<<endl;
            }
        }
        else
        {
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
    }
    else
    {
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
    }

    mysql_close(conn);
}

//check balance
void accounts::checkBalance(string acc)
{
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
     int qstate;
     conn = mysql_init(0);
     conn = mysql_real_connect(conn,"localhost","root","","bank",3306,NULL,0);
     if(conn)
        cout<<"CONNECTED TO SYSTEM: "<<endl;
     else
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
//

 if(conn)
    {
        string acc_no;
        acc_no=acc;
        string query="select BALANCE from accounts where ACCOUNT_NUMBER="+acc_no+"";
           const char* q = query.c_str();
            qstate = mysql_query(conn,q);
        if(!qstate)
        {
            res = mysql_store_result(conn);
            while((row=mysql_fetch_row(res)))
            {
                cout<<"BALANCE:"<<row[0]<<endl;
            }
        }
        else
        {
            cout<<"query error: "<<mysql_error(conn)<<endl;
        }
    }
    else
    {
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
    }

    mysql_close(conn);
}

// Deposit cash
void accounts::deposit()
{
      MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
     int dstate;
     int qstate;
     conn = mysql_init(0);
     conn = mysql_real_connect(conn,"localhost","root","","bank",3306,NULL,0);
     if(conn)
        cout<<"CONNECTED TO SYSTEM: "<<endl;
     else
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
//

 if(conn)
    {
        int bal,cash;
        string acc_no;
         string depo;
        cout<<"ENTER YOUR ACCOUNT NO:"<<endl;
        cin>>acc_no;

        string query="select BALANCE from accounts where ACCOUNT_NUMBER="+acc_no+"";
           const char* q = query.c_str();
            qstate = mysql_query(conn,q);
        if(!qstate)
        {
            res = mysql_store_result(conn);
            while((row=mysql_fetch_row(res)))
            {

                cout<<"BALANCE:"<<row[0]<<endl;
                 stringstream geek(row[0]);
                 geek>>bal;

            }
            cout<<"ENTER AMMOUNT:"<<endl;
            cin>>cash;
            int money=bal+cash;
            ostringstream str1;
            str1<<money;
            depo=str1.str();
            string upquery="update accounts set BALANCE='"+depo+"' where ACCOUNT_NUMBER='"+acc_no+"'";
             const char* up = upquery.c_str();
            dstate = mysql_query(conn,up);
            if(!dstate)
            {
                cout<<"BALANCE UPDATED:"<<endl;
                checkBalance(acc_no);
            }
        }
        else
        {
            cout<<"Account NOT FOUND: "<<mysql_error(conn)<<endl;
        }

    }
    else
    {
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
    }

    mysql_close(conn);
}
//withdrawl
void accounts::widrawl()
{
      MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES *res;
     int dstate;
     int qstate;
     conn = mysql_init(0);
     conn = mysql_real_connect(conn,"localhost","root","","bank",3306,NULL,0);
     if(conn)
        cout<<"CONNECTED TO SYSTEM: "<<endl;
     else
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
//

 if(conn)
    {
        int bal,cash;
        string acc_no;
         string depo;
        cout<<"ENTER YOUR ACCOUNT NO:"<<endl;
        cin>>acc_no;

        string query="select BALANCE from accounts where ACCOUNT_NUMBER="+acc_no+"";
           const char* q = query.c_str();
            qstate = mysql_query(conn,q);
        if(!qstate)
        {
            res = mysql_store_result(conn);
            while((row=mysql_fetch_row(res)))
            {

                cout<<"BALANCE:"<<row[0]<<endl;
                 stringstream geek(row[0]);
                 geek>>bal;

            }
            cout<<"ENTER AMMOUNT:"<<endl;
            cin>>cash;
            if(cash>bal)
            {
                cout<<"INSUFFICIENT BALANCE:"<<endl;
                exit(0);
            }
            else
            {
            int money=bal-cash;
            ostringstream str1;
            str1<<money;
            depo=str1.str();
            string upquery="update accounts set BALANCE='"+depo+"' where ACCOUNT_NUMBER='"+acc_no+"'";
             const char* up = upquery.c_str();
            dstate = mysql_query(conn,up);
            if(!dstate)
            {
                cout<<"BALANCE UPDATED:"<<endl;
                checkBalance(acc_no);
            }
            }
        }
        else
        {
            cout<<"Account NOT FOUND: "<<mysql_error(conn)<<endl;
        }

    }
    else
    {
        cout<<"connection problem: "<<mysql_error(conn)<<endl;
    }

    mysql_close(conn);
}
int main()
{
    cout<<"         welcome to Bank Management system        "<<endl;
    cout<<"               Branch:CSE 3rd YEAR                "<<endl;
    cout<<endl<<endl;
    while(1)
    {
    cout<<"     MENU  "<<endl;
    cout<<"     1.CREATE BANK ACCOUNT:"<<endl;
    cout<<"     2.CHECK ACCOUNT DETAILS:"<<endl;
    cout<<"     3.CHECK ACCOUNT BALANCE:"<<endl;
    cout<<"     4.DEPOSITE CASH:"<<endl;
    cout<<"     5.WITHDRAW CASH:"<<endl;
    cout<<"     6.EXIT"<<endl;
    int ch;
    string acc;
    cin>>ch;
    accounts a1;

    //options
    switch(ch)
    {
    case 1:
        a1.createAccount();
        break;
    case 2:
        a1.displayDetails();
        break;
    case 3:
        cout<<"ENTER ACCOUNT NUMBER:"<<endl;
        cin>>acc;
        a1.checkBalance(acc);
        break;
    case 4:
        a1.deposit();
        break;
    case 5:
        a1.widrawl();
        break;
    case 6:
        exit(0);
    default:
        cout<<"INVALID OPTION IS CHOOSEN:"<<endl;
        break;
    }
  }
    return 0;
}
