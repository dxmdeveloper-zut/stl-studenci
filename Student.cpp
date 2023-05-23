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

bool Student::operator<<(std::istream& stream){
    std::string line;
    
    if(stream.eof() || !stream) return false;
    std::getline(stream, this->imie);
    if(this->imie.empty()) return false;
    std::getline(stream, this->nazwisko);
    std::getline(stream, this->nrAlbumu);
    std::getline(stream, this->grupa);
    std::getline(stream, line);
    this->rok = std::stoi(line);
    return true;
}
