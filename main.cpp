#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Student.hpp"

int main(int argc, char *argv[]){
    std::ifstream fstudenci("studenci.txt");
    std::vector<Student> listaStudentow;
    Student student {"", "", "", ""};

    while(student << fstudenci){
    	listaStudentow.push_back(student);
    }
    
    std::for_each(listaStudentow.begin(), listaStudentow.end(), [](const Student& student){
    	std::cout << student << std::endl;
    });
    
    auto foundNowaksIter = std::find_if(listaStudentow.begin(), listaStudentow.end(), 
    	[](const Student& student){
    	    return student.nazwisko=="Nowak";
	}
    );
    
    {
    	size_t i = 1;
        std::for_each(foundNowaksIter, listaStudentow.end(), [&i](const Student& student){
            std::cout << "Nowak nr " << i << ". " << student << std:: endl;
            i++;
        });
    }
    
    size_t trzeciakiCount = std::count_if(listaStudentow.begin(), listaStudentow.end(),
    	[](const Student& student){
    	    return student.rok == 3;
    	}
    );
    
    std::cout << "Liczba trzeciaków: " << trzeciakiCount << std::endl;

    // Zapis do pliku
    std::ofstream ofstudenci("studenci.txt");
    std::for_each(listaStudentow.begin(), listaStudentow.end(), [&ofstudenci](auto &student){
        ofstudenci << student;
    });

    return 0;
}
