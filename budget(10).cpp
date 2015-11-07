#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include "income.h"
#include "money_menu.cpp"
#include "outgo.h"
#include "money_func.cpp"
/*
This program performs as a budget check for the user. It can determine
what percentage of your income is going into housing, savings, debt, general
expenses, and transportation. It takes your percentages and compares it to the
ideal. It saves your input every time you run it. This website was used to obtain
the ideal percentages: http://www.savespendsplurge.com/the-ideal-household-budget-for-spending/
PLEASE be careful when entering input because it may crash when the wrong
input type is entered. Happy Budgeting!
-Sarah Dudley
*/
int main()
{
int earnednum, unearnednum; ///declare variables
string incomename;
string newincomename;
char which;
double monthtotal;
double outgototal;
double incometotal;
double remainder;
double etotal;
double utotal;
double htotal;
double ttotal;
double dtotal;
double stotal;
double gtotal;
income * earnedhead = NULL;
income * earnedcurr = NULL;
income * earnedprev = NULL;
income * unearnedhead = NULL;
income * unearnedcurr = NULL;
income * unearnedprev = NULL;
outgo * househead = NULL; ///There are 5 types of outgo's This means that there will be 5 different linked lists.
outgo * housecurr = NULL;
outgo * houseprev = NULL;
outgo * transhead = NULL;
outgo * transcurr = NULL;
outgo * transprev = NULL;
outgo * debthead = NULL;
outgo * debtcurr = NULL;
outgo * debtprev = NULL;
outgo * savehead = NULL;
outgo * savecurr = NULL;
outgo * saveprev = NULL;
outgo * genhead = NULL;
outgo * gencurr = NULL;
outgo * genprev = NULL;
int each;
string outgoname;
cout<<"\t\t\t\tMONTHLY BUDGET CHECK"<<endl;///Introduction to user
cout<<"\t\t\t\t--------------------"<<endl;
cout<<endl;
cout<<"Would you like to load the financial information from your previous visit?"<<endl;
cout<<"\t\t\t\t(Y)es or (N)o."<<endl;
char input;
cin>>input;
if (input == 'Y' || input == 'y')
    {
    fstream fin;/*******************************Enter in File!*/
    fin.open("earned.txt",ios::in);
    while (getline(fin,incomename))///**********fill earned from file
        {
        int freq;
        double amount;
        fin>>freq;
        fin>>amount;
        if(earnedhead==NULL)
            {
            earnedhead = new income;
            earnedcurr = earnedhead;
            earnedhead -> setname(incomename);
            earnedhead -> setfrequency(freq);
            earnedhead -> setamount(amount);
            }
        else
            {
            earnedcurr -> makenew();
            earnedcurr = earnedcurr -> getnext();
            earnedcurr -> setname(incomename);
            earnedcurr -> setfrequency(freq);
            earnedcurr -> setamount(amount);
            }
        getline(fin,incomename);
        }///end of earned file
        fin.close();
    fin.open("unearned.txt",ios::in);
    while (getline(fin,incomename))///**********fill unearned from file
        {
        int freq;
        double amount;
        fin>>freq;
        fin>>amount;
        if(unearnedhead==NULL)
            {
            unearnedhead = new income;
            unearnedcurr = unearnedhead;
            unearnedhead -> setname(incomename);
            unearnedhead -> setfrequency(freq);
            unearnedhead -> setamount(amount);
            }
        else
            {
            unearnedcurr -> makenew();
            unearnedcurr = unearnedcurr -> getnext();
            unearnedcurr -> setname(incomename);
            unearnedcurr -> setfrequency(freq);
            unearnedcurr -> setamount(amount);
            }
        getline(fin,incomename);
        }///end of unearned file
        fin.close();
    fin.open("housing.txt",ios::in);
    while (getline(fin,outgoname))///**********fill in housing from file
        {
        int freq;
        double amount;
        fin>>freq;
        fin>>amount;
        if(househead==NULL)
            {
            househead = new outgo;
            housecurr = househead;
            househead -> setname(outgoname);
            househead -> setfrequency(freq);
            househead -> setamount(amount);
            }
        else
            {
            housecurr -> makenew();
            housecurr = housecurr -> getnext();
            housecurr -> setname(outgoname);
            housecurr -> setfrequency(freq);
            housecurr -> setamount(amount);
            }
        getline(fin,outgoname);
        }///end of housing file
        fin.close();
    fin.open("transportation.txt",ios::in);
    while (getline(fin,outgoname))///**********fill in transportation from file
        {
        int freq;
        double amount;
        fin>>freq;
        fin>>amount;
        if(transhead==NULL)
            {
            transhead = new outgo;
            transcurr = transhead;
            transhead -> setname(outgoname);
            transhead -> setfrequency(freq);
            transhead -> setamount(amount);
            }
        else
            {
            transcurr -> makenew();
            transcurr = transcurr -> getnext();
            transcurr -> setname(outgoname);
            transcurr -> setfrequency(freq);
            transcurr -> setamount(amount);
            }
        getline(fin,outgoname);
        }///end of transportation file
        fin.close();
    fin.open("debt.txt",ios::in);
    while (getline(fin,outgoname))///**********fill in debt from file
        {
        int freq;
        double amount;
        fin>>freq;
        fin>>amount;
        if(debthead==NULL)
            {
            debthead = new outgo;
            debtcurr = debthead;
            debthead -> setname(outgoname);
            debthead -> setfrequency(freq);
            debthead -> setamount(amount);
            }
        else
            {
            debtcurr -> makenew();
            debtcurr = debtcurr -> getnext();
            debtcurr -> setname(outgoname);
            debtcurr -> setfrequency(freq);
            debtcurr -> setamount(amount);
            }
        getline(fin,outgoname);
        }///end of debt file
    fin.close();
    fin.open("savings.txt",ios::in);
    while (getline(fin,outgoname))///**********fill in saving from file
        {
        int freq;
        double amount;
        fin>>freq;
        fin>>amount;
        if(savehead==NULL)
            {
            savehead = new outgo;
            savecurr = savehead;
            savehead -> setname(outgoname);
            savehead -> setfrequency(freq);
            savehead -> setamount(amount);
            }
        else
            {
            savecurr -> makenew();
            savecurr = savecurr -> getnext();
            savecurr -> setname(outgoname);
            savecurr -> setfrequency(freq);
            savecurr -> setamount(amount);
            }
        getline(fin,outgoname);
        }///end of save file
        fin.close();
    fin.open("generalexp.txt",ios::in);
    while (getline(fin,outgoname))///**********fill in general expenses from file
        {
        int freq;
        double amount;
        fin>>freq;
        fin>>amount;
        if(genhead==NULL)
            {
            genhead = new outgo;
            gencurr = genhead;
            genhead -> setname(outgoname);
            genhead -> setfrequency(freq);
            genhead -> setamount(amount);
            }
        else
            {
            gencurr -> makenew();
            gencurr = gencurr -> getnext();
            gencurr -> setname(outgoname);
            gencurr -> setfrequency(freq);
            gencurr -> setamount(amount);
            }
        getline(fin,outgoname);
        }///end of general expense file
        fin.close();

            cout<<"\t\t\t\tIncome List"<<endl; ///display the matrix
            cout<<"\t\t\t\t-----------"<<endl;
            cout<<endl;
            cout<<"Earned Income: "<<endl;
            if (earnedhead != NULL) {earnedhead -> showall();}
            else {cout<<"Earned income was not entered";}
            cout<<endl;
            cout<<"Unearned Income: "<<endl;
            if (unearnedhead != NULL) {unearnedhead -> showall();}
            else {cout<<"Unearned income was not entered";}
            cout<<endl<<endl;
        char ans;
       while (ans != 4)
            {
            ans = incomemenu();
            if (ans == 1) ///start of change code
                {
                cout<<"Would you like to change (e)arned or (u)nearned income? ";///start of change code for earned only
                cin>>which;
                    if (which == 'e' || which == 'E')
                        {
                        if(earnedhead == NULL)
                            {
                            cout<<endl;
                            cout<<"Hey! You can't change an income that you never entered!"<<endl;
                            }
                        else
                            {
                            cout<<endl;
                            cin.ignore();
                            cout<<"Please enter the name assigned to the earned income"<<endl;
                            cout<<"you would like to change: ";
                            getline(cin,incomename);
                            earnedcurr = earnedhead;
                                while(earnedcurr -> getname() != incomename )
                                    {
                                    earnedcurr = earnedcurr ->getnext();
                                    }///end of while loop
                            cout<<"Please enter the new name of income: ";
                            getline(cin,newincomename);
                            cout<<"\nPlease enter the earned income frequency."<<endl;
                            cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                            int newfreq;
                            cin>>newfreq;
                            cout<<"Please enter the amount received based on frequency."<<endl;
                            double newamount;
                            cin>>newamount;
                            cout<<endl;
                            earnedcurr -> setname(newincomename); /// insert user data with pointers
                            earnedcurr -> setfrequency(newfreq);
                            earnedcurr -> setamount(newamount);
                            cin.ignore();///End of change code for earned
                            cout<<"\t\t\t\tIncome List"<<endl; ///display the matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Earned Income: "<<endl;
                            if (earnedhead != NULL) {earnedhead -> showall();}
                            else {cout<<"Earned income was not entered";}
                            cout<<endl;
                            cout<<"Unearned Income: "<<endl;
                            if (unearnedhead != NULL) {unearnedhead -> showall();}
                            else {cout<<"Unearned income was not entered";}
                            }
                        }
                    else if (which == 'u'|| which == 'U')///Start of change code for unearned only.
                        {
                        if (unearnedhead == NULL)
                            {
                            cout<<endl;
                            cout<<"Hey! You can't change an income that you never entered!"<<endl;
                            }
                        else
                            {
                            cout<<endl;
                            cin.ignore();
                            cout<<"Please enter the name assigned to the unearned income you would like to change: ";
                            getline(cin,incomename);
                            unearnedcurr = unearnedhead;
                                while(unearnedcurr -> getname() != incomename )
                                    {
                                    unearnedcurr = unearnedcurr ->getnext();
                                    }///end of while loop
                            cout<<"Please enter the NEW name of income: ";
                            getline(cin,newincomename);
                            cout<<"\nPlease enter the earned income frequency."<<endl;
                            cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                            int newfreq;
                            cin>>newfreq;
                            cout<<"Please enter the amount received based on frequency."<<endl;
                            double newamount;
                            cin>>newamount;
                            cout<<endl;
                            string type = "Unearned";
                            unearnedcurr -> setname(newincomename); /// insert user data with pointers
                            unearnedcurr -> setfrequency(newfreq);
                            unearnedcurr -> setamount(newamount);
                            unearnedcurr -> settype(type);
                            cin.ignore(); ///end of change code for unearned only.
                            cout<<"\t\t\t\tIncome List"<<endl; ///display the matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Earned Income: "<<endl;
                            if (earnedhead != NULL) {earnedhead -> showall();}
                            else {cout<<"Earned income was not entered";}
                            cout<<endl;
                            cout<<"Unearned Income: "<<endl;
                            if (unearnedhead != NULL) {unearnedhead -> showall();}
                            else {cout<<"Unearned income was not entered";}
                            }
                        }
                }                                                          ///end of change code
            else if (ans == 2)///Start of remove code
                    {
                    cout<<"Would you like to remove an (e)arned income or an (u)nearned income?"<<endl;
                    cin>>which;
                    cin.ignore();
                        if (which == 'e' || which == 'E')///start of remove code for earned only
                        {
                        cout<<endl;
                        cout<<"Please enter the name assigned to the income you would like to remove: ";
                        getline(cin,incomename);
                        earnedcurr = earnedhead;
                        earnedprev = earnedhead;
                            while(earnedcurr -> getname() != incomename)
                                {
                                earnedprev = earnedcurr;
                                earnedcurr = earnedcurr -> getnext();
                                }
                            if(earnedcurr == earnedhead)
                                {
                                earnedhead = earnedhead ->getnext();
                                earnedcurr -> setnext(NULL);
                                delete (earnedcurr);
                                }
                            else
                                {
                                earnedprev->setnext(earnedcurr->getnext());
                                earnedcurr -> setnext(NULL);
                                delete earnedcurr;
                                } ///end of remove code for earned only
                                          ///display the matrix
                            cout<<"\t\t\t\tIncome List"<<endl; ///display the matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Earned Income: "<<endl;
                            if (earnedhead != NULL) {earnedhead -> showall();}
                            else {cout<<"Earned income was not entered";}
                            cout<<endl;
                            cout<<"Unearned Income: "<<endl;
                            if (unearnedhead != NULL) {unearnedhead -> showall();}
                            else {cout<<"Unearned income was not entered";}
                        }
                        else if (which == 'u' || which == 'U')///start of remove code for unearned
                        {
                        cout<<endl;
                        cout<<"Please enter the name assigned to the income you would like to remove: ";
                        getline(cin,incomename);
                        unearnedcurr = unearnedhead;
                        unearnedprev = unearnedhead;
                            while(unearnedcurr -> getname() != incomename)
                                {
                                unearnedprev = unearnedcurr;
                                unearnedcurr = unearnedcurr -> getnext();
                                }
                            if(unearnedcurr == unearnedhead)
                                {
                                unearnedhead = unearnedhead ->getnext();
                                unearnedcurr -> setnext(NULL);
                                delete (unearnedcurr);
                                }
                            else
                                {
                                unearnedprev->setnext(unearnedcurr->getnext());
                                unearnedcurr -> setnext(NULL);
                                delete unearnedcurr;
                                }                   ///end of remove code for unearned only.
                            cout<<"\t\t\t\tIncome List"<<endl; ///display the matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Earned Income: "<<endl;
                            if (earnedhead != NULL) {earnedhead -> showall();}
                            else {cout<<"Earned income was not entered";}
                            cout<<endl;
                            cout<<"Unearned Income: "<<endl;
                            if (unearnedhead != NULL) {unearnedhead -> showall();}
                            else {cout<<"Unearned income was not entered";}
                        }
                    }
            else if (ans == 3) ///Start of ADD code
                    {
                    cout<<"Would you like to add an (e)arned income or an (u)nearned income?"<<endl;
                    cin>>which;
                        if (which == 'e' || which == 'E')
                        {
                        cin.ignore();
                        cout<<"Please enter the name of the new earned income: ";
                        getline(cin,incomename);
                        cout<<"\nPlease enter the earned income frequency."<<endl;
                        cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                        int newfreq;
                        cin>>newfreq;
                        cout<<"Please enter the amount received based on frequency."<<endl;
                        double newamount;
                        cin>>newamount;
                        cout<<endl;
                        string type = "Earned";
                        earnedcurr = earnedhead;
                        earnedprev = earnedhead;
                            if (earnedhead == NULL)
                                {
                                earnedhead = new income;
                                earnedhead ->setname(incomename);
                                earnedhead ->setfrequency(newfreq);
                                earnedhead ->setamount(newamount);
                                earnedhead ->settype(type);
                                }
                           else if (earnedhead != NULL)
                            {
                               while (earnedcurr != NULL)
                                    {
                                    earnedprev = earnedcurr;
                                    earnedcurr = earnedcurr -> getnext();
                                    }
                            earnedprev -> makenew();
                            earnedcurr = earnedprev -> getnext();
                            earnedcurr -> setname(incomename); /// insert user data with pointers
                            earnedcurr -> setfrequency(newfreq);
                            earnedcurr -> setamount(newamount);
                            earnedcurr ->settype(type);
                            }
                        cin.ignore();///End of change code for earned
                        cout<<"\t\t\t\tIncome List"<<endl; ///display the matrix
                        cout<<"\t\t\t\t-----------"<<endl;
                        cout<<endl;
                        cout<<"Earned Income: "<<endl;
                        if (earnedhead != NULL) {earnedhead -> showall();}
                        else {cout<<"Earned income was not entered";}
                        cout<<endl;
                        cout<<"Unearned Income: "<<endl;
                        if (unearnedhead != NULL) {unearnedhead -> showall();}
                        else {cout<<"Unearned income was not entered";}
                        }
                        else if (which == 'u'|| which == 'U')
                        {
                        cin.ignore();
                        cout<<"Please enter the name of the new unearned income: ";
                        getline(cin,incomename);
                        cout<<"\nPlease enter the earned income frequency"<<endl;
                        cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                        int newfreq;
                        cin>>newfreq;
                        cout<<"Please enter the amount received based on frequency."<<endl;
                        double newamount;
                        cin>>newamount;
                        string type = "Unearned";
                        cout<<endl;
                        unearnedcurr = unearnedhead;
                        unearnedprev = unearnedhead;
                            if (unearnedhead == NULL)
                                {
                                unearnedhead = new income;
                                unearnedhead ->setname(incomename);
                                unearnedhead ->setfrequency(newfreq);
                                unearnedhead ->setamount(newamount);
                                unearnedhead ->settype(type);
                                }
                           else if (unearnedhead != NULL)
                            {
                               while (unearnedcurr != NULL)
                                    {
                                    unearnedprev = unearnedcurr;
                                    unearnedcurr = unearnedcurr -> getnext();
                                    }
                            unearnedprev -> makenew();
                            unearnedcurr = unearnedprev -> getnext();
                            unearnedcurr -> setname(incomename); /// insert user data with pointers
                            unearnedcurr -> setfrequency(newfreq);
                            unearnedcurr -> setamount(newamount);
                            unearnedcurr ->settype(type);
                            }
                        cin.ignore();///End of change code for earned
                        cout<<"\t\t\t\tIncome List"<<endl; ///display the matrix
                        cout<<"\t\t\t\t-----------"<<endl;
                        cout<<endl;
                        cout<<"Earned Income: "<<endl;
                        if (earnedhead != NULL) {earnedhead -> showall();}
                        else {cout<<"Earned income was not entered";}
                        cout<<endl;
                        cout<<"Unearned Income: "<<endl;
                        if (unearnedhead != NULL) {unearnedhead -> showall();}
                        else {cout<<"Unearned income was not entered";}
                        }
                    }
            }
            cout<<"\t\t\t\tOutgo List"<<endl;
            cout<<"\t\t\t\t-----------"<<endl;
            cout<<endl;
            cout<<"Housing: "<<endl;
            if (househead != NULL) {househead -> showall();}
            else {cout<<"No housing expenses entered.";}
            cout<<endl<<endl;
            cout<<"Transportation: "<<endl;
            if (transhead != NULL) {transhead -> showall();}
            else {cout<<"No transportation expenses entered";}
            cout<<endl<<endl;
            cout<<"Debts: "<<endl;
            if (debthead != NULL) {debthead -> showall();}
            else {cout<<"No debt expenses entered";}
            cout<<endl<<endl;
            cout<<"Savings: "<<endl;
            if (savehead != NULL) {savehead -> showall();}
            else {cout<<"No savings entered";}
            cout<<endl<<endl;
            cout<<"General Expenses: "<<endl;
            if (genhead != NULL) {genhead -> showall();}
            else {cout<<"No general expenses entered.";}
            ans = 100;
      ///Ask user if they would like to change/remove/add outgo data
    while (ans != 4)
            {
            ans = outgomenu();
            if (ans == 1) ///start of change code
                {
                cout<<"In which category would you like to change an outgo?"<<endl<<endl;
                cout<<"(h)ousing / (t)ransporation / (d)ebts / (s)avings / (g)eneral expenses"<<endl<<endl;
                cout<<"Please enter the corresponding character: ";
                cin>>which;
                cin.ignore();
                if (which == 'h'|| which == 'H') /// Start of change code for housing only
                        {
                        if (househead == NULL)
                            {
                            cout<<endl;
                            cout<<"Hey! You can't change an outgo that you never entered!"<<endl;
                            }
                        else
                            {
                            cout<<endl;
                            cout<<"Please enter the name assigned to the housing expense"<<endl;
                            cout<<"you would like to change: ";
                            getline(cin,outgoname);
                            housecurr = househead;
                                while(housecurr -> getname() != outgoname )
                                    {
                                    housecurr = housecurr ->getnext();
                                    }///end of while loop
                            cout<<"Please enter the new name of the housing expense: ";
                            getline(cin,outgoname);
                            cout<<"\nPlease enter the payment frequency."<<endl;
                            cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                            int newfreq;
                            cin>>newfreq;
                            cout<<"Please enter the amount based on frequency."<<endl;
                            double newamount;
                            cin>>newamount;
                            cout<<endl;
                            housecurr -> setname(outgoname); /// insert user data with pointers
                            housecurr -> setfrequency(newfreq);
                            housecurr -> setamount(newamount);
                            cin.ignore();                           ///End of change code for housing
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                            }
                        }
                else if (which == 't' || which == 'T')///Start of change code for transportation only.
                        {
                        if (transhead == NULL)
                            {
                            cout<<endl;
                            cout<<"Hey! You can't change an outgo that you never entered!"<<endl;
                            }
                        else
                            {
                            cout<<endl;
                            cout<<"Please enter the name assigned to the transportation"<<endl;
                            cout<<"expense that you would like to change: ";
                            getline(cin,outgoname);
                            transcurr = transhead;
                                while(transcurr -> getname() != outgoname )
                                    {
                                    transcurr = transcurr ->getnext();
                                    }///end of while loop
                            cout<<"Please enter the new name for this transportation expense: ";
                            getline(cin,outgoname);
                            cout<<"\nPlease enter the payment frequency."<<endl;
                            cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                            int newfreq;
                            cin>>newfreq;
                            cout<<"Please enter the amount received based on frequency."<<endl;
                            double newamount;
                            cin>>newamount;
                            cout<<endl;
                            transcurr -> setname(outgoname); /// insert user data with pointers
                            transcurr -> setfrequency(newfreq);
                            transcurr -> setamount(newamount);
                            cin.ignore(); ///end of change code for transportation only.
                                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                            }

                        }
                else if (which == 'd' || which == 'D')///Start of change code for debts only.
                        {
                        if (debthead == NULL)
                            {
                            cout<<endl;
                            cout<<"Hey! You can't change an outgo that you never entered!"<<endl;
                            }
                        else
                            {
                            cout<<endl;
                            cout<<"Please enter the name assigned to the debt"<<endl;
                            cout<<"that you would like to change: ";
                            getline(cin,outgoname);
                            debtcurr = debthead;
                                while(debtcurr -> getname() != outgoname )
                                    {
                                    debtcurr = debtcurr ->getnext();
                                    }///end of while loop
                            cout<<"Please enter the new name for this debt: ";
                            getline(cin,outgoname);
                            cout<<"\nPlease enter the payment frequency."<<endl;
                            cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                            int newfreq;
                            cin>>newfreq;
                            cout<<"Please enter the amount received based on frequency."<<endl;
                            double newamount;
                            cin>>newamount;
                            cout<<endl;
                            debtcurr -> setname(outgoname); /// insert user data with pointers
                            debtcurr -> setfrequency(newfreq);
                            debtcurr -> setamount(newamount);
                            cin.ignore();                               ///end of change code for debt only.
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                            }
                        }
                else if (which == 's'|| which == 'S')///Start of change code for savings only.
                        {
                        if (savehead == NULL)
                            {
                            cout<<endl;
                            cout<<"Hey! You can't change an outgo that you never entered!"<<endl;
                            }
                        else
                            {
                            cout<<endl;
                            cout<<"Please enter the name assigned to the savings"<<endl;
                            cout<<"that you would like to change: ";
                            getline(cin,outgoname);
                            savecurr = savehead;
                                while(savecurr -> getname() != outgoname )
                                    {
                                    savecurr = savecurr ->getnext();
                                    }///end of while loop
                            cout<<"Please enter the new name for this form of saving: ";
                            getline(cin,outgoname);
                            cout<<"\nPlease enter the saving frequency."<<endl;
                            cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                            int newfreq;
                            cin>>newfreq;
                            cout<<"Please enter the amount saved based on frequency."<<endl;
                            double newamount;
                            cin>>newamount;
                            cout<<endl;
                            savecurr -> setname(outgoname); /// insert user data with pointers
                            savecurr -> setfrequency(newfreq);
                            savecurr -> setamount(newamount);
                            cin.ignore();                       ///end of change code for saving only.
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                            }
                        }
                  else if (which == 'g'|| which == 'G')///Start of change code for general expenses only.
                        {
                        if (genhead == NULL)
                            {
                            cout<<endl;
                            cout<<"Hey! You can't change an outgo that you never entered!"<<endl;
                            }
                        else
                            {
                            cout<<endl;
                            cout<<"Please enter the name assigned to the general expense"<<endl;
                            cout<<"that you would like to change: ";
                            getline(cin,outgoname);
                            gencurr = genhead;
                                while(gencurr -> getname() != outgoname )
                                    {
                                    gencurr = gencurr ->getnext();
                                    }///end of while loop
                            cout<<"Please enter the new name for this general expense: ";
                            getline(cin,outgoname);
                            cout<<"\nPlease enter the payment frequency."<<endl;
                            cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                            int newfreq;
                            cin>>newfreq;
                            cout<<"Please enter the amount based on frequency."<<endl;
                            double newamount;
                            cin>>newamount;
                            cout<<endl;
                            gencurr -> setname(outgoname); /// insert user data with pointers
                            gencurr -> setfrequency(newfreq);
                            gencurr -> setamount(newamount);
                            cin.ignore();                       ///end of change code for general expense only.
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                            }
                        }
                }  ///end of ALL change code
            else if (ans == 2)
                {
                cout<<"Where would you like to remove an outgo from?"<<endl<<endl;
                cout<<"(h)ousing / (t)ransporation / (d)ebts / (s)avings / (g)eneral expenses"<<endl<<endl;
                cout<<"Please enter the corresponding character: ";
                cin>>which;
                cin.ignore();
                if (which == 'h'|| which == 'H')///start of remove code for housing only
                    {
                    cout<<endl;
                    cout<<"Please enter the name of outgo that you would like to \nremove from housing: ";
                    getline(cin,outgoname);
                    housecurr = househead;
                    houseprev = househead;
                    while(housecurr -> getname() != outgoname)
                                {
                                houseprev = housecurr;
                                housecurr = housecurr -> getnext();
                                }
                            if(housecurr == househead)
                                {
                                househead = househead ->getnext();
                                housecurr -> setnext(NULL);
                                delete (housecurr);
                                }
                            else
                                {
                                houseprev->setnext(housecurr->getnext());
                                housecurr -> setnext(NULL);
                                delete housecurr;
                                }
                                    ///end of remove code for housing only
                                    cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                    }
                else if (which == 't'|| which == 'T') /// start of remove code for transportation only
                    {
                    cout<<endl;
                    cout<<"Please enter the name of outgo that you would like to \nremove from transportation: ";
                    getline(cin,outgoname);
                    transcurr = transhead;
                    transprev = transhead;
                    while(transcurr -> getname() != outgoname)
                                {
                                transprev = transcurr;
                                transcurr = transcurr -> getnext();
                                }
                            if(transcurr == transhead)
                                {
                                transhead = transhead ->getnext();
                                transcurr -> setnext(NULL);
                                delete (transcurr);
                                }
                            else
                                {
                                transprev->setnext(transcurr->getnext());
                                transcurr -> setnext(NULL);
                                delete transcurr;
                                }
                                    ///end of remove code for general expenses only
                                  cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}


                    }
                else if (which == 'd'|| which == 'D')///start of remove code for debts only
                    {
                    cout<<endl;
                    cout<<"Please enter the name of outgo that you would like to \nremove from debts: ";
                    getline(cin,outgoname);
                    debtcurr = debthead;
                    debtprev = debthead;
                    while(debtcurr -> getname() != outgoname)
                                {
                                debtprev = debtcurr;
                                debtcurr = debtcurr -> getnext();
                                }
                            if(debtcurr == debthead)
                                {
                                debthead = debthead ->getnext();
                                debtcurr -> setnext(NULL);
                                delete (debtcurr);
                                }
                            else
                                {
                                debtprev->setnext(debtcurr->getnext());
                                debtcurr -> setnext(NULL);
                                delete debtcurr;
                                }
                                    ///end of remove code for general expenses only
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                    }
                else if (which == 's'|| which == 'S')              ///start of remove code for savings only
                    {
                    cout<<endl;
                    cout<<"Please enter the name of outgo that you would like to \nremove from savings: ";
                    getline(cin,outgoname);
                    savecurr = savehead;
                    saveprev = savehead;
                    while(savecurr -> getname() != outgoname)
                                {
                                saveprev = savecurr;
                                savecurr = savecurr -> getnext();
                                }
                            if(savecurr == savehead)
                                {
                                savehead = savehead ->getnext();
                                savecurr -> setnext(NULL);
                                delete (savecurr);
                                }
                            else
                                {
                                saveprev->setnext(savecurr->getnext());
                                savecurr -> setnext(NULL);
                                delete savecurr;
                                }                   ///end of remove code for general expenses only
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                    }
                else if (which == 'g' || which == 'G')///start of remove code for general expenses only
                    {
                    cout<<endl;
                    cout<<"Please enter the name of outgo that you would like to \nremove from general expenses: ";
                    getline(cin,outgoname);
                    gencurr = genhead;
                    genprev = genhead;
                    while(gencurr -> getname() != outgoname)
                                {
                                genprev = gencurr;
                                gencurr = gencurr -> getnext();
                                }
                            if(gencurr == genhead)
                                {
                                genhead = genhead ->getnext();
                                gencurr -> setnext(NULL);
                                delete (gencurr);
                                }
                            else
                                {
                                genprev->setnext(gencurr->getnext());
                                gencurr -> setnext(NULL);
                                delete gencurr;
                                }///end of remove code for general expenses only
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                    }///end of ALL remove code
                }
            else if (ans == 3)///Start of ADD code
                {
                cout<<"In which category would you like to add an outgo?"<<endl<<endl;
                cout<<"(h)ousing / (t)ransporation / (d)ebts / (s)avings / (g)eneral expenses"<<endl<<endl;
                cout<<"Please enter the corresponding character: ";
                cin>>which;
                cin.ignore();
                    if (which == 'h' || which == 'H')
                        {
                        cout<<"Enter name of housing expense: ";
                        getline(cin,outgoname);
                        cout<<"\nPlease enter the frequency of payment"<<endl;
                        cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                        int newfreq;
                        cin>>newfreq;
                        cout<<"Please enter the amount taken based on frequency."<<endl;
                        double newamount;
                        cin>>newamount;
                        string type = "Housing";
                        cout<<endl;
                        housecurr = househead;
                        houseprev = househead;
                            if (househead == NULL)
                                {
                                househead = new outgo;
                                househead ->setname(outgoname);
                                househead ->setfrequency(newfreq);
                                househead ->setamount(newamount);
                                househead ->settype(type);
                                }
                           else if (househead != NULL)
                            {
                               while (housecurr != NULL)
                                    {
                                    houseprev = housecurr;
                                    housecurr = housecurr -> getnext();
                                    }
                            houseprev -> makenew();
                            housecurr = houseprev -> getnext();
                            housecurr -> setname(outgoname); /// insert user data with pointers
                            housecurr -> setfrequency(newfreq);
                            housecurr -> setamount(newamount);
                            housecurr ->settype(type);
                            }
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                        }
                    else if (which == 't'|| which == 'T')
                        {
                        cout<<"Enter name of transportation expense: ";
                        getline(cin,outgoname);
                        cout<<"\nPlease enter the frequency of payment"<<endl;
                        cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                        int newfreq;
                        cin>>newfreq;
                        cout<<"Please enter the amount taken based on frequency."<<endl;
                        double newamount;
                        cin>>newamount;
                        string type = "Transportation";
                        cout<<endl;
                        transcurr = transhead;
                        transprev = transhead;
                            if (transhead == NULL)
                                {
                                transhead = new outgo;
                                transhead ->setname(outgoname);
                                transhead ->setfrequency(newfreq);
                                transhead ->setamount(newamount);
                                transhead ->settype(type);
                                }
                           else if (transhead != NULL)
                            {
                               while (transcurr != NULL)
                                    {
                                    transprev = transcurr;
                                    transcurr = transcurr -> getnext();
                                    }
                            transprev -> makenew();
                            transcurr = transprev -> getnext();
                            transcurr -> setname(outgoname); /// insert user data with pointers
                            transcurr -> setfrequency(newfreq);
                            transcurr -> setamount(newamount);
                            transcurr ->settype(type);
                            }
                                                     cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}


                        }
                    else if (which == 'd'|| which == 'D')
                        {
                        cout<<"Enter name of debt: ";
                        getline(cin,outgoname);
                        cout<<"\nPlease enter the frequency of payment"<<endl;
                        cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                        int newfreq;
                        cin>>newfreq;
                        cout<<"Please enter the amount taken based on frequency."<<endl;
                        double newamount;
                        cin>>newamount;
                        string type = "Debts";
                        cout<<endl;
                        debtcurr = debthead;
                        debtprev = debthead;
                            if (debthead == NULL)
                                {
                                debthead = new outgo;
                                debthead ->setname(outgoname);
                                debthead ->setfrequency(newfreq);
                                debthead ->setamount(newamount);
                                debthead ->settype(type);
                                }
                           else if (debthead != NULL)
                            {
                               while (debtcurr != NULL)
                                    {
                                    debtprev = debtcurr;
                                    debtcurr = debtcurr -> getnext();
                                    }
                            debtprev -> makenew();
                            debtcurr = debtprev -> getnext();
                            debtcurr -> setname(outgoname); /// insert user data with pointers
                            debtcurr -> setfrequency(newfreq);
                            debtcurr -> setamount(newamount);
                            debtcurr ->settype(type);
                            }
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}


                        }
                    else if (which == 's'|| which == 'S')
                        {
                        cout<<"Enter name of savings: ";
                        getline(cin,outgoname);
                        cout<<"\nPlease enter the frequency of savings"<<endl;
                        cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                        int newfreq;
                        cin>>newfreq;
                        cout<<"Please enter the amount based on frequency."<<endl;
                        double newamount;
                        cin>>newamount;
                        string type = "Savings";
                        cout<<endl;
                        savecurr = savehead;
                        saveprev = savehead;
                            if (savehead == NULL)
                                {
                                savehead = new outgo;
                                savehead ->setname(outgoname);
                                savehead ->setfrequency(newfreq);
                                savehead ->setamount(newamount);
                                savehead ->settype(type);
                                }
                           else if (savehead != NULL)
                            {
                               while (savecurr != NULL)
                                    {
                                    saveprev = savecurr;
                                    savecurr = savecurr -> getnext();
                                    }
                            saveprev -> makenew();
                            savecurr = saveprev -> getnext();
                            savecurr -> setname(outgoname); /// insert user data with pointers
                            savecurr -> setfrequency(newfreq);
                            savecurr -> setamount(newamount);
                            savecurr ->settype(type);
                            }
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}


                        }
                    else if (which == 'g'|| which == 'G')
                        {
                        cout<<"Enter name of general expense: ";
                        getline(cin,outgoname);
                        cout<<"\nPlease enter the frequency of payment"<<endl;
                        cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                        int newfreq;
                        cin>>newfreq;
                        cout<<"Please enter the amount taken based on frequency."<<endl;
                        double newamount;
                        cin>>newamount;
                        string type = "General Expenses";
                        cout<<endl;
                        gencurr = genhead;
                        genprev = genhead;
                            if (genhead == NULL)
                                {
                                genhead = new outgo;
                                genhead ->setname(outgoname);
                                genhead ->setfrequency(newfreq);
                                genhead ->setamount(newamount);
                                genhead ->settype(type);
                                }
                           else if (genhead != NULL)
                            {
                               while (gencurr != NULL)
                                    {
                                    genprev = gencurr;
                                    gencurr = gencurr -> getnext();
                                    }
                            genprev -> makenew();
                            gencurr = genprev -> getnext();
                            gencurr -> setname(outgoname); /// insert user data with pointers
                            gencurr -> setfrequency(newfreq);
                            gencurr -> setamount(newamount);
                            gencurr ->settype(type);
                            }
                        }
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}


                }           ///End of ADD code


            }
