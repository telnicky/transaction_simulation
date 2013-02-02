// Warehouse Implementation
// cs3505 1/28/13
#include "product.h"
#include "warehouse.h"
#include "date.h"
#include <iostream>

using namespace std;

namespace cs3505 {

  Warehouse::Warehouse(std::string warehouse_name) {
    name = warehouse_name;
    total_days = 0;
    busiest_total = 0;
    current_day = 0;
  }

  Warehouse::Warehouse() {
    name = "";
    total_days = 0;
    busiest_total = 0;
    current_day = 0;
  }

  Warehouse::~Warehouse() {

  }

  date Warehouse::get_busiest_day() {
    return busiest_day;
  }

  int Warehouse::get_busiest_total() {
    return busiest_total;
  }

  string Warehouse::get_name() {
    return name;
  }

  int Warehouse::next_day() {
    current_day = 0;
    return ++total_days;
  }
  
  int Warehouse::receive(product food_item, int quantity) {
    transaction(quantity);
    
    // products map
    food_item.set_shelf_life(total_days + food_item.get_shelf_life());
    for( int i = 0; i < quantity; i++) {
      products[food_item.get_upc()].push_front(food_item);
    }

    return 1;
  }
  
  int Warehouse::request(product food_item, int quantity) {
    transaction(quantity);
    
    product request;
    int fulfilled = 0;
    list<product> product_list;
    product_list = products[food_item.get_upc()];


    // check if product is in stock
    if(product_list.size() == 0) {
      return 0;
    }

    while(true) {
      if(product_list.size() == 0) {
        break;
      }

      request = product_list.front();
      product_list.pop_front();

      if(!request.expired(total_days)) {
        fulfilled++;
        if(fulfilled == quantity){
          break;
        }
      }      
    }
    
    return 1;
  }

  
  int Warehouse::set_start_day(date date) {
    start_date = date;
  }

  int Warehouse::set_busiest_day(date date) {
    busiest_day = date;
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

  int Warehouse::transaction(int quantity) {
    current_day += quantity;

    if(busiest_total <= current_day) {
      date temp = start_date;      
      for(int i = 0; i < total_days; i++) {
        temp.increment();
      }
      
      busiest_total = current_day;
      set_busiest_day(temp);      
    }
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
