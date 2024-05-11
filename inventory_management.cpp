// Project :    Inventory Management System 




// Coders :     Hamza Sajjad & Ghulam Murtaza  
//                23p-0035      23p-0057



// Purpose of code: 

//                   The purpose of an inventory management system code is to efficiently track and manage inventory 
//                   and by helping the users to get to know whats available in the inventory 
//                   it only works when a user login tho inventory management system and to login 
//                   user is required to register or signup 

//                    It helps user by adding new product in the inventory and also helps them 
//                    by removing products stored in the inventory 

//                    Morevoer it makes it easy to find a product for user just by searching the product id 
//                    and if a user dont know the product id than he/she can search for all products which are
//                    availabl ein the invnetory .



#include <iostream>
#include <string>
#include<fstream>
#include <vector>
using namespace std;

#define Reset "\033[0m"
#define Red   "\033[91m"
#define Bold  "\033[1m"
#define Green "\033[92m"
#define Yellow "\033[93m"
#define Cyan   "\033[96m"
#define White      "\033[37m"
#define BrightWhite "\033[97m"


void welcomeMessage()
{
    cout<< Cyan       <<" - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
    cout<< Cyan       <<"|                                                         |"<<endl;
    cout<< Cyan       <<"|"<<Cyan<<"            INVENTORY MANAGEMENT SYSTEMS          " <<Cyan <<"       |"<<endl;
    cout<< Cyan       <<"|                                                         |"<<endl;
    cout<< Cyan       <<" - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
    cout<<Reset;
}


void Enter()
{
    cout<<"Press Enter to continue...";
    cin.ignore();
    cin.get();
}

class MainPage{
public:
    void displayMenu() {
        cout<<Cyan<<Bold<< "1. Sign Up"<<Reset<<endl;
        cout<<Cyan<<Bold"2. Sign In"<<Reset<<endl;
        cout<<Cyan<<Bold<<"3. About Us"<<Reset<<endl;
        cout<<Cyan<<Bold<< "4. Managers"<<Reset<<endl;
        cout<<Cyan<<Bold<<"5. Exit"<<Reset<<endl;
    }

    void opt()
    {
        char option;
        do
        {
            cout<<"Select an option from 1 to 5:"<<endl;
            cin>>option;

            switch(option)
            {
                case '1' :
                    signUp();
                    break;
                case '2' :
                    login();
                    break;
                case '3':
                    aboutUs();
                    break;
                case '4' :
                    Managers();
                    break;
                case '5' :
                    exitProgram();
                    break;
                default:
                    cout<<endl;
                    cout<<Red<<"Error Selection an option  !!"<<endl;
                    cout<<Reset;
                    break;
            }
        }
        while(option < '1' || option > '5');
    }

private:
    void signUp() {
        string user_id;
        string user_password;
        
        cout<<endl;
        cout<<"Hold a minute ,Signing you up"<< endl;
        cout<<"Almost Done"<<endl<<endl;
        cout<<"Select your new Id :";
        cin>>user_id;
        
        cout<<"Select your new Password :";
        cin>>user_password;
        
        ofstream outFile("accounts.txt",ios::app);
        if(outFile.is_open())
        {
            outFile<<user_id<<" "<<user_password<<endl;
            outFile.close();
            cout<<Green<<"SignUp sucessfuly  :) "<<endl;
            cout<<Reset;

            //signup check = correct
            cout<<endl;
            
            cout<<"Your new ID is "<<user_id;
            cout<<" and new password is "<<user_password<<endl;
        }
        else
        {
            cout<<"Unable to overwrite!"<<endl;
        }
        displayMenu();
        opt();
    }

private:
    void login()
    {
        string user_id;
        string user_password;

        cout<<"Sign In"<<endl;
        cout<<endl;
        
        string cuser_idFromFile;
        string cuser_passwordFromFile;
        
        cout<<endl<<"Enter your id: ";
        cin>>user_id;
        cout<<"Enter your password: ";
        cin>>user_password;
        
        ifstream f1("accounts.txt");
        if(f1.is_open())
        {
            bool found=false;
            while(f1>>cuser_idFromFile>>cuser_passwordFromFile)
            {
                if(user_id==cuser_idFromFile && user_password==cuser_passwordFromFile)
                {
                    found=true;
                    break;
                    //Logged in check = correct
                }
            }
            
            f1.close();
            if(!found)
            {
                cout<<Red<<"Invalid id and Password , Please Try again "<<endl<<endl;
                cout<<Reset;
                displayMenu();
                opt();
            }
            else
            {
                system("cls");
            }
        }
        else
        {
            cout<<"Unable to open file!"<<endl;
        }
    }

private:
    void aboutUs()
    {
        cout<<endl;
        cout<<"At our core, we're all about making businesses' lives easier by helping them keep track of their stuff better."<<endl;
        cout<<" We're here to shake up how inventory management works, using smart tech and simple strategies."<<endl;
        cout<<"Think of us as the friend who helps you tidy up your messy room, but for businesses."<<endl;
        cout<<"From knowing exactly what's in stock to predicting what customers will want next, we've got it covered. Our goal?"<<endl;
        cout<<"To make inventory management a breeze, so businesses can focus on growing and thriving."<<endl;
        cout<<"help them in their work "<<endl;
        cout<<endl;
        cout<<endl;

        Enter();
        system("cls");
        displayMenu();
        opt();
    }       //check = correct

private:
    void Managers()
    {
        cout<<Cyan<<"Project Managers"<<endl;
        cout<<Reset;
        cout<<Reset;
        cout<<"             Project managers:"<<endl;
        cout<<endl<<endl;
        cout<<"1.  Hamza Sajjad (23p0035)"<<endl;
        cout<<"2.  Ghulam Murtaza  (23P-0057)"<<endl;
        cout<<endl<<endl;

                        // check = correct
        Enter();
        system("cls");
        displayMenu();
        opt();
    }

