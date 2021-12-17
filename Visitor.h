#pragma once

#include <iostream>
#include "Comp.h"

class Visitor {
protected:
	int memory_cost = 0;
public:
	Visitor() {}
	template<class Item>
	void visitOthers(Item* component) {}
	int memoryCost() const {
		return memory_cost;
	}
	void visitMemory(Memory component) {
		memory_cost += component.item_cost();
	}
};


