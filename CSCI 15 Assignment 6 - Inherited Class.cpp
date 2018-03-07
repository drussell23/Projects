/**
    Derek J. Russell
    Professor Desmond Chun
    CSCI 15 - Assignment 6
    Due April 13th, 2016
    Inherited Class
    April 7th, 2016
**/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <string>
#include <memory>

using namespace std;

class Vehicles // Base Class
{
    protected:
                string VehicleName_Type;
                intmax_t NumberOfPassengers;
                intmax_t NumberOfWheels_OnTheVehicle;
                double MaximumMiles_PerHour_Speed;
    public:
            Vehicles() /// Normal Constructor
            {
                VehicleName_Type = "Motorcycle";
                NumberOfPassengers = 2;
                NumberOfWheels_OnTheVehicle = 2;
                MaximumMiles_PerHour_Speed = 100.0;
            }
            void Display_All_Vehicles()
            {
                cout << VehicleName_Type << " Carries " << NumberOfPassengers << " Passengers " << "(Including the driver)" << endl;
                cout << endl;
                cout << VehicleName_Type << " Has " << NumberOfWheels_OnTheVehicle << " Wheels and can travel a Maximum of " << MaximumMiles_PerHour_Speed << " mph" << endl;
            }
            void SetALL(string VehicleType_NAME, intmax_t PASSENGERS, intmax_t WHEELS, double MAXIMUM_SPEED)
            {
                VehicleName_Type = VehicleType_NAME;
                NumberOfPassengers = PASSENGERS;
                NumberOfWheels_OnTheVehicle = WHEELS;
                MaximumMiles_PerHour_Speed = MAXIMUM_SPEED;
            }
            void SET_VehicleName(string VEHICLE_NAME)
            {
                VehicleName_Type = VEHICLE_NAME;
            }
            void SET_NumberOfPassengers(intmax_t NUMBER_OF_PASSENGERS)
            {
                NumberOfPassengers = NUMBER_OF_PASSENGERS;
            }
            void SET_NumberOfWheels(intmax_t NUMBER_OF_WHEELS)
            {
                NumberOfWheels_OnTheVehicle = NUMBER_OF_WHEELS;
            }
            void SET_MaximumMiles_PerHour_Speed(double MAXIMUM_SPEED)
            {
                MaximumMiles_PerHour_Speed = MAXIMUM_SPEED;
            }
            string Get_VEHICLE_NAME() const
            {
                return VehicleName_Type;
            }
            intmax_t Get_NUMBER_OF_PASSENGERS() const
            {
                return NumberOfPassengers;
            }
            intmax_t Get_NUMBER_OF_WHEELS__ON_THE_VEHICLE() const
            {
                return NumberOfWheels_OnTheVehicle;
            }
            double Get_MAXIMUM_MILES_PER_HOUR_SPEED() const
            {
                return MaximumMiles_PerHour_Speed;
            }
};
class Trucks : public Vehicles
{
                /**
                    - Trucks is the Derived Class ("Child")
                    - Vehicle is the Based Class ("Parent")
                **/
    private:
            float LOAD;
            float WEIGHT;

    public:
            void Load_Weight_SetALL(double load_set, double weight_set)
            {
                LOAD = load_set;
                WEIGHT = weight_set;
            }
            void Display_All_Trucks()
            {
                cout << VehicleName_Type << " weighs " << WEIGHT << " pounds and carries a Load of " << LOAD << " pounds " << endl;
                cout << endl;
                cout << VehicleName_Type << " has " << NumberOfWheels_OnTheVehicle << " Wheels and carries " << NumberOfPassengers << " passengers " << endl;
                cout << endl;
                cout << VehicleName_Type << " has a maximum speed of " << MaximumMiles_PerHour_Speed << " mph" << endl;
            }
            void Set_LOAD_OF_TRUCK(float Load_Variable)
            {
                LOAD = Load_Variable;
            }
            void Set_WEIGHT_OF_TRUCK(float Weight_Variable)
            {
                WEIGHT = Weight_Variable;
            }
            double Get_LoadOfVehicle() const
            {
                return LOAD;
            }
            double Get_WeightOfVehicle() const
            {
                return WEIGHT;
            }
            Trucks() // Default Constructor
            {
                LOAD = 0.0;
                WEIGHT = 2000;
            }

};
/// Function Prototypes
void DisplayTitle();