cout<<endl;
cout<<"This is what you have entered for income and outgos."<<endl<<endl;

                ///display the matrix
            cout<<"\t\t\t\tIncome List"<<endl;
            cout<<"\t\t\t\t-----------"<<endl;
            cout<<endl;
            earnedcurr = earnedhead;
            cout<<"Earned Income: "<<endl;
            while(earnedcurr!=NULL)
                    {
                    earnedcurr -> display();
                    cout<<endl;
                    earnedcurr = earnedcurr -> getnext();
                    }
            cout<<endl;
            unearnedcurr = unearnedhead;
            cout<<"Unearned Income: "<<endl;
            while(unearnedcurr!=NULL)
                        {
                        unearnedcurr -> display();
                        cout<<endl;
                        unearnedcurr = unearnedcurr -> getnext();
                        }
            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
            cout<<"\t\t\t\t----------"<<endl;
            cout<<endl;
            cout<<"Housing: "<<endl;
            if (househead != NULL) {househead -> showall();}
            else {cout<<"No housing expenses entered.";}
            cout<<endl<<endl;
            cout<<"Transportation: "<<endl;
            if (transhead != NULL) {transhead -> showall();}
            else {cout<<"No transportation expenses entered";}
            cout<<endl<<endl;
            cout<<"Debts: "<<endl;
            if (debthead != NULL) {debthead -> showall();}
            else {cout<<"No debt expenses entered";}
            cout<<endl<<endl;
            cout<<"Savings: "<<endl;
            if (savehead != NULL) {savehead -> showall();}
            else {cout<<"No savings entered";}
            cout<<endl<<endl;
            cout<<"General Expenses: "<<endl;
            if (genhead != NULL) {genhead -> showall();}
            else {cout<<"No general expenses entered.";}
            ///Display totals
            cout<<endl<<endl;
            cout<<"All the information you entered will be compiled now!"<<endl<<endl;
            cout<<endl;
            cout<<"\t\t\t\tMonthly Totals"<<endl; ///display outgo matrix
            cout<<"\t\t\t\t--------------"<<endl;
            cout<<"Income:"<<endl;
            cout<<"-------"<<endl;
                if (earnedhead != NULL) ///---------------------------------income totals
                    {
                    monthtotal = earnedhead -> totalincome();
                    etotal = monthtotal;
                    cout<<"The monthly total for earned income is $"<<fixed<<setprecision(2)<<etotal<<". "<<endl<<endl;
                    }
                else
                    {
                    monthtotal = 0.0;
                    etotal = monthtotal;
                    cout<<"The monthly total for earned income is $"<<fixed<<setprecision(2)<<etotal<<". "<<endl<<endl;
                    }
                if (unearnedhead !=NULL)
                    {
                    monthtotal = unearnedhead -> totalincome();
                    utotal = monthtotal;
                    cout<<"The monthly total for unearned income is $"<<fixed<<setprecision(2)<<utotal<<". "<<endl<<endl;
                    }
                else
                    {
                    monthtotal = 0.0;
                    utotal = monthtotal;
                    cout<<"The monthly total for unearned income is $"<<fixed<<setprecision(2)<<utotal<<". "<<endl<<endl;
                    }                   ///-------------------------end of income totals
            cout<<"Outgos:"<<endl; ///--------Start of outgo totals
            cout<<"-------"<<endl;
                if (househead != NULL)
                    {
                    monthtotal = househead -> totaloutgo();
                    htotal = monthtotal;
                    cout<<"The monthly total for housing expenses is $"<<fixed<<setprecision(2)<<htotal<<". "<<endl<<endl;
                    }
                else
                    {
                    monthtotal = 0.0;
                    htotal = monthtotal;
                    cout<<"The monthly total for housing expenses is $"<<fixed<<setprecision(2)<<htotal<<". "<<endl<<endl;
                    }
                if (transhead != NULL)
                    {
                    monthtotal = transhead -> totaloutgo();
                    ttotal = monthtotal;
                    cout<<"The monthly total for transportation expenses is $"<<fixed<<setprecision(2)<<ttotal<<". "<<endl<<endl;
                    }
                else
                    {
                    monthtotal = 0.0;
                    ttotal = monthtotal;
                    cout<<"The monthly total for transportation expenses is $"<<fixed<<setprecision(2)<<ttotal<<". "<<endl<<endl;
                    }
                if (debthead != NULL)
                    {
                    monthtotal = debthead -> totaloutgo();
                    dtotal = monthtotal;
                    cout<<"The monthly total for debt expenses is $"<<fixed<<setprecision(2)<<dtotal<<". "<<endl<<endl;
                    }
                else
                    {
                    monthtotal = 0.0;
                    dtotal = monthtotal;
                    cout<<"The monthly total for debt expenses is $"<<fixed<<setprecision(2)<<dtotal<<". "<<endl<<endl;
                    }
                if (savehead != NULL)
                    {
                    monthtotal = savehead -> totaloutgo();
                    stotal = monthtotal;
                    cout<<"The monthly total for savings is $"<<fixed<<setprecision(2)<<stotal<<". "<<endl<<endl;
                    }
                else
                    {
                    monthtotal = 0.0;
                    stotal = monthtotal;
                    cout<<"The monthly total for savings is $"<<fixed<<setprecision(2)<<stotal<<". "<<endl<<endl;
                    }
                 if (genhead != NULL)
                    {
                    monthtotal = genhead -> totaloutgo();
                    gtotal = monthtotal;
                    cout<<"The monthly total for general expenses is $"<<fixed<<setprecision(2)<<gtotal<<". "<<endl<<endl;
                    }
                else
                    {
                    monthtotal = 0.0;
                    gtotal = monthtotal;
                    cout<<"The monthly total for general expenses is $"<<fixed<<setprecision(2)<<gtotal<<". "<<endl<<endl;
                    }///end of outgo totals
            cout<<"Totals:"<<endl; ///--------Start of outgo totals
            cout<<"-------"<<endl;
            double incometotal;
            incometotal = incomesum(etotal,utotal);
            cout<<"The total income for the month is $"<<fixed<<setprecision(2)<<incometotal<<". "<<endl<<endl;
            double outgototal;
            outgototal = outgosum(htotal,ttotal,dtotal,stotal,gtotal);
            cout<<"The total outgo for the month is $"<<fixed<<setprecision(2)<<outgototal<<". "<<endl<<endl;
            double remainder = leftover(incometotal,outgototal);
            if (remainder < 0)
                {
            cout<<"You have over spent by $"<<fixed<<setprecision(2)<<abs(remainder)<<"."<<endl<<endl;
                }
            else if (remainder == 0)
                {
                cout<<"There is nothing left over for this month."<<endl<<endl;
                }
            else if (remainder > 0)
                {
                double lpercent;
                lpercent = percentleftover(remainder,incometotal);
                cout<<"%"<<lpercent<<" of your income is leftover for this month."<<endl<<endl;
                }
    cout<<"\t\t\t\tIdeal vs Reality"<<endl;///Ideal vs reality
    cout<<"\t\t\t\t-----------------"<<endl;
    cout<<"Reality Percentages:"<<endl;
    cout<<"-------------------"<<endl;
    double hpercent = percenthousing(htotal,incometotal);
    double tpercent = percenttrans(ttotal,incometotal);
    double dpercent = percentdebt(dtotal,incometotal);
    double spercent = percentsavings(stotal,incometotal);
    double gpercent = percentgeneralex(gtotal,incometotal);
    cout<<"Your housing percentage is %"<<fixed<<setprecision(2)<<hpercent<<"."<<endl<<endl;
    cout<<"Your transportation percentage is %"<<fixed<<setprecision(2)<<tpercent<<"."<<endl<<endl;
    cout<<"Your debt repayment percentage is %"<<fixed<<setprecision(2)<<dpercent<<"."<<endl<<endl;
    cout<<"Your savings percentage is %"<<fixed<<setprecision(2)<<spercent<<"."<<endl<<endl;
    cout<<"Your general expense percentage is %"<<fixed<<setprecision(2)<<gpercent<<"."<<endl<<endl;
    cout<<"Ideal Percentages:"<<endl; ///--------Start of outgo totals
    cout<<"------------------"<<endl;
    double iHamount = idealHamount(incometotal,0.35);
    double iTamount = idealTamount(incometotal,0.15);
    double iDamount = idealDamount(incometotal,0.15);
    double iSamount = idealSamount(incometotal,0.10);
    double iGamount = idealGamount(incometotal,0.25);
    cout<<"Housing should be %"<<35<<" of your total income; which amounts to $"<<iHamount<<"."<<endl<<endl;
    cout<<"Transportation should be %"<<15<<" of your total income; which amounts to $"<<iTamount<<"."<<endl<<endl;
    cout<<"Debt repayment should be %"<<15<<" of your total income; which amounts to $"<<iDamount<<"."<<endl<<endl;
    cout<<"Savings should be %"<<10<<" of your total income; which amounts to $"<<iSamount<<"."<<endl<<endl;
    cout<<"General expenses should be %"<<25<<" of your total income; which amounts to $"<<iGamount<<"."<<endl<<endl;
    fstream fout1,fout2,fout3,fout4,fout5,fout6,fout7,fout8;/*******************************Enter in File!****/
    fout1.open("earned.txt",ios::out);
    earnedcurr = earnedhead;
    unearnedcurr = unearnedhead;
    housecurr = househead;
    transcurr = transhead;
    debtcurr = debthead;
    savecurr = savehead;
    gencurr = genhead;
    while (earnedcurr != NULL)///**********fill earned file
        {
        fout1<<earnedcurr->getname();
        fout1<<endl;
        fout1<<earnedcurr -> getfrequency();
        fout1<<endl;
        fout1<<earnedcurr ->getamount();
        fout1<<endl;
        earnedcurr = earnedcurr -> getnext();
        }///end of earned file
        fout1.close();
    fout2.open("unearned.txt",ios::out);
    while (unearnedcurr != NULL)///**********fill unearned file
        {
        fout2<<unearnedcurr->getname();
        fout2<<endl;
        fout2<<unearnedcurr->getfrequency();
        fout2<<endl;
        fout2<<unearnedcurr->getamount();
        fout2<<endl;
        unearnedcurr = unearnedcurr -> getnext();
        }///end of unearned file
        fout2.close();
    fout3.open("housing.txt",ios::out);
    while (housecurr != NULL)///**********fill in housing file
        {
        fout3<<housecurr->getname();
        fout3<<endl;
        fout3<<housecurr ->getfrequency();
        fout3<<endl;
        fout3<<housecurr ->getamount();
        fout3<<endl;
        housecurr = housecurr -> getnext();
        }///end of housing file
        fout3.close();
    fout4.open("transportation.txt",ios::out);
    while (transcurr != NULL)///**********fill in transportation from file
        {
        fout4<<transcurr->getname();
        fout4<<endl;
        fout4<<transcurr->getfrequency();
        fout4<<endl;
        fout4<<transcurr->getamount();
        fout4<<endl;
        transcurr = transcurr -> getnext();
        }///end of transportation file
        fout4.close();
    fout5.open("debt.txt",ios::out);
    while (debtcurr != NULL)///**********fill in debt from file
        {
        fout5<<debtcurr->getname();
        fout5<<endl;
        fout5<<debtcurr->getfrequency();
        fout5<<endl;
        fout5<<debtcurr->getamount();
        fout5<<endl;
        debtcurr = debtcurr -> getnext();
        }///end of debt file
        fout5.close();
    fout6.open("savings.txt",ios::out);
    while (savecurr != NULL)///**********fill in saving from file
        {
        fout6<<savecurr->getname();
        fout6<<endl;
        fout6<<savecurr->getfrequency();
        fout6<<endl;
        fout6<<savecurr->getamount();
        fout6<<endl;
        savecurr = savecurr -> getnext();
        }///end of save file
        fout6.close();
    fout7.open("generalexp.txt",ios::out);
    while (gencurr != NULL)///**********fill in general expenses from file
        {
        fout7<<gencurr->getname();
        fout7<<endl;
        fout7<<gencurr->getfrequency();
        fout7<<endl;
        fout7<<gencurr->getamount();
        fout7<<endl;
        gencurr = gencurr ->getnext();
        }///end of general expense file
        fout7.close();
    fout8.open("data.txt",ios::out);
        fout8<<"Housing "<<hpercent<<" "<<35.0<<endl;
        fout8<<"Transportation "<<tpercent<<" "<<15.0<<endl;
        fout8<<"DebtRepayment "<<dpercent<<" "<<15.0<<endl;
        fout8<<"Savings "<<spercent<<" "<<10.0<<endl;
        fout8<<"GeneralExpenses "<<gpercent<<" "<<25.0;
        fout8.close();
    }
