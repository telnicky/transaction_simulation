// Warehouse Implementation
// cs3505 1/28/13
#include "product.h"
#include "warehouse.h"
#include "date.h"

using namespace std;

namespace cs3505 {

  Warehouse::Warehouse(std::string warehouse_name) {
    name = warehouse_name;
  }

  Warehouse::~Warehouse() {

  }

  string Warehouse::get_name() {
    return name;
  }

  int Warehouse::next_day() {
    for (map<string, list<product> >::iterator it = products.begin(); 
        it != products.end(); ++it) {
      decrement_product_shelf_life(it->second); 
    }
  }
  
  int Warehouse::receive(product food_item, int quantity) {
    // products map
    // TODO: push product to list in correct position based on shelf life
    // TODO: push new product not string
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
}