void DisplayTitle()
{
    time_t CurrentTime;
    struct tm *localTime;

    time(&CurrentTime); // This gets the current time.
    localTime = localtime(&CurrentTime); // This converts the time to local time.

    intmax_t Day   = localTime -> tm_mday;
    intmax_t Month = localTime -> tm_mon + 1;
    intmax_t Year  = localTime -> tm_year + 1900;
    intmax_t Hour  = localTime -> tm_hour;
    intmax_t Min   = localTime -> tm_min;
    intmax_t Sec   = localTime -> tm_sec;

    cout << "Name: Derek J. Russell\t\t\t\t\t\t" << "Date: " << Month << "/" << Day << "/" << Year << endl;
    cout << "\n\n";
    cout << setw(55) << "\t\1 CSCI 15 Assignment 6 - Inherited Class \2" << endl;
}
int main()
{
    bool again = true;
    int choice;
    const int max = 5;
    const int Truck_MAX = 2;

    Vehicles VEHICLES_1, VEHICLES_2, VEHICLES_3, VEHICLES_4;
    Trucks TRUCKS_1, TRUCKS_2;

    // Create 4 class members.
    VEHICLES_1.SetALL("Sedan", 5, 4, 80.0);
    VEHICLES_2.SetALL("Bicycle", 1, 2, 30.0);
    VEHICLES_3.SetALL("Unicycle", 1, 1, 15.0);
    VEHICLES_4.SetALL("Row Boat", 3, 0, 10.0);

    // Initialize two "Trucks" members.
    TRUCKS_1.SetALL("Pickup Truck", 2, 4, 65.0);
    TRUCKS_2.SetALL("Van", 2, 6, 70.0);

    Vehicles vehicles_ARRAY[max] = {VEHICLES_1, VEHICLES_2, VEHICLES_3, VEHICLES_4};
    Trucks trucks_ARRAY[Truck_MAX] = {TRUCKS_1, TRUCKS_2};

    int Input_INDEX = -1;

    intmax_t CHANGE_CHOICE_OPTION_VEHCILCES;
    string change_VehicleName_Type;
    int change_NumberOfPassengers;
    int change_NumberOfWheels_OnTheVehicle;
    double change_MaximumMiles_PerHour_Speed;
/*******************************************************/
    string change_TruckName;
    int change_Passengers_Truck;
    int change_Wheels_Truck;
    double change_MPH_Truck;
    float change_LOAD;
    float change_Weight;
    intmax_t CHANGE_CHOICE_OPTION_TRUCKS;


    while(again)
    {
        DisplayTitle();
        cout << "\n\n";
        cout << "(1.) - Display All Vehicles" << endl;
        cout << endl;
        cout << "(2.) - Change Values of a Class Member" << endl;
        cout << endl;
        cout << "(3.) - Find a Vehicle Class Member" << endl;
        cout << endl;
        cout << "(4.) - Display Truck Values" << endl;
        cout << endl;
        cout << "(5.) - Change Truck Members" << endl;
        cout << endl;
        cout << "(6.) - Quit" << endl;
        cout << "\n\n";
        cout << "Enter an Option (1 - 6): ";
        cin >> choice;

        choice = abs(choice);

        cout << "\n\n";
        system("PAUSE");
        system("CLS");

        switch (choice)
        {
            case 1:
                    cout << "1 - Display All Vehicles:" << endl;
                    cout << "\n\n";
                    for(int count = 0; count < max; count++)
                    {
                        cout << "Index #" << count;
                        cout << "\n\n";
                        vehicles_ARRAY[count].Display_All_Vehicles();
                        cout << "\n\n";
                        cout << "===============================================================================" << endl;
                    }
                    system("PAUSE");
                    system("CLS");

                    break;

            case 2:
                    cout << "2 - Change Values of  a Class Member" << endl;
                    cout << "\n\n";

                    cout << "Enter an Index (0 to " << max - 1 << "): ";
                    cin >> Input_INDEX;
                    cout << "\n\n";

                    while(Input_INDEX < 0 || Input_INDEX > max - 1)
                    {
                        cout << "Enter an Index (0 to " << max - 1 << "): ";
                        cin >> Input_INDEX;
                        cout << "\n\n";
                    }
                    vehicles_ARRAY[Input_INDEX].Display_All_Vehicles();
                    cout << "\n\n";
                    cout << "================================================================================" << endl;
                    cout << "\n\n";
                    cout << "Change a Vehicle class member's values:" << endl;
                    cout << "\n\n";
                    cout << "1 - Change the Vehicle Name." << endl;
                    cout << endl;
                    cout << "2 - Change the Number of Passengers." << endl;
                    cout << endl;
                    cout << "3 - Change the Number of Wheels on the Vehicle." << endl;
                    cout << endl;
                    cout << "4 - Change the Maximum Miles (Per Hour)." << endl;
                    cout << endl;
                    cout << "5 - Cancel." << endl;
                    cout << "\n\n";
                    cout << "Enter your choice (1 to 5): ";
                    cin >> CHANGE_CHOICE_OPTION_VEHCILCES;

                    CHANGE_CHOICE_OPTION_VEHCILCES = abs(CHANGE_CHOICE_OPTION_VEHCILCES);

                    cout << "\n\n";
                    system("PAUSE");
                    system("CLS");

                    switch (CHANGE_CHOICE_OPTION_VEHCILCES)
                    {
                        case 1:
                                cout << "1 - Change the Truck Name: " << endl;
                                cout << "\n\n";

                                cin.ignore();

                                cout << "Enter the name of the Vehicle: ";
                                getline(cin, change_VehicleName_Type);
                                vehicles_ARRAY[Input_INDEX].SET_VehicleName(change_VehicleName_Type);
                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                break;

                        case 2:
                                cout << "2 - Change the Number of Passengers:" << endl;
                                cout << "\n\n";

                                cout << "Enter the Number of Passenger: ";
                                cin >> change_NumberOfPassengers;
                                vehicles_ARRAY[Input_INDEX].SET_NumberOfPassengers(change_NumberOfPassengers);
                                cout << endl;

                                while(change_NumberOfPassengers < 0)
                                {
                                    cout << "Enter the Number of Passenger: ";
                                    cin >> change_NumberOfPassengers;
                                    vehicles_ARRAY[Input_INDEX].SET_NumberOfPassengers(change_NumberOfPassengers);
                                    cout << endl;
                                }

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                break;

                        case 3:
                                cout << "3 - Change the Number of Wheels on the Vehicle:" << endl;
                                cout << "\n\n";
                                cout << "Enter the Number of Wheels: ";
                                cin >> change_NumberOfWheels_OnTheVehicle;
                                vehicles_ARRAY[Input_INDEX].SET_NumberOfWheels(change_NumberOfWheels_OnTheVehicle);
                                cout << endl;

                                while(change_NumberOfWheels_OnTheVehicle < 0)
                                {
                                    cout << "Enter the Number of Wheels: ";
                                    cin >> change_NumberOfWheels_OnTheVehicle;
                                    vehicles_ARRAY[Input_INDEX].SET_NumberOfWheels(change_NumberOfWheels_OnTheVehicle);
                                    cout << endl;
                                }

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                break;

                        case 4:
                                cout << "4 - Change the Maximum Miles (Per Hour)" << endl;
                                cout << "\n\n";
                                cout << "Enter the Maximize Speed (Miles Per Hour): ";
                                cin >> change_MaximumMiles_PerHour_Speed;
                                vehicles_ARRAY[Input_INDEX].SET_MaximumMiles_PerHour_Speed(change_MaximumMiles_PerHour_Speed);
                                cout << endl;

                                while(change_MaximumMiles_PerHour_Speed < 0)
                                {
                                    cout << "Enter the Maximize Speed (Miles Per Hour): ";
                                    cin >> change_MaximumMiles_PerHour_Speed;
                                    vehicles_ARRAY[Input_INDEX].SET_MaximumMiles_PerHour_Speed(change_MaximumMiles_PerHour_Speed);
                                    cout << endl;
                                }

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                break;

                        case 5:
                                break;

                        default:
                                cout << "Sorry! Please select an option on the MENU from (1 to 5)." << endl;
                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");
                    }
                    break;

            case 3:

                   cout << "3 - Find a Vehicle Class Member:" << endl;
                   cout << "\n\n";

                    int count;
                    count = -1;

                    while(count < 0 || count > max - 1)
                    {
                        cout << "Enter an Index (0 to " << max - 1 << "): ";
                        cin >> count;
                        cout << "\n\n";
                    }
                    vehicles_ARRAY[count].Display_All_Vehicles();
                    cout << "\n\n";
                    system("PAUSE");
                    system("CLS");

                    break;


            case 4:
                   cout << "4 - Display Truck Values" << endl;
                   cout << "\n\n";

                    for(int count = 0; count < Truck_MAX; count++)
                    {
                        cout << "Index #" << count;
                        cout << "\n\n";
                        trucks_ARRAY[count].Display_All_Trucks();
                        cout << "\n\n";
                    }
                    system("PAUSE");
                    system("CLS");

                    break;

            case 5:
                    cout << "5 - Change Truck Members" << endl;
                    cout << "\n\n";
                    cout << "1 - Change " << trucks_ARRAY[0].Get_VEHICLE_NAME() << " Values." << endl;
                    cout << endl;
                    cout << "2 - Change " << trucks_ARRAY[1].Get_VEHICLE_NAME() << " Values." << endl;
                    cout << endl;
                    cout << "3 - Cancel" << endl;
                    cout << "\n\n";
                    cout << "Enter your choice (1 to 3): ";
                    cin >> CHANGE_CHOICE_OPTION_TRUCKS;

                    CHANGE_CHOICE_OPTION_TRUCKS = abs(CHANGE_CHOICE_OPTION_TRUCKS);

                    cout << "\n\n";
                    system("PAUSE");
                    system("CLS");

                    switch (CHANGE_CHOICE_OPTION_TRUCKS)
                    {
                        case 1:
                                cout << "1 - Change " << trucks_ARRAY[0].Get_VEHICLE_NAME() << " Values" << endl;
                                cout << "\n\n";

                                cin.ignore();

                                cout << "(1 of 6) - Enter the name of the " << trucks_ARRAY[0].Get_VEHICLE_NAME() << ": ";
                                getline(cin, change_TruckName);
                                trucks_ARRAY[0].SET_VehicleName(change_TruckName);
                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                cout << "(2 of 6) - Set the number of passengers of the " << trucks_ARRAY[0].Get_VEHICLE_NAME() << ": ";
                                cin >> change_Passengers_Truck;
                                trucks_ARRAY[0].SET_NumberOfPassengers(change_Passengers_Truck);
                                cout << endl;

                                while(change_Passengers_Truck < 0)
                                {
                                     cout << "(2 of 6) - Set the number of passengers of the " << trucks_ARRAY[0].Get_VEHICLE_NAME() << ": ";
                                     cin >> change_Passengers_Truck;
                                     trucks_ARRAY[0].SET_NumberOfPassengers(change_Passengers_Truck);
                                     cout << endl;
                                }

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                cout << "(3 of 6) - Set the Weight of the " << trucks_ARRAY[0].Get_VEHICLE_NAME() << ": ";
                                cin >> change_Weight;
                                trucks_ARRAY[0].Set_WEIGHT_OF_TRUCK(change_Weight);
                                cout << endl;

                                while(change_Weight < 0)
                                {
                                    cout << "(3 of 6) - Set the Weight of the " << trucks_ARRAY[0].Get_VEHICLE_NAME() << ": ";
                                    cin >> change_Weight;
                                    trucks_ARRAY[0].Set_WEIGHT_OF_TRUCK(change_Weight);
                                    cout << endl;
                                }

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                cout << "(4 of 6) - Set the Maximum Load of the " << trucks_ARRAY[0].Get_VEHICLE_NAME() << ": ";
                                cin >> change_LOAD;
                                trucks_ARRAY[0].Set_LOAD_OF_TRUCK(change_LOAD);
                                cout << endl;

                                while(change_LOAD < 0)
                                {
                                    cout << "(4 of 6) - Set the Maximum Load of the " << trucks_ARRAY[0].Get_VEHICLE_NAME() << ": ";
                                    cin >> change_LOAD;
                                    trucks_ARRAY[0].Set_LOAD_OF_TRUCK(change_LOAD);
                                    cout << endl;
                                }

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                cout << "(5 of 6) - Set the Number of Wheels on the " << trucks_ARRAY[0].Get_VEHICLE_NAME() << ": ";
                                cin >> change_Wheels_Truck;
                                trucks_ARRAY[0].SET_NumberOfWheels(change_Wheels_Truck);
                                cout << endl;

                                while(change_Wheels_Truck < 0)
                                {
                                    cout << "(5 of 6) - Set the Number of Wheels on the " << trucks_ARRAY[0].Get_VEHICLE_NAME() << ": ";
                                    cin >> change_Wheels_Truck;
                                    trucks_ARRAY[0].SET_NumberOfWheels(change_Wheels_Truck);
                                    cout << endl;
                                }

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                cout << "(6 of 6) - Set the Maximize Speed of the " << trucks_ARRAY[0].Get_VEHICLE_NAME() << ": ";
                                cin >> change_MPH_Truck;
                                trucks_ARRAY[0].SET_MaximumMiles_PerHour_Speed(change_MPH_Truck);
                                cout << endl;

                                while(change_MPH_Truck < 0)
                                {
                                    cout << "(6 of 6) - Set the Maximize Speed of the "
                                         << trucks_ARRAY[0].Get_VEHICLE_NAME() << "mph" << ": ";
                                    cin >> change_MPH_Truck;
                                    trucks_ARRAY[0].SET_MaximumMiles_PerHour_Speed(change_MPH_Truck);
                                    cout << endl;
                                }

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                break;

                        case 2:
                                cout << "2 - Change " << trucks_ARRAY[1].Get_VEHICLE_NAME() << " Values" << endl;
                                cout << "\n\n";

                                cin.ignore();

                                cout << "(1 of 6) - Enter the name of the " << trucks_ARRAY[1].Get_VEHICLE_NAME() << ": ";
                                getline(cin, change_TruckName);
                                trucks_ARRAY[1].SET_VehicleName(change_TruckName);
                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                cout << "(2 of 6) - Set the number of passengers of the " << trucks_ARRAY[1].Get_VEHICLE_NAME() << ": ";
                                cin >> change_Passengers_Truck;
                                trucks_ARRAY[1].SET_NumberOfPassengers(change_Passengers_Truck);
                                cout << endl;

                                while(change_Passengers_Truck < 0)
                                {
                                     cout << "(2 of 6) - Set the number of passengers of the " << trucks_ARRAY[1].Get_VEHICLE_NAME() << ": ";
                                     cin >> change_Passengers_Truck;
                                     trucks_ARRAY[1].SET_NumberOfPassengers(change_Passengers_Truck);
                                     cout << endl;
                                }

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                cout << "(3 of 6) - Set the Weight of the " << trucks_ARRAY[1].Get_VEHICLE_NAME() << ": ";
                                cin >> change_Weight;
                                trucks_ARRAY[1].Set_WEIGHT_OF_TRUCK(change_Weight);
                                cout << endl;

                                while(change_Weight < 0)
                                {
                                    cout << "(3 of 6) - Set the Weight of the " << trucks_ARRAY[1].Get_VEHICLE_NAME() << ": ";
                                    cin >> change_Weight;
                                    trucks_ARRAY[1].Set_WEIGHT_OF_TRUCK(change_Weight);
                                    cout << endl;
                                }

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                cout << "(4 of 6) - Set the Maximum Load of the " << trucks_ARRAY[1].Get_VEHICLE_NAME() << ": ";
                                cin >> change_LOAD;
                                trucks_ARRAY[1].Set_LOAD_OF_TRUCK(change_LOAD);
                                cout << endl;

                                while(change_LOAD < 0)
                                {
                                    cout << "(4 of 6) - Set the Maximum Load of the " << trucks_ARRAY[1].Get_VEHICLE_NAME() << ": ";
                                    cin >> change_LOAD;
                                    trucks_ARRAY[1].Set_LOAD_OF_TRUCK(change_LOAD);
                                    cout << endl;
                                }

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                cout << "(5 of 6) - Set the Number of Wheels on the " << trucks_ARRAY[1].Get_VEHICLE_NAME() << ": ";
                                cin >> change_Wheels_Truck;
                                trucks_ARRAY[1].SET_NumberOfWheels(change_Wheels_Truck);
                                cout << endl;

                                while(change_Wheels_Truck < 0)
                                {
                                    cout << "(5 of 6) - Set the Number of Wheels on the " << trucks_ARRAY[1].Get_VEHICLE_NAME() << ": ";
                                    cin >> change_Wheels_Truck;
                                    trucks_ARRAY[1].SET_NumberOfWheels(change_Wheels_Truck);
                                    cout << endl;
                                }

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                cout << "(6 of 6) - Set the Maximize Speed of the " << trucks_ARRAY[1].Get_VEHICLE_NAME() << ": ";
                                cin >> change_MPH_Truck;
                                trucks_ARRAY[1].SET_MaximumMiles_PerHour_Speed(change_MPH_Truck);
                                cout << endl;

                                while(change_MPH_Truck < 0)
                                {
                                    cout << "(6 of 6) - Set the Maximize Speed of the " << trucks_ARRAY[1].Get_VEHICLE_NAME() << ": ";
                                    cin >> change_MPH_Truck;
                                    trucks_ARRAY[1].SET_MaximumMiles_PerHour_Speed(change_MPH_Truck);
                                    cout << endl;
                                }

                                cout << "\n\n";
                                system("PAUSE");
                                system("CLS");

                                break;

                        case 3:

                                break;

                        default:
                                 cout << "Sorry! Please select an option on the MENU from (1 to 3)." << endl;
                                 cout << "\n\n";
                                 system("PAUSE");
                                 system("CLS");
                    }

                    break;

            case 6:
                    cout << "6 - Quit:" << endl;
                    cout << "\n\n\n";

                    again = false;
                    cout << "\1 Good Bye!!! \2" << endl;

                    break;

            default:
                     cout << "Sorry! Please select an option on the MENU from (1 to 6)." << endl;
                     cout << "\n\n";
                     system("PAUSE");
                     system("CLS");
        }

    }
    return EXIT_SUCCESS;
}
