#include <iostream>
#include <cstdlib> // system()

// jmlibh (jM Libraries Helper)

int listLibs();
char selectLib();
int downloadLib(char& code);
// 
// listLibs()  -> Lists existing libraries, hardcoded because I'm lazy.
// selectLib() -> Lets user select a library with a single char and returns char (user selection)
// downloadLib( char& code ) -> Downloads selected library
//

int main() {
	
	while(true) {
		std::cout
		<< "[ jM Libraries Helper ]\n\n"
		<< "Options:\n\n"

		<< "[q] list libraries\n"
		<< "[w] download a library\n"
		<< "[e] exit.\n"
		<< "$ ";
		char opt;
		std::cin >> opt;
	
		switch(opt) {
			case "q":
				listLibs();
				break;
			case "w":
				char code = selectLib();
				int status = downloadLib(code);
				if (status == 1)
					return 1;
				else return 0;
			case "e":
				std::cout << "Exiting ..";
				return 0;
			default:
				std::cout << "Unknown option selected, exiting ..\n";
				return 0;

		}

		return 1;
	} return 0;
}

// todo: instead of handling the entire thing in downloadLib(), use multiple functions maybe?

int listLibs() {
	
	std::cout
	<< "[ Libraries list ]\n\n"

	<< "[e]scape.ANSI.sux\n"
	<< "[d]og.cfg\n"
	<< "[a]nge_tui\n"
	;

	return 0;
}

char selectLib() {
	char select;

	listLibs();
	std::cout << "$ ";
	std::cin >> select;

	if (select != 'e' &&
		select != 'd' &&
		select != 'a'
	) return '0'; // '0' = oh shit!
	else return select;
}

int downloadLib(char& code) {
	if (code == 'e') {
		system("mkdir ~/.jlibh");
	} else if (code == 'd') {

	} else if (code == 'a') {

	} else return 1;
}
