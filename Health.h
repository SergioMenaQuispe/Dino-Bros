#pragma once

class Health {
public:
	int operator()(int difficult) {
		if (difficult == 2) return difficult;
		else if (difficult == 1) return 3;
		else if (difficult == 3) return 1;
	}

	Health(){}
};