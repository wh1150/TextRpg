#pragma once

#include <iostream>
#include <algorithm>
#include "Item.h"

template<typename T>
class Inventory{
	T* pItems_;
	int capacity_;
	int size_;

public:
	Inventory(int capacity): pItems_(nullptr), capacity_(capacity), size_(0){
		if (capacity_ < 0){
			capacity_ = 0;
		}

		pItems_ = new T[capacity_];
	}

	~Inventory(){
		delete[] pItems_;
	}

	Inventory(const Inventory& other): pItems_(nullptr), capacity_(other.capacity_), size_(other.size_){
		pItems_ = new T[capacity_];

		for (int i = 0; i < size_; ++i)
			pItems_[i] = other.pItems_[i];
		
	}

	Inventory& operator=(const Inventory& other){
		if (this == &other)	return *this;

		delete[] pItems_;

		capacity_ = other.capacity_;
		size_ = other.size_;
		pItems_ = new T[capacity_];

		for (int i = 0; i < size_; ++i)
			pItems_[i] = other.pItems_[i];

		return *this;
	}

	void addItem(const T& item){
		if (size_ >= capacity_){
			printf("Adding item... (%d/%d full)\n", size_, capacity_);
			resize(capacity_ * 2);
			printf("-> Inventory auto-expanded! (%d -> %d)\n-> Item added\n", size_, capacity_);
			printAllItems();
			return;
		}

		pItems_[size_] = item;
		++size_;
	}

	void removeLastItem(){
		if (size_ <= 0){
			std::cout << "Inventory is empty." << std::endl;
			return;
		}

		--size_;
	}

	void printAllItems() const{
		for (int i = 0; i < size_; ++i) {
			std::cout << i+1 << ". ";
			pItems_[i]->printInfo();
		}
	}

	static bool compareByPrice(const T& a, const T& b) {
		return a->getPrice() < b->getPrice();
	}
	
	void SortItems() {
		std::sort(begin(), end(), compareByPrice);
	}
	void resize(int newCapacity) {
		T* pItems_2 = new T[newCapacity];
		
		SortItems();

		for (int i = 0; i < size_; ++i)
			pItems_2[i] = pItems_[i];
		
		 pItems_ = pItems_2;
		 capacity_ = newCapacity;
	}

	int getSize() const{return size_;}
	int getCapacity() const{return capacity_;}
	
	T* begin() { return pItems_; }
	T* end() { return pItems_ + size_; }

	const T* begin() const { return pItems_; }
	const T* end() const { return pItems_ + size_; }
};