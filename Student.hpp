#pragma once
#include <string>
#include <iostream>
#include <fstream>

class Student {
public:
    friend std::ostream& operator<<(std::ostream& stream, const Student& student);
    friend std::ofstream& operator<<(std::ofstream& stream, const Student& student);
    Student& operator<<(std::istream& stream);
    explicit operator bool() const{
        return (bool)(rok);
    }

public:
    std::string imie;
    std::string nazwisko;
    std::string nrAlbumu;
    std::string grupa;
    unsigned int rok;
};