else if (input == 'N' || input == 'n')
    {
    cout<<"First, we will start with income."<<endl<<endl;
    cout<<"There are two types of income: earned income and unearned income."<<endl<<endl;
    cout<<"Earned income includes salary or commission in exchange for"<<endl;
    cout<<"services."<<endl<<endl;
    cout<<"Unearned income includes retirement benefits, dividends, child support"<<endl;
    cout<<"royalties, prizes, gifts, etc."<<endl<<endl;
    cout<<"How many forms of 'earned income' would you like to enter? ";
    cin>>earnednum;
    cout<<endl;

    cout<<"How many forms of 'unearned income' would you like to enter? ";
    cin>>unearnednum;
    cout<<endl;
    cin.ignore();

        for (int i=0; i<earnednum; i++) ///Fill in EARNED only
            {
                if (earnedhead == NULL) ///If earnedhead is at null, create new income
                    {
                    earnedhead = new income;
                    earnedcurr = earnedhead;
                    int counter = i;
                    cout<<"Earned Income "<<counter+1<<":"<<endl;
                    cout<<"----------------"<<endl;
                    cout<<"Enter name of income: ";
                    getline(cin,incomename);
                    cout<<"\nPlease enter the earned income frequency."<<endl;
                    cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                    int newfreq;
                    cin>>newfreq;
                    cout<<"Please enter the amount received based on frequency."<<endl;
                    double newamount;
                    cin>>newamount;
                    cout<<endl;
                    earnedhead -> setname(incomename); /// insert user data with pointers
                    earnedhead -> setfrequency(newfreq);
                    earnedhead -> setamount(newamount);
                    cin.ignore();
                    }
                else
                    {
                    earnedcurr -> makenew();
                    earnedcurr = earnedcurr -> getnext();
                    int counter = i;
                    cout<<"Earned Income "<<counter+1<<":"<<endl;
                    cout<<"----------------"<<endl;
                    cout<<"Enter name of income: ";
                    getline(cin,incomename);
                    cout<<"\nPlease enter the earned income frequency."<<endl;
                    cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                    int newfreq;
                    cin>>newfreq;
                    cout<<"Please enter the amount received based on frequency."<<endl;
                    double newamount;
                    cin>>newamount;
                    cout<<endl;
                    earnedcurr -> setname(incomename); /// insert user data with pointers
                    earnedcurr -> setfrequency(newfreq);
                    earnedcurr -> setamount(newamount);
                    cin.ignore();
                    }
            }
        for (int i=0; i<unearnednum; i++) ///Fill in UNEARNED only
            {
                  if (unearnedhead == NULL) ///If unearnedhead is at null, create new income
                    {
                    unearnedhead = new income;
                    unearnedcurr = unearnedhead;
                    int counter = i;
                    cout<<"Unearned Income "<<counter+1<<":"<<endl;
                    cout<<"----------------"<<endl;
                    cout<<"Enter name of income: ";
                    getline(cin,incomename);
                    cout<<"\nPlease enter the unearned income frequency."<<endl;
                    cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                    int newfreq;
                    cin>>newfreq;
                    cout<<"Please enter the amount received based on frequency."<<endl;
                    double newamount;
                    cin>>newamount;
                    cout<<endl;
                    string type = "Unearned";
                    unearnedhead -> setname(incomename); /// insert user data with pointers
                    unearnedhead -> setfrequency(newfreq);
                    unearnedhead -> setamount(newamount);
                    unearnedhead -> settype(type);
                    cin.ignore();
                    }
                else
                    {
                    unearnedcurr -> makenew();
                    unearnedcurr = unearnedcurr -> getnext();
                    int counter = i;
                    cout<<"Unearned Income "<<counter+1<<":"<<endl;
                    cout<<"-----------------"<<endl;
                    cout<<"Enter name of income: ";
                    getline(cin,incomename);
                    cout<<"\nPlease enter the unearned income frequency."<<endl;
                    cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                    int newfreq;
                    cin>>newfreq;
                    cout<<"Please enter the amount received based on frequency."<<endl;
                    double newamount;
                    cin>>newamount;
                    cout<<endl;
                    string type = "Unearned";
                    unearnedcurr -> setname(incomename); /// insert user data with pointers
                    unearnedcurr -> setfrequency(newfreq);
                    unearnedcurr -> setamount(newamount);
                    unearnedcurr -> settype(type);
                    cin.ignore();
                    }
            }
        cout<<"\t\t\t\tIncome List"<<endl; ///display the matrix
        cout<<"\t\t\t\t-----------"<<endl;
        cout<<endl;
        cout<<"Earned Income: "<<endl;
        if (earnedhead != NULL) {earnedhead -> showall();}
        else {cout<<"Earned income was not entered";}
        cout<<endl;
        cout<<"Unearned Income: "<<endl;
        if (unearnedhead != NULL) {unearnedhead -> showall();}
        else {cout<<"Unearned income was not entered";}
    int ans = 100;
      ///Ask user if they would like to change/remove/add income data, then move on to debts
    while (ans != 4)
            {
            ans = incomemenu();
            if (ans == 1) ///start of change code
                {
                cout<<"Would you like to change (e)arned or (u)nearned income? ";///start of change code for earned only
                cin>>which;
                    if (which == 'e'|| which == 'E')
                        {
                        if(earnedhead == NULL)
                            {
                            cout<<endl;
                            cout<<"Hey! You can't change an income that you never entered!"<<endl;
                            }
                        else
                            {
                            cout<<endl;
                            cin.ignore();
                            cout<<"Please enter the name assigned to the earned income"<<endl;
                            cout<<"you would like to change: ";
                            getline(cin,incomename);
                            earnedcurr = earnedhead;
                                while(earnedcurr -> getname() != incomename )
                                    {
                                    earnedcurr = earnedcurr ->getnext();
                                    }///end of while loop
                            cout<<"Please enter the new name of income: ";
                            getline(cin,newincomename);
                            cout<<"\nPlease enter the earned income frequency."<<endl;
                            cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                            int newfreq;
                            cin>>newfreq;
                            cout<<"Please enter the amount received based on frequency."<<endl;
                            double newamount;
                            cin>>newamount;
                            cout<<endl;
                            earnedcurr -> setname(newincomename); /// insert user data with pointers
                            earnedcurr -> setfrequency(newfreq);
                            earnedcurr -> setamount(newamount);
                            cin.ignore();///End of change code for earned
                            cout<<"\t\t\t\tIncome List"<<endl; ///display the matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Earned Income: "<<endl;
                            if (earnedhead != NULL) {earnedhead -> showall();}
                            else {cout<<"Earned income was not entered";}
                            cout<<endl;
                            cout<<"Unearned Income: "<<endl;
                            if (unearnedhead != NULL) {unearnedhead -> showall();}
                            else {cout<<"Unearned income was not entered";}
                            }
                        }
                    else if (which == 'u'|| which == 'U')///Start of change code for unearned only.
                        {
                        if (unearnedhead == NULL)
                            {
                            cout<<endl;
                            cout<<"Hey! You can't change an income that you never entered!"<<endl;
                            }
                        else
                            {
                            cout<<endl;
                            cin.ignore();
                            cout<<"Please enter the name assigned to the unearned income you would like to change: ";
                            getline(cin,incomename);
                            unearnedcurr = unearnedhead;
                                while(unearnedcurr -> getname() != incomename )
                                    {
                                    unearnedcurr = unearnedcurr ->getnext();
                                    }///end of while loop
                            cout<<"Please enter the NEW name of income: ";
                            getline(cin,newincomename);
                            cout<<"\nPlease enter the earned income frequency."<<endl;
                            cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                            int newfreq;
                            cin>>newfreq;
                            cout<<"Please enter the amount received based on frequency."<<endl;
                            double newamount;
                            cin>>newamount;
                            cout<<endl;
                            string type = "Unearned";
                            unearnedcurr -> setname(newincomename); /// insert user data with pointers
                            unearnedcurr -> setfrequency(newfreq);
                            unearnedcurr -> setamount(newamount);
                            unearnedcurr -> settype(type);
                            cin.ignore(); ///end of change code for unearned only.
                            cout<<"\t\t\t\tIncome List"<<endl; ///display the matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Earned Income: "<<endl;
                            if (earnedhead != NULL) {earnedhead -> showall();}
                            else {cout<<"Earned income was not entered";}
                            cout<<endl;
                            cout<<"Unearned Income: "<<endl;
                            if (unearnedhead != NULL) {unearnedhead -> showall();}
                            else {cout<<"Unearned income was not entered";}
                            }
                        }
                }                                                          ///end of change code
            else if (ans == 2)///Start of remove code
                    {
                    cout<<"Would you like to remove an (e)arned income or an (u)nearned income?"<<endl;
                    cin>>which;
                    cin.ignore();
                        if (which == 'e' || which == 'E')///start of remove code for earned only
                        {
                        cout<<endl;
                        cout<<"Please enter the name assigned to the income you would like to remove: ";
                        getline(cin,incomename);
                        earnedcurr = earnedhead;
                        earnedprev = earnedhead;
                            while(earnedcurr -> getname() != incomename)
                                {
                                earnedprev = earnedcurr;
                                earnedcurr = earnedcurr -> getnext();
                                }
                            if(earnedcurr == earnedhead)
                                {
                                earnedhead = earnedhead ->getnext();
                                earnedcurr -> setnext(NULL);
                                delete (earnedcurr);
                                }
                            else
                                {
                                earnedprev->setnext(earnedcurr->getnext());
                                earnedcurr -> setnext(NULL);
                                delete earnedcurr;
                                } ///end of remove code for earned only
                                          ///display the matrix
                            cout<<"\t\t\t\tIncome List"<<endl; ///display the matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Earned Income: "<<endl;
                            if (earnedhead != NULL) {earnedhead -> showall();}
                            else {cout<<"Earned income was not entered";}
                            cout<<endl;
                            cout<<"Unearned Income: "<<endl;
                            if (unearnedhead != NULL) {unearnedhead -> showall();}
                            else {cout<<"Unearned income was not entered";}
                        }
                        else if (which == 'u'|| which =='U')///start of remove code for unearned
                        {
                        cout<<endl;
                        cout<<"Please enter the name assigned to the income you would like to remove: ";
                        getline(cin,incomename);
                        unearnedcurr = unearnedhead;
                        unearnedprev = unearnedhead;
                            while(unearnedcurr -> getname() != incomename)
                                {
                                unearnedprev = unearnedcurr;
                                unearnedcurr = unearnedcurr -> getnext();
                                }
                            if(unearnedcurr == unearnedhead)
                                {
                                unearnedhead = unearnedhead ->getnext();
                                unearnedcurr -> setnext(NULL);
                                delete (unearnedcurr);
                                }
                            else
                                {
                                unearnedprev->setnext(unearnedcurr->getnext());
                                unearnedcurr -> setnext(NULL);
                                delete unearnedcurr;
                                }                   ///end of remove code for unearned only.
                            cout<<"\t\t\t\tIncome List"<<endl; ///display the matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Earned Income: "<<endl;
                            if (earnedhead != NULL) {earnedhead -> showall();}
                            else {cout<<"Earned income was not entered";}
                            cout<<endl;
                            cout<<"Unearned Income: "<<endl;
                            if (unearnedhead != NULL) {unearnedhead -> showall();}
                            else {cout<<"Unearned income was not entered";}
                        }
                    }
            else if (ans == 3) ///Start of ADD code
                    {
                    cout<<"Would you like to add an (e)arned income or an (u)nearned income?"<<endl;
                    cin>>which;
                        if (which == 'e' || which == 'E')
                        {
                        cin.ignore();
                        cout<<"Please enter the name of the new earned income: ";
                        getline(cin,incomename);
                        cout<<"\nPlease enter the earned income frequency."<<endl;
                        cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                        int newfreq;
                        cin>>newfreq;
                        cout<<"Please enter the amount received based on frequency."<<endl;
                        double newamount;
                        cin>>newamount;
                        cout<<endl;
                        string type = "Earned";
                        earnedcurr = earnedhead;
                        earnedprev = earnedhead;
                            if (earnedhead == NULL)
                                {
                                earnedhead = new income;
                                earnedhead ->setname(incomename);
                                earnedhead ->setfrequency(newfreq);
                                earnedhead ->setamount(newamount);
                                earnedhead ->settype(type);
                                }
                           else if (earnedhead != NULL)
                            {
                               while (earnedcurr != NULL)
                                    {
                                    earnedprev = earnedcurr;
                                    earnedcurr = earnedcurr -> getnext();
                                    }
                            earnedprev -> makenew();
                            earnedcurr = earnedprev -> getnext();
                            earnedcurr -> setname(incomename); /// insert user data with pointers
                            earnedcurr -> setfrequency(newfreq);
                            earnedcurr -> setamount(newamount);
                            earnedcurr ->settype(type);
                            }
                        cin.ignore();///End of change code for earned
                        cout<<"\t\t\t\tIncome List"<<endl; ///display the matrix
                        cout<<"\t\t\t\t-----------"<<endl;
                        cout<<endl;
                        cout<<"Earned Income: "<<endl;
                        if (earnedhead != NULL) {earnedhead -> showall();}
                        else {cout<<"Earned income was not entered";}
                        cout<<endl;
                        cout<<"Unearned Income: "<<endl;
                        if (unearnedhead != NULL) {unearnedhead -> showall();}
                        else {cout<<"Unearned income was not entered";}
                        }
                        else if (which == 'u'|| which =='U')
                        {
                        cin.ignore();
                        cout<<"Please enter the name of the new unearned income: ";
                        getline(cin,incomename);
                        cout<<"\nPlease enter the earned income frequency"<<endl;
                        cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                        int newfreq;
                        cin>>newfreq;
                        cout<<"Please enter the amount received based on frequency."<<endl;
                        double newamount;
                        cin>>newamount;
                        string type = "Unearned";
                        cout<<endl;
                        unearnedcurr = unearnedhead;
                        unearnedprev = unearnedhead;
                            if (unearnedhead == NULL)
                                {
                                unearnedhead = new income;
                                unearnedhead ->setname(incomename);
                                unearnedhead ->setfrequency(newfreq);
                                unearnedhead ->setamount(newamount);
                                unearnedhead ->settype(type);
                                }
                           else if (unearnedhead != NULL)
                            {
                               while (unearnedcurr != NULL)
                                    {
                                    unearnedprev = unearnedcurr;
                                    unearnedcurr = unearnedcurr -> getnext();
                                    }
                            unearnedprev -> makenew();
                            unearnedcurr = unearnedprev -> getnext();
                            unearnedcurr -> setname(incomename); /// insert user data with pointers
                            unearnedcurr -> setfrequency(newfreq);
                            unearnedcurr -> setamount(newamount);
                            unearnedcurr ->settype(type);
                            }
                        cin.ignore();///End of change code for earned
                        cout<<"\t\t\t\tIncome List"<<endl; ///display the matrix
                        cout<<"\t\t\t\t-----------"<<endl;
                        cout<<endl;
                        cout<<"Earned Income: "<<endl;
                        if (earnedhead != NULL) {earnedhead -> showall();}
                        else {cout<<"Earned income was not entered";}
                        cout<<endl;
                        cout<<"Unearned Income: "<<endl;
                        if (unearnedhead != NULL) {unearnedhead -> showall();}
                        else {cout<<"Unearned income was not entered";}
                        }
                    }
            }

    ///-------------------------------------------------------------------------------------------------------///
    ///NOW ONTO OUTGOS
    cout<<endl;
    cout<<"\t\t\t\tOutgo List"<<endl;
    cout<<"\t\t\t\t----------"<<endl;
    cout<<"This section is separated into 5 parts:"<<endl<<endl;
    cout<<"1) Housing - This includes rent, utilities, \nhousing insurance, home repairs, etc."<<endl<<endl;
    cout<<"2) Transportation - This includes public transit,\n gas, car insurance, car maintenance, etc."<<endl<<endl;
    cout<<"3) Debt Repayment - This is the money that you should\n be setting aside to pay off debts."<<endl<<endl;
    cout<<"4) Savings - This includes retirement savings, emergency\n funds, investing, and travel funds."<<endl<<endl;
    cout<<"5) General Expenses - This includes groceries, clothing,\n entertainment, pet expenses, medical needs, and more."<<endl<<endl;
    cout<<"How many entries would you like to enter for housing? ";
    cin>>each;
    cout<<endl;
    cin.ignore();
            for (int i =0; i < each; i++) ///Fill in housing
                {
                if (househead == NULL) ///If househead is at null, create new outgo
                    {
                    househead = new outgo;
                    housecurr = househead;
                    int counter = i;
                    cout<<"Housing Cost "<<counter+1<<":"<<endl;
                    cout<<"---------------"<<endl;
                    cout<<"Enter name of housing expense: ";
                    getline(cin,outgoname);
                    cout<<"\nPlease enter the frequency of payment"<<endl;
                    cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                    int newfreq;
                    cin>>newfreq;
                    cout<<"Please enter the amount taken based on frequency."<<endl;
                    double newamount;
                    cin>>newamount;
                    string type = "Housing";
                    cout<<endl;
                    househead -> setname(outgoname); /// insert user data with pointers
                    househead -> setfrequency(newfreq);
                    househead -> setamount(newamount);
                    househead -> settype(type);
                    cin.ignore();
                    }
                else
                    {
                    housecurr -> makenew();
                    housecurr = housecurr -> getnext();
                    int counter = i;
                    cout<<"Housing cost "<<counter+1<<":"<<endl;
                    cout<<"----------------"<<endl;
                    cout<<"Enter name of housing expense: ";
                    getline(cin,outgoname);
                    cout<<"\nPlease enter the payment frequency"<<endl;
                    cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                    int newfreq;
                    cin>>newfreq;
                    cout<<"Please enter the amount taken based on frequency."<<endl;
                    double newamount;
                    cin>>newamount;
                    string type = "Housing";
                    cout<<endl;
                    housecurr -> setname(outgoname); /// insert user data with pointers
                    housecurr -> setfrequency(newfreq);
                    housecurr -> setamount(newamount);
                    housecurr -> settype(type);
                    cin.ignore();
                    }
                }
cout<<"How many entries would you like to enter for transportation? ";///Now the user will enter transportation costs
    cin>>each;
    cout<<endl;
    cin.ignore();
            for (int i =0; i < each; i++) ///Fill in transportation
                {
                if (transhead == NULL) ///If transhead is at null, create new outgo
                    {
                    transhead = new outgo;
                    transcurr = transhead;
                    int counter = i;
                    cout<<"Transportation Cost "<<counter+1<<":"<<endl;
                    cout<<"--------------------"<<endl;
                    cout<<"Enter name of transportation expense: ";
                    getline(cin,outgoname);
                    cout<<"\nPlease enter the frequency of payment"<<endl;
                    cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                    int newfreq;
                    cin>>newfreq;
                    cout<<"Please enter the amount taken based on frequency."<<endl;
                    double newamount;
                    cin>>newamount;
                    string type = "Transportation";
                    cout<<endl;
                    transhead -> setname(outgoname); /// insert user data with pointers
                    transhead -> setfrequency(newfreq);
                    transhead -> setamount(newamount);
                    transhead -> settype(type);
                    cin.ignore();
                    }
                else
                    {
                    transcurr -> makenew();
                    transcurr = transcurr -> getnext();
                    int counter = i;
                    cout<<"Transportation cost "<<counter+1<<":"<<endl;
                    cout<<"-------------------"<<endl;
                    cout<<"Enter name of transportation expense: ";
                    getline(cin,outgoname);
                    cout<<"\nPlease enter the payment frequency"<<endl;
                    cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                    int newfreq;
                    cin>>newfreq;
                    cout<<"Please enter the amount taken based on frequency."<<endl;
                    double newamount;
                    cin>>newamount;
                    string type = "Transportation";
                    cout<<endl;
                    transcurr -> setname(outgoname); /// insert user data with pointers
                    transcurr -> setfrequency(newfreq);
                    transcurr -> setamount(newamount);
                    transcurr -> settype(type);
                    cin.ignore();
                    }
                }
cout<<"How many entries would you like to enter for debt repayment? ";
    cin>>each;
    cout<<endl;
    cin.ignore();
            for (int i =0; i < each; i++) ///Fill in debt info
                {
                if (debthead == NULL) ///If debthead is at null, create new outgo
                    {
                    debthead = new outgo;
                    debtcurr = debthead;
                    int counter = i;
                    cout<<"Debt Repayment Cost "<<counter+1<<":"<<endl;
                    cout<<"--------------------"<<endl;
                    cout<<"Enter name of debt: ";
                    getline(cin,outgoname);
                    cout<<"\nPlease enter the frequency of payment"<<endl;
                    cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                    int newfreq;
                    cin>>newfreq;
                    cout<<"Please enter the amount taken based on frequency."<<endl;
                    double newamount;
                    cin>>newamount;
                    string type = "Debt";
                    cout<<endl;
                    debthead -> setname(outgoname); /// insert user data with pointers
                    debthead -> setfrequency(newfreq);
                    debthead -> setamount(newamount);
                    debthead -> settype(type);
                    cin.ignore();
                    }
                else
                    {
                    debtcurr -> makenew();
                    debtcurr = debtcurr -> getnext();
                    int counter = i;
                    cout<<"Debt Repayment Cost "<<counter+1<<":"<<endl;
                    cout<<"-------------------"<<endl;
                    cout<<"Enter name of debt: ";
                    getline(cin,outgoname);
                    cout<<"\nPlease enter the payment frequency"<<endl;
                    cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                    int newfreq;
                    cin>>newfreq;
                    cout<<"Please enter the amount taken based on frequency."<<endl;
                    double newamount;
                    cin>>newamount;
                    string type = "Debt";
                    cout<<endl;
                    debtcurr -> setname(outgoname); /// insert user data with pointers
                    debtcurr -> setfrequency(newfreq);
                    debtcurr -> setamount(newamount);
                    debtcurr -> settype(type);
                    cin.ignore();
                    }
                }
cout<<"How many entries would you like to enter for savings? ";
    cin>>each;
    cout<<endl;
    cin.ignore();
            for (int i =0; i < each; i++) ///Fill in savings info
                {
                if (savehead == NULL) ///If savehead is at null, create new outgo
                    {
                    savehead = new outgo;
                    savecurr = savehead;
                    int counter = i;
                    cout<<"Saving "<<counter+1<<":"<<endl;
                    cout<<"---------"<<endl;
                    cout<<"Enter name of saving: ";
                    getline(cin,outgoname);
                    cout<<"\nPlease enter the frequency of setting aside saving"<<endl;
                    cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                    int newfreq;
                    cin>>newfreq;
                    cout<<"Please enter the amount based on frequency."<<endl;
                    double newamount;
                    cin>>newamount;
                    string type = "Savings";
                    cout<<endl;
                    savehead -> setname(outgoname); /// insert user data with pointers
                    savehead -> setfrequency(newfreq);
                    savehead -> setamount(newamount);
                    savehead -> settype(type);
                    cin.ignore();
                    }
                else
                    {
                    savecurr -> makenew();
                    savecurr = savecurr -> getnext();
                    int counter = i;
                    cout<<"Saving "<<counter+1<<":"<<endl;
                    cout<<"-------------"<<endl;
                    cout<<"Enter name of saving: ";
                    getline(cin,outgoname);
                    cout<<"\nPlease enter the frequency of setting aside saving."<<endl;
                    cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                    int newfreq;
                    cin>>newfreq;
                    cout<<"Please enter the amount based on frequency."<<endl;
                    double newamount;
                    cin>>newamount;
                    string type = "Savings";
                    cout<<endl;
                    savecurr -> setname(outgoname); /// insert user data with pointers
                    savecurr -> setfrequency(newfreq);
                    savecurr -> setamount(newamount);
                    savecurr -> settype(type);
                    cin.ignore();
                    }
                }
cout<<"How many entries would you like to enter for general expenses? ";
    cin>>each;
    cout<<endl;
    cin.ignore();
            for (int i =0; i < each; i++) ///Fill in general expenses info
                {
                if (genhead == NULL) ///If genhead is at null, create new outgo
                    {
                    genhead = new outgo;
                    gencurr = genhead;
                    int counter = i;
                    cout<<"General Expense "<<counter+1<<":"<<endl;
                    cout<<"------------------"<<endl;
                    cout<<"Enter name of general expense: ";
                    getline(cin,outgoname);
                    cout<<"\nPlease enter the frequency of payment"<<endl;
                    cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                    int newfreq;
                    cin>>newfreq;
                    cout<<"Please enter the amount taken based on frequency."<<endl;
                    double newamount;
                    cin>>newamount;
                    string type = "General Expenses";
                    cout<<endl;
                    genhead -> setname(outgoname); /// insert user data with pointers
                    genhead -> setfrequency(newfreq);
                    genhead -> setamount(newamount);
                    genhead -> settype(type);
                    cin.ignore();
                    }
                else
                    {
                    gencurr -> makenew();
                    gencurr = gencurr -> getnext();
                    int counter = i;
                    cout<<"General Expense "<<counter+1<<":"<<endl;
                    cout<<"-------------------"<<endl;
                    cout<<"Enter name of general expense: ";
                    getline(cin,outgoname);
                    cout<<"\nPlease enter the payment frequency"<<endl;
                    cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                    int newfreq;
                    cin>>newfreq;
                    cout<<"Please enter the amount taken based on frequency."<<endl;
                    double newamount;
                    cin>>newamount;
                    string type = "Debt";
                    cout<<endl;
                    gencurr -> setname(outgoname); /// insert user data with pointers
                    gencurr -> setfrequency(newfreq);
                    gencurr -> setamount(newamount);
                    gencurr -> settype(type);
                    cin.ignore();
                    }
                }
///-----------------------------------------display out matrix
            cout<<"\t\t\t\tOutgo List"<<endl;
            cout<<"\t\t\t\t-----------"<<endl;
            cout<<endl;
            cout<<"Housing: "<<endl;
            if (househead != NULL) {househead -> showall();}
            else {cout<<"No housing expenses entered.";}
            cout<<endl<<endl;
            cout<<"Transportation: "<<endl;
            if (transhead != NULL) {transhead -> showall();}
            else {cout<<"No transportation expenses entered";}
            cout<<endl<<endl;
            cout<<"Debts: "<<endl;
            if (debthead != NULL) {debthead -> showall();}
            else {cout<<"No debt expenses entered";}
            cout<<endl<<endl;
            cout<<"Savings: "<<endl;
            if (savehead != NULL) {savehead -> showall();}
            else {cout<<"No savings entered";}
            cout<<endl<<endl;
            cout<<"General Expenses: "<<endl;
            if (genhead != NULL) {genhead -> showall();}
            else {cout<<"No general expenses entered.";}
cout<<endl<<endl;
ans = 100;
      ///Ask user if they would like to change/remove/add outgo data
    while (ans != 4)
            {
            ans = outgomenu();
            if (ans == 1) ///start of change code
                {
                cout<<"In which category would you like to change an outgo?"<<endl<<endl;
                cout<<"(h)ousing / (t)ransporation / (d)ebts / (s)avings / (g)eneral expenses"<<endl<<endl;
                cout<<"Please enter the corresponding character: ";
                cin>>which;
                cin.ignore();
                if (which == 'h'||which == 'H') /// Start of change code for housing only
                        {
                        if (househead == NULL)
                            {
                            cout<<endl;
                            cout<<"Hey! You can't change an outgo that you never entered!"<<endl;
                            }
                        else
                            {
                            cout<<endl;
                            cout<<"Please enter the name assigned to the housing expense"<<endl;
                            cout<<"you would like to change: ";
                            getline(cin,outgoname);
                            housecurr = househead;
                                while(housecurr -> getname() != outgoname )
                                    {
                                    housecurr = housecurr ->getnext();
                                    }///end of while loop
                            cout<<"Please enter the new name of the housing expense: ";
                            getline(cin,outgoname);
                            cout<<"\nPlease enter the payment frequency."<<endl;
                            cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                            int newfreq;
                            cin>>newfreq;
                            cout<<"Please enter the amount based on frequency."<<endl;
                            double newamount;
                            cin>>newamount;
                            cout<<endl;
                            housecurr -> setname(outgoname); /// insert user data with pointers
                            housecurr -> setfrequency(newfreq);
                            housecurr -> setamount(newamount);
                            cin.ignore();                           ///End of change code for housing
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                            }
                        }
                else if (which == 't'|| which == 'T')///Start of change code for transportation only.
                        {
                        if (transhead == NULL)
                            {
                            cout<<endl;
                            cout<<"Hey! You can't change an outgo that you never entered!"<<endl;
                            }
                        else
                            {
                            cout<<endl;
                            cout<<"Please enter the name assigned to the transportation"<<endl;
                            cout<<"expense that you would like to change: ";
                            getline(cin,outgoname);
                            transcurr = transhead;
                                while(transcurr -> getname() != outgoname )
                                    {
                                    transcurr = transcurr ->getnext();
                                    }///end of while loop
                            cout<<"Please enter the new name for this transportation expense: ";
                            getline(cin,outgoname);
                            cout<<"\nPlease enter the payment frequency."<<endl;
                            cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                            int newfreq;
                            cin>>newfreq;
                            cout<<"Please enter the amount received based on frequency."<<endl;
                            double newamount;
                            cin>>newamount;
                            cout<<endl;
                            transcurr -> setname(outgoname); /// insert user data with pointers
                            transcurr -> setfrequency(newfreq);
                            transcurr -> setamount(newamount);
                            cin.ignore(); ///end of change code for transportation only.
                                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                            }

                        }
                else if (which == 'd'|| which == 'D')///Start of change code for debts only.
                        {
                        if (debthead == NULL)
                            {
                            cout<<endl;
                            cout<<"Hey! You can't change an outgo that you never entered!"<<endl;
                            }
                        else
                            {
                            cout<<endl;
                            cout<<"Please enter the name assigned to the debt"<<endl;
                            cout<<"that you would like to change: ";
                            getline(cin,outgoname);
                            debtcurr = debthead;
                                while(debtcurr -> getname() != outgoname )
                                    {
                                    debtcurr = debtcurr ->getnext();
                                    }///end of while loop
                            cout<<"Please enter the new name for this debt: ";
                            getline(cin,outgoname);
                            cout<<"\nPlease enter the payment frequency."<<endl;
                            cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                            int newfreq;
                            cin>>newfreq;
                            cout<<"Please enter the amount received based on frequency."<<endl;
                            double newamount;
                            cin>>newamount;
                            cout<<endl;
                            debtcurr -> setname(outgoname); /// insert user data with pointers
                            debtcurr -> setfrequency(newfreq);
                            debtcurr -> setamount(newamount);
                            cin.ignore();                               ///end of change code for debt only.
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                            }
                        }
                else if (which == 's'|| which == 'S')///Start of change code for savings only.
                        {
                        if (savehead == NULL)
                            {
                            cout<<endl;
                            cout<<"Hey! You can't change an outgo that you never entered!"<<endl;
                            }
                        else
                            {
                            cout<<endl;
                            cout<<"Please enter the name assigned to the savings"<<endl;
                            cout<<"that you would like to change: ";
                            getline(cin,outgoname);
                            savecurr = savehead;
                                while(savecurr -> getname() != outgoname )
                                    {
                                    savecurr = savecurr ->getnext();
                                    }///end of while loop
                            cout<<"Please enter the new name for this form of saving: ";
                            getline(cin,outgoname);
                            cout<<"\nPlease enter the saving frequency."<<endl;
                            cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                            int newfreq;
                            cin>>newfreq;
                            cout<<"Please enter the amount saved based on frequency."<<endl;
                            double newamount;
                            cin>>newamount;
                            cout<<endl;
                            savecurr -> setname(outgoname); /// insert user data with pointers
                            savecurr -> setfrequency(newfreq);
                            savecurr -> setamount(newamount);
                            cin.ignore();                       ///end of change code for saving only.
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                            }
                        }
                  else if (which == 'g'|| which == 'G')///Start of change code for general expenses only.
                        {
                        if (genhead == NULL)
                            {
                            cout<<endl;
                            cout<<"Hey! You can't change an outgo that you never entered!"<<endl;
                            }
                        else
                            {
                            cout<<endl;
                            cout<<"Please enter the name assigned to the general expense"<<endl;
                            cout<<"that you would like to change: ";
                            getline(cin,outgoname);
                            gencurr = genhead;
                                while(gencurr -> getname() != outgoname )
                                    {
                                    gencurr = gencurr ->getnext();
                                    }///end of while loop
                            cout<<"Please enter the new name for this general expense: ";
                            getline(cin,outgoname);
                            cout<<"\nPlease enter the payment frequency."<<endl;
                            cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                            int newfreq;
                            cin>>newfreq;
                            cout<<"Please enter the amount based on frequency."<<endl;
                            double newamount;
                            cin>>newamount;
                            cout<<endl;
                            gencurr -> setname(outgoname); /// insert user data with pointers
                            gencurr -> setfrequency(newfreq);
                            gencurr -> setamount(newamount);
                            cin.ignore();                       ///end of change code for general expense only.
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                            }
                        }
                }  ///end of ALL change code
            else if (ans == 2)
                {
                cout<<"Where would you like to remove an outgo from?"<<endl<<endl;
                cout<<"(h)ousing / (t)ransporation / (d)ebts / (s)avings / (g)eneral expenses"<<endl<<endl;
                cout<<"Please enter the corresponding character: ";
                cin>>which;
                cin.ignore();
                if (which == 'h'|| which == 'H')///start of remove code for housing only
                    {
                    cout<<endl;
                    cout<<"Please enter the name of outgo that you would like to \nremove from housing: ";
                    getline(cin,outgoname);
                    housecurr = househead;
                    houseprev = househead;
                    while(housecurr -> getname() != outgoname)
                                {
                                houseprev = housecurr;
                                housecurr = housecurr -> getnext();
                                }
                            if(housecurr == househead)
                                {
                                househead = househead ->getnext();
                                housecurr -> setnext(NULL);
                                delete (housecurr);
                                }
                            else
                                {
                                houseprev->setnext(housecurr->getnext());
                                housecurr -> setnext(NULL);
                                delete housecurr;
                                }
                                    ///end of remove code for housing only
                                    cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                    }
                else if (which == 't' || which == 'T') /// start of remove code for transportation only
                    {
                    cout<<endl;
                    cout<<"Please enter the name of outgo that you would like to \nremove from transportation: ";
                    getline(cin,outgoname);
                    transcurr = transhead;
                    transprev = transhead;
                    while(transcurr -> getname() != outgoname)
                                {
                                transprev = transcurr;
                                transcurr = transcurr -> getnext();
                                }
                            if(transcurr == transhead)
                                {
                                transhead = transhead ->getnext();
                                transcurr -> setnext(NULL);
                                delete (transcurr);
                                }
                            else
                                {
                                transprev->setnext(transcurr->getnext());
                                transcurr -> setnext(NULL);
                                delete transcurr;
                                }
                                    ///end of remove code for general expenses only
                                  cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}


                    }
                else if (which == 'd'|| which == 'D')///start of remove code for debts only
                    {
                    cout<<endl;
                    cout<<"Please enter the name of outgo that you would like to \nremove from debts: ";
                    getline(cin,outgoname);
                    debtcurr = debthead;
                    debtprev = debthead;
                    while(debtcurr -> getname() != outgoname)
                                {
                                debtprev = debtcurr;
                                debtcurr = debtcurr -> getnext();
                                }
                            if(debtcurr == debthead)
                                {
                                debthead = debthead ->getnext();
                                debtcurr -> setnext(NULL);
                                delete (debtcurr);
                                }
                            else
                                {
                                debtprev->setnext(debtcurr->getnext());
                                debtcurr -> setnext(NULL);
                                delete debtcurr;
                                }
                                    ///end of remove code for general expenses only
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                    }
                else if (which == 's'||which == 'S')              ///start of remove code for savings only
                    {
                    cout<<endl;
                    cout<<"Please enter the name of outgo that you would like to \nremove from savings: ";
                    getline(cin,outgoname);
                    savecurr = savehead;
                    saveprev = savehead;
                    while(savecurr -> getname() != outgoname)
                                {
                                saveprev = savecurr;
                                savecurr = savecurr -> getnext();
                                }
                            if(savecurr == savehead)
                                {
                                savehead = savehead ->getnext();
                                savecurr -> setnext(NULL);
                                delete (savecurr);
                                }
                            else
                                {
                                saveprev->setnext(savecurr->getnext());
                                savecurr -> setnext(NULL);
                                delete savecurr;
                                }                   ///end of remove code for general expenses only
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                    }
                else if (which == 'g'|| which == 'G')///start of remove code for general expenses only
                    {
                    cout<<endl;
                    cout<<"Please enter the name of outgo that you would like to \nremove from general expenses: ";
                    getline(cin,outgoname);
                    gencurr = genhead;
                    genprev = genhead;
                    while(gencurr -> getname() != outgoname)
                                {
                                genprev = gencurr;
                                gencurr = gencurr -> getnext();
                                }
                            if(gencurr == genhead)
                                {
                                genhead = genhead ->getnext();
                                gencurr -> setnext(NULL);
                                delete (gencurr);
                                }
                            else
                                {
                                genprev->setnext(gencurr->getnext());
                                gencurr -> setnext(NULL);
                                delete gencurr;
                                }///end of remove code for general expenses only
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                    }///end of ALL remove code
                }
            else if (ans == 3)///Start of ADD code
                {
                cout<<"In which category would you like to add an outgo?"<<endl<<endl;
                cout<<"(h)ousing / (t)ransporation / (d)ebts / (s)avings / (g)eneral expenses"<<endl<<endl;
                cout<<"Please enter the corresponding character: ";
                cin>>which;
                cin.ignore();
                    if (which == 'h' || which == 'H')
                        {
                        cout<<"Enter name of housing expense: ";
                        getline(cin,outgoname);
                        cout<<"\nPlease enter the frequency of payment"<<endl;
                        cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                        int newfreq;
                        cin>>newfreq;
                        cout<<"Please enter the amount taken based on frequency."<<endl;
                        double newamount;
                        cin>>newamount;
                        string type = "Housing";
                        cout<<endl;
                        housecurr = househead;
                        houseprev = househead;
                            if (househead == NULL)
                                {
                                househead = new outgo;
                                househead ->setname(outgoname);
                                househead ->setfrequency(newfreq);
                                househead ->setamount(newamount);
                                househead ->settype(type);
                                }
                           else if (househead != NULL)
                            {
                               while (housecurr != NULL)
                                    {
                                    houseprev = housecurr;
                                    housecurr = housecurr -> getnext();
                                    }
                            houseprev -> makenew();
                            housecurr = houseprev -> getnext();
                            housecurr -> setname(outgoname); /// insert user data with pointers
                            housecurr -> setfrequency(newfreq);
                            housecurr -> setamount(newamount);
                            housecurr ->settype(type);
                            }
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}

                        }
                    else if (which == 't'|| which == 'T')
                        {
                        cout<<"Enter name of transportation expense: ";
                        getline(cin,outgoname);
                        cout<<"\nPlease enter the frequency of payment"<<endl;
                        cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                        int newfreq;
                        cin>>newfreq;
                        cout<<"Please enter the amount taken based on frequency."<<endl;
                        double newamount;
                        cin>>newamount;
                        string type = "Transportation";
                        cout<<endl;
                        transcurr = transhead;
                        transprev = transhead;
                            if (transhead == NULL)
                                {
                                transhead = new outgo;
                                transhead ->setname(outgoname);
                                transhead ->setfrequency(newfreq);
                                transhead ->setamount(newamount);
                                transhead ->settype(type);
                                }
                           else if (transhead != NULL)
                            {
                               while (transcurr != NULL)
                                    {
                                    transprev = transcurr;
                                    transcurr = transcurr -> getnext();
                                    }
                            transprev -> makenew();
                            transcurr = transprev -> getnext();
                            transcurr -> setname(outgoname); /// insert user data with pointers
                            transcurr -> setfrequency(newfreq);
                            transcurr -> setamount(newamount);
                            transcurr ->settype(type);
                            }
                                                     cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}


                        }
                    else if (which == 'd'|| which == 'D')
                        {
                        cout<<"Enter name of debt: ";
                        getline(cin,outgoname);
                        cout<<"\nPlease enter the frequency of payment"<<endl;
                        cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                        int newfreq;
                        cin>>newfreq;
                        cout<<"Please enter the amount taken based on frequency."<<endl;
                        double newamount;
                        cin>>newamount;
                        string type = "Debts";
                        cout<<endl;
                        debtcurr = debthead;
                        debtprev = debthead;
                            if (debthead == NULL)
                                {
                                debthead = new outgo;
                                debthead ->setname(outgoname);
                                debthead ->setfrequency(newfreq);
                                debthead ->setamount(newamount);
                                debthead ->settype(type);
                                }
                           else if (debthead != NULL)
                            {
                               while (debtcurr != NULL)
                                    {
                                    debtprev = debtcurr;
                                    debtcurr = debtcurr -> getnext();
                                    }
                            debtprev -> makenew();
                            debtcurr = debtprev -> getnext();
                            debtcurr -> setname(outgoname); /// insert user data with pointers
                            debtcurr -> setfrequency(newfreq);
                            debtcurr -> setamount(newamount);
                            debtcurr ->settype(type);
                            }
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}


                        }
                    else if (which == 's'|| which == 'S')
                        {
                        cout<<"Enter name of savings: ";
                        getline(cin,outgoname);
                        cout<<"\nPlease enter the frequency of savings"<<endl;
                        cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                        int newfreq;
                        cin>>newfreq;
                        cout<<"Please enter the amount based on frequency."<<endl;
                        double newamount;
                        cin>>newamount;
                        string type = "Savings";
                        cout<<endl;
                        savecurr = savehead;
                        saveprev = savehead;
                            if (savehead == NULL)
                                {
                                savehead = new outgo;
                                savehead ->setname(outgoname);
                                savehead ->setfrequency(newfreq);
                                savehead ->setamount(newamount);
                                savehead ->settype(type);
                                }
                           else if (savehead != NULL)
                            {
                               while (savecurr != NULL)
                                    {
                                    saveprev = savecurr;
                                    savecurr = savecurr -> getnext();
                                    }
                            saveprev -> makenew();
                            savecurr = saveprev -> getnext();
                            savecurr -> setname(outgoname); /// insert user data with pointers
                            savecurr -> setfrequency(newfreq);
                            savecurr -> setamount(newamount);
                            savecurr ->settype(type);
                            }
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}


                        }
                    else if (which == 'g'|| which == 'G')
                        {
                        cout<<"Enter name of general expense: ";
                        getline(cin,outgoname);
                        cout<<"\nPlease enter the frequency of payment"<<endl;
                        cout<<"1 = weekly, 2 = biweekly, 3 = monthly, 4 = daily"<<endl;
                        int newfreq;
                        cin>>newfreq;
                        cout<<"Please enter the amount taken based on frequency."<<endl;
                        double newamount;
                        cin>>newamount;
                        string type = "General Expenses";
                        cout<<endl;
                        gencurr = genhead;
                        genprev = genhead;
                            if (genhead == NULL)
                                {
                                genhead = new outgo;
                                genhead ->setname(outgoname);
                                genhead ->setfrequency(newfreq);
                                genhead ->setamount(newamount);
                                genhead ->settype(type);
                                }
                           else if (genhead != NULL)
                            {
                               while (gencurr != NULL)
                                    {
                                    genprev = gencurr;
                                    gencurr = gencurr -> getnext();
                                    }
                            genprev -> makenew();
                            gencurr = genprev -> getnext();
                            gencurr -> setname(outgoname); /// insert user data with pointers
                            gencurr -> setfrequency(newfreq);
                            gencurr -> setamount(newamount);
                            gencurr ->settype(type);
                            }
                        }
                            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
                            cout<<"\t\t\t\t-----------"<<endl;
                            cout<<endl;
                            cout<<"Housing: "<<endl;
                            if (househead != NULL) {househead -> showall();}
                            else {cout<<"No housing expenses entered.";}
                            cout<<endl<<endl;
                            cout<<"Transportation: "<<endl;
                            if (transhead != NULL) {transhead -> showall();}
                            else {cout<<"No transportation expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Debts: "<<endl;
                            if (debthead != NULL) {debthead -> showall();}
                            else {cout<<"No debt expenses entered";}
                            cout<<endl<<endl;
                            cout<<"Savings: "<<endl;
                            if (savehead != NULL) {savehead -> showall();}
                            else {cout<<"No savings entered";}
                            cout<<endl<<endl;
                            cout<<"General Expenses: "<<endl;
                            if (genhead != NULL) {genhead -> showall();}
                            else {cout<<"No general expenses entered.";}


                }           ///End of ADD code


            }
