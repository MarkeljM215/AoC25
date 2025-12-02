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
    while (std::getline(input_file, line))
    {
    std::stringstream ss(line);
    std::vector<long long> seznam;
	std::string range;
    char del = ',';
    
            //funkcija ki splita pri , 
            while (getline(ss, range, del))
            {
  
                //funkcija ki splita pri -
                    
                    std::stringstream ss(range);
                    std::string start_vrst;
                    std::string start;
                    std::string konec;
                    char delit = '-';
                    long long temp = 0;
                    long long start_1;
                    long long konec_1;
                    long long razlika;
                    while (getline(ss, start_vrst, delit))
                    {
                        if (temp == 0)
                        {
                            start = start_vrst;
                            temp = 1;
                        }
                        else
                        {
                            konec = start_vrst;
                            temp = 0;
                        }
                        

                    }
                        //pretvormo funkciji v integer
                        start_1 = std::stoll(start);
                        konec_1 = std::stoll(konec);

                        razlika = konec_1 - start_1;
                        
                        for (long long i = 0; i < (razlika+1); i++)
                        {

                            std::stringstream ss;
                            std::string temp;

                            ss << start_1;
                            ss >> temp;
                            bool velikost = ((temp.size()) % 2);

                             

                            if(velikost == 0)
                            {
                            //std::cout << " " << velikost << " "; 
                            std::string rez_1 = temp.substr(0,((temp.size())/2)) ;
                            std::string rez_2 = temp.substr(((temp.size())/2),((temp.size())/2)) ;  
                            //std::cout << " " << rez_1 << " "<< rez_2<< std::endl; 

                            if(rez_1 == rez_2)
                                {
                                    
                                    seznam.push_back(start_1);
                                }
                            }
                            start_1 = start_1+1;

                        }




            }
            long long vsota = 0;
            std::cout << "tole je vsota" << std::endl;
            for (int i = 0; i < seznam.size(); i++)
            {
                vsota = vsota + seznam[i];
                
            }
                std::cout << vsota << " "<< std::endl;

        }




    
   
    return 0;
}