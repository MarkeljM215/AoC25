#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>

int main()
{
    //vnasanje datoteke
    std::ifstream input_file("input.txt");

    //preverimo ce input fileo bstaja
    if (!input_file)
    {
        std::cerr << "could not open file .\n";
    }

    //branje datoteke
        std::string line;
        std::vector<int> vrsta;
        std::vector<std::vector<int>> seznam = {};
        
        
    while (std::getline(input_file, line))
    {
        //splitanje stvari pri ,
    std::stringstream ss(line); 
	std::string range;
    char del = ',';
    int stevilka;
    //spraznem vektor
    vrsta = {};


        while (getline(ss, range, del))
            {
              stevilka= std::stoi(range);
                vrsta.push_back(stevilka); 
            }

            //shranim vector v matriko
            seznam.push_back(vrsta);


    }

//izračun ploscino vseh pravokotnikov in dobim najvecjo
long long ploscina = 0;
long long stranica_a = 0;
long long stranica_b = 0;
long long temp_ploscina = 0;
for (int i = 0; i < seznam.size(); i ++)
{
    int m = 0;
    for (int j = 1; j < seznam.size(); j++)
    {
        
        stranica_a = (std::abs (seznam[i][0] - seznam[j][0]))+1;
        stranica_b = (std::abs (seznam[i][1] - seznam[j][1]))+1;
        ploscina =stranica_a * stranica_b;
        
        if (ploscina > temp_ploscina )
        {
            temp_ploscina = ploscina;
            
        }
    }
}
std::cout << temp_ploscina << std::endl;

return 0;

}