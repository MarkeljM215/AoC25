#include <iostream>
#include <fstream>
#include <string>


int main()
{
    //vnasanje datoteke
    std::ifstream input_file("input.txt");

    //preverimo ce input fileo bstaja
    if (!input_file)
    {
        std::cerr << "Could not open file .\n";
    }

    //branje vrstico po vrstico lahko uporabljamo while ker imamo konec datoteke
    std::string line;

    int zac_stanje = 50;
    int rezultat = 0;
    int vmesno_stanje = 0;

    int temp = 0;

    int vrednost = 0;
    int dodatek = 0;
    int temp_zac_stanje = 50;

    while (std::getline(input_file, line))
    {
    //handlanje stevilke ka gre notr (ustvari nov string, od 1 člena do ceotne dolzine stringa)
        std::string rez = line.substr(1,(line.size()-1)) ;
        rezultat = std::stoi(rez);
  
        
        dodatek = 0;
        vmesno_stanje = zac_stanje;   
        if (line[0] == 'R')
            {

            for (int i = 0; i < rezultat; i++)
            {
                vmesno_stanje = vmesno_stanje + 1;
            
                if(vmesno_stanje == 100)
                {
                    vmesno_stanje = 0;
                    dodatek = dodatek +1;
                }
                else if(vmesno_stanje == 0)
                {
                    dodatek = dodatek +1;
                }
            }
       
        }
        else
        {
            for (int i = 0; i < rezultat; i++)
            {
                vmesno_stanje = vmesno_stanje - 1;
            
                if(vmesno_stanje == -100)
                {
                    vmesno_stanje = 0;
                    dodatek = dodatek +1;
                }
                else if(vmesno_stanje == 0)
                {
                    dodatek = dodatek +1;
                }
            }
        }
        
        
        temp = temp + dodatek;

        zac_stanje = vmesno_stanje;        


    }
    input_file.close();
    std::cout << temp <<std::endl;

    return 0;
}