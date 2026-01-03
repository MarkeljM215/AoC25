#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

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
        std::vector<char> vrsta1;

        std::vector<std::vector<char>> vse;
        
    while (std::getline(input_file, line))
    {
        //vrsta_stevec = 0;    
        vrsta1 = {};
        
            for (int j = 0; j < line.size(); j++)
            {   

                vrsta1.push_back(line[j]);

            } 

    }

return 0;

}