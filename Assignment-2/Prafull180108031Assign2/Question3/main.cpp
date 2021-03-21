#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<cstdlib>
#include<regex>

using namespace std;

#define dashed cout<<"\n"; for(int i = 0; i < 30; i++) { cout <<"--";}
#define wait cout<<"\n\n\nEnter 0 to goto previous menu";cin>>a;
#define clear_screen system("clear");


class Item {
        string item_name;
        int quantity;
        double price;
        string specs;
    public:
        Item();
        string get_item_name();
        double get_price();
        int get_quantity();
        void set_quantity(int);
        void input_item_data();
        void display();
};


class Category {
        string category_name;
        vector<Item> items;
    public:
        Category();
        string get_category_name();
        vector<Item> get_items();
        void add_item(Item&);
        void display();
};


class Customer {
        string user_id;
        string first_name;
        string last_name;
        string phone;
        vector<Item> order_history;
        vector<pair<Item, int>> cart;
        vector<Item> wishlist;
        string password;
    public:
        Customer();
        bool input_customer_data(string);
        bool validate_user(string);
        void display();
        void menu();
        void display_cart();
        void display_order_history();
        void display_wishlist();
        void checkout();
        void checkout(pair<Item,int>);
        void remove_from_cart(Item);
        void shopping_page();
};


class Seller {
        string seller_id;
        string company_name;
        string phone;
        string password;
    public:
        Seller();
        void display();
        void menu();
        bool input_seller_data(string);
        bool validate_user(string);
        void add_item();
};


// global variables to store and process data

vector<Category> category_list;
unordered_map<string, Customer> customers;
unordered_map<string, Seller> sellers;
char a;

//function prototypes

void main_menu();
void customer_operations();
void seller_operations();
void register_new_customer();
void login_customer();
void register_new_seller();
void login_seller();



//main function

int main() {
    main_menu();
    return 0;
}

//class method definitions

Item :: Item() {
    item_name = "";
    quantity = 0;
    price = 0.00;
    specs = "";
}


string Item :: get_item_name() {
    return item_name;
}


double Item :: get_price() {
    return price;
}


int Item :: get_quantity() {
    return quantity;
}


void Item :: set_quantity(int quant) {
    quantity = quant;
}


void Item :: input_item_data() {
    cout<<"\nEnter item name: ";
    cin>> item_name;
    cout<<"\nEnter Price: ";
    cin>>price;
    cout<<"Enter stocked Quantity: ";
    cin>>quantity;
    cout<<"\nEnter Specifications (press $ to complete): ";
    getline(cin,specs,'$');
}


void Item :: display() {
    dashed
    cout<<"\n"<<item_name;
    dashed
    cout<<"\nPrice: "<<price;
    cout<<"\tQuantity Available: "<<quantity;
    cout<<"\nSpecifications: "<<specs;
    dashed
}


Category :: Category() {
    string name;
    cout<< "Enter Category name to add: ";
    getline(cin, name);
    category_name = name;
}


string Category :: get_category_name(){
    return category_name;
}

vector<Item> Category :: get_items() {
    return items;
}

void Category :: add_item(Item &item) {
    vector<Item>::iterator it;
    for (auto it = items.begin(); it != items.end(); it++)
    {
        if ((*it).get_item_name() == item.get_item_name() && (*it).get_price() == item.get_price())
        {
            int quant = (*it).get_quantity() + item.get_quantity();
            (*it).set_quantity(quant);
            break;
        }
    }
    if (it == items.end())
    {
        items.push_back(item);
        return;
    }
}


void Category :: display() {
    cout<<"\n"<<category_name;
    cout<<"\tNumber of items in this Category: "<<items.size();
    dashed
}


Customer :: Customer() {
    user_id = "";
    first_name = "";
    last_name = "";
    phone = "";
    password = "";
}


