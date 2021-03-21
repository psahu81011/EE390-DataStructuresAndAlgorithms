#include <bits/stdc++.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;



class Item
{
  string name;
  string code;
  float price;

public:
  Item() {
    system("clear");
    cout << "\nItem Name : ";
    cin >> name;
    cout << "Item ID : ";
    cin >> code;
    cout << "Item price: ";
    cin >> price;
    getchar();
    getchar();
  }

  string get_code() {
    return code;
  }

  string get_name() {
    return name;
  }

  float get_price() {
    return price;
  }
};


class Inventory {
  vector<Item> items;
public:
  void add_item() {    
    Item i;
    items.push_back(i);
    getchar();
  }
  void delete_item() {
    system("clear");
    cout << "\nEnter the item code:";
    string code;
    cin>>code;
    auto itr = items.begin();
    for (; itr != items.end(); itr++){
      if((*itr).get_code() == code) {
        break;
      }
    }
    for (auto it = items.begin(); it != items.end(); it++)
    {
      if((*it).get_code() == code) {
        items.erase(it);
        it--;
        cout<<"\n The item is deleted";
      }
    }
    if (itr == items.end())
    {
      cout<<"\nItem does not exist in inventory";
    }
    
    getchar();
    getchar();
  }
  void display_stock() {
    int i = 1;
    system("clear");
    for (auto it = items.begin(); it != items.end(); it++)
    {
      cout << i << ".Item Name    : " << (*it).get_name();
      cout <<"\n  Item Code    : " << (*it).get_code();
      cout <<"\n  Item Price   : Rs. " << (*it).get_price() << endl
           << endl;
      i++;
    }
    if(items.size() == 0)
      cout<<"Inventory Empty";
    getchar();
    getchar();
  }
  void sell_item() {
    float total_price = 0.0;
    system("clear");
    l:
    cout<<"\nEnter item code: ";
    string code;
    cin>>code;
    auto it = items.begin();
    for (; it != items.end(); it++)
    {
      if((*it).get_code() == code) {
        cout<<"\nItem name: "<<(*it).get_name();
        cout<<"\nPrice     : Rs. "<<(*it).get_price();
        total_price += (*it).get_price();
        items.erase(it);
        it--;
        cout<<"\nDo you want to sell another item?(y/n):";
        char c;
        cin>>c;
        if(c=='y' || c=='Y') {
          goto l;
        }
        else{
          goto m;
        }
      }
    }
    if (it == items.end())
    {
      cout<<"\nItem out of stock!!!";
      cout<<"\nDo you want to sell another item?(y/n):";
      char c;
      cin>>c;
      if (c == 'y' || c == 'Y')
      {
        goto l;
      }      
    }
    m:
    if (total_price == 0)
    {
      cout<<"\nNothing sold!!!\nGoing back to previous menu...";
      getchar();
      getchar();
      return;
    }
    cout<<"\nTotal amount: "<<total_price<<" Rupees\nThank You...";
    getchar();
    getchar();
  }

};


int main()

{
  char choice;
  Inventory inventory;
  system("clear");

  while (1)
  {
    cout << "\n   Choose your action:" << endl;
    cout << "\n1: Add a new item.";
    cout << "\n2: Delete an item.";
    cout << "\n3: Sell an item.";
    cout << "\n4: Display all items.";
    cout << "\n5: Exit" << endl;
    cout << "\n\n Choose a number: ";
    cin >> choice;

    switch (choice)
    {
    case '1':

      inventory.add_item();
      break;

    case '2':

      inventory.delete_item();
      break;

    case '3':

      inventory.sell_item();
      break;

    case '4':

      inventory.display_stock();
      break;

    case '5':

      cout << "Thank you.\n";
      exit(0);
    }
    system("clear");
  }
  return 0;
}
