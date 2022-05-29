#include <iostream>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <cfloat>
#include <limits>
class Robot
{  
    std::string robot_name , variable ;
    unsigned int velocity;
    int battery_charge_status , temperature ,enum_change, stop;
    enum status{ Exploring , Sampling , Returning , Idle};
    status stt ;
    
    public:
    Robot() { robot_name = "noname" , variable = "cos" , battery_charge_status = 1 , temperature = 1 , velocity = 0 , stt = Idle ;}
    void editor()
    {
        while( variable != "end" )
        {
            int liczba = 0 ;
            void wait();
            //system("clear");
            std::cout << "Which variable to check?" << std::endl;
            std::cout << "select from : name , battery ,  temperature , velocity , status , end" << std::endl;
            std::cin >> variable; 
            
            if( variable == "name" )                    
            {
                std::cout << robot_name << std::endl;
                std::cout <<"edit variable press 1      check number of bytes press 2   :";
                std::cin >>  liczba;
                switch( liczba )
                    {
                    case 1: std::cin >> robot_name ; break;
                    case 2: std::cout << sizeof(robot_name) << std::endl ;
                    std::cin.ignore(); break;
                    }
            }
            else if(variable == "battery")
            {
                std::cout << battery_charge_status<< " %" << std::endl; 
                std::cout <<"edit variable press 1  check number of bytes press 2  maximum and minimum battery status press 3 :";
                std::cin >>  liczba;
                switch( liczba )
                    {
                    case 1:
                        std::cin >> battery_charge_status ;
                         while( (battery_charge_status< 0) || (battery_charge_status> 100))
                            {
                                if(battery_charge_status< 0)
                                    {
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                                    std::cout << "try again minimum = 0 "  << std::endl ;
                                    std::cin >> battery_charge_status ;    
                                    }
                                else if(battery_charge_status> 100)    
                                    {
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                                    std::cout << "try again minimum = 100 " << std::endl ;
                                    std::cin >> battery_charge_status  ;   
                                    }
                            }
                        break;
                    case 2:
                        std::cout << sizeof(battery_charge_status) << std::endl ;
                         break;
                    case 3:
                        std::cout << "maximum battery status = 0% maximum battery status = 100% "<< std::endl ;
                         break;    
                    }
            }
            else if(variable == "temperature")     
            {
                std::cout << temperature << "  Celsius degrees " << std::endl; 
                std::cout <<"edit variable press 1   check number of bytes press 2 " << std::endl;
                std::cout <<"maximum and minimum temperature status press 3   Converting the temperature value to its absolute value 4 :"<< std::endl;
                std::cout <<"temperature in Kelvin degrees press  5: "<< std::endl;
                std::cin >>  liczba;
                switch( liczba )
                    {
                    case 1: std::cin >> temperature ; 
                    while( (temperature< -2147483646) || (temperature> 2147483646))
                            {
                                if(temperature< -2147483646)
                                    {
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                                    std::cout << "try again minimum = -2147483646"  << std::endl ;
                                    std::cin >> temperature;    
                                    }
                                else if(temperature> 2147483646)    
                                    {
                                    std::cin.clear();
                                    std::cin.ignore(std::numeric_limits<int>::max(), '\n');
                                    std::cout << "try again minimum =  2147483646" << std::endl ;
                                    std::cin >> temperature ;   
                                    }
                            }
                    
                     break;
                    case 2: std::cout << sizeof(temperature) << std::endl ;   break;
                    case 3: std::cout << "minimum temperature = " << INT_MIN << " maximum temperature = " << INT_MAX << std::endl ;  break; 
                    case 4: std::cout << abs(temperature) << std::endl ;  break;
                    case 5: std::cout << (temperature + 273.15)<< " Kelvin degrees" << std::endl ;  break;
                    }
            }
            else if(variable == "velocity")           
            {
                std::cout << velocity << " km/h " << std::endl; 
                std::cout <<"edit variable press 1  check number of bytes press 2  :"<< std::endl;
                std::cout <<"maximum and minimum velocity status press 3  velocity in scientific notation press 4 : ";
                std::cin >>  liczba ;
                switch( liczba )
                    {
                    case 1: std::cin >> velocity ;  break ;
                    case 2: std::cout << sizeof(velocity) << std::endl ;  break ;
                    case 3: std::cout << "minimum velocity = 0  miximum velocity = "<< UINT_MAX<< std::endl ;  break ;
                    case 4: std::cout << std::scientific << static_cast<double>(velocity) << std::endl ;  break ;
                    }
            }
            else if(variable == "status")           
            {
                switch (stt)
                    {
                    case 0: std::cout << "Exploring" << std::endl ;  break ; 
                    case 1: std::cout << "Sampling"  << std::endl ;  break ; 
                    case 2: std::cout << "Returning" << std::endl ;  break ; 
                    case 3: std::cout << "Idle"      << std::endl ;  break ;
                    }                  
                std::cout <<"edit variable press 1      check number of bytes press 2   ";
                std::cin >>  liczba ;
                switch( liczba )
                    {
                    case 1:
                        std::cout <<"Exploring press :1  Sampling press :2  Returning press :3   Idle press :4 " ;
                        std::cin >> enum_change ;
                        switch( enum_change )
                            {
                            case 1:  stt = Exploring ;  break ;
                            case 2:  stt = Sampling ;   break ;
                            case 3:  stt = Returning ;  break ;
                            case 4:  stt = Idle ;       break ;
                            }
                    break;    
                    case 2: std::cout << sizeof(stt) << std::endl ;  break;
                    }    
            }
            else if(variable == "end") {}
            else  {std::cout << "invalid parameter"<< std::endl ;}   
        }        
    }
};
int main()
{
    Robot franek;
    franek.editor();    
    return 0;
}

