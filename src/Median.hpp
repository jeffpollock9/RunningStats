#ifndef MEDIAN_HPP_
#define MEDIAN_HPP_

#include <algorithm>
#include <ostream>

template<class T>
class Median {
public:
	Median() {
	}

	double getValue() const {
		if (heapSizeOdd()) {
			return maxHeap.front();
		} else {
			return (minHeap.front() + maxHeap.front()) / 2.0;
		}
	}

	void addNumber(T number) {
		if (heapSizeOdd()) {
			if (number < maxHeap.front()) {
				maxHeap.push_back(number);
				std::push_heap(maxHeap.begin(), maxHeap.end());

				number = maxHeap.front();

				std::pop_heap(maxHeap.begin(), maxHeap.end());
				maxHeap.pop_back();
			}
			minHeap.push_back(number);
			std::push_heap(minHeap.begin(), minHeap.end(), std::greater<T>());
		} else {
			if (getMinHeapSize() > 0 && number > minHeap.front()) {
				minHeap.push_back(number);
				std::push_heap(minHeap.begin(), minHeap.end(), std::greater<T>());

				number = minHeap.front();

				std::pop_heap(minHeap.begin(), minHeap.end(), std::greater<T>());
				minHeap.pop_back();
			}
			maxHeap.push_back(number);
			std::push_heap(maxHeap.begin(), maxHeap.end());
		}
	}

	friend std::ostream& operator<<(std::ostream &os, const Median &median) {
		return os << "\t" << "Median: " << median.getValue();
	}

private:
	std::size_t getHeapSize() const {
		return minHeap.size() + maxHeap.size();
	}

	std::size_t getMaxHeapSize() const {
		return maxHeap.size();
	}

	std::size_t getMinHeapSize() const {
		return minHeap.size();
	}

	bool heapSizeOdd() const {
		return getHeapSize() % 2;
	}

	std::vector<T> minHeap; //NOTE: requires std::greater<T>()
	std::vector<T> maxHeap; //NOTE: default max-heap
};

#endif /* MEDIAN_HPP_ */
