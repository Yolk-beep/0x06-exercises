#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Struct til at opbevare coordinates.
struct Coordinates
{
  double lattitude;
  double longitude;
};
// Struct til at opbevare make, model, number, coordinates & type.
struct Vehicle
{
  string make;
  string model;
  int number;
  Coordinates location;
  string type;
};
// Function to print a vehicle.
void printVehicle(Vehicle v)
{
  cout << "The closest car is : "
       << v.make << ", "
       << v.model << ", "
       << v.number << ", "
       << v.type << endl;
}
// Function to calculate distance between 2 vehicles.
double calculateDistance(const Coordinates &coord1, const Coordinates &coord2)
{
  double distance = sqrt(pow(coord2.lattitude - coord1.lattitude, 2) + pow(coord2.longitude - coord1.longitude, 2));
  return distance;
}
int main()
{
  cout << "Exercise 0x06" << endl;
  Vehicle b0 = {"BMW", "M3", 1, {56.08879136135274, 10.2233311613884}, "BRAVO"};            // Moesgaard Museum
  Vehicle b1 = {"Volkswagen", "Golf", 2, {56.127760815765505, 10.20281162730732}, "BRAVO"}; // Marselisborg Palace
  Vehicle b2 = {"Honda", "Accord", 3, {56.17100325888462, 10.19929977544253}, "BRAVO"};     // Aarhus University
  Vehicle h1 = {"Volkswagen", "Golf", 6, {56.15255312320674, 10.203038127629382}, "HOTEL"}; // Aarhus City Hall
  Vehicle h2 = {"Fiat", "500", 1, {56.16217140423636, 10.18949261907776}, "HOTEL"};         // Botanical Garden and Greenhouses
  Vehicle r0 = {"Fiat", "500", 4, {56.153889095359624, 10.199705269637143}, "ROMEO"};       // ARoS Aarhus Art Museum
  Vehicle r1 = {"Honda", "Civic", 2, {56.150191891576384, 10.204729114263282}, "ROMEO"};    // Aarhus Central Station

  vector<Vehicle> fleet = {b0, b1, b2, h1, h2, r0, r1};

  cout << "Hello, please input your coordinates." << endl;
  cout << "Lattitude: " << endl;
  double crank1;
  cin >> crank1;
  cout << "Longitude: " << endl;
  double crank2;
  cin >> crank2;
  Coordinates point1 = {crank1, crank2};
  int j = 0;
  double Lbozo = calculateDistance(point1, fleet[0].location);
  for (int i = 1; i < fleet.size(); i++)
  {
    double Wbozo = calculateDistance(point1, fleet[i].location);
    if (Wbozo < Lbozo)
      Lbozo = Wbozo;
    j = i;
  }
  printVehicle(fleet[j]);
  return 0;
}