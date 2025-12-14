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
            std::vector<unsigned long long> seznam;
            std::vector<unsigned long long>  seznam_stevil;
    while (std::getline(input_file, line))
    {
    std::stringstream ss(line);

	std::string range;
    char del = '-';
    int temp= 0;
    std::string start;
    std::string konec;
    unsigned long long start_1;
    unsigned long long konec_1;
    unsigned long long razlika;
    unsigned long long stevilka;
    
    
       //preverim ce linija vsebuje vrstico
        bool linija = false;
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i]== '-')
            {
                linija = true;
            }
                     
        }
        
            //funkcija ki splita pri - 

            if (linija == true ) 
            {
            for (int i = 0; i < 2; i++)
             {
                 getline(ss, range, del);             
                    
                        if (temp == 0)
                        {
                            start = range;
                            temp = 1;
                        }
                        else
                        {
                            konec = range;
                            temp = 0;
                        }
                    }                   
                        //pretvormo funkciji v integer
                        start_1 = std::stoll(start);
                        konec_1 = std::stoll(konec);

                        razlika = konec_1 - start_1;
                        //shranim prebrani stevilki v seznam
                        seznam.push_back(start_1);
                        seznam.push_back(konec_1);

                   


            }
            else if(line !="" ) 
            {
                
                stevilka = std::stoll(line);
                seznam_stevil.push_back(stevilka);
                
            }





    }
            //preverba ali je stevilo na seznamu
            unsigned long long vsota = 0;
            std::cout << "tole je vsota" << std::endl;
            //vzamem prvo stevilo na seznamu stevil in jo primerjam z vsemi stevili na seznamu
            for (int i = 0; i < seznam_stevil.size(); i++)
            {
                for (int j = 0; j < seznam.size(); j +=2)
                {
                    //stevilka manjsa od max in vecja od min
                    if (seznam_stevil[i] >= seznam[j] && seznam_stevil[i] <= seznam[j+1])
                    {
                        vsota = vsota + 1;
                        break;
                    }
                    
                }
                
                
                
            }
                std::cout <<vsota <<std::endl;

        




    
   input_file.close();
    return 0;
}