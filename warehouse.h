// Warehouse Header file
// CS3505 1/28/13
//
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

    Warehouse(std::string warehouse_name);
    ~Warehouse();
    std::string get_name();
    int receive(product food_item, int quantity);
    int request(product food_item, int quantity);
    
    // this method will advance the products shelf life by one day
    int next_day();
    
    // TODO: date should be of type date
    int set_start_day(date date);
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
    
    // TODO: list should contain products in it
    int decrement_product_shelf_life(std::list<product> & product);
  };
}
