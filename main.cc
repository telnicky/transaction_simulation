#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include "Warehouse.h"
#include "product.h"
#include "date.h"

using namespace std;

void read_txt(string filename)
{
	ifstream in(filename.c_str());
	string current_word;

	// in >> first_word;
  //  in >> first_word;
	//getline(in, current_word,' ');
  //cout << current_word <<endl;
  
  string temp_upc = "";
  int temp_shelf_life = 0;
  string temp_name = "";
  string temp_warehouse_name = "";
  string temp_date = "";
  cs3505::date start_date;
	

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
            //cout << current_word << endl;
            in >> temp_shelf_life;
            cout << temp_shelf_life << endl;
            in >> current_word;
            getline(in, temp_name);
            temp_name.erase(0, 1);
            cout << temp_name << endl;
            break;
          }
          else;  
        }
	// Travis I'm getting this error with this code:
	/*main.cc: In function ‘void read_txt(std::string)’:
	 *main.cc:58: error: ‘products’ was not declared in this scope
	 *main.cc:58: error: ‘product’ was not declared in this scope
	 */
	//Also is this the correct way to add an item to a map 
	//Also how do I access an object in a map to update that objects properties.
        products[temp_upc] = product(temp_shelf_life, temp_upc, temp_name);
        
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
            cout << temp_warehouse_name << endl;
            break;
          }
          else; 
        }

        //warehouses[temp_warehouse_name] = Warehouse(temp_warehouse_name);
        //break;
      }

      //First word of a line == Start
      else if(current_word == "Start")   
      {
        in >> current_word;
        in >> temp_date;
        cout << temp_date.substr(0,2) << endl;
        cout << temp_date.substr(3,2) << endl;
        cout << temp_date.substr(6,4) << endl;
      
        int month = atoi(temp_date.substr(0,2).c_str());
        int day = atoi(temp_date.substr(3,2).c_str());
        int year = atoi(temp_date.substr(6,4).c_str());
        if(month < 10)

        cout << month << endl;
        cout << day << endl;
        cout << year << endl;
        cs3505::date temp(month, day, year);
        start_date = temp;

        cout << start_date << endl;
      }

      //First word  == recieve
      else if(current_word == "Receive")   
      {
        int temp_quantity;

        in >> temp_upc;
        in >> temp_quantity;
        in >> temp_warehouse_name;

        //ToDO Uodate warehouse;
        //warehouses[]
        
      }

      //First word  == request
      else if(current_word == "Request")   
      {
        int temp_quantity;

        in >> temp_upc;
        in >> temp_quantity;
        in >> temp_warehouse_name;

        cout << temp_upc << " " << temp_quantity << " " << temp_warehouse_name << endl;

        //ToDO Uodate warehouse;
        //warehouses[]
        
      }

      //First word of a line == Next
      else if(current_word == "Next")   
      {
        start_date.increment();

        cout << start_date << endl; 
      }

      else;

        // Eng of File
      

   }

}

int main() {

  map<string, cs3505::Warehouse> warehouses;
  map<string, cs3505::product> products;

  read_txt("data1.txt");

 return 0;
}