cout<<endl;
cout<<"This is what you have entered for income and outgos."<<endl<<endl;

                ///display the matrix
            cout<<"\t\t\t\tIncome List"<<endl;
            cout<<"\t\t\t\t-----------"<<endl;
            cout<<endl;
            earnedcurr = earnedhead;
            cout<<"Earned Income: "<<endl;
            while(earnedcurr!=NULL)
                    {
                    earnedcurr -> display();
                    cout<<endl;
                    earnedcurr = earnedcurr -> getnext();
                    }
            cout<<endl;
            unearnedcurr = unearnedhead;
            cout<<"Unearned Income: "<<endl;
            while(unearnedcurr!=NULL)
                        {
                        unearnedcurr -> display();
                        cout<<endl;
                        unearnedcurr = unearnedcurr -> getnext();
                        }
            cout<<"\t\t\t\tOutgo List"<<endl; ///display outgo matrix
            cout<<"\t\t\t\t-----------"<<endl;
            cout<<endl;
            cout<<"Housing: "<<endl;
            if (househead != NULL) {househead -> showall();}
            else {cout<<"No housing expenses entered.";}
            cout<<endl<<endl;
            cout<<"Transportation: "<<endl;
            if (transhead != NULL) {transhead -> showall();}
            else {cout<<"No transportation expenses entered";}
            cout<<endl<<endl;
            cout<<"Debts: "<<endl;
            if (debthead != NULL) {debthead -> showall();}
            else {cout<<"No debt expenses entered";}
            cout<<endl<<endl;
            cout<<"Savings: "<<endl;
            if (savehead != NULL) {savehead -> showall();}
            else {cout<<"No savings entered";}
            cout<<endl<<endl;
            cout<<"General Expenses: "<<endl;
            if (genhead != NULL) {genhead -> showall();}
            else {cout<<"No general expenses entered.";}
