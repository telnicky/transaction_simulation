// Travis Elnicky and Dustin Robinson
// cs3505 hw4 2/2/13


#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "Warehouse.h"
#include "product.h"
#include "date.h"

using namespace std;


void read_txt(string filename, map<string, cs3505::Warehouse> & warehouses, 
  map<string, cs3505::product> & products, cs3505::date start_date)
{
  ifstream in(filename.c_str());
  string current_word;
  
  string temp_upc = "";
  int temp_shelf_life = 0;
  string temp_name = "";
  string temp_warehouse_name = "";
  string temp_date = "";  


   while(!in.fail())
   {
      in >> current_word;

      //First word of a line == FoodItem
      if(current_word == "FoodItem")   
      {
        int i = 0;
        while(true)
        {
          i++;
          in >> current_word;

          if(i == 3)
            in >> temp_upc;
          else if(i == 5)
          {
            in >> temp_shelf_life;
            in >> current_word;
            getline(in, temp_name);
            temp_name.erase(0, 1);
            break;
          }
          else;  
        }

        products[temp_upc] = cs3505::product(temp_shelf_life, temp_upc, temp_name);        
      }

      //First word of a line == Warehouse
      else if(current_word == "Warehouse")   
      {
        
        in >> current_word;
        // in >> temp_warehouse_name;
        getline(in, temp_warehouse_name);
        temp_warehouse_name.erase(0, 1);
        temp_warehouse_name.erase(temp_warehouse_name.size() - 1, 1);

        warehouses[temp_warehouse_name] = cs3505::Warehouse(temp_warehouse_name);
      }

      //First word of a line == Start
      else if(current_word == "Start")   
      {
        in >> current_word;
        in >> temp_date;

        int month = atoi(temp_date.substr(0,2).c_str());
        int day = atoi(temp_date.substr(3,2).c_str());
        int year = atoi(temp_date.substr(6,4).c_str());

        cs3505::date temp(month, day, year);
        start_date = temp;

        for (map<string, cs3505::Warehouse>::iterator wh = warehouses.begin(); 
          wh != warehouses.end(); ++wh) {          
          wh->second.set_start_day(start_date);
          wh->second.set_busiest_day(start_date);
        } 
cout << start_date << endl;
      }

      //First word  == recieve
      else if(current_word == "Receive:")   
      {
        int temp_quantity;

        in >> temp_upc;
        in >> temp_quantity;
        getline(in, temp_warehouse_name);
        temp_warehouse_name.erase(0, 1);
        temp_warehouse_name.erase(temp_warehouse_name.size() - 1, 1);

        // update warehouse
        warehouses[temp_warehouse_name]
          .receive(products[temp_upc], temp_quantity);

      }

      //First word  == request
      else if(current_word == "Request:")   
      {
        int temp_quantity;

        in >> temp_upc;
        in >> temp_quantity;
        getline(in, temp_warehouse_name);
        temp_warehouse_name.erase(0, 1);
        temp_warehouse_name.erase(temp_warehouse_name.size() - 1, 1);
        //Update warehouse;
        warehouses[temp_warehouse_name]
          .request(products[temp_upc], temp_quantity);
      }

      //First word of a line == Next
      else if(current_word == "Next")   
      {
        for (map<string, cs3505::Warehouse>::iterator wh = warehouses.begin(); 
          wh != warehouses.end(); ++wh) {          
          wh->second.next_day();
        } 
      }

   }

}

//Prints a list of prodcuts that are out of stock at every warehouse
void out_of_stock(map<string, cs3505::Warehouse> & warehouses, map<string, cs3505::product> & products)
{

  map<string, cs3505::product> temp_products = products;

  //Iterate through all the warehouses
  for (map<string, cs3505::Warehouse >::iterator wit = warehouses.begin(); 
        wit != warehouses.end(); ++wit) 
  {
    map<string, cs3505::product>::iterator product_list = products.begin();
    
    // check for products that are out of stock
    for (product_list; product_list != products.end(); ++product_list) {
      string upc = product_list->first;

      if(!(wit->second.is_out_of_stock(upc))) {
        // remove from out of stock list
        temp_products.erase(upc);
      }
    }
  }

  // remaining items in list are out of stock in every warehouse
  // print products in stock

  cout << "Unstocked Products:" << endl;
  for(map<string, cs3505::product>::iterator prod = temp_products.begin(); 
        prod != temp_products.end(); ++prod) {
    cout << prod->first << " " << prod->second.get_name() << endl;
  }

}

//Prints a list of prodcuts that are in stock at every warehouse
void in_stock(map<string, cs3505::Warehouse> & warehouses, map<string, cs3505::product> & products)
{

  map<string, cs3505::product> temp_products = products;

  //Iterate through all the warehouses
  for (map<string, cs3505::Warehouse >::iterator wit = warehouses.begin(); 
        wit != warehouses.end(); ++wit) 
  {
    map<string, cs3505::product>::iterator product_list = products.begin();
    
    // check for products that are out of stock
    for (product_list; product_list != products.end(); ++product_list) {
      string upc = product_list->first;

      if(wit->second.is_out_of_stock(upc)) {
        // remove from in stock list
        temp_products.erase(upc);
      }
    }
  }

  // remaining items in list are in stock in every warehouse
  // print products in stock

  cout << "Fully-Stocked Products:" << endl;
  for(map<string, cs3505::product>::iterator prod = temp_products.begin(); 
        prod != temp_products.end(); ++prod) {
    cout << prod->first << " " << prod->second.get_name() << endl;
  }

}

int print_busiest_day(map<string, cs3505::Warehouse> &warehouses) {
  cout << "Busiest Days:" << endl;

  for (map<string, cs3505::Warehouse>::iterator wh = warehouses.begin(); 
      wh != warehouses.end(); ++wh) {
    
    cout << wh->second.get_name() << " ";
    cout << wh->second.get_busiest_day() << " ";
    cout << wh->second.get_busiest_total() << endl;
  }

  return 0;
}

int main(int argc, char* argv[]) {
  map<string, cs3505::Warehouse> warehouses;
  map<string, cs3505::product> products;
  cs3505::date start_date;

  if(argc != 2) {
    cout << "Must provide one file" << endl;
    return 1;
  }

  read_txt(argv[1], warehouses, products, start_date);
  cout << "Report by Travis Elnicky and Dustin Robinson" << endl;
  cout << endl;
  out_of_stock(warehouses, products);
  cout << endl;
  in_stock(warehouses,products);
  cout << endl;
  print_busiest_day(warehouses);


 return 0;
 
}