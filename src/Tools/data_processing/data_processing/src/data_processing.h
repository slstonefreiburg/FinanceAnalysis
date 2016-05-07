#ifndef DATA_PROCESSING_H
#define DATA_PROCESSING_H

#include <windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <string>
#include <vector>


using namespace std;

class DataProcessing
{
   public:
	   struct myDate {
		   int year;
		   int month;
		   int day;
		   myDate() { year=0; month=0; day=0; }

		   bool operator== (const myDate &d) const {
			   return (year == d.year && month == d.month && day == d.day);
		   };

		   bool operator>= (const myDate &d) const {
			   bool ret = true;
			   if (year < d.year) {
				   ret = false;
			   }
			   else if (year == d.year) {
				   if (month < d.month)
					   ret = false;
				   else if (month == d.month) {
					   if (day < d.day)
						   ret = false;
				   }
			   }
			   return ret;
		   };
	   };

	   struct myTime {
		   double hour;
		   double min;
		   double sec;
		   myTime() { hour = 0.0; min = 0.0; sec = 0.0; }
	   };

	   struct myIndexData {
		   myDate date;
		   myTime time;
		   double volume;
		   double price;
		   double diff;
		   double change;

		   myIndexData() {
			   date = myDate(); time = myTime(); 
			   volume = 0.0; price = 0.0; diff = 0.0; change = 0.0;
		   }
	   };

	   DataProcessing();
	   ~DataProcessing();

	   bool readIn(const std::string &filename);
	   void convertToCNTKFormat();

	   vector<myIndexData>& getIndexData() { 
		   return _index_data;
	   };

	   int getSizeOfIndexData() {
		   return _index_data.size();
	   };

   protected:
	   vector<myIndexData> _index_data;
	   void tokenize(const string& str, vector<string>& tokens, const string& delimiters);

};
#endif


