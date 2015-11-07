int incomemenu()
{
    cout<<endl<<endl;
    int ans;
    cout<<"\t\t\t\tIncome Menu"<<endl;
    cout<<"\t\t\t\t-----------"<<endl;
    cout<<"What would you like to do next?"<<endl;
    cout<<"1. Change income(s)."<<endl;
    cout<<"2. Remove income(s)."<<endl;
    cout<<"3. Add income(s)."<<endl;
    cout<<"4. Move on to outgos."<<endl;
    cin>>ans;
    while(1)
        {
            if(cin.fail())
                {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<endl<<"Wrong input type. Please try to enter input again."<<endl;
                cin>>ans;
                }
        break;
        }
    return ans;
}

int outgomenu()
{
    cout<<endl<<endl;
    int ans;
    cout<<"\t\t\t\tOutgo Menu"<<endl;
    cout<<"\t\t\t\t-----------"<<endl;
    cout<<"What would you like to do next?"<<endl;
    cout<<"1. Change outgo(s)."<<endl;
    cout<<"2. Remove outgo(s)."<<endl;
    cout<<"3. Add outgo(s)."<<endl;
    cout<<"4. Exit menu."<<endl;
    cin>>ans;
    while(1)
        {
            if(cin.fail())
                {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout<<endl<<"Wrong input type. Please try to enter input again."<<endl;
                cin>>ans;
                }
        break;
        }
    return ans;
}
