#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#define random(min,max) (min + rand() % (max - min + 1))
using namespace std;

int vehicleID = 0;
int parkingID = 0;
int ticketParkingID = 0;
string lastPlate = "";	