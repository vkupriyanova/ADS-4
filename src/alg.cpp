// Copyright 2021 NNTU-CS
#include <unordered_map>
#include <algorithm>
int countPairs1(int *arr, int len, int value) {
  int countt = 0;
  for (int i = 0; i < len - 1; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        ++countt;
      }
    }
  }
  return countt;
}
int countPairs2(int *arr, int len, int value) {
  std::sort(arr, arr + len);
  int countt = 0;
  int leftt = 0, rightt = len -1;
  while (leftt < rightt) {
    int summa;
    summa = arr[leftt] + arr[rightt];
    if (summa == value) {
      if (arr[leftt] == arr[rightt]) {
        int n = rightt - leftt +1;
        countt += (n * (n - 1)) / 2;
        break;
      }
      int lefttCountt = 1;
      while (leftt + 1 < rightt && arr[leftt] == arr[leftt + 1]) {
        ++lefttCountt;
        ++leftt;
      }
      int righttCountt = 1;
      while (rightt - 1 > leftt && arr[rightt] == arr[rightt-1]) {
        ++righttCountt;
        --rightt;
      }
      countt += lefttCountt * righttCountt;
      ++leftt;
      --rightt;
    } else if (summa < value) {
      ++leftt;
    } else {
      --rightt;
    }
  }
  return countt;
}
int countPairs3(int *arr, int len, int value) {
  std::unordered_map<int, int> freq;
  int countt = 0;
  for (int i = 0; i < len; ++i) {
    int complementt = value - arr[i];
    if (freq.find(complementt) != freq.end()) {
      countt += freq[complementt];
    }
    ++freq[arr[i]];
  }
  return countt;
}
