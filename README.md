# Valet Parking Application

<p align="center">
  <img width="460" height="300" src="https://github.com/tknle/Valet-Parking-Program/blob/main/car-parking.jfif">
</p>

## Table of Contents

* [About the Project](#about-the-project)
  * [Sample Output / Display ](#sample-output)
  * [Enter Vehicle Information Manually](#enter-vehicle)
  * [Close Parking](#close-parking)
  * [Exit Parking](#exit-parking)
* [Getting Started](#getting-started)
  * [Compilation](#compilation)
 

## About The Project

Valet Parking Application is the final project introducing to Object Oriented Programming using C++

This project simulates a  valet parking complex. the application keeps track of the number of the parking vehicles and the total parked vehicles are limited. Vehicle's owner can also have a car wash. 

Application takes in the date from a csv file. It keeps track of a valet parking for vehicles and retrieves the information back when requested. The application displays a menu allowing users to create, update, retrieve, and delete the data.

### Sample Output

```sh
Pass 1: ------->
****** Seneca Valet Parking ******
***** Available spots: 2 *****
Parking Menu, select an action:
1 - Park Vehicle
2 - Return Vehicle
3 - List Parked Vehicles
4 - Close Parking (End of day)
5 - Exit Program

> 3
*** List of parked vehicles ***
Vehicle type: Car
Parking Spot Number: 1
Licence Plate: ASD
Make and Model: Honda Civic
Without Carwash

Vehicle type: Motorcycle
Parking Spot Number: 2
Licence Plate: AS
Make and Model: Honda 125
With Sidecar

Vehicle type: Car
Parking Spot Number: 3
Licence Plate: QWE
Make and Model: BMW 320
With Carwash

Vehicle type: Motorcycle
Parking Spot Number: 4
Licence Plate: ZXC
Make and Model: Suzuki 750

Vehicle type: Car
Parking Spot Number: 5
Licence Plate: ASDASD
Make and Model: Ford F
Without Carwash

```

### Enter Vehicle

```sh
****** Seneca Valet Parking ******
***** Available spots: 2 *****
Parking Menu, select an action:
1 - Park Vehicle
2 - Return Vehicle
3 - List Parked Vehicles
4 - Close Parking (End of day)
5 - Exit Program

> 1
Select type of the vehicle:
1 - Car
2 - Motorcycle
3 - Cancel

> 1
Car information entry

Enter Licence Plate Number:
Invalid Licence Plate, try again: 123456789
Invalid Licence Plate, try again: aaaa
Enter Make and Model: a
Invalid Make and model, try again: ab
Carwash while parked? (Y)es/(N)o: yes
Invalid response, only (Y)es or (N)o are acceptable, retry: n
Parking Ticket
Vehicle type: Car

Parking Spot Number: 10
Licence Plate: AAAA
Make and Model: ab
Without Carwash
```


### Close Parking
When closing the parking, it will save all the changes to the system to the csv file and print the towing request at the end of the day.

``` sh

****** Seneca Valet Parking ******
***** Available spots: 1 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 4
This will Remove and tow all remaining vehicles from the parking!
Are you sure? (Y)es/(N)o: y
Closing Parking
Towing request
*********************
Vehicle type: Car
Parking Spot Number: 1
Licence Plate: ASD
Make and Model: Ford
Without Carwash
Towing request
*********************
Vehicle type: Motorcycle
Parking Spot Number: 2
Licence Plate: AS12
Make and Model: Honda 125
With Sidecar
Towing request
*********************
Vehicle type: Car
Parking Spot Number: 3
Licence Plate: QWE123
Make and Model: BMW 320
With Carwash
Towing request
*********************
Vehicle type: Motorcycle
Parking Spot Number: 4
Licence Plate: ZXC123
Make and Model: Suzuki 750
Towing request
*********************
Vehicle type: Car
Parking Spot Number: 5
Licence Plate: ASDASD
Make and Model: Ford F150
Without Carwash
```

### Exit Parking
Save all the data to csv file and terminate the program

```sh
****** Seneca Valet Parking ******
***** Available spots: 10 *****
Parking Menu, select an action:
1- Park Vehicle
2- Return Vehicle
3- List Parked Vehicles
4- Close Parking (End of day)
5- Exit Program
> 5
This will terminate the program!
Are you sure? (Y)es/(N)o: y
Exiting program!

```


## Getting Started

[Click here to run on Repl.it](https://repl.it/@tknle/Valet-Parking-Application#main.cpp)

To run this program, press the 'Run' button in repl.it


### Compilation

If download or clone the repository, please run the following command.
```sh
 g++ -Wall -std=c++11 -g -o Car.cpp Menu.cpp Motorcycle.cpp Parking.cpp ParkingAppTester.cpp ReadWritable.cpp Utils.cpp Vehicle.cpp
```

You can also run on Visual Studio by clicking the **ms5.vcxproj** file

## Author

Mia Le

Project Link: 
[Project Link](https://github.com/tknle/Valet-Parking-Application)
