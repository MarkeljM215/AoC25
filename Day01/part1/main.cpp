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



    //zacetek preracunavanja stanja
        if (line[0] == 'L')
        {

            zac_stanje = zac_stanje-rezultat; 
          
        }
        else
        {
            zac_stanje = rezultat + zac_stanje;

        }    
        
        

        
        zac_stanje = zac_stanje %1000;
        zac_stanje = zac_stanje %100;
        
        

        
        

        //stejem stevilo 0;
        if (zac_stanje == 0)
        {
           vrednost = vrednost + 1;   
        }
        


    }
    input_file.close();
    std::cout << vrednost <<std::endl;

    return 0;
}