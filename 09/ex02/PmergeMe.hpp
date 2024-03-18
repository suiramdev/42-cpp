#pragma once

#include <algorithm>
#include <memory>
#include <utility>
#include <iterator>

template <template <typename T, typename = std::allocator<T> > class Container>
class PmergeMe {
private:
  static Container<std::pair<int, int> > makePairs(const Container<int> &container) {
    Container<std::pair<int, int> > pairs;
    for (size_t i = 0; i < container.size(); i += 2) {
      if (i + 1 < container.size()) {
        pairs.push_back(std::make_pair(container[i], container[i + 1]));
      }
    }
    return pairs;
  }

  static void sortPairs(Container<std::pair<int, int> > &pairs) {
    for (typename Container<std::pair<int, int> >::iterator it = pairs.begin();
       it != pairs.end(); ++it) {
      if (it->first < it->second) {
        std::swap(it->first, it->second);
      }
    }
  }

  static void mergeSort(Container<std::pair<int, int> > &container, size_t left,
                        size_t right) {
    if (left < right) {
      size_t middle = (left + right) / 2;
      mergeSort(container, left, middle);
      mergeSort(container, middle + 1, right);
      merge(container, left, middle, right);
    }
  }

  static void merge(Container<std::pair<int, int> > &container, size_t left,
                    size_t middle, size_t right) {
    size_t i = left;
    size_t j = middle + 1;
    size_t k = left;

    Container<std::pair<int, int> > temp(container.size());

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

public:
  static Container<int> sort(Container<int> container) {
    if (container.size() <= 1) {
      return container;
    }

    // Difference between consecutive Jacobsthal numbers up to 64
    static const u_int64_t jacobsthal_diff[] = {
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

    // Make pairs, sort the elements of each pair and sort the entire container
    Container<std::pair<int, int> > pairs = makePairs(container);
    sortPairs(pairs);
    mergeSort(pairs, 0, pairs.size() - 1);

    int last = -1;
    if (container.size() % 2 != 0) {
      last = container.back();
    }

    // Extract the sorted elements from the pairs
    // and put them back into the original container
    container.clear();
    // The first element of the first pair is always the smallest
    // so we can add it to the container right away
    container.push_back(pairs[0].second);
    for (typename Container<std::pair<int, int> >::const_iterator it = pairs.begin();
       it != pairs.end(); ++it) {
      container.push_back(it->first);
    }
    pairs.erase(pairs.begin());

    typename Container<std::pair<int, int> >::iterator limitIt = pairs.begin();

    // Insertion from Jacobsthal numbers
    for (size_t i = 0; i < 64; i++) {
      u_int64_t diff = jacobsthal_diff[i];
      if (diff > static_cast<size_t>(std::distance(limitIt, pairs.end()))) break;
      typename Container<std::pair<int, int> >::iterator it = limitIt;
      std::advance(it, diff);

      do {
        typename Container<int>::iterator insertIt = std::upper_bound(container.begin(), container.end(), it->second);
        container.insert(insertIt, it->second);
        --it;
      } while (it != limitIt);

      std::advance(limitIt, diff);
    }

    // Insert the last elements left
    for (typename Container<std::pair<int, int> >::iterator it = limitIt;
       it != pairs.end(); ++it) {
      typename Container<int>::iterator insertIt = std::upper_bound(container.begin(), container.end(), it->second);
      container.insert(insertIt, it->second);
    }

    if (last != -1) {
      typename Container<int>::iterator insertIt = std::upper_bound(container.begin(), container.end(), last);
      container.insert(insertIt, last);
    }

    // The container is now sorted and we can return it
    return container;
  }
};
