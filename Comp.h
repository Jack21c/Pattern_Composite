#pragma once
#include <iostream>
#include <vector>
#include "Visitor.h"

using namespace std;

class Object {
protected:
	int _cost;
public:
	Object(int cost = 10) :_cost(cost) {

	}
	virtual int item_cost() {
		return _cost;
	}

	virtual void work() {
		//тут прописывается, какую работу выполняет конкретный компонент
	}
	virtual void accept(Visitor v) {
		v.visitOthers<Object>(this);
	}
	~Object(){}
};

class ComposedObject : public Object {
protected:
	vector<Object*> _components;
public:
	ComposedObject() : Object(0) {}
	ComposedObject(Object* component) : Object(component->item_cost()), _components(1, component) {}
	ComposedObject(vector<Object*> components) : Object(0), _components(components) {
		for (Object* oj : components)
			_cost += oj->item_cost();
	}
	virtual void add(Object* component) {
		_components.push_back(component);
		_cost += component->item_cost();
	}
	virtual int item_cost() {
		return _cost;
	}
	virtual void work() {
		//тут прописывается, какую работу выполняет конкретный компонент
		//возможно зависит от входящих в него компонентов
	}
	virtual void accept(Visitor v) {
		for (Object* oj : _components)
			oj->accept(v);
	}
	~ComposedObject() {
		_components.clear();
	}

};

class Computer : public ComposedObject {
public:
	Computer() : ComposedObject() {}
	Computer(Object* component) : ComposedObject(component) {}
	Computer(vector<Object*> components) : ComposedObject(components) {}
	void add(Object* component) {
		_components.push_back(component);
		_cost += component->item_cost();
	}
	int item_cost() {
		return _cost;
	}
	void work() {
		//тут прописывается, какую работу выполняет конкретный компонент
		//возможно зависит от входящих в него компонентов
	}
	void accept(Visitor v) {
		for (Object* oj : _components)
			oj->accept(v);
	}
	~Computer() {}

};

class KeyBoard : public Object {
public:
	KeyBoard(int cost = 210) : Object(cost) {}
	int item_cost() {
		return _cost;
	}
	void work() {
		//тут прописывается, какую работу выполняет конкретный компонент
	}
	void accept(Visitor v) {
		v.visitOthers<Object>(this);
	}
	~KeyBoard() {}
};

class CPU : public Object {
public:
	CPU(int cost = 340) : Object(cost) {}
	int item_cost() {
		return _cost;
	}
	void work() {
		//тут прописывается, какую работу выполняет конкретный компонент
	}
	void accept(Visitor v) {
		v.visitOthers<Object>(this);
	}
	~CPU() {}
};

class GPU : public Object {
public:
	GPU(int cost = 310) : Object(cost) {}
	int item_cost() {
		return _cost;
	}
	void work() {
		//тут прописывается, какую работу выполняет конкретный компонент
	}
	void accept(Visitor v) {
		v.visitOthers<Object>(this);
	}
	~GPU() {}
};

class Monitor : public Object {
public:
	Monitor(int cost = 280) : Object(cost) {}
	int item_cost() {
		return _cost;
	}
	void work() {
		//тут прописывается, какую работу выполняет конкретный компонент
	}
	void accept(Visitor v) {
		v.visitOthers<Object>(this);
	}
	~Monitor() {}
};

class Memory : public Object {
public:
	Memory(int cost = 265) : Object(cost) {}
	int item_cost() {
		return _cost;
	}
	void work() {
		//тут прописывается, какую работу выполняет конкретный компонент
	}
	void accept(Visitor v) {
		v.visitMemory(*this);
	}
	~Memory() {}
};

class GraphCard : public ComposedObject {
public:
	GraphCard() : ComposedObject() {}
	GraphCard(Object* component) : ComposedObject(component) {}
	GraphCard(vector<Object*> components) : ComposedObject(components) {}
	void add(Object* component) {
		_components.push_back(component);
		_cost += component->item_cost();
	}
	int item_cost() {
		return _cost;
	}
	void work() {
		//тут прописывается, какую работу выполняет конкретный компонент
		//возможно зависит от входящих в него компонентов
	}
	void accept(Visitor v) {
		for (Object* oj : _components)
			oj->accept(v);
	}
	~GraphCard() {}

};