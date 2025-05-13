// Copyright 2021 NNTU-CS
int binarySearch(int len, int member_couple, int* arr, int low) {
  int high = len - 1;
  int middle;
  while (low <= high) {
    middle = (low + high) / 2;
    if (member_couple == arr[middle]) {
      return middle;
    } else if (arr[middle] > member_couple) {
      high = middle - 1;
    } else {
      low = middle + 1;
    }
  }
  return -1;
}

int countPairs1(int* arr, int len, int value) {
  int kol = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        ++kol;
      }
    }
  }
  return kol;
}

int countPairs2(int* arr, int len, int value) {
  int left = 0;
  int right = len - 1;
  int pairs = 0;

  while (left < right) {
    int s = arr[left] + arr[right];
    if (s < value) {
      ++left;
    } else if (s > value) {
      --right;
    } else {
      if (arr[left] != arr[right]) {
        int lcnt = 1;
        int rcnt = 1;
        while (left + lcnt < right && arr[left + lcnt] == arr[left]) {
          ++lcnt;
        }
        while (left + lcnt - 1 < right - rcnt &&
               arr[right - rcnt] == arr[right]) {
          ++rcnt;
        }
        pairs += lcnt * rcnt;
        left += lcnt;
        right -= rcnt;
      } else {
        int k = right - left + 1;
        pairs += k * (k - 1) / 2;
        break;
      }
    }
  }
  return pairs;
}

int countPairs3(int* arr, int len, int value) {
  int count_couple = 0;
  for (int i = 0; i < len; ++i) {
    int middle;
    int member_couple = value - arr[i];
    if (member_couple < arr[i]) {
      break;
    }
    middle = binarySearch(len, member_couple, arr, i + 1);
    if (middle == -1) {
      continue;
    } else {
      ++count_couple;
      int temp_middle_increase = middle;
      int temp_middle_decrease = middle;
      while (temp_middle_increase + 1 < len &&
             arr[temp_middle_increase + 1] == member_couple) {
        ++temp_middle_increase;
        ++count_couple;
      }
      while (temp_middle_decrease - 1 > i &&
             arr[temp_middle_decrease - 1] == member_couple) {
        --temp_middle_decrease;
        ++count_couple;
      }
    }
  }
  return count_couple;
}