bool Customer :: input_customer_data(string id) {
    user_id = id;
    string _password, confirm_password;
    m:
    cout<<"\nCreate password(minimum 4 letters): ";
    cin.ignore();
    l:
    getline(cin,_password);
    if(_password == "0")
        return false;
    if (_password.size() < 4)
    {
        cout<<"\nPassword should consist minimum 4 letters!!! Enter again: ";
        goto l;
    }
    cout<<"\nConfirm Password: ";
    getline(cin,confirm_password);
    if (_password == "0")
        return false;
    if (_password != confirm_password)
    {
        cout<<"\nPassword do not match!!!";
        goto m;
    }
    password = _password;
    cout<<"\nEnter first name: ";
    cin>>first_name;
    if(first_name == "0")
        return false;
    cout<<"\nEnter last name: ";
    cin>>last_name;
    if(last_name == "0")
        return false;
    n:
    string _phone;
    cout<<"\n\nEnter 10 digit mobile number: ";
    cin>>_phone;
    if(_phone == "0")
        return false;
    regex validate_phone(R"(\d{10})");
    if (!regex_match(_phone, validate_phone))
    {
        cout<<"\nEnter valid mobile number...";
        goto n;
    }
    phone = _phone;
    return true;
}


bool Customer :: validate_user(string _password) {
    return password == _password;
}


void Customer :: display() {
    clear_screen
    cout<<"Profile";
    dashed
    cout<<"\nUser Id: "<<user_id;
    cout<<"\nName: "<<first_name<<" "<<last_name;
    cout<<"\nPhone: "<<phone;
    dashed
    cout<<"\nCart: "<<cart.size()<<" items";
    cout<<"\tWishlist: "<<wishlist.size()<<" items";
    dashed
    wait
}


void Customer :: menu() {
    l:
    clear_screen
    cout<<"Customer menu";
    dashed
    cout<<"\nWelcome "<<first_name<<" "<<last_name;
    dashed
    cout<<"\nChoose options...";
    char choice;
    cout<<"\n1. Profile";
    cout<<"\n2. Cart";
    cout<<"\n3. Wishlist";
    cout<<"\n4. Previous Orders";
    cout<<"\n5. Shopping Page";
    cout<<"\n6. Checkout";
    cout<<"\n7. Change Password";
    cout<<"\n8. Back to previous menu";
    cout<<"\n";
    cin>>choice;
    switch (choice)
    {
    case '1':
        display();
        break;
    case '2':
        display_cart();
        break;
    case '3':
        display_wishlist();
        break;
    case '4':
        display_order_history();
        break;
    case '5':
        shopping_page();
        break;
    case '6':
        checkout();
        break;
    case '7':
        return;
    default:
        break;
    }
    goto l;
}



void Customer :: shopping_page() {
    l:
    clear_screen
    cout<<"Shopping page";
    dashed
    cout<<"\nChoose Category or 0 to abort";
    dashed
    for (int i = 0; i < category_list.size(); i++)
    {
        cout<<"\n"<<i+1<<". "<<category_list[i].get_category_name();
    }
    cout<<"\n";
    string _choice;
    cin>>_choice;
    int choice = stoi(_choice);
    if (choice == 0)
    {
        return;
    }
    if (choice <= category_list.size()) {
        m:
        clear_screen
        cout<<"Category: "<<category_list[choice-1].get_category_name();
        dashed
        cout<<"\nChoose Item or 0 to abort";
        dashed
        vector<Item> items = category_list[choice-1].get_items();
        for (int i = 0; i < items.size(); i++)
        {
            cout<<"\n"<<i+1<<". "<<items[i].get_item_name();
        }
        cout<<"\n";
        string ___choice;
        cin>>___choice;
        int __choice = stoi(___choice);
        if (__choice == 0)
        {
            goto l;
        }
        if (__choice <= items.size())
        {
            k:
            clear_screen
            cout<<"Product: "<<items[__choice-1].get_item_name();
            dashed
            cout<<"\nChoose option or 0 to abort";
            dashed
            cout<<"\n1. Add to cart";
            cout<<"\n2. Add to wishlist";
            cout<<"\n3. Buy";
            char opt;
            cin>>opt;
            switch (opt)
            {
            case '0':
                goto m;
                break;
            case '1':
                cout<<"\nHow many to add to cart?: ";
                int cart_no;
                cin>>cart_no;
                cart.push_back(make_pair(items[__choice-1], cart_no));
                cout<<"\nAdded to cart successfully...";
                wait
                break;
            case '2':
                wishlist.push_back(items[__choice-1]);
                cout<<"\nAdded to wishlist successfully...";
                wait
                break;
            case '3':
                cout<<"How many to buy?: ";
                int buy_no;
                cin>>buy_no;
                checkout(make_pair(items[__choice-1],buy_no));
                break;
            default:
                goto k;
                break;
            }
            goto l;
        }
        goto m;
    }
    goto l;
}