    void exitProgram()
    {
        cout<<Red<<"Inventory Closing Soon .... "<<endl<<endl;
        cout<<Reset;
        exit(0);
    }
};



class user{

private:
string id;
string pass;

public:
 
    user()
    {
        id='0';
        pass='0';
    }

    user(string user_id , string user_pass)
    {
        user_id=id;
        user_pass=pass;
    }
    
    string getuserId()const
    { 
        return id;
    }
    
    string getuserPass()const
    {
        return pass;
    }

    void setUserId(string& userId)
    {
        userId=id;
    }
    
    void setPassword(string& password)
    {
        password=pass;
    }

};

class product{
private:
    int id;
    string name;
    string category;
    double price;
    int quantity;
public:
    string type1;
    string type2;
    string type3;

public:
    product(int id, string name, string category, double price, int quantity)
    {
        this->id=id;
        this->name=name;
        this->category=category;
        this->price=price;
        this->quantity=quantity;
    }

    int getId() const
    {
        return id;
    }

    void setId(int id)
    {
        this->id=id;
    }

    string getname() const
    {
        return name;
    }

    void setName(string name)
    {
        this->name=name;
    }

    string getcategory() const
    {
        return category;
    }

    void setCategory(string category)
    {
        this->category=category;
    }

    double getprice()const
    {
        return price;
    }

    void setPrice(double price)
    {
        this->price=price;
    }

    int geetquantity() const
    {
        return quantity;
    }

    void setQuantity(int quantity)
    {
        this->quantity=quantity;
    }
};


// class category:public product{

//     public:

// };

class Inventory{

private:
    vector<product> p1s;    

public:


    void addp1(product p1)
    {
        bool found=false;
        for(auto& p : p1s)
        {
            if(p.getId()==p1.getId())
            {
                cout<<Red<<"Id already Exist."<<endl;
                cout<<Reset;
                found=true;
                break;
            }
        }
        if(!found)
        {
            p1s.push_back(p1);
            cout<<Green<<" Product added successfully."<<endl;
            cout<<Reset;
            cout<<"___________________________________________________________"<<endl;
        }
    }

    void removep1(int id)
    {
        bool found=false;
        for(auto i=p1s.begin(); i != p1s.end(); i++)
        {
            if(i->getId()==id)
            {
                p1s.erase(i);
                found=true;
                cout<<Green<<"Product removed successfully."<<endl;
                cout<<Reset;
                cout<<"___________________________________________________________"<<endl;
                break;
            }
        }

        if(!found)
        {
            cout<<Red<<"Id does not exist"<<endl;
            cout<<Reset;
        }
    }

