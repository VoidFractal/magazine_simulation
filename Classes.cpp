#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> // exit(0) 
#include "Classes.h"


using namespace std;

//////////////////////////////////////////////////////
/////// Constructors
/////////////////////////////////////

/////////////////////////////////////
/////// Car Constructor

Car::Car(string fbrand, string fmodel, int fprod_year, float feng_capacity, int fweight, int fnum_of_wheels, int fmun_of_windshields, int fnum_of_entrances)
{
	brand = fbrand; 
	model = fmodel;
    prod_year = fprod_year;
    engine_capacity = feng_capacity;
    weight = fweight;
	num_of_wheels = fnum_of_wheels; 
	num_of_windshield = fmun_of_windshields;
	num_of_entrances = fnum_of_entrances;
}

/////////////////////////////////////
/////// Bus Constructor

Bus::Bus(string fbrand, string fmodel, int fprod_year, float feng_capacity, int fweight, int fnum_of_wheels, int fmun_of_windshields, int fnum_of_entrances)
{
	brand = fbrand; 
	model = fmodel;
    prod_year = fprod_year;
    engine_capacity = feng_capacity;
    weight = fweight;
	num_of_wheels = fnum_of_wheels; 
	num_of_windshield = fmun_of_windshields;
	num_of_entrances = fnum_of_entrances;
}

/////////////////////////////////////
/////// Bike Constructor

Bike::Bike(string fbrand, string fmodel, int fprod_year, float feng_capacity, int fweight, int fnum_of_wheels, int fmun_of_windshields, int fnum_of_entrances)
{
	brand = fbrand; 
	model = fmodel;
    prod_year = fprod_year;
    engine_capacity = feng_capacity;
    weight = fweight;
	num_of_wheels = fnum_of_wheels; 
	num_of_windshield = fmun_of_windshields;
	num_of_entrances = fnum_of_entrances;
}

//////////////////////////////////////////////////////
/////// Vehicles methods
/////////////////////////////////////

void Vehicle::display_prod_year(Vehicle *vP)
{
	cout << (*vP).brand << ' ' << (*vP).model << " production year is: " << (*vP).prod_year << endl;
}

void Vehicle::display_engine_capacity(Vehicle *vP)
{
	cout << (*vP).brand << ' ' << (*vP).model << " enginge capacity is: " << (*vP).engine_capacity << " dm^3" << endl;
}

void Vehicle::display_weight(Vehicle *vP)
{
	cout << (*vP).brand << ' ' << (*vP).model << " weight is: " << (*vP).weight << " kg" << endl;
}

void Vehicle::display_num_of_wheels(Vehicle *vP)
{
	cout << (*vP).brand << ' ' << (*vP).model << " have: " << (*vP).num_of_wheels << " wheels" << endl;
}

void Vehicle::anserw_question_function(string question, Vehicle *vP) //the mane of this function is selfexplonatory
{
	if(question == "when_produced")
	{
		display_prod_year(vP);
	}
	else if(question == "what_engine_capacity")
	{
		display_engine_capacity(vP);
	}
	else if(question == "how_much_it_weighs")
	{
		display_weight(vP);
	}
	else if(question == "how_many_wheels")
	{
		display_num_of_wheels(vP);
	}
	else if(question == "how_many_windshields")
	{
		display_num_of_windshields();
	}
	else if(question == "how_many_entrances")
	{
		display_num_of_entrances();
	}
	else cerr << "Please, try another question" << endl;
}

//////////////////////////////////////////////////////
/////// Methods displaying number of windshields
/////////////////////////////////////

void Car::display_num_of_windshields()
{
	cout << brand << ' ' << model << " have: " << num_of_windshield << " windshields" << endl;
}

void Bus::display_num_of_windshields()
{
	cout << brand << ' ' << model << " have: " << num_of_windshield << " windshields" << endl;
}

void Bike::display_num_of_windshields()
{
	cout <<  "For bikes, question about number of windshields dont realy make sense. " << endl;
}

//////////////////////////////////////////////////////
/////// Methods displaying number of entrances
/////////////////////////////////////

void Car::display_num_of_entrances()
{
	cout << brand << ' ' << model << " have: " << num_of_entrances << " entrances" << endl;
}

void Bus::display_num_of_entrances()
{
	cout << brand << ' ' << model << " have: " << num_of_entrances << " entrances" << endl;
}

void Bike::display_num_of_entrances()
{
	cout <<  "For bikes, question about number of entrances dont realy make sense. " << endl;
}

//////////////////////////////////////////////////////
/////// Additional functions not related to any class
/////////////////////////////////////

void opening_and_checking_file(string file_name, fstream *filePointer)
{
	(*filePointer).open(file_name, ios::in);
	if((*filePointer).good()==false)
	{
		cout << "File does not exist. Please create one before running the program" << endl;
		exit(0);
	}
}


void extract_function(string line, string *brandP, string *modelP, string *questionP)
{
    int c1 = 0, c2 =0;
    int line_lenght = line.length();
    for(int j=0; j < line_lenght; j++)
    {
        if(line[j] != '_') 
        {
            c1++;
        }
        else break;
    }
    for(int j=c1; j < line_lenght; j++)
    {
        if(line[j] != ',') 
        {
            c2++;
        }
        else break;
    }
	(*brandP) = line.substr(0,c1);
	(*modelP) = line.substr(c1+1,c2-1);
	(*questionP) = line.erase(0,c1+c2+2);
}


string char_vector_to_string(vector <char> vec)
{
	int vector_size = vec.size();
	char output[vector_size];
	for(int k=0; k < vector_size; k++)
	{
		output[k] = vec.at(k);
	}
	return (string)output;
	
}

void extract_function2(string line, string *brandP, string *modelP, int *prod_yearP, float *eng_capacityP, int *weightP, int *num_of_wheelsP, int *num_of_windshieldsP, int *num_of_entrancesP)
{
	vector <char> v[8];
	int num_of_floor=0;
	int line_lenght = line.length();
	for(int h=0; h < line_lenght; h++)
	{
		if(line[h]!='_')
		{
			v[num_of_floor].push_back(line[h]);
		}
		else num_of_floor++;
	}
	string output[8];
	for(int i=0; i < 8; i++)
	{
		output[i] = char_vector_to_string(v[i]);
	}
	(*brandP) = output[0];
	(*modelP) = output[1];
	(*prod_yearP) = atoi(output[2].c_str());
	(*eng_capacityP) = (float)atof(output[3].c_str());
	(*weightP) = atoi(output[4].c_str());
	(*num_of_wheelsP) = atoi(output[5].c_str());
	(*num_of_windshieldsP) = atoi(output[6].c_str());
	(*num_of_entrancesP) = atoi(output[7].c_str());

}