///Display totals
cout<<endl<<endl;
cout<<"All the information you entered will be compiled now!"<<endl<<endl;
cout<<endl;
cout<<"\t\t\t\tMonthly Totals"<<endl; ///display outgo matrix
cout<<"\t\t\t\t--------------"<<endl;
cout<<"Income:"<<endl;
cout<<"-------"<<endl;
    if (earnedhead != NULL) ///---------------------------------income totals
        {
        monthtotal = earnedhead -> totalincome();
        etotal = monthtotal;
        cout<<"The monthly total for earned income is $"<<fixed<<setprecision(2)<<etotal<<". "<<endl<<endl;
        }
    else
        {
        monthtotal = 0.0;
        etotal = monthtotal;
        cout<<"The monthly total for earned income is $"<<fixed<<setprecision(2)<<etotal<<". "<<endl<<endl;
        }
    if (unearnedhead !=NULL)
        {
        monthtotal = unearnedhead -> totalincome();
        utotal = monthtotal;
        cout<<"The monthly total for unearned income is $"<<fixed<<setprecision(2)<<utotal<<". "<<endl<<endl;
        }
    else
        {
        monthtotal = 0.0;
        utotal = monthtotal;
        cout<<"The monthly total for unearned income is $"<<fixed<<setprecision(2)<<utotal<<". "<<endl<<endl;
        }                   ///-------------------------end of income totals
