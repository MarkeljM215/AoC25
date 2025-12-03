#include <iostream>
#include <fstream>
#include <string>
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
        std::string crka;
        std::vector<int> seznam;
        int temp;
        int vsota= 0;

    while (std::getline(input_file, line))
    {
        //spremenim vsako cifro iz string v integer
        seznam = {};
    for (int i = 0; i < line.size(); i++)
     {
        crka = line[i];

        temp = std::stoi(crka);
        
        seznam.push_back(temp);

        //poiscem max vectorja
     }
        int max1 = 0;
        int max1_prev = 0;
        int pozicija_max1= 0;
        int pozicija_max1_prev;
        int max2 = 0;
        int pozicija_max2;

        for (int i = 0; i < seznam.size(); i++)
        {
            if (seznam[i] > max1)
            {
                max1_prev = max1;
                max1 = seznam[i];
                pozicija_max1_prev = pozicija_max1;
                pozicija_max1 = i;
            }
            
        }
        //v primeru da imamo najvecjo cifro na zadnjem mestu zamenjamo z prejsno cifro
        if ((pozicija_max1+1) == seznam.size())
        {
            pozicija_max1 = pozicija_max1_prev;
            max1 = max1_prev;
        }
        


        //poiscem drugo max cifro

        for (int j = (pozicija_max1+1); j < seznam.size(); j++)
        {
            if (seznam[j] > max2)
            {
                max2 = seznam[j];
                pozicija_max2 = (j+pozicija_max1);
            } 

        }
        

        
        
        //std::cout<< "prva max cifra " << max1 << "druga max cifra " << max2 << std::endl;
        vsota = vsota +(max1*10+max2);
        
     
     
     

    }

std::cout<<"Tole je vsota"<<vsota<<std::endl;
input_file.close();
    return 0;
}