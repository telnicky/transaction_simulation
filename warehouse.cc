// Warehouse Implementation
// cs3505 1/28/13
#include "warehouse.h"
using namespace std;

namespace cs3505 {

  Warehouse::Warehouse(std::string warehouse_name) {
    name = warehouse_name;
  }

  Warehouse::~Warehouse() {
    delete &products;
    delete &inventory;
    delete &name;
  }

  string Warehouse::get_name() {
    return name;
  }

  int Warehouse::next_day() {
    for (map<string, list<string> >::iterator it = products.begin(); 
        it != products.end(); ++it) {
      decrement_product_shelf_life(it->second); 
    }
  }
  
  int Warehouse::receive(string upc, int quantity) {
    // products map
    // TODO: push product to list in correct position based on shelf life
    // TODO: push new product not string
    products[upc].push_front(upc);

    // inventory map
    inventory[upc] += 1;
    
    return 1;
  }
  
  int Warehouse::request(std::string upc, int quantity) {
    // check if product is in stock
    if(inventory[upc]) {
      return 0;
    }
    
    // decrement stock
    inventory[upc] -= 1;

    // products map
    // when sorted this should be removing the product
    // closest to expiring
    products[upc].pop_front();
    return 1;
  }

  //TODO: date should be of type date
  int Warehouse::set_start_day(std::string date) {
    start_date = date;
  }
  
  int Warehouse::decrement_product_shelf_life(list<string> & product) {
 //   for (list<int>::iterator it = product.begin(); it != product.end(); ++it) {
      // TODO: decrement shelf life by one
      // update inventory map
   // }
  }
}
