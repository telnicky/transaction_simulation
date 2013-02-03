/* Represents the a date
 * ie. 1/20/2013 
 *
 * Dustin Robinson
 * Travis Elnicky
 * January 29, 2013
 */

#include <iostream>
#include <string>
#include "date.h"

namespace cs3505
{
    //Empty Constructor
    date::date()
    {
        this->month = 0;
        this->day = 0;
        this->year = 0;
    }
    // Constructor
    date::date(int _month, int _day ,int _year) 
    {
        this->month = _month;
        this->day = _day;
        this->year = _year;
    }

    // Copy constructor     
    date::date(const date & other)
    {
        this->month = other.month;
        this->day = other.day;
        this->year = other.year;
    }

    //~product();  // Destructor
    //ToDO

    /*
     * Overrides cout <<
     */
    std::ostream& operator<< (std::ostream &out, const date & rhs )
    {
        std::string _month = (rhs.month < 10) ? "0" : "";
        std::string _day = (rhs.day < 10) ? "0" : "";
        out << _month << rhs.month << "/" << _day << rhs.day << "/" << rhs.year;

        return out;
    }
                              
    /*
     * Increments the date by one day
     */
    void date::increment()
    {
        //April, June, September, November have 30 days
        if(month == 4 || month == 6 || month == 9 || month == 11 )
        {

            if(day == 30)
            {
                day = 1;
                if(month == 12)
                {
                    month = 1;
                    year++;
                }
                else  
                    month++;     
            }
            else
                day++;
        }

        //Febuary has 28 days
        else if(month == 2)
        {
            //If Leap Year Febuary has 29 days
            //Check for Leap Year
            if((year % 400  == 0 )|| (year % 4 == 0 ))
            {
                if(day == 29)
                 {
                    day = 1;

                    if(month == 12)
                    {
                        month = 1;
                        year++;
                    }
                    else  
                        month++; 
                }
                else
                    day++;
            }

            //Not a Lear Year
            else
            {
                if(day == 28)
                {
                    day = 1;

                    if(month == 12)
                    {
                        month = 1;
                        year++;
                    }
                    else  
                        month++; 
                }
                else 
                    day++; 
            }
        }

        //All other months have 31 days
        else
        {
            if(day == 31)
            {
                day = 1;

                if(month == 12)
                {
                    month = 1;
                    year++;
                }
                else  
                month++; 
            }
                
            else
                day++;  
        }

    } 

    int date::getMonth()
    {
        return month;
    }

    int date::getDay()
    {
        return day;
    }

    int date::getYear()
    {
        return year;
    }
    
}


     
    