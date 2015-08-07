#ifndef KTHSMALLESTNUMBER_HPP_
#define KTHSMALLESTNUMBER_HPP_

#include <algorithm>
#include <ostream>

template<class T>
class KthSmallestNumber {
public:
	KthSmallestNumber(std::size_t k) {
		this->k = k;
	}

	T getValue() const {
		return maxHeap.front();
	}

	void addNumber(T number) {

		if (getHeapSize() < k) {
			maxHeap.push_back(number);
			std::push_heap(maxHeap.begin(), maxHeap.end());
			return;
		}

		if (number >= getValue()) {
			return;
		}

		maxHeap.push_back(number);
		std::push_heap(maxHeap.begin(), maxHeap.end());

		std::pop_heap(maxHeap.begin(), maxHeap.end());
		maxHeap.pop_back();
	}

	friend std::ostream& operator<<(std::ostream &os, const KthSmallestNumber &kthSmallestNumber) {
		std::size_t heapSize = kthSmallestNumber.getHeapSize();
		std::size_t k = kthSmallestNumber.getK();

		if (heapSize < k) {
			return os << "\t" << k << "-th smallest number: NA (only observed " << heapSize << " numbers)";
		} else {
			return os << "\t" << k << "-th smallest number: " << kthSmallestNumber.getValue();
		}
	}

private:
	std::size_t getK() const {
		return k;
	}

	std::size_t getHeapSize() const {
		return maxHeap.size();
	}

	std::size_t k;
	std::vector<T> maxHeap; //NOTE: default max-heap
};

#endif /* KTHSMALLESTNUMBER_HPP_ */
