// Warehouse Implementation
// cs3505 1/28/13
#include "product.h"
#include "warehouse.h"
#include "date.h"
#include <iostream>

using namespace std;

namespace cs3505 {

  Warehouse::Warehouse()
  {
    name = "";
  }
  Warehouse::Warehouse(std::string warehouse_name) {
    name = warehouse_name;
    total_days = 0;
  }

  Warehouse::Warehouse() {
    name = "";
    total_days = 0;
  }

  Warehouse::~Warehouse() {
<<<<<<< HEAD

=======
    // delete &products;
    // delete &inventory;
    // delete &name;
>>>>>>> Some errors in Parsing
  }

  string Warehouse::get_name() {
    return name;
  }

  int Warehouse::next_day() {
    total_days++;
  }
  
  int Warehouse::receive(product food_item, int quantity) {
    // products map
    food_item.set_shelf_life(total_days + food_item.get_shelf_life());
    products[food_item.get_upc()].push_front(food_item);
    
    // inventory map
    inventory[food_item.get_upc()] += 1;
    return 1;
  }
  
  int Warehouse::request(product food_item, int quantity) {
    // check if product is in stock
    if(inventory[food_item.get_upc()]) {
      return 0;
    }
    
    // decrement stock
    inventory[food_item.get_upc()] -= 1;

    // products map
    // when sorted this should be removing the product
    // closest to expiring
    
    products[food_item.get_upc()].pop_front();
    return 1;
  }

  
  int Warehouse::set_start_day(date date) {
    start_date = date;
  }

  

  int Warehouse::decrement_product_shelf_life(list<product> & product_list) {
    for (list<product>::iterator it = product_list.begin(); it != product_list.end(); ++it) {
      // TODO: decrement shelf life by one
      it->decrement_shelf_life();
    }
    
    //TODO: make sure front exists as well
    // while(product_list.front.get_shelf_life() == 0) {
      // product_list.pop_front();
    // }
  }


  /*
     * Overrides cout <<
     */
  std::ostream& operator<< (std::ostream &out, Warehouse & rhs ) {
    out << rhs.name << ": " << endl;
    map<string, list<product> >::iterator product_list = rhs.products.begin();
    // list products
    for (product_list; product_list != rhs.products.end(); ++product_list) {
      list<product>::iterator food_item = product_list->second.begin();
      for (food_item; food_item != product_list->second.end(); ++food_item) {        
        out << (*food_item) << endl;
      }
    }

    return out;
  }
}
