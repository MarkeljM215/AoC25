#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main()
{   
    int ponovitev = 60;
    //veckrat izvedem main program da mi vsa intevarvala ki se prekrivajo podela
for (int p = 0; p < ponovitev; p++)
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
     int temp1 = 0;
    while (std::getline(input_file, line))
    {
    std::stringstream ss(line);

	std::string range;
    char del = '-';
    int temp= 0;

    std::string start;
    std::string konec;
    int ni_uspelo = 0;
    long long start_1;
    long long konec_1;
    long long razlika;
    long long stevilka;
    
    
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
                        if (temp1 == 0)
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
                            //opcija 1 zamenjam zacetek
                            if (start_1 <= seznam[i] && konec_1 <= seznam[i+1] && konec_1 >= seznam[i] )
                            {
                               seznam[i] = start_1; 
                               ni_uspelo = 1;
                               break;
                            }
                            //opcija 2 zamenjam konec
                            else if (start_1 >= seznam[i] && start_1 <= seznam[i+1]&& konec_1 >= seznam[i+1])
                            {
                                seznam[i+1] = konec_1;
                                ni_uspelo = 1;
                                break;
                            }
                            //opcija 3 že v razponu intervala
                            else if (start_1 >= seznam[i] && konec_1 <= seznam[i+1])
                            {
                                ni_uspelo = 1;
                                break;                                   
                            }

                            //opcija 6 povecam in zacetek in konec
                            else if (start_1 <= seznam[i]&& konec_1 >= seznam[i+1])
                            {
                                seznam[i] = start_1;
                                seznam[i+1] = konec_1;
                                ni_uspelo = 1;
                                break;
                            }

                        }
                        //če ne uspem popravit ranga ga dodam                      
                            if (ni_uspelo == 0)
                            {
                                seznam.push_back(start_1);
                                seznam.push_back(konec_1);
                                ni_uspelo = 0;
                                
                            }

                        }

                        
                             
                   


            }
            else if(line !="" ) 
            {
                
                stevilka = std::stoll(line);
                seznam_stevil.push_back(stevilka);
                
            }





    }

        
input_file.close();
//prepisem zmeraj samo zadnjic ne da lahko operiram
if (p != ponovitev -1)
{
        //Prepiši datoteko
    std::ofstream output("input.txt", std::ios::trunc); // trunc = izbriše vsebino
    for(int i = 0; i < seznam.size(); i =  i+2) 
    {
        output << seznam[i] <<"-"<< seznam[i+1] <<std::endl;
    }
    output.close();
                
}
else
//izračunam koliko je vseh števil v novo nastalih rangih
{
    long long rezultat = 0;
    long long vmesni_rezultat = 0;
    for (int s = 0; s < seznam.size(); s = s+2)
    {
     vmesni_rezultat = (seznam[s+1]-seznam[s]) +1;
     rezultat = vmesni_rezultat + rezultat;
    }
    std::cout <<"tole je rezultat "<< rezultat << std::endl;
}



                
                


        




    
   
}
    return 0;
}