/**
 * @file inventory.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include"inventory.h"

const char* inputFile = "data.csv";
vector<Data> dataTracking;

int highestDemandConsumer(vector<Data> dataTracking)
{	
	float highestDemand = 0.0;
	int productNo;
	for(auto i:dataTracking){
    		if(i.getDemand()>highestDemand){
    			highestDemand = i.getDemand();
    			productNo = i.getProductNum();
    		} 
	}
	return productNo;
}

int highestProductQuantity(vector<Data> dataTracking)
{
	float highestQuantity = 0.0;
	int productNo=0;
	for(auto i:dataTracking){
		if(i.getQuantity()==highestQuantity)
		{
			//strcat(",",productNo);	
		}
    		else if(i.getQuantity()>highestQuantity){
    			highestQuantity = i.getQuantity();
    			productNo = i.getProductNum();
    		} 
	}
	return productNo;
}

vector<Data> productStatusAvailable(vector<Data> dataTracking,string product)
{	
	vector<Data> Available;
	string available = "Available";
	
	for(auto i:dataTracking){
		string str1 = i.getState();
    		if(str1==available && i.getProductName()==product)//0==strcmp(str1,available)){
    		{
    			Available.push_back(i);
    		} 
	}
	return Available;
}

vector<Data> productStatusUnavailable(vector<Data> dataTracking,int giveQuant)
{	
	vector<Data> Unavailable;
	string unavail = "Unavailable";
	
	for(auto i:dataTracking){
		string str1 = i.getState();
    		if(str1==unavail && i.getQuantity()>giveQuant)
    		{
    			Unavailable.push_back(i);
    		} 
	}
	return Unavailable;
}

vector<Data> productsAboutToFinish(vector<Data> dataTracking){
	vector<Data> limitedproducts;
	
	float miniQuant = 20.00;
	for(auto i:dataTracking){
		
    		if( i.getQuantity()<= miniQuant)
    		{
    			limitedproducts.push_back(i);
    		} 
	}
	return limitedproducts;
}

Data stringToObject(string s)
{
	string delimiter = ",";
	string productName;
    	string productNumber;
    	string Demand;
    	string state;
    	string productQuantity;
    	int p=1;
	size_t pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos) {
	    token = s.substr(0, pos);
	    s.erase(0, pos + delimiter.length());
	    if(p==1){
	    productName = token;
	    }else if(p==2){
	    	productNumber=token;
	    }
	    else if(p==3){
	   	Demand=token;
	    }
	    else if(p==4){
	    	state=token;
	    }   
	    p++;
	}
	productQuantity=s;
	Data d(productName, stoi(productNumber), (float)stof(Demand), state, (float)stof(productQuantity));
	return d;
}

int readCSV()
{	
	string line;
	ifstream file(inputFile);// open a file in read mode.
	if(!file)  // Checking whether file got opened successfully or not 
  	{  
		cout << "File opening failed\n";
		return EXIT_FAILURE;
    	}
    	
  	dataTracking.clear();//clear the garbage values
	while(getline(file, line))
	{
		istringstream s(line);
		string field;
	  	while (getline(s, field,'\n'))
	  	{
	  		dataTracking.push_back(stringToObject(field));
	  	}
  	}
	file.close();	
	return 0;
}

void printResults()
{
    string product = "Soap";
    float minimumDemand = 20;
    cout<<"Highest Consumer Demand (Product Number): "<<highestDemandConsumer(dataTracking)<<"\n"<<endl;
	cout<<"Highest Product quantity available (Product Number)): "<< highestProductQuantity(dataTracking)<<"\n"<<endl;
    cout<<"|------------------------------------------------------------|"<<"\n"<<endl;
	cout<<"Details of Product "<<product<<" which is available currently"<<"\n"<<endl;
    for(auto i:productStatusAvailable(dataTracking, product))
		cout<<i.getProductName()
    	<<'\t'<<'\t'<<i.getProductNum()
    	<<'\t'<<'\t'<<i.getDemand()
    	<<'\t'<<'\t'<<i.getState()
    	<<'\t'<<'\t'<<i.getQuantity()<<'\n';
    cout<<"\n"<<"|------------------------------------------------------------|"<<endl;
	cout<<"\n"<<"Details of High demand products (unavailable) : "<<minimumDemand<<"\n"<<endl;	    
   	for(auto i:productStatusUnavailable(dataTracking,minimumDemand))
		cout<<i.getProductName()
    	<<'\t'<<i.getProductNum()
    	<<'\t'<<i.getDemand()
    	<<'\t'<<i.getState()
    	<<'\t'<<i.getQuantity()<<'\n';

	cout<<"\n"<<"Remaining products in inventory which are about to finish"<<"\n"<<endl;	    
   	for(auto i:productsAboutToFinish( dataTracking))
		cout<<i.getProductName()
    	<<'\t'<<'\t'<<i.getProductNum()
    	<<'\t'<<'\t'<<i.getDemand()
    	<<'\t'<<'\t'<<i.getState()
    	<<'\t'<<'\t'<<i.getQuantity()<<'\n';
}
