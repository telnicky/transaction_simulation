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

    Warehouse(std::string warehouse_name);
    Warehouse();
    ~Warehouse();
    std::string get_name();
    int receive(product food_item, int quantity);
    int request(product food_item, int quantity);
    
    // this method will advance the products shelf life by one day
    int next_day();    
    date get_busiest_day();
    int get_busiest_total();

    bool is_out_of_stock(std::string upc);

    int set_busiest_day(date date);
    int set_start_day(date date);


    int transaction(int quantity);

    friend std:: ostream& operator<< (std::ostream &out, Warehouse & rhs ); //Overrides cout
  private:
    // map for product information
    // key is upc, value is a list of products with that upc
    // products will be inserted in list based on shelf life
    
    std::map<std::string, std::list<product> > products;

    // name of Warehouse
    std::string name;

    
    date start_date;
    date busiest_day;

    int busiest_total;
    int current_day;
    int total_days;
    
  };
}

#endif
