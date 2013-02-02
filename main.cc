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
<<<<<<< HEAD
<<<<<<< HEAD
	ifstream in(filename.c_str());
	string current_word;
  
=======
  ifstream in(filename.c_str());
  string current_word;

>>>>>>> Some errors in Parsing
=======
	ifstream in(filename.c_str());
	string current_word;
  
>>>>>>> moved out_of_stock into warehouse
  string temp_upc = "";
  int temp_shelf_life = 0;
  string temp_name = "";
  string temp_warehouse_name = "";
<<<<<<< HEAD
<<<<<<< HEAD
  string temp_date = "";  
	
=======
  string temp_date = "";
  cs3505::date start_date;

>>>>>>> Some errors in Parsing
=======
  string temp_date = "";  
	
>>>>>>> moved out_of_stock into warehouse

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
cout<< "Shelf Life: " << temp_shelf_life << endl;
            in >> current_word;
            getline(in, temp_name);
            temp_name.erase(0, 1);
cout << "Description: " << temp_name << endl;
            break;
          }
          else;  
        }
<<<<<<< HEAD
<<<<<<< HEAD

        products[temp_upc] = cs3505::product(temp_shelf_life, temp_upc, temp_name);        
=======
<<<<<<< HEAD
	// Travis I'm getting this error with this code:
	/*main.cc: In function ‘void read_txt(std::string)’:
	 *main.cc:58: error: ‘products’ was not declared in this scope
	 *main.cc:58: error: ‘product’ was not declared in this scope
	 */
	//Also is this the correct way to add an item to a map 
	//Also how do I access an object in a map to update that objects properties.
=======
 
>>>>>>> Some errors in Parsing
        products[temp_upc] = cs3505::product(temp_shelf_life, temp_upc, temp_name);
        
>>>>>>> Some errors in Parsing
=======

        products[temp_upc] = cs3505::product(temp_shelf_life, temp_upc, temp_name);        
>>>>>>> moved out_of_stock into warehouse
      }

      //First word of a line == Warehouse
      else if(current_word == "Warehouse")   
      {
        //for(int i = 0; i < 8 ; i++)
        int i = 0;
        while(true)
        {
          i++;
          in >> current_word;

          if(i == 1)
          {
            in >> temp_warehouse_name;
// cout << "Warehouse Name: " << temp_warehouse_name << endl;
            break;
          }
          else; 
        }

        warehouses[temp_warehouse_name] = cs3505::Warehouse(temp_warehouse_name);
<<<<<<< HEAD
<<<<<<< HEAD
=======
        
>>>>>>> Some errors in Parsing
=======
>>>>>>> moved out_of_stock into warehouse
      }

      //First word of a line == Start
      else if(current_word == "Start")   
      {
        in >> current_word;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> moved out_of_stock into warehouse
        in >> temp_date;
// cout << "M: " << temp_date.substr(0,2) << endl;
// cout << "D: " << temp_date.substr(3,2) << endl;
// cout << "Y: " << temp_date.substr(6,4) << endl;
<<<<<<< HEAD
      
        int month = atoi(temp_date.substr(0,2).c_str());
        int day = atoi(temp_date.substr(3,2).c_str());
        int year = atoi(temp_date.substr(6,4).c_str());
=======
        getline(in, temp_date);
        cout << temp_date.substr(1,2) << endl;
        cout << temp_date.substr(4,2) << endl;
        cout << temp_date.substr(7,4) << endl;
      
        int month = atoi(temp_date.substr(1,2).c_str());
        int day = atoi(temp_date.substr(4,2).c_str());
        int year = atoi(temp_date.substr(7,4).c_str());
        if(month < 10)
>>>>>>> Some errors in Parsing
=======
      
        int month = atoi(temp_date.substr(0,2).c_str());
        int day = atoi(temp_date.substr(3,2).c_str());
        int year = atoi(temp_date.substr(6,4).c_str());
>>>>>>> moved out_of_stock into warehouse


// cout << "Month: " << month << endl;
// cout << "Day: " << day << endl;
// cout << "Year: " << year << endl;
        cs3505::date temp(month, day, year);
        start_date = temp;

// cout << "Date: " << start_date << endl;
      }

      //First word  == recieve
      else if(current_word == "Receive:")   
      {
        int temp_quantity;

        in >> temp_upc;
        in >> temp_quantity;
        in >> temp_warehouse_name;
// cout << "REC: " << temp_upc << " " << temp_quantity << " "
  // << temp_warehouse_name << endl;
// cout << "PROD: " << products[temp_upc] << endl;
        // update warehouse
        warehouses[temp_warehouse_name]
          .receive(products[temp_upc], temp_quantity);

<<<<<<< HEAD
<<<<<<< HEAD
=======
        //Update the warehouse records
        warehouses[temp_warehouse_name].receive(products[temp_upc],temp_quantity);
        
>>>>>>> Some errors in Parsing
=======
>>>>>>> moved out_of_stock into warehouse
      }

      //First word  == request
      else if(current_word == "Request:")   
      {
        int temp_quantity;

        in >> temp_upc;
        in >> temp_quantity;
        in >> temp_warehouse_name;

// cout << "REQ: " << temp_upc << " " << temp_quantity << " " 
  // << temp_warehouse_name << endl;

<<<<<<< HEAD
<<<<<<< HEAD
        //Update warehouse;
        // warehouses[temp_warehouse_name]
          // .request(products[temp_upc], temp_quantity);
=======
        //Update the warehouse records
        warehouses[temp_warehouse_name].request(products[temp_upc], temp_quantity);
>>>>>>> Some errors in Parsing
=======
        //Update warehouse;
        // warehouses[temp_warehouse_name]
          // .request(products[temp_upc], temp_quantity);
>>>>>>> moved out_of_stock into warehouse
        
      }

      //First word of a line == Next
      else if(current_word == "Next")   
      {
        start_date.increment();
<<<<<<< HEAD
<<<<<<< HEAD

// cout << "NEXT DAY: " << start_date << endl; 
      }

