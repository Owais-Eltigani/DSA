#include <bits/stdc++.h>

void preprocessBlocks(std::vector<int> &arr, std::vector<int> &blocks) {

  int len = blocks.size();

  for (size_t i = 0; i < arr.size(); i++) {

    blocks[i / len] += arr[i];
  }
}

int main(int argc, char const *argv[]) {

  //  array of values
  std::vector<int> arr{5, 3, -2, 1, 9};

  // computting the size of blocks
  int len = sqrt(arr.size()) + 1; //?  + 1 for non perfect sqrt numbers {5 , 23}

  //  for saving sum of each block in arr
  std::vector<int> blocks(len);

  // calculating the sum of each block
  preprocessBlocks(arr, blocks);

  int query;

  std::cout << "enter number of  querys you want: ";
  std::cin >> query;

  while (query--) {

    // query parameters [left, right]
    int l, r, sum = 0;

    std::cout << "left and right parameters: ";
    std::cin >> l >> r;

    // index -1
    l--, r--;

    //   taking the pre-calculated sum from blocks
    for (size_t i = l; i < r;) {

      // if the l,r are a perfect query [left, right]
      if (i % len == 0 && i + len <= r) {

        sum += blocks[i / len];
        i += len;

      }

      // the l,r not perfect query
      else {

        sum += arr[i];
        i++;
      }
    }

    std::cout << sum << "\n";
  }

  return 0;
}
