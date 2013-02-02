// Warehouse Header file
// CS3505 1/28/13
//

#ifndef WAREHOUSE
#define WAREHOUSE

#include <map>
#include <string>
#include <list>
#include "date.h"
#include "product.h"

namespace cs3505 {

  // class date;
  // class product;

  class Warehouse {
  public:
    Warehouse();
    Warehouse(std::string warehouse_name);
    Warehouse();
    ~Warehouse();
    std::string get_name();
    int receive(product food_item, int quantity);
    int request(product food_item, int quantity);
    
    // this method will advance the products shelf life by one day
    int next_day();    
    int set_start_day(date date);

    friend std:: ostream& operator<< (std::ostream &out, Warehouse & rhs ); //Overrides cout
  private:
    // map for product information
    // key is upc, value is a list of products with that upc
    // products will be inserted in list based on shelf life
    
    std::map<std::string, std::list<product> > products;
    
    // map for inventory information
    // key is upc, value is amount in stock
    std::map<std::string, int> inventory;

    // name of Warehouse
    std::string name;

    
    date start_date;

    int total_days;
    
    // TODO: list should contain products in it
    int decrement_product_shelf_life(std::list<product> & product);
  };
}

#endif
