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
    int temp1 = 0;
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
                        //izvedem samo prvic
                        if (temp1 = 0)
                        {
                        seznam.push_back(start_1);
                        seznam.push_back(konec_1);
                            temp1 = 1;
                        }
                        
                        //preverjam opcije vedno moram gledat in konec in start
                        else
                        {
                        for (int i = 0; i < seznam.size(); i+=2)
                        {
                            if (seznam[i]< start_1 && seznam[i+1]>start_1)
                            {
                                //zacetek ranga je ze v rangu
                            }
                            else if ((seznam[i]> start_1 && seznam[i+1]> start_1))
                            {
                                //zamenjam prvo vrednost nov zacetek ranga
                                seznam[i]= start_1;
                                
                            }
                            else if (seznam[i]<start_1 && seznam[i+1]<konec_1)
                            {
                                //zamenjam konec ranga v novo vrednost
                                seznam[i+1] =konec_1;
                                
                            }
                            else if (seznam[i]> start_1 && seznam[i+1] > konec_1)
                            {
                                //dodam nov range v vector ki je manjsi od vsega
                                seznam.push_back(start_1);
                                seznam.push_back(konec_1);
                                break;
                            }
                            else if (seznam[i+1]<start_1)
                            {
                                seznam.push_back(start_1);
                                seznam.push_back(konec_1);
                                break;

                            }




                        }
                        }

                        
                        
                   


            }
            else if(line !="" ) 
            {
                
                stevilka = std::stoll(line);
                seznam_stevil.push_back(stevilka);
                
            }





    }
           //preverimo kakšen razpon vrednosti imamo trenutno
           //v primeru da manjsi zamenamo manjso
           //v primeru da vecji zamenamo vecjo
           //ali dodamo 

           //print seznam
        for (int i = 0; i < seznam.size(); i+=2)
        {
            std::cout<<seznam[i] << "-"<<seznam[i+1]<<std::endl;
        }
        


                
                
                


        




    
   input_file.close();
    return 0;
}