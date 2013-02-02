/* Represents the a date in time 
 * ie. 1/20/2013 
 *
 * Dustin Robinson
 * Travis Elnicky
 * January 29, 2013
 */

#ifndef DATE
#define DATE

#include <ostream>
#include <string>

namespace cs3505

{

  class date
  {
  public:
    
    date();
    date(int _month, int _day , int _year);     // Constructor
    date(const date & other);                   // Copy constructor
    //~date();                                  // Destructor

    friend std:: ostream& operator<< (std::ostream &out, const date & rhs ); //Overrides cout

    void increment(); // Increments the date by one day
    int getMonth();
    int getDay();
    int getYear();


  private:
    int month;  
    int day;
    int year;        
    
  };

 
}

#endif