#include "gambling.h"
#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;

void Player::setName(string n) {
    name = n;
}

string Player::getName() {
    return name; 
}