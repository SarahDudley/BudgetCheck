class income
{
public:
    income (){type = "earned"; name = " "; amount = 0.0; frequency = 3; nextptr = NULL;}
   ~income(){};

    void setname(string a){name = a;}
    string getname(){return name;}

    void settype(string a){type = a;}
    string gettype(){return type;}

    void setamount(double a){amount = a;}
    double getamount(){return amount;}

    void setfrequency(int a){frequency = a;}
    int getfrequency(){return frequency;}

    void setnext(income * n){nextptr = n;}
    income * getnext(){return nextptr;}

    void makenew()
        {
        nextptr = new income;
        }

    void display()
        {
        cout<<name<<" provides $";
        cout<<amount;
                if (frequency == 1)
                    {
                    cout<<" every week.";
                    cout<<endl;
                    }
                else if (frequency == 2)
                    {
                    cout<<" every two weeks.";
                    cout<<endl;
                    }
                else if (frequency == 3)
                    {
                    cout<<" every month.";
                    cout<<endl;
                    }
                else if (frequency == 4)
                    {
                    cout<<" everyday.";
                    cout<<endl;
                    }
        }
    void showall()
    {
    display();
    if(nextptr!=NULL)
        {
        nextptr->showall();
        }
    }

    double totalincome()
            {
            income * nextptr = this;
            double rate;
            double monthtotal = 0.0;
                while (nextptr != NULL)
                    {
                    if (nextptr -> getfrequency() == 1)
                        {
                        rate = 4.35;
                        }
                    else if (nextptr -> getfrequency() == 2)
                        {
                        rate = 2.17;
                        }
                    else if (nextptr -> getfrequency() == 3)
                        {
                        rate = 1.0;
                        }
                    else if (nextptr -> getfrequency() == 4)
                        {
                        rate = 30.0;
                        }
                    monthtotal = (monthtotal + (nextptr -> getamount() * rate));
                    nextptr = nextptr -> getnext();
                    }

            return monthtotal;
            }



private:
    string name;
    string type;
    double amount;
    int frequency;
    income * nextptr;
};

///primitive to a string requires cin.ignore
///1week.2biweekly.3month.4daily
///average of 30 days in a month (daily)
///average of 4.35 weeks in a month (weekly)
///use 2.17 for biweekly (which is 4.35481 divided by 2)
