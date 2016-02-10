#include "all.h"

int show(int i);

int main()
{
    int select;
reshow:
    select = show(0);
    if(select == 1)
    {
        Seller seller;
        if(seller.Check())
        {
            while(1)
            {
                select = show(1);
                switch(select)
                {
                    case 1 : seller.Initial(); break;
                    case 2 : seller.Change(); break;
                    case 3 : seller.Search(); break;
                    case 4 : seller.Lookall(); break;
                    default : goto reshow;
                }
                fflush(stdin);
                cout << "Press enter to return to the menu..." << endl;
                getchar();
            }
        }
        else
        {
            cout<<"Account or password error! Will return to the menu!"<<endl;
            goto reshow;
        }
    }

    else if(select == 2)
    {
        Buyer buyer;
        if(buyer.Check())
        {
            while(1)
            {
                select = show(2);
                switch(select)
                {
                    case 1: buyer.Search(); break;
                    case 2: buyer.Lookall(); break;
                    case 3: buyer.Buyticket(); break;
                    case 4: buyer.Quitticket(); break;
                    case 5: buyer.Changekey(); break;
                    case 6: buyer.Changeinfo(); break;
                    default: goto reshow;
                }
                fflush(stdin);
                cout << "Press enter to return to the main menu..." << endl;
                getchar();
            }
        }
        else
        {
            cout<<"Account or password error! Will return to the main menu!"<<endl;
            goto reshow;
        }
    }

    else if(select == 3)
    {
        Buyer buyer;
        if(buyer.Creatinfo())
        {
            if(buyer.Improveinfo()) cout<<"Complete information success!Will go to the main menu!"<<endl;
            else cout<<"Failure to complete information! Please log in again to improve the information!"<<endl;
        }
        else
        {
            cout<<"Failed to register!"<<endl;
            cout<<"User name already exists!"<<endl;
            cout<<"Please re-enter your username and enter the 'Modify user information' to improve your information!"<<endl;
            cout<<"Will return to the main menu!"<<endl;
        }
        fflush(stdin);
        cout << "Press enter to return to the main menu..." << endl;
        getchar();
        goto reshow;
    }

    else return 0;
}

int show(int i)
{
    int select;
	if (i == 0)
    {
		system("cls");
		cout << "         [Train ticket system]    " << endl;
		cout << "=======================================" << endl;
		cout << "=  (1) System administrator login     =" << endl;
		cout << "=  (2) The general user landing       =" << endl;
		cout << "=  (3) The general user registration  =" << endl;
		cout << "=  (0) Quit the program               =" << endl;
		cout << "=======================================" << endl;
		cout << ">>>Execute input options:";
	}
	else if (i == 1)
    {
		system("cls");
		cout << "        [Train ticket system-Admin]    " << endl;
		cout << "===========================================" << endl;
		cout << "=  (1) Initialize the day shift           =" << endl;
		cout << "=  (2) Change the frequency information   =" << endl;
		cout << "=  (3) Search the frequency information        =" << endl;
		cout << "=  (4) View all the frequency information =" << endl;
		cout << "=  (0) Return to the landing interface    =" << endl;
		cout << "===========================================" << endl;
		cout << ">>>Execute input options:";
	}
	else if (i == 2)
    {
		system("cls");
		cout << "         [Train ticket system-User]    " << endl;
		cout << "============================================" << endl;
		cout << "=  (1) Search the frequency information    =" << endl;
		cout << "=  (2) View all the frequency information  =" << endl;
		cout << "=  (3) The buy ticket system               =" << endl;
		cout << "=  (4) The quit ticket system              =" << endl;
		cout << "=  (5) Change the user password            =" << endl;
		cout << "=  (6) Change user information             =" << endl;
		cout << "=  (0) Return to the landing interface     =" << endl;
		cout << "============================================" << endl;
		cout << ">>>Execute input options:";
	}
	cin>>select;
	return select;
}
