#include "AsteroBocal.hpp"
#include "BocalSteroid.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"
#include "MiningBarge.hpp"
#include "IMiningLaser.hpp"

int main( void ) {
	StripMiner a;
	DeepCoreMiner b;
	MiningBarge barge;
	MiningBarge barge2;
	IAsteroid *asteroid1 = new BocalSteroid();
	IAsteroid *asteroid2 = new AsteroBocal();

	std::cout << "---------- Test - names ----------" << std::endl;
	std::cout << asteroid1->getName() << std::endl;
	std::cout << asteroid2->getName() << std::endl;

	std::cout << "---------- Test - IMiningLaster::mine ----------" << std::endl;
	std::cout << "StripMiner on BocalSteroid" << std::endl;
	a.mine(asteroid1);
	std::cout << "DeepCoreMiner on BocalSteroid" << std::endl;
	b.mine(asteroid1);
	std::cout << "StripMiner on AsteroBocal" << std::endl;
	a.mine(asteroid2);
	std::cout << "DeepCoreMiner on AsteroBocal" << std::endl;
	b.mine(asteroid2);
	std::cout << "---------- Test - MiningBarge without lasers (nothing) ----------" << std::endl;
	barge.mine(asteroid1);
	std::cout << "---------- Test - MiningBarge with lasers ----------" << std::endl;
	barge.equip(&a);
	barge.equip(&b);
	barge2 = barge;
	barge2.mine(asteroid1);
	barge2.mine(asteroid2);
	delete asteroid1;
	delete asteroid2;
	return 0;
}