void Customer :: display_cart() {
    l:
    cout<<"\nCart";    
    for (int i = 0; i < cart.size(); i++)
    {
        dashed
        cout<<"\n"<<i+1<<". "<<cart[i].first.get_item_name();
        cout<<"\tQuantity: "<<cart[i].second;
    }
    dashed
    cout<<"\nEnter a choice to see options(0 to go to previous menu)";
    string _choice;
    cin>>_choice;
    int choice = stoi(_choice);
    if (choice == 0)
    {
        return;
    }
    
    if (choice <= cart.size() && choice > 0)
    {
        m:
        clear_screen
        cout<<"\n1. Buy";
        cout<<"\n2. Remove from cart";
        cout<<"\n3. Back to previous menu";
        char choice1;
        cin>>choice1;
        switch (choice1)
        {
        case '1':
            checkout(cart[choice-1]);
            clear_screen
            goto l;
            break;
        case '2':
            remove_from_cart(cart[choice-1].first);
            break;
        case '3':
            clear_screen
            goto l;
            break;
        default:
            goto m;
            break;
        }
    }
    
}


void Customer :: display_wishlist() {
    cout<<"\nWishlist";
    dashed
    for (int i = 0; i < wishlist.size(); i++)
    {
        wishlist[i].display();
    }
    dashed
    wait
}


void Customer :: display_order_history() {
    cout<<"\nPrevious Orders";
    dashed
    for (int i = 0; i < order_history.size(); i++)
    {
        order_history[i].display();
    }
    dashed
    wait
}

void Customer :: checkout() {
    l:
    double total_amount = 0;
    cout<<"\nCheckout";
    for(int i = 0; i<cart.size(); i++) {
        double amount_per_item = cart[i].second * cart[i].first.get_price();
        total_amount += amount_per_item;
        cout<<"\n"<<i<<". "<<cart[i].first.get_item_name();
        cout<<"\t"<<cart[i].second<<"X"<<cart[i].first.get_price();
        cout<<" = "<<amount_per_item;
    }
    dashed
    cout<<"\nTotal Amount: "<<total_amount;
    char choice;
    cout<<"\nEnter 1 to checkout or 0 to abort...";
    cin>>choice;
    if (choice == '1')
    {
        cout<<"\nMake a payment of Rupees "<<total_amount;
        cout<<"\nClearing cart...";
        cart.clear();
        wait
        return;
    }
    if(choice == '0') {
        return;
    }
    clear_screen
    goto l;
}



void Customer :: checkout(pair<Item, int> cart_item) {
    l:
    cout<<"\nCheckout";
    double amount = cart_item.first.get_price() * cart_item.second;
    cout<<"\n"<<1<<". "<<cart_item.first.get_item_name();
    cout<<"\t"<<cart_item.second<<"X"<<cart_item.first.get_price();
    cout<<" = "<<amount;
    dashed
    cout<<"\nTotal Amount: "<<amount;
    char choice;
    cout<<"\nEnter 1 to checkout or 0 to abort...";
    cin>>choice;
    if (choice == '1')
    {
        cout<<"\nMake a payment of Rupees "<<amount;
        remove_from_cart(cart_item.first);
        wait
        return;
    }
    if(choice == '0') {
        return;
    }
    clear_screen
    goto l;
}


