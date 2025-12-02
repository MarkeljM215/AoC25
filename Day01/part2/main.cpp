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
    

    while (std::getline(input_file, line))
    {
    //handlanje stevilke ka gre notr (ustvari nov string, od 1 člena do ceotne dolzine stringa)
        std::string rez = line.substr(1,(line.size()-1)) ;
        rezultat = std::stoi(rez);
  
        //stevec kok je nicel
        dodatek = 0;
        vmesno_stanje = zac_stanje;   
        if (line[0] == 'R')
            {
            //vrednost povecujem za 1
            for (int i = 0; i < rezultat; i++)
            {
                vmesno_stanje = vmesno_stanje + 1;
                //vrnem nazaj na zacetek de ne preseze stevicnie
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
        {   //vrednost zmanjsujem za 1
            for (int i = 0; i < rezultat; i++)
            {
                vmesno_stanje = vmesno_stanje - 1;
                //vrnem nazaj na zacetek de ne preseze
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
        
       //kocni stevec nicel 
        temp = temp + dodatek;

        zac_stanje = vmesno_stanje;        


    }
    input_file.close();
    std::cout << temp <<std::endl;

    return 0;
}