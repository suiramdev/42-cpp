#pragma once

#include <cmath>
#include <ctime>
#include <memory>
#include <utility>
#include <iostream>
#include <stdint.h>

template <template <typename, typename> class ContainerType> class PmergeMe {
private:
  typedef ContainerType<int, std::allocator<int> > ChainContainer;
  typedef ContainerType<std::pair<int, int>, std::allocator<std::pair<int, int> > > PairContainer;

  /**
   * @brief Make pairs, sort the elements of each pair and sort the entire
   * container (based on the first value of the pair, otherwise known as << a >> or << main >>).
   *
   * @param container the container of elements
   * @return a container of sorted pairs
   */
  static PairContainer makeSortedPairs(const ChainContainer &container) {
    PairContainer pairs;

    for (size_t i = 0; i < container.size(); i += 2) {
      if (i + 1 < container.size()) {
        if (container[i] >= container[i + 1]) {
          pairs.push_back(std::make_pair(container[i], container[i + 1]));
        } else {
          pairs.push_back(std::make_pair(container[i + 1], container[i]));
        }
      }
    }

    mergeSort(pairs, 0, pairs.size() - 1);

    return pairs;
  }

  static void mergeSort(PairContainer &container, size_t left, size_t right) {
    if (left < right) {
      size_t middle = (left + right) / 2;
      mergeSort(container, left, middle);
      mergeSort(container, middle + 1, right);
      merge(container, left, middle, right);
    }
  }

  static void merge(PairContainer &container, size_t left, size_t middle,
                    size_t right) {
    size_t i = left;
    size_t j = middle + 1;
    size_t k = left;

    PairContainer temp(container.size());

    while (i <= middle && j <= right) {
      if (container[i].first <= container[j].first) {
        temp[k] = container[i];
        i++;
      } else {
        temp[k] = container[j];
        j++;
      }
      k++;
    }

    while (i <= middle) {
      temp[k] = container[i];
      i++;
      k++;
    }

    while (j <= right) {
      temp[k] = container[j];
      j++;
      k++;
    }

    for (size_t l = left; l <= right; l++) {
      container[l] = temp[l];
    }
  }

  static typename ChainContainer::iterator findInsertPosition(ChainContainer &container, int value) {
    size_t low = 0;
    size_t high = container.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (container[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }

    typename ChainContainer::iterator it = container.begin();
    std::advance(it, low);

    return it;
  }

  static ChainContainer generateInsertionIndexes(size_t size) {
    ChainContainer indexes;
    int jacobsthalNumbers[size + 1];
    int lastJacobsthalNumber = 2;

    jacobsthalNumbers[0] = 0;
    jacobsthalNumbers[1] = 1;
    for (size_t i = 2; indexes.size() < size; i++) {
      
      jacobsthalNumbers[i] = jacobsthalNumbers[i - 1] + 2 * jacobsthalNumbers[i - 2];

      if (i != 2) {
        indexes.push_back(jacobsthalNumbers[i]);
      }

      for (int j = jacobsthalNumbers[i]; j > lastJacobsthalNumber; j--) {
        indexes.push_back(j);
      }

      lastJacobsthalNumber = jacobsthalNumbers[i];
    }

    return indexes;
  }

public:
  PmergeMe() {}

  PmergeMe(const PmergeMe &other) { *this = other; }

  PmergeMe &operator=(const PmergeMe &other) {
    (void)other;
    return *this;
  }

  ~PmergeMe() {}

  /**
   * @brief Sort the elements of a container using Merge Insert Sort
   *
   * @param container the container of elements
   * @return the time it took to sort the container in microseconds
   */
  static double sort(ChainContainer &container) {
    clock_t start = clock();

    int last = -1;

    if (container.size() % 2 != 0) {
      last = container[container.size() - 1];
    }

    // We form pairs, sort the elements of each pair and sort the entire
    // container (based on the first value of the pair, otherwise known as `a`).
    PairContainer sortedPairs = makeSortedPairs(container);

    // Finally, we form a list from the `a`s, the "main-chain", into which we will proceed insertion from the `b`s.
    container.clear();
    container.push_back(sortedPairs[0].second);
    for (typename PairContainer::const_iterator it = sortedPairs.begin(); it != sortedPairs.end(); ++it) {
      container.push_back(it->first);
    }

    ChainContainer insertionIndexes = generateInsertionIndexes(sortedPairs.size());

    for (size_t i = 0; i < insertionIndexes.size(); i++) {
      if (size_t(insertionIndexes[i]) >= sortedPairs.size()) {
        break;
      }

      typename PairContainer::const_iterator it = sortedPairs.begin();
      std::advance(it, insertionIndexes[i]);

      typename ChainContainer::iterator insertionPoint = findInsertPosition(container, it->second);
      container.insert(insertionPoint, it->second);
    }

    if (last != -1) {
      typename ChainContainer::iterator insertionPoint = findInsertPosition(container, last);
      container.insert(insertionPoint, last);
    }

    return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
  }
};