void Customer :: remove_from_cart(Item item) {
    for (auto it = cart.begin(); it != cart.end(); it++)
    {
        if((*it).first.get_item_name() == item.get_item_name() && (*it).first.get_price() == item.get_price())
        {
            cart.erase(it);
            it--;
        }        
    }    
}


Seller :: Seller() {
    seller_id = "";
    password = "";
    phone = "";
    company_name = "";
}


void Seller :: display() {
    cout<<"\nId: "<<seller_id;
    cout<<"\n"<<company_name;
    cout<<"\nPhone: "<<phone;
    dashed
    wait
}


void Seller :: menu() {
    while(1) {
        cout<<"\nWelcome "<<company_name;
        dashed
        cout<<"\nChoose options...";
        char choice;
        cout<<"\n1. Profile";
        cout<<"\n2. Add Item";
        cout<<"\n3. Back to previous menu";
        cin>>choice;
        switch (choice)
        {
        case '1':
            display();
            break;
        case '2':
            add_item();
            break;
        case '3':
            return;
        default:
            cout<<"Choose a valid option!!!";
            break;
        }
    }
}


bool Seller :: input_seller_data(string id) {
    seller_id = id;
    string _password, confirm_password;
    m:
    cout<<"\nCreate password(minimum 4 letters): ";
    cin.ignore();
    getline(cin,_password);
    l:
    if (_password == "0")
    {
        return false;
    }    
    if (_password.size() < 4)
    {
        cout<<"\nPassword should consist minimum 4 letters!!! Enter again: ";
        goto l;
    }
    cout<<"\nConfirm Password: ";
    getline(cin,confirm_password);
    if (confirm_password == "0")
    {
        return false;
    }
    
    if (_password != confirm_password)
    {
        cout<<"\nPassword do not match!!!";
        goto m;
    }
    password = _password;
    cout<<"\nEnter Company name: ";
    cin>>company_name;
    if (company_name == "0")
    {
        return false;
    }
    
    n:
    string _phone;
    cout<<"\nEnter 10 digit mobile number: ";
    cin>>_phone;
    if(_phone == "0")
        return false;
    regex validate_phone(R"(\d{10})");
    if (!regex_match(_phone, validate_phone))
    {
        cout<<"\nEnter valid mobile number...";
        goto n;
    }
    else{
        phone = _phone;
    }
    return true;
}



bool Seller :: validate_user(string _password) {
    return password == _password;
}



void Seller :: add_item() {
    l:
    clear_screen
    int n = category_list.size();
    cout<<"\nAdd item to sell..";
    cout<<"\nChoose categories(0 to return to previous menu)";
    for (int i = 0; i < n; i++)
    {
        cout<<"\n"<<i+1<<". "<<category_list[i].get_category_name();
        if (i == n-1)
        {
            cout<<"\n"<<i+2<<". Add new category";
        }        
    }
    string _choice;
    cin>>_choice;
    int choice = stoi(_choice);
    if (choice == 0)
    {
        return;
    }
    if (choice > 0 && choice <= n)
    {
        clear_screen
        cout<<"\nAdding Item to "<<category_list[choice-1].get_category_name();
        Item item;
        item.input_item_data();
        category_list[choice-1].add_item(item);
        return;
    }
    if (choice == n+1)
    {
        clear_screen
        cout<<"\nAdding new Category";
        Category category;
        category_list.push_back(category);
    }
    goto l;
}




//function definitions


void main_menu() {
    l:
    clear_screen
    cout<<"Welcome";
    dashed
    cout<<"\nSelect any option....";
    cout<<"\n1. Customer Menu";
    cout<<"\n2. Seller Menu";
    cout<<"\n3. Exit";
    cout<<"\n";
    char choice;
    cin >> choice;
    switch (choice)
    {
    case '1':
        customer_operations();
        break;
    case '2':
        seller_operations();
        break;
    case '3':
        exit(0);
        break;    
    default:
        break;
    }
    goto l; 
}