=======
        //cout << start_date << endl; 
      }
=======
>>>>>>> moved out_of_stock into warehouse

// cout << "NEXT DAY: " << start_date << endl; 
      }

<<<<<<< HEAD
      else;
        // Do Nothing, Continue to get next word until end of File
>>>>>>> Some errors in Parsing
=======
>>>>>>> moved out_of_stock into warehouse
   }

}

//Prints a list of prodcuts that are in stock at every warehouse
void in_stock(map<string, cs3505::Warehouse> & warehouses, map<string, cs3505::product> & products)
{
<<<<<<< HEAD
<<<<<<< HEAD
  //map<string, cs3505::product> temp_products = products;
=======
  map<string, cs3505::product> temp_products = products;
>>>>>>> Some errors in Parsing
=======
  //map<string, cs3505::product> temp_products = products;
>>>>>>> moved out_of_stock into warehouse

  //Iterate through all the warehouses
  for (map<string, cs3505::Warehouse >::iterator wit = warehouses.begin(); 
        wit != warehouses.end(); ++wit) 
  {
<<<<<<< HEAD
<<<<<<< HEAD
    cout << wit->first << endl;
    //map<string, cs3505::product> current_temp;
=======
    //cout << wit->first << endl;
    map<string, cs3505::product> current_temp;
>>>>>>> Some errors in Parsing
=======
    cout << wit->first << endl;
    //map<string, cs3505::product> current_temp;
>>>>>>> moved out_of_stock into warehouse
    //Iterate through the products in each of those warehouses
    //For each product that exists continue to add it back to the list as long as other 
    //warehouses contain it
    /*
     *There is a problem iterating through an object from an iterator
     *Once this line of code works the rest should
     */
    // for(map<string, list<cs3505::product> >::iterator it = wit->second.products.begin(); 
    //     it != wit->second.products.end(); ++it)
    // {
    //   map<string, cs3505::product> current_temp;

    //   if(temp_products[it->first])
    //     current_temp[it->first] = it->second;
    // }
    // temp_products = current_temp;
  }
  //cout << "Fully-Stocked Products:" << endl;
  //
  //temp_products contains all products that exist in every warehouse
  //Iterate through the map and return those items
  // if(!temp_products.empty())
  // {
  //
  //
  //   for (map<string, cs3505::product >::iterator pit = temp_products.begin(); 
  //       pit != temp_products.end(); ++pit) 
  //     cout << pit.get_upc() << " " << pit.get_name() <<endl;
  // }
  //
  // cout << "" << endl;
}

int main() {

  map<string, cs3505::Warehouse> warehouses;
  map<string, cs3505::product> products;
  cs3505::date start_date;


<<<<<<< HEAD
<<<<<<< HEAD
  read_txt("data1.txt", warehouses, products, start_date);
=======
  read_txt("data1.txt", warehouses, products);
  out_of_stock(warehouses, products);
  in_stock(warehouses,products);

>>>>>>> Some errors in Parsing
>>>>>>> Some errors in Parsing
=======

  read_txt("data1.txt", warehouses, products, start_date);
>>>>>>> moved out_of_stock into warehouse

  for (map<string, cs3505::Warehouse>::iterator wh = warehouses.begin(); 
      wh != warehouses.end(); ++wh) {
    cout << wh->second << endl;
  }
 return 0;
 
}