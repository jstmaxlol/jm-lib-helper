#include <iostream>
#include <cstdlib> // system() to call the
				   //download-[x].sh scripts.

// jmlibh (jM Libraries Helper)

// silly developer sidenote:
// i did not test this so i am not sure it works
// tho it's just a couple ifs and elses, right?
// R.I.P. to whoever tried it and had *any* issue.
// now i'm going to sleep, goodnight!

int listLibs();
char selectLib();
int downloadLib(char& code);

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
			// i didn't write shit in a bit
			// therefore i dont even remember
			// if the switch case's 'break'
			// keyword kills the entire loop
			// (while) or just the switch's.
			// probably the latter.
			case "q":
				listLibs();
				break;
			case "w":
				char code = selectLib();
				int status = downloadLib(code);
				if (status == 1)
					return 1;
				else break;
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
		// for escape.ansi.sux
		int return = system("./download-e.sh");
		if (return != 0) {
			std::cout << "If nothing happened, try 'chmod +x ./*.sh'\n";
			return 1;
		}
		else return 0;
	}
	else if (code == 'd') {
		// for dog.cfg
		int return = system("./download-d.sh");
		if (return != 0) {
			std::cout << "If nothing happened, try 'chmod +x ./*.sh'\n";
			return 1;
		}
		else return 0;
	}
	else if (code == 'a') {
		// for ange_tui
		int return = system("./download-a.sh");
		if (return != 0) {
			std::cout << "If nothing happened, try 'chmod +x ./*.sh'\n";
			return 1;
		}
		else return 0;
	}
	else if (code == '0') {
		// this is a kinda stupid edge-case for '0'
		// but since this function generically says
		// bye-bye to every code that is not the
		// aforementioned this becomes rather useless.
		std::cout << "Unknown code entered.\n";
		return 1;
	}
	// any other code is a generic error so just return 1 and call it a day.
	else return 1;
}