void customer_operations() {
    l:
    clear_screen
    cout<< "Welcome to Customer Login page";
    dashed
    cout<<"\n1. Register";
    cout<<"\n2. Login";
    cout<<"\n3. Back to main menu";
    cout<<"\n";
    char choice;
    cin >> choice;
    switch (choice)
    {
    case '1':
        register_new_customer();
        break;
    case '2':
        login_customer();
        break;
    case '3':
        return;
    default:
        break;
    }
    goto l;
}



void seller_operations() {
    l:
    clear_screen
    cout<< "Welcome to Seller Login page";
    dashed
    cout<<"\n1. Register";
    cout<<"\n2. Login";
    cout<<"\n3. Back to main menu.....\n";
    char choice;
    cin >> choice;
    switch (choice)
    {
    case '1':
        register_new_seller();
        break;
    case '2':
        login_seller();
        break;
    case '3':
        return;
    default:
        break;
    }
    goto l;
}



void register_new_customer() {
    Customer c;
    string user_id;
    l:
    clear_screen
    cout<<"New user registraion";
    dashed
    cout<<"\nEnter 0 to abort or... ";
    
    cout<<"\nEnter your preferred user id:";
    m:
    cin>> user_id;
    if (user_id == "0")
    {
        return;
    }
    
    if (customers.find(user_id) != customers.end()) {
        cout<< "\nUser Id taken!!! Please enter a different user id: ";
        goto m;
    }
    if(c.input_customer_data(user_id)) {
        cout<<"\nRegistration complete";
        wait
        customers[user_id] = c;
    }
    else {
        cout<<"\nRegistration aborted!!!";
        wait
    }
}


void login_customer() {
    string user_id;
    clear_screen
    cout<<"Login Menu";
    dashed
    cout<<"\nEnter 0 to abort";
    dashed
    cout<<"\nEnter user id:";
    l:
    cin>> user_id;
    if (user_id == "0")
    {
        return;
    }    
    if (customers.find(user_id) == customers.end()) {
        cout<< " \nInvalid User Id!!! Please enter again: ";
        goto l;
    }
    Customer c = customers[user_id];
    string password;
    cout<<"\nEnter Password: ";
    m:
    cin>>password;
    if (password == "0")
    {
        return;
    }  
    if (!c.validate_user(password))
    {
        cout<<"Invalid Password!!! Please enter again: ";
        goto m;
    }    
    c.menu();
}


void register_new_seller() {
    Seller s;
    string user_id;
    l:
    clear_screen
    cout<<"Seller Registration";
    dashed
    cout<<"\nEnter your preferred user id:";
    cin>> user_id;
    if (user_id == "0")
    {
        return;
    }
    
    if (sellers.find(user_id) != sellers.end()) {
        cout<< " \nUser Id taken!!! Please enter a different user id...\n";
        goto l;
    }
    if(s.input_seller_data(user_id)) {
        sellers[user_id] = s;
        cout<<"\nRegistration Complete";
    }
    else {
        cout<<"\nRegistration Aborted!!!";
    }
    wait
}


void login_seller() {
    string user_id;
    cout<<"\n\nEnter 0 to abort... or Enter user id:";
    l:
    cin>> user_id;
    if (user_id == "0")
    {
        return;
    }    
    if (sellers.find(user_id) == sellers.end()) {
        cout<< " \nInvalid User Id!!! Please enter again (0 to abort) :";
        goto l;
    }
    Seller s = sellers[user_id];
    string password;
    cout<<"\nEnter Password (0 to abort):";
    m:
    cin>>password;
    if (password == "0")
    {
        return;
    }  
    if (!s.validate_user(password))
    {
        cout<<"Invalid Password!!! Please enter again (0 to abort):";
        goto m;
    }    
    s.menu();
}
