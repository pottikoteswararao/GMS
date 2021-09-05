#ifndef _INVENTORY_H
#define _INVENTORY_H

/*Include files*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cstdlib>


using namespace std; 

class Data
{
	/**private members*/
private:
	string productName;
    int productNumber;
    float demand;
    string state;
    float productQuantity;

	/*public members*/
public:
	/*empty constructor*/
	Data():
		productName("Null"), productNumber(0), demand(0.0), state("Unavailable"), productQuantity(0.0){};

	/*parameterised constructor*/
	Data(string prodName, int num, float dem, string st, float quant):
		productName(prodName), productNumber(num), demand(dem), state(st), productQuantity(quant){};

	string getProductName()
	{ 
		return productName; 
	}

	int getProductNum()
	{ 
		return productNumber; 
	}

	float getDemand()
	{ 
		return demand; 
	}

	string getState()
	{ 
		return state; 
	}

	float getQuantity()
	{ 
		return productQuantity; 
	}	

};

void printResults();

int readCSV();

Data stringToObject(string);

int highestDemandConsumer(vector<Data>);

int highestProductQuantity(vector<Data>);

vector<Data> productStatusAvailable(vector<Data>,string);

vector<Data> productStatusUnavailable(vector<Data>,int);

vector<Data> productsAboutToFinish(vector<Data>);

#endif //__INVENTORY_H_

