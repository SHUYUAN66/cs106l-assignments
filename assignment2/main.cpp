/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */
#include <sstream>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>

std::string kYourName = "Shuyuan Wang"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::ifstream names(filename);
  std::string name;
  // use set here
  std::set<std::string> set_names;
  while (std::getline(names,name)){
    set_names.insert(name);
  }
  std::cout << "Set size " << set_names.size() << std::endl;
  return set_names;
  

}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::stringstream ss(name);
  std::string first, last;
  ss >> first >> last;
  first = first[0];
  last = last[0];
  std::cout << first << " " << last;

  std::queue<const std::string*> matches;
  for (const std::string& student : students ){
    //why add const here?
    std::stringstream current(student);
    std::string cur_1, cur_2;
    current >> cur_1 >> cur_2;
    cur_1 = cur_1[0];
    cur_2 = cur_2[0];
    if ((cur_1 == first) && (cur_2 == last)){
      matches.push(&student);

    }
  }
  return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  if(matches.size() == 0){
    std::cout << "NO MATCHES FOUND." << std::endl;
    return "";
  }
  const std::string* match;
  match = matches.front();
  matches.pop();
  return *match;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
