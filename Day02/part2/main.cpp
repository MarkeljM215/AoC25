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
                    //definicja spremenljivk ki se uporabljajo
                    std::stringstream ss(range);
                    std::string start_vrst;
                    std::string start;
                    std::string konec;
                    std::string start_st = "0";
                    char delit = '-';
                    long long temp = 0;
                    long long start_1;
                    long long konec_1;
                    long long razlika;

                    //preberem obmocej v katerem so stevila
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
                        
                        
                    //stejemo od prvega stevila do koncnega stevila v rangu
                        for (long long i = 0; i < (razlika+1); i++)
                        {
                        //pretvorimo stevilo ki smo ga presteli v string za manipaluajo
                            std::stringstream ss;
                            std::string temp;

                            ss << start_1;
                            ss >> temp;
                            //5 mest enakih
                        if (temp.size()== 10 &&temp[0]==temp[5] && temp[1]== temp[6] && temp[2]==temp[7]&&temp[3] == temp[8] && temp[4]== temp[9])
                        {
                            seznam.push_back(start_1);
                        }
                         //4 mesta enake
                        else if (temp.size() == 8 && temp[0]==temp[4] && temp[1]== temp[5] && temp[2]==temp[6]&&temp[3] == temp[7])
                        {
                            seznam.push_back(start_1);
                        }
                        //3 mesta enake 2 opcije
                        else if (temp.size() == 9 && temp[0]==temp[3] && temp[1]== temp[4] && temp[2]==temp[5]&&temp[0] == temp[6]&& temp[1]== temp[7]&& temp[2]==temp[8])
                        {
                            seznam.push_back(start_1);
                        }
                        else if (temp.size() == 6 && temp[0]==temp[3] && temp[1]== temp[4] && temp[2]==temp[5])
                        {
                            seznam.push_back(start_1);
                        }
                        //2 mesta enaka 4 opcije
                        else if (temp.size() == 10 && temp[0]==temp[2] && temp[0]== temp[4] && temp[0]==temp[6]&&temp[0]==temp[8]&&
                            temp[1]==temp[3] && temp[1]== temp[5] && temp[1]==temp[7]&&temp[1]==temp[9])   
                        {
                            seznam.push_back(start_1);
                        }
                        else if (temp.size() == 8 && temp[0]==temp[2] && temp[0]== temp[4] && temp[0]==temp[6]&&
                            temp[1]==temp[3] && temp[1]== temp[5] && temp[1]==temp[7])
                        {
                            seznam.push_back(start_1);
                        }
                        else if (temp.size() == 6 && temp[0]==temp[2] && temp[0]== temp[4] &&
                            temp[1]==temp[3] && temp[1]== temp[5])
                        {
                            seznam.push_back(start_1);
                        }
                        else if (temp.size() == 4 && temp[0]==temp[2] &&
                            temp[1]==temp[3])
                        {
                            seznam.push_back(start_1);
                        }
                        //1 mest enak 9 opcij
                        else if (temp.size() == 10 && temp[0]==temp[1] && temp[0]== temp[2] && temp[0]==temp[3]&&temp[0]==temp[4]&&
                            temp[0]==temp[5] && temp[0]== temp[6] && temp[0]==temp[7]&&temp[0] == temp[8] &&temp[0]==temp[9])   
                        {
                            seznam.push_back(start_1);
                        }
                        else if (temp.size() == 9 && temp[0]==temp[1] && temp[0]== temp[2] && temp[0]==temp[3]&&temp[0]==temp[4]&&
                            temp[0]==temp[5] && temp[0]== temp[6] && temp[0]==temp[7]&&temp[0] == temp[8] )   
                        {
                            seznam.push_back(start_1);
                        }
                        else if (temp.size() == 8 && temp[0]==temp[1] && temp[0]== temp[2] && temp[0]==temp[3]&&temp[0]==temp[4]&&
                            temp[0]==temp[5] && temp[0]== temp[6] && temp[0]==temp[7])   
                        {
                            seznam.push_back(start_1);
                        }
                        else if (temp.size() == 7 && temp[0]==temp[1] && temp[0]== temp[2] && temp[0]==temp[3]&&temp[0]==temp[4]&&
                            temp[0]==temp[5] && temp[0]== temp[6])   
                        {
                            seznam.push_back(start_1);
                        }
                        else if (temp.size() == 6 && temp[0]==temp[1] && temp[0]== temp[2] && temp[0]==temp[3]&&temp[0]==temp[4]&&
                            temp[0]==temp[5])   
                        {
                            seznam.push_back(start_1);
                        }
                        else if (temp.size() == 5 && temp[0]==temp[1] && temp[0]== temp[2] && temp[0]==temp[3]&&temp[0]==temp[4])   
                        {
                            seznam.push_back(start_1);
                        }
                        else if (temp.size() == 4 && temp[0]==temp[1] && temp[0]== temp[2] && temp[0]==temp[3])   
                        {
                            seznam.push_back(start_1);
                        }
                        else if (temp.size() == 3 && temp[0]==temp[1] && temp[0]== temp[2] )   
                        {
                            seznam.push_back(start_1);
                        }
                        else if (temp.size() == 2 && temp[0]==temp[1] )   
                        {
                            seznam.push_back(start_1);
                        }
                        //std::cout << start_st << std::endl;
                        

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
    input_file.close();
    return 0;
}