    product* findp1(int id)
    {
        for(auto& p1 : p1s)
        {
            if(p1.getId()==id)
            {
                return &p1;
            }
        }
        return nullptr;
    }

    void updatep1(int id, string name, string category, double price, int quantity)
    {
        bool found=false;
        for(auto& p1 : p1s)
        {
            if(p1.getId()==id)
            {
                p1.setName(name);
                p1.setCategory(category);
                p1.setPrice(price);
                p1.setQuantity(quantity);
                found=true;
                break;
            }
        }
        
        if(!found)
        {
            cout<<"ID does not exist."<<endl;
        }
    }

    void printp1() const
    {
        for(auto& p1 : p1s)
        {
            cout<<endl;
            cout<<"ID :"<< p1.getId() <<endl;
            cout<<"Name :"<< p1.getname() <<endl;
            cout<<"Category :"<< p1.getcategory()<<endl;
            cout<<"Price : Rs. "<< p1.getprice()<<endl;
            cout<<"Quantity :"<< p1.geetquantity()<<endl;
            cout<<"__________________________________________________________";
            cout<<endl<<endl;
        }
    }
};



int main()
{
    Inventory inventory;
    MainPage mp1;

        welcomeMessage();
        Enter();

        mp1.displayMenu();
        mp1.opt();


char option;
    do{

        cout<<"Please select an option:"<<endl;
        cout<<"1. Add a Product"<<endl;
        cout<<"2. Remove a Product"<<endl;
        cout<<"3. Find a Product"<<endl;
        cout<<"4. Update a Product"<<endl;
        cout<<"5. Review all Products"<<endl;
        cout<<"Q. Quit"<<endl;
        cin>> option;

        if(option=='1')
        {
            int id;
            string name, category;
            double price;
            int quantity;
            cout<<BrightWhite<<Bold<<"Enter id: ";
            cout<<BrightWhite;
            cin>>id;

            cout<<Bold<<"Enter product name: ";
            cout<<BrightWhite;
            cin>>name;

            cout<<Bold<<"Enter product category: ";
            cout<<BrightWhite;
            cin>>category;

            cout<<Bold<<"Enter product price: Rs. ";
            cout<<BrightWhite;
            cin>>price;

            cout<<Bold<<"Enter product quantity: ";
            cout<<BrightWhite;
            cin>>quantity;
            cout<<Reset;

            product p1(id, name, category, price, quantity);
            inventory.addp1(p1);
        }
        
        else if(option=='2')
        {
            int id;
            cout<<"Enter product id: ";
            cin>>id;
            inventory.removep1(id);
        }
        
        else if(option=='3')
        {
            int id;
            cout<<"Enter product id: ";
            cin>> id;
            product* p1=inventory.findp1(id);
            if(p1)
            {
                cout<<"Name :"<<p1->getname() <<endl;
                cout<<"Category :"<<p1->getcategory() <<endl;
                cout<<"Price:   Rs."<<p1->getprice() <<endl;
                cout<<"Quantity :"<<p1->geetquantity() <<endl;
                cout<<"___________________________________________________________________"<<endl;
            }
            
            else
            {
                cout<<Red<< "Product not found."<<endl;
                cout<<Reset<< "___________________________________________________________"<<endl;
            }
        }

        else if(option=='4')
        {
            int quantity;
            int id;
            string name;
            string category;
            double price;

            cout<<"Enter the product id: ";
            cin>>id;
            
            cout<<"Enter new product name: ";
            cin>>name;
            
            cout<<"Enter new product category: ";
            cin>>category;
            
            cout<<"Enter new product price: Rs. ";
            cin>>price;
            
            cout<<"Enter new product quantity: ";
            cin>>quantity;
            inventory.updatep1(id, name, category, price, quantity);
            cout<<Green<<"Product updated successfully."<<endl;
            cout<<Reset;
            cout<<"___________________________________________________________"<<endl;
        }
        
        else if(option=='5')
        {
            inventory.printp1();
        }
        
        else if(option=='Q' || option=='q')
        {
            cout<<Green<<endl<<"Goodbye!"<<endl<<endl;
            cout<<Reset <<"___________________________________________________________"<<endl;
            return 0;
        }
        else
        {
            cout<<Red<<"Invalid option. Please Try again"<<endl;
            cout<<"___________________________________________________________"<<endl;
            cout<<Reset;
        }
    }while(true);


    return 0;
}
