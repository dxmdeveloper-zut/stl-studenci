#include "Student.hpp"

std::ostream& operator<<(std::ostream& stream, const Student& student){
    stream << student.imie << " " << student.nazwisko << "\tnr albumu: " << student.nrAlbumu << "\tgrupa: " << student.grupa << "\trok: " << student.rok;
    return stream; 
}

std::ofstream& operator<<(std::ofstream& stream, const Student& student){
    stream << student.imie << std::endl
    	   << student.nazwisko << std::endl
    	   << student.nrAlbumu << std::endl
    	   << student.grupa << std::endl
    	   << student.rok << std::endl;
    return stream;
}

Student& Student::operator<<(std::istream& stream){
    std::string line;
    this->rok = 0;
    
    if(stream.eof() || !stream) return *this;
    std::getline(stream, this->imie);
    if(this->imie.empty()) return *this;
    std::getline(stream, this->nazwisko);
    std::getline(stream, this->nrAlbumu);
    std::getline(stream, this->grupa);
    std::getline(stream, line);
    this->rok = std::stoi(line);
    return *this;
}
