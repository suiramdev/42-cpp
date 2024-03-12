#pragma once

#include <cmath>
#include <ctime>
#include <memory>
#include <utility>
#include <iostream>

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
      } else {
        pairs.push_back(std::make_pair(container[i], -1)); // NOTE: That's a weird trick lol
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

  static typename ChainContainer::const_iterator findInsertPosition(const ChainContainer &container, int value) {
    size_t low = 0;
    size_t high = container.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (container[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }

    return container.begin() + low;
  }

  static int jacobsthal(int n) {
    return static_cast<int>((std::pow(2, n) + std::pow(-1, n - 1)) / 3);
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

    // We form pairs, sort the elements of each pair and sort the entire
    // container (based on the first value of the pair, otherwise known as `a`).
    PairContainer sortedPairs = makeSortedPairs(container);

    // Finally, we form a list from the `a`s, the "main-chain", into which we will proceed insertion from the `b`s.
    ChainContainer mainChain;
    for (typename PairContainer::const_iterator it = sortedPairs.begin(); it != sortedPairs.end(); ++it) {
      if (it == sortedPairs.begin()) {
        mainChain.push_back(it->second);
      }
      mainChain.push_back(it->first);
    }

    static const std::uint_least64_t jacobsthal_diff[] = {
        2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
        2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
        1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
        178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
        11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
        366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
        11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
        375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
        6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
        96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
        1537228672809129216u, 3074457345618258432u, 6148914691236516864u
    };

    for (size_t i = 0; ; i++) {
      std::uint_least64_t dist = jacobsthal_diff[i];
      if (dist >= sortedPairs.size()) break;

      typename PairContainer::const_iterator it = sortedPairs.begin();
      std::advance(it, dist);

      if (it->second == -1) {
        continue; // NOTE: 🤡
      }

      typename ChainContainer::const_iterator insertionPoint = findInsertPosition(mainChain, it->second);
      mainChain.insert(insertionPoint, it->second);
    }

    // We replace the container passed in parameter with our sorted list.
    container = mainChain;

    return static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
  }
};
