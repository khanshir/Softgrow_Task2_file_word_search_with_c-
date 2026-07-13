#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
	while(true) {
		cout << "1: Search a word" << endl;
		cout << "0: Exit" << endl;
		
		char option;
		cout << "\nEnter option here --> ";
		cin >> option;
		
		while(option != '1' && option != '0') {
			cout << "\nInvalid input! Enter Again -->";
			cin >> option;
		}
		
		if(option == '1') {
			string user_srch;
			string word;
			int count = 0;
			
			cout << "Enter your word here --> ";
			cin >> user_srch;
			
			string user_srch_in_lwrcase;
			for(int k = 0; k < user_srch.length(); k++) {
				user_srch_in_lwrcase += tolower(user_srch[k]);
			}
			
			ifstream file("data1.txt");
			if(!(file.is_open())) {
				cout << "File Opening Error!";
				return 1;
			}
	
			string line;
			while(getline(file, line)) {
				for(int i = 0; i < line.length(); i++) {
					if( (line[i] >= 65 && line[i] <= 90) || 
						(line[i] >= 97 && line[i] <= 122)|| 
						(line[i] >= 48 && line[i] <= 57) ||
						(line[i] == '_' || line[i] == '+' || line[i] == '#' || line[i] == '@' || 
						line[i] == '-' || line[i] == 39) || line[i] == '$' || line[i] == '%' || line[i] == '&' ||
						(line[i] == '.' && i != (line.length() - 1) && line[i+1] != ' '))
					{
						word += line[i];
					} else {
						string tempword;
						for(int j = 0; j < word.length(); j++) {
							tempword += tolower(word[j]);
						}
						if(tempword == user_srch_in_lwrcase) {
							count++;
						}
						word = "";
					}
				}
				if(word.length() > 0 ) {
						string tempword;
						for(int j = 0; j < word.length(); j++) {
							tempword += tolower(word[j]);
						}
						if(tempword == user_srch_in_lwrcase) {
							count++;
						}
						word = "";
					}
			}
	
			file.close();
			
			if(count) {
				cout << "The word (" << user_srch << ") appears " << count << " times!" << endl;   
				cout << "***---------------------------------------------------------------***" << endl << endl;
			} else {
				cout << "Word Not Found!" << endl;
				cout << "***---------------------------------------------------------------***" << endl << endl;
			}
			
		} else {
			cout << "\nProgram ends....";
			break;
		}
	}
}



