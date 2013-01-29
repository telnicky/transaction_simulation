// Warehouse Header file
// CS3505 1/28/13
//
#include <map>
#include <string>
#include <list>

namespace cs3505 {
  class Warehouse {
  public:
    Warehouse(std::string warehouse_name);
    ~Warehouse();
    std::string get_name();
    int receive(std::string upc, int quantity);
    int request(std::string upc, int quantity);
    
    // this method will advance the products shelf life by one day
    int next_day();
    
    // TODO: date should be of type date
    int set_start_day(std::string date);
  private:
    // map for product information
    // key is upc, value is a list of products with that upc
    // products will be inserted in list based on shelf life
    // TODO: change value type to product when implemented
    std::map<std::string, std::list<std::string> > products;
    
    // map for inventory information
    // key is upc, value is amount in stock
    std::map<std::string, int> inventory;

    // name of Warehouse
    std::string name;

    //TODO: date should be of type date class
    std::string start_date;
    
    // TODO: list should contain products in it
    int decrement_product_shelf_life(std::list<std::string> & product);
  };
}
