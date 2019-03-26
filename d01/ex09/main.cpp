
#include "Logger.hpp"

int 	main(void) {

	Logger instance = Logger("log-tests");

	instance.log("file","message n°1");
	instance.log("file","message n°2");
	instance.log("file","message n°3");
	instance.log("file","message n°4");
	instance.log("console","login success");
	instance.log("file","message n°5");
	instance.log("file","message n°6");
	
	return 0;
}