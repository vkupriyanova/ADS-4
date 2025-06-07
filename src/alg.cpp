// Copyright 2021 NNTU-CS
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
  int countt = 0;
  int leftt = 0, rightt = len -1;
  while (leftt < rightt) {
    int summa;
    summa = arr[leftt] + arr[rightt];
    if (summa == value) {
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
  int countt = 0;
  for (int i = 0; i < len - 1; ++i) {
    int mark = value - arr[i];
    int leftt = i + 1, rightt = len - 1;
    while (leftt <= rightt) {
      int midPos = leftt + (rightt - leftt)/2;
      if (arr[midPos] == mark) {
        int Temp = midPos;
        while (Temp >= leftt && arr[Temp] == mark) {
          ++countt;
          --Temp;
        }
        Temp = midPos + 1;
        while (Temp <= rightt && arr[Temp] == mark) {
          ++countt;
          ++Temp;
        }
        break;
      } else if (arr[midPos] < mark) {
        leftt = midPos + 1;
      } else {
        rightt = midPos - 1;
      }
    }
  }
  return countt;
}