cout<<"Outgos:"<<endl; ///--------Start of outgo totals
cout<<"-------"<<endl;
    if (househead != NULL)
        {
        monthtotal = househead -> totaloutgo();
        htotal = monthtotal;
        cout<<"The monthly total for housing expenses is $"<<fixed<<setprecision(2)<<htotal<<". "<<endl<<endl;
        }
    else
        {
        monthtotal = 0.0;
        htotal = monthtotal;
        cout<<"The monthly total for housing expenses is $"<<fixed<<setprecision(2)<<htotal<<". "<<endl<<endl;
        }
    if (transhead != NULL)
        {
        monthtotal = transhead -> totaloutgo();
        ttotal = monthtotal;
        cout<<"The monthly total for transportation expenses is $"<<fixed<<setprecision(2)<<ttotal<<". "<<endl<<endl;
        }
    else
        {
        monthtotal = 0.0;
        ttotal = monthtotal;
        cout<<"The monthly total for transportation expenses is $"<<fixed<<setprecision(2)<<ttotal<<". "<<endl<<endl;
        }
    if (debthead != NULL)
        {
        monthtotal = debthead -> totaloutgo();
        dtotal = monthtotal;
        cout<<"The monthly total for debt expenses is $"<<fixed<<setprecision(2)<<dtotal<<". "<<endl<<endl;
        }
    else
        {
        monthtotal = 0.0;
        dtotal = monthtotal;
        cout<<"The monthly total for debt expenses is $"<<fixed<<setprecision(2)<<dtotal<<". "<<endl<<endl;
        }
    if (savehead != NULL)
        {
        monthtotal = savehead -> totaloutgo();
        stotal = monthtotal;
        cout<<"The monthly total for savings is $"<<fixed<<setprecision(2)<<stotal<<". "<<endl<<endl;
        }
    else
        {
        monthtotal = 0.0;
        stotal = monthtotal;
        cout<<"The monthly total for savings is $"<<fixed<<setprecision(2)<<stotal<<". "<<endl<<endl;
        }
     if (genhead != NULL)
        {
        monthtotal = genhead -> totaloutgo();
        gtotal = monthtotal;
        cout<<"The monthly total for general expenses is $"<<fixed<<setprecision(2)<<gtotal<<". "<<endl<<endl;
        }
    else
        {
        monthtotal = 0.0;
        gtotal = monthtotal;
        cout<<"The monthly total for general expenses is $"<<fixed<<setprecision(2)<<gtotal<<". "<<endl<<endl;
        }///end of outgo totals
    cout<<"Totals:"<<endl; ///--------Start of outgo totals
    cout<<"-------"<<endl;
    double incometotal;
    incometotal = incomesum(etotal,utotal);
    cout<<"The total income for the month is $"<<fixed<<setprecision(2)<<incometotal<<". "<<endl<<endl;
    double outgototal;
    outgototal = outgosum(htotal,ttotal,dtotal,stotal,gtotal);
    remainder = leftover(incometotal,outgototal);
    cout<<"The total outgo for the month is $"<<fixed<<setprecision(2)<<outgototal<<". "<<endl<<endl;
    cout<<"Percentages:"<<endl; ///--------Start of outgo totals
    cout<<"-----------"<<endl;
    double hpercent = percenthousing(htotal,incometotal);
    double tpercent = percenttrans(ttotal,incometotal);
    double dpercent = percentdebt(dtotal,incometotal);
    double spercent = percentsavings(stotal,incometotal);
    double gpercent = percentgeneralex(gtotal,incometotal);
    double remainder = leftover(incometotal,outgototal);
            if (remainder < 0)
                {
            cout<<"You have over spent by $"<<fixed<<setprecision(2)<<abs(remainder)<<"."<<endl<<endl;
                }
            else if (remainder == 0)
                {
                cout<<"There is nothing left over for this month."<<endl<<endl;
                }
            else if (remainder > 0)
                {
                double lpercent;
                lpercent = percentleftover(remainder,incometotal);
                cout<<"%"<<lpercent<<" of your income is leftover for this month."<<endl<<endl;
                }
    cout<<"\t\t\t\tIdeal vs Reality"<<endl;///Ideal vs reality
    cout<<"\t\t\t\t-----------------"<<endl;
    cout<<"Reality Percentages:"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"Your housing percentage is %"<<fixed<<setprecision(2)<<hpercent<<"."<<endl<<endl;
    cout<<"Your transportation percentage is %"<<fixed<<setprecision(2)<<tpercent<<"."<<endl<<endl;
    cout<<"Your debt repayment percentage is %"<<fixed<<setprecision(2)<<dpercent<<"."<<endl<<endl;
    cout<<"Your savings percentage is %"<<fixed<<setprecision(2)<<spercent<<"."<<endl<<endl;
    cout<<"Your general expense percentage is %"<<fixed<<setprecision(2)<<gpercent<<"."<<endl<<endl;
    cout<<"Ideal Percentages:"<<endl; ///--------Start of outgo totals
    cout<<"------------------"<<endl;
    double iHamount = idealHamount(incometotal,0.35);
    double iTamount = idealTamount(incometotal,0.15);
    double iDamount = idealDamount(incometotal,0.15);
    double iSamount = idealSamount(incometotal,0.10);
    double iGamount = idealGamount(incometotal,0.25);
    cout<<"Housing should be %"<<35<<" of your total income; which amounts to $"<<iHamount<<"."<<endl<<endl;
    cout<<"Transportation should be %"<<15<<" of your total income; which amounts to $"<<iTamount<<"."<<endl<<endl;
    cout<<"Debt repayment should be %"<<15<<" of your total income; which amounts to $"<<iDamount<<"."<<endl<<endl;
    cout<<"Savings should be %"<<10<<" of your total income; which amounts to $"<<iSamount<<"."<<endl<<endl;
    cout<<"General expenses should be %"<<25<<" of your total income; which amounts to $"<<iGamount<<"."<<endl<<endl;
    fstream fout1,fout2,fout3,fout4,fout5,fout6,fout7,fout8;
    fout1.open("earned.txt",ios::out);
    earnedcurr = earnedhead;
    unearnedcurr = unearnedhead;
    housecurr = househead;
    transcurr = transhead;
    debtcurr = debthead;
    savecurr = savehead;
    gencurr = genhead;
    while (earnedcurr != NULL)///**********fill earned file
        {
        fout1<<earnedcurr->getname();
        fout1<<endl;
        fout1<<earnedcurr -> getfrequency();
        fout1<<endl;
        fout1<<earnedcurr ->getamount();
        fout1<<endl;
        earnedcurr = earnedcurr -> getnext();
        }///end of earned file
        fout1.close();
    fout2.open("unearned.txt",ios::out);
    while (unearnedcurr != NULL)///**********fill unearned file
        {
        fout2<<unearnedcurr->getname();
        fout2<<endl;
        fout2<<unearnedcurr->getfrequency();
        fout2<<endl;
        fout2<<unearnedcurr->getamount();
        fout2<<endl;
        unearnedcurr = unearnedcurr -> getnext();
        }///end of unearned file
        fout2.close();
    fout3.open("housing.txt",ios::out);
    while (housecurr != NULL)///**********fill in housing file
        {
        fout3<<housecurr->getname();
        fout3<<endl;
        fout3<<housecurr ->getfrequency();
        fout3<<endl;
        fout3<<housecurr ->getamount();
        fout3<<endl;
        housecurr = housecurr -> getnext();
        }///end of housing file
        fout3.close();
    fout4.open("transportation.txt",ios::out);
    while (transcurr != NULL)///**********fill in transportation from file
        {
        fout4<<transcurr->getname();
        fout4<<endl;
        fout4<<transcurr->getfrequency();
        fout4<<endl;
        fout4<<transcurr->getamount();
        fout4<<endl;
        transcurr = transcurr -> getnext();
        }///end of transportation file
        fout4.close();
    fout5.open("debt.txt",ios::out);
    while (debtcurr != NULL)///**********fill in debt from file
        {
        fout5<<debtcurr->getname();
        fout5<<endl;
        fout5<<debtcurr->getfrequency();
        fout5<<endl;
        fout5<<debtcurr->getamount();
        fout5<<endl;
        debtcurr = debtcurr -> getnext();
        }///end of debt file
        fout5.close();
    fout6.open("savings.txt",ios::out);
    while (savecurr != NULL)///**********fill in saving from file
        {
        fout6<<savecurr->getname();
        fout6<<endl;
        fout6<<savecurr->getfrequency();
        fout6<<endl;
        fout6<<savecurr->getamount();
        fout6<<endl;
        savecurr = savecurr -> getnext();
        }///end of save file
        fout6.close();
    fout7.open("generalexp.txt",ios::out);
    while (gencurr != NULL)///**********fill in general expenses from file
        {
        fout7<<gencurr->getname();
        fout7<<endl;
        fout7<<gencurr->getfrequency();
        fout7<<endl;
        fout7<<gencurr->getamount();
        fout7<<endl;
        gencurr = gencurr ->getnext();
        }///end of general expense file
        fout7.close();
    fout8.open("data.txt",ios::out);
        fout8<<"Housing "<<hpercent<<" "<<35.0<<endl;
        fout8<<"Transportation "<<tpercent<<" "<<15.0<<endl;
        fout8<<"Debt"<<dpercent<<" "<<15.0<<endl;
        fout8<<"Savings"<<spercent<<" "<<10.0<<endl;
        fout8<<"Gen.Expenses"<<gpercent<<" "<<25.0;
        fout8.close();
    }
system("gnuplot histo_command_v2.txt");
return 0;
}

