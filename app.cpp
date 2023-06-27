#include <fstream>
#include <iostream>
#include <sstream>


bool checkLat(double lat) {
	if ((lat >= 50) && (lat <= 80)) {
		return true;
	}
	else return false;
}

bool checkLon(double lon) {

	if ((lon >= 20) && (lon <= 45)) {
		return true;
	}
	else return false;
}

int main() 
{

	bool noMatch = true;

	std::ifstream ifile("coordinates.txt", std::ios::in);
	if (ifile.is_open()) {
		while (ifile) {
			std::string line;
			std::getline(ifile, line);			
			std::stringstream ss;
			ss << line;			
			
			double lon, lat = 0;
			ss.ignore(1);
			ss >> lat;			
			
			ss.ignore(1);
			ss >> lon;
			
			if (checkLat(lat) && (checkLon(lon))) {
				std::cout << lat << ", " << lon << std::endl;
				noMatch = false;
			}
		}
		if (noMatch) {
			std::cout << "No coordinates match";
		}
	}
}