class outgo
{
public:
    outgo (){type = " "; name = " "; amount = 0.0; frequency = 3; nextptr =NULL;}
   ~outgo(){};

    void setname(string a){name = a;}
    string getname(){return name;}

    void settype(string a){type = a;}
    string gettype(){return type;}

    void setamount(double a){amount = a;}
    double getamount(){return amount;}

    void setfrequency(int a){frequency = a;}
    int getfrequency(){return frequency;}

    void setnext(outgo * n){nextptr = n;}
    outgo * getnext(){return nextptr;}

    void makenew()
        {
        nextptr = new outgo;
        }

    void display()
        {
        cout<<name<<" takes away $";
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
    if(nextptr != NULL)
        {
        nextptr -> showall();
        }
    }

    double totaloutgo()
            {
            outgo * nextptr = this;
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
    outgo * nextptr;
};

///primitive to a string requires cin.ignore
