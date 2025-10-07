#include <iostream>
#include <limits>
#include <cstdlib>

// jmlibh (jM Libraries Helper)

#ifdef __WIN32__
int main() {
	std::cout << "( @ .@) you are running jmlibh on an unsupported os (wincocks) - better luck next time\n";
}
#endif

int listLibs();
char selectLib();
int downloadLib(char& code);
void pause();
void clear() { system("clear"); }

int main() {
	clear();

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
			case 'q':{
				listLibs();
				pause();
				clear();
				break;
			} case 'w':{
				char code = selectLib();
				int status = downloadLib(code);
				if (status == 1)
					return 1;
				else {
					clear();
					break;
				}
			} case 'e':{
				std::cout << "( T-T) exiting ..";
				return 0;
			} default:{
				std::cout << "(>//< ) unknown option selected, exiting ..\n";
				return 0;
			}
		}
	} return 0;
}

int listLibs() {
	clear();

	std::cout
	<< "[ libraries list ]\n\n"

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
		// for escape.ansi.sux
		int returnCode = system("./download-e.sh");
		if (returnCode != 0) {
			clear();
			std::cout << "if nothing happened, try 'chmod +x ./*.sh'\n";
			pause();
			return 0;
		} else return 0;
	}
	else if (code == 'd') {
		// for dog.cfg
		int returnCode = system("./download-d.sh");
		if (returnCode != 0) {
			clear();
			std::cout << "if nothing happened, try 'chmod +x ./*.sh'\n";
			pause();
			return 0;
		} else return 0;
	}
	else if (code == 'a') {
		// for ange_tui
		int returnCode = system("./download-a.sh");
		if (returnCode != 0) {
			clear();
			std::cout << "if nothing happened, try 'chmod +x ./*.sh'\n";
			pause();
			return 0;
		} else return 0;
	}
	else {
		clear();
		std::cout << "(>//< ) unknown code entered.\n";
		pause();
		return 0;
	}
	return 0; // never reached
}

void pause() {
	std::cout << "(-.- ) press enter to continue\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.ignore();
}
