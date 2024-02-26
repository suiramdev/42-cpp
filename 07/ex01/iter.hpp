#pragma once

template <typename T, typename Func> void iter(T *arr, int len, Func f) {
  for (int i = 0; i < len; i++) {
    f(arr[i]);
  }
}
