/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h"
#include <iostream>

void sandbox() {
  // STUDENT TODO: Construct an instance of your class!
  Person<std::string> p1;
  std::cout << "p1: "
              << p1.getName()  << ", "
              << p1.getEmail() << ", age=" << p1.getAge() << "\n";

  Person<std::string> p2("Alice","alice@outlook.com",18);
  std::cout << "p2: " << p2.getName() << ", " << p2.getEmail();

}