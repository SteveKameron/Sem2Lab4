#include <iostream>
#include <deque>
#include <list>
#include <fstream>
#include <string>
#include <algorithm>


class Book {
public:
	std::string FIO;
	std::string Book_Name;
	std::string Book_Publishing_Office;
	int Year_Of_Pulishing, Amount_Of_Pages;

	Book(std::string fio, std::string name, std::string office, int year, int pages) {
		FIO = fio;
		Book_Name = name;
		Book_Publishing_Office = office;
		Year_Of_Pulishing = year;
		Amount_Of_Pages = pages;
	}

	//Default construnctor
	Book() {

	}

	//Constructor of copying
	Book(const Book &Other_Book) {
		this->FIO = Other_Book.FIO;
		this->Book_Name = Other_Book.Book_Name;
		this->Book_Publishing_Office = Other_Book.Book_Publishing_Office;
		this->Year_Of_Pulishing = Other_Book.Year_Of_Pulishing;
		this->Amount_Of_Pages = Other_Book.Amount_Of_Pages;
	}

	// = 
	Book& operator = (const Book& Other_Book) {
		this->FIO = Other_Book.FIO;
		this->Book_Name = Other_Book.Book_Name;
		this->Book_Publishing_Office = Other_Book.Book_Publishing_Office;
		this->Year_Of_Pulishing = Other_Book.Year_Of_Pulishing;
		this->Amount_Of_Pages = Other_Book.Amount_Of_Pages;
		return *this;
	}
};

std::ostream& operator << (std::ostream& Output, Book& Other_Book) {
	Output << Other_Book.FIO << '\n';
	Output << Other_Book.Book_Name << '\n';
	Output << Other_Book.Book_Publishing_Office << '\n';
	Output << Other_Book.Year_Of_Pulishing << '\n';
	Output << Other_Book.Amount_Of_Pages << '\n';
	return Output;
}

bool Book_Sort_Criterion(const Book& Book_1, const Book& Book_2) {
	return Book_1.FIO < Book_2.FIO;
}


int main() {
	std::deque<Book> Book_Deque{};
	std::ifstream file("input.txt");
	std::string Temp_FIO, Temp_Book_Name, Temp_Office;
	int Temp_Year, Temp_Pages;
	std::string another;
	while (!file.eof()) {
		getline(file, Temp_FIO);
		getline(file, Temp_Book_Name);
		file >> Temp_Office;
		file >> Temp_Year;
		file >> Temp_Pages;
		Book Temp_Book(Temp_FIO, Temp_Book_Name, Temp_Office, Temp_Year, Temp_Pages);
		Book_Deque.emplace_back(Temp_Book);
		getline(file, another);
	}



	//Before Sorting (deque)
	std::cout << "----------DEQUE----------" << std::endl;
	std::cout << "----------BEFORE SORTING----------" << std::endl;
	for (int i = 0; i < Book_Deque.size(); i++) {
		std::cout << "Book number: " << i+1 << '\n' << '\n' << Book_Deque[i] << std::endl;
	}
	


	//Copy of starting container (for output file)
	std::deque<Book> Unsorted_Deque;
	Unsorted_Deque.resize(Book_Deque.size());
	std::copy(Book_Deque.begin(), Book_Deque.end(), Unsorted_Deque.begin());



	std::list<Book> Book_List;
	Book_List.resize(Book_Deque.size());
	std::copy(Book_Deque.begin(), Book_Deque.end(), Book_List.begin());



	std::sort(Book_Deque.begin(), Book_Deque.end(), Book_Sort_Criterion);
	std::cout << "----------AFTER SORTING----------" << std::endl;
	for (int i = 0; i < Book_Deque.size(); i++) {
		std::cout << "Book number: " << i + 1 << '\n' << '\n' << Book_Deque[i] << std::endl;
	}



	std::cout << "----------LIST----------" << std::endl;
	int n = 0;
	for (Book i : Book_List) {
		std::cout << "Book number: " << n + 1 << '\n' << '\n' << i << std::endl;
		n++;
	}


	//Working with output.txt
	std::ofstream outfile;
	outfile.open("output.txt");


	//Starting container before sorting
	outfile << "==========Starting Container==========" << std::endl;
	for (int i = 0; i < Unsorted_Deque.size(); i++) {
		outfile << Unsorted_Deque[i] << std::endl;
	}
	outfile << "======================================" << std::endl;


	//Starting container after sorting
	outfile << "==========After Sorting==========" << std::endl;
	for (int i = 0; i < Book_Deque.size(); i++) {
		outfile << Book_Deque[i] << std::endl;
	}

	
	//List that were copied in
	outfile << "==========List==========" << std::endl;
	for (Book i : Book_List) {
		outfile << i << std::endl;
	}


	return 0;
}