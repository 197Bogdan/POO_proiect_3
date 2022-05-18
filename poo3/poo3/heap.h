#pragma once
#include <vector>


template <class T> class Heap {

public:

	T getValue(int position) {
		return values[position];
	}
	void setValue(int position, T value) {
		values[position] = value;
	}
	std::vector<T> getValues() {
		return values;
	}
	void setValues(std::vector<T> v) {
		values = v;
	}

	void insert(T value) {
		values.push_back(value);
		goUp();
	}
	T remove() {
		swap(int(values.size()) - 1, 0);

		T value = values.back();
		values.pop_back();
		goDown();
		return value;
	}
	T peek() {
		return values.back();
	}
	int getSize() {
		return int(values.size());
	}
	void heapSort(std::vector<T>& v) {
		v.clear();
		std::vector<T> copy = values;
		int size = getSize();
		for (int i = 0; i < size; i++)
			v.push_back(this->remove());
		values = copy;
	}



protected:
	virtual void goUp() = 0;
	virtual void goDown() = 0;
	void swap(int child, int parent) {
		T temp;
		temp = values[child];
		values[child] = values[parent];
		values[parent] = temp;
	}
	int getLeftChild(int parent) {
		return 2 * parent + 1;
	}
	int getRightChild(int parent) {
		return 2 * parent + 2;
	}
	int getParent(int child) {
		return (child - 1) / 2;
	}

private:
	std::vector<T> values;
};

template <class T>
class HeapMin : public Heap<T> {

public:
	HeapMin() {
		this->setValues({});
	}
	HeapMin(const std::vector<T>& v, bool is_heap = 0) {
		if (is_heap)
			this->setValues(v);
		else
			for (T el : v)
				this->insert(el);
	}

private:
	void goUp() {
		int child = this->getSize() - 1;
		int parent = this->getParent(child);

		while (child > 0 && this->getValue(child) < this->getValue(parent)) {
			this->swap(child, parent);
			child = parent;
			parent = this->getParent(child);
		}

	}
	void goDown() {
		int parent = 0;
		int length = this->getSize();
		while (1) {
			int left = this->getLeftChild(parent);
			int right = this->getRightChild(parent);

			int lowest = parent;

			if (left < length && this->getValue(left) < this->getValue(lowest))
				lowest = left;

			if (right < length && this->getValue(right) < this->getValue(lowest))
				lowest = right;

			if (lowest != parent) {
				this->swap(lowest, parent);
				parent = lowest;
			}
			else
				break;
		}
	}
};

template <class T>
class HeapMax : public Heap<T> {

public:
	HeapMax() {
		this->setValues({});
	}
	HeapMax(const std::vector<T>& v, bool is_heap = 0) {
		if (is_heap)
			this->setValues(v);
		else
			for (T el : v)
				this->insert(el);
	}

private:
	void goUp() {
		int child = this->getSize() - 1;
		int parent = this->getParent(child);

		while (child > 0 && this->getValue(child) > this->getValue(parent)) {
			this->swap(child, parent);
			child = parent;
			parent = this->getParent(child);
		}
	}
	void goDown() {
		int parent = 0;
		int length = this->getSize();

		while (1) {
			int left = this->getLeftChild(parent);
			int right = this->getRightChild(parent);

			int largest = parent;

			if (left < length && this->getValue(left) > this->getValue(largest))
				largest = left;

			if (right < length && this->getValue(right) > this->getValue(largest))
				largest = right;

			if (largest != parent) {
				this->swap(largest, parent);
				parent = largest;
			}
			else
				break;
		}
	}
};
