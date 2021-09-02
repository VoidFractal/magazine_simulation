#include <iostream>
#include <fstream>
#include "Classes.h"

using namespace std;

int main()
{
	//// file variables
	fstream question_file, magazine_file[3];

	//// names of magazine files
	string mag_file_name[3];
	mag_file_name[0] = "cars.txt", mag_file_name[1] = "buses.txt", mag_file_name[2] = "bikes.txt";

	//// variables needed to obtain info from questions
	string question, brand_from_question, model_from_question;

	//// variables needed to store information about vehicles in magazine
	string brand, model;
    int prod_year, weight, num_of_wheels, num_of_windshields, num_of_entrances;
    float engine_capacity;


	string line, line2; //additional variables needed to store strings from files

	Vehicle *absPointer; //pointer to abstract object
	opening_and_checking_file("question_file.txt", &question_file);
	while(getline(question_file,line)) //reading the question file, each line in this file stands for one vehicle (and one question about this vehicle)
	{
		extract_function(line, &brand_from_question, &model_from_question, &question); //obtaining brand and model from question
		int if_present_in_magazine = 0; //this is inital setup, it changes to 1 if vehicle is present in magazine files

		for(int y=0; y < 3; y++) // variable y have value: 0 for cars, 1 for buses and 2 for bikes
		{
			opening_and_checking_file(mag_file_name[y], &magazine_file[y]);
			while(getline(magazine_file[y], line2))
			{
				extract_function2(line2, &brand, &model, &prod_year, &engine_capacity, &weight, &num_of_wheels, &num_of_windshields, &num_of_entrances); //obtaining informations from magazine
				if( (brand == brand_from_question) & (model == model_from_question) ) //checking if vehicle is present in magazine files
				{
					if_present_in_magazine = 1;
					if(y==0) // if object is a car
					{
						Car car(brand, model, prod_year, engine_capacity, weight, num_of_wheels, num_of_windshields, num_of_entrances);
						absPointer = &car;
						absPointer -> anserw_question_function(question, absPointer);
					}
					else if(y==1) // if object is a bus
					{
						Bus bus(brand, model, prod_year, engine_capacity, weight, num_of_wheels, num_of_windshields, num_of_entrances);
						absPointer = &bus;
						absPointer -> anserw_question_function(question, absPointer);
					}
					else if(y==2) // if object is a bike
					{
						Bike bike(brand, model, prod_year, engine_capacity, weight, num_of_wheels, num_of_windshields, num_of_entrances);
						absPointer = &bike;
						absPointer -> anserw_question_function(question, absPointer);
					}
					
				}
			}
			magazine_file[y].close();
		}

		if(if_present_in_magazine == 0) // it is program reaction when vehicle is not present in magazine files 
		{	
			cerr << brand_from_question << ' ' << model_from_question << " is not available." << endl;
		}
	}
	
	question_file.close();

}
