#include <iostream>
#include <string>
#include <vector>

using namespace std;

//////////////////////////////////////////////////////
/////// Virtual Core Class - Vehicle
/////////////////////////////////////

class Vehicle
{

protected:
    
    string brand, model;
    int prod_year;
    float engine_capacity;
    int weight, num_of_wheels, num_of_windshield, num_of_entrances;


public:
    virtual void display_prod_year(Vehicle *vP);
    virtual void display_engine_capacity(Vehicle *vP);
    virtual void display_weight(Vehicle *vP);
    virtual void display_num_of_wheels(Vehicle *vP);
    virtual void display_num_of_windshields()=0;
    virtual void display_num_of_entrances()=0;
    virtual void anserw_question_function(string question, Vehicle *vP);
};

//////////////////////////////////////////////////////
/////// Concrete classes
/////////////////////////////////////


/////////////////////////////////////
/////// Class Car

class Car :public Vehicle
{
    //int num_of_entrances;

public:
    Car(string = "Ford", string = "Probe", int = 1992, float = 2.2, int = 1350, int = 4, int = 6, int = 3);
    virtual void display_num_of_windshields();
    virtual void display_num_of_entrances();
};


//////////////////////////////////////
/////// Class Bus

class Bus :public Vehicle
{

    //int num_of_entrances;

public:
    Bus(string = "Mercedes", string = "Sprinter", int = 2009, float = 2.2, int = 2000, int = 4, int = 10, int = 3);
    virtual void display_num_of_windshields();
    virtual void display_num_of_entrances();
};


//////////////////////////////////////
/////// Class Bike

class Bike :public Vehicle
{
public:
    Bike(string = "Heckler", string = "PROMO ALOY", int = 2020, float = 0, int = 17, int = 2, int = 0, int =0);
    virtual void display_num_of_windshields();
    virtual void display_num_of_entrances();
};


//////////////////////////////////////////////////////
/////// Ordinary functions, not classes methods
/////////////////////////////////////


void opening_and_checking_file(string file_name, fstream *filePointer);
void extract_function(string line, string *brandP, string *modelP, string *questionP); //obtaining brand and model from question
string char_vector_to_string(vector <char> vec);
void extract_function2(string line, string *brandP, string *modelP, int *prod_yearP, float *eng_capacityP, int *weightP, int *num_of_wheelsP, int *num_of_windshieldsP, int *num_of_entrancesP); //obtaining informations from magazine