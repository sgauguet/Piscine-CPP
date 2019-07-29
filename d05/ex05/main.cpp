#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include <time.h>
#include "OfficeBlock.hpp"
#include "CentralBureaucracy.hpp"

int main(void) {
	srand(static_cast<unsigned int>(time(NULL)));

	CentralBureaucracy city;
	const char *bureaucrats1[] = {"Aanor", "Aaran", "Aaricia", "Aaron", "Abbon", "Abby", "Abdel", "Abdon", "Abel", "Abélard", "Abélia", "Abella", "Abigaël", "Abondance", "Abraham", "Abriel", "Acace", "Achahildis", "Achille", "Adalard", "Adalbert", "Adalric" };
	const char *bureaucrats2[] = {"Babet", "Babeth", "Babette", "Babylas", "Bacchus", "Bakhita", "Balbine", "Baldassare", "Baldwin", "Balian", "Balthazar", "Baptiste","Barbara", "Barbe", "Barberine", "Barnabé", "Barnard", "Barry", "Barthélemy", "Bartholomé", "Bastienne", "Bathilde"};
	const char *targets[] = { "kitchen", "know", "knowledge", "land", "language","large", "last", "late", "later", "laugh", "law", "lawyer", "lay",
	"lead", "leader", "learn", "least", "leave", "left", "leg","legal", "less","let","letter","level","lie","life",
	"light","like","likely","line","list","listen","little","live","local","long","look","lose","loss","lot",
	"love","low","machine","magazine","main","maintain","major","majority","make","man","manage","management",
	"manager","many","market","marriage","material","matter","may","maybe","me","mean","measure","media",
	"medical","meet","meeting","member","memory","mention","message","method","middle","might","military",
	"million","mind","minute","miss","mission","model","modern","moment","money","month","more","morning",
	"most","mother","mouth","move","movement","movie","Mr","Mrs","much","music","must","my","myself",
	"name","nation","national","natural","nature","near","nearly","necessary","need","network","never","new",
	"news","newspaper","next","nice","night","no","none","nor","north","not","note","nothing","notice","now","n't",
	"number","occur","of","off","offer","office","officer","official""often","oh","oil","ok","old","on","once",
	"one","only","onto","open","operation","opportunity","option","or","order","organization","other",
	"others","our","out","outside","over","own","owner","page","pain","painting","paper","parent","part",
	"participant","particular","particularly","partner","party","pass","past","patient","pattern","pay","peace","people",
	"per","perform","performance","perhaps","period","person","personal","phone","physical" };

	int random_number, max_value = 150, min_value = 1, i = 0;
	std::cout << "bureaucracy with no bureaucrats -- impossible" << std::endl << std::endl;
	city.doBureaucracy();

	while (i < 20) {
		random_number = rand() % (max_value - min_value) + min_value;
		city.addSigner(bureaucrats1[i], random_number);
		city.addExecutor(bureaucrats2[i], random_number);
		i++;
	}
	std::cout << "bureaucracy with no queue -- nothing to do" << std::endl << std::endl;
	city.doBureaucracy();
	i = 0;
	while (i < 150) {
		city.queueUp(targets[i]);
		i++;
	}
	std::cout << "Start bureaucracy" << std::endl << std::endl;
	city.doBureaucracy();
}

