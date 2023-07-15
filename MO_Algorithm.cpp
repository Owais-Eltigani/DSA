#include <bits/stdc++.h>

int len;
struct Query {

  int l, r, idx;
};

bool compare(Query q1, Query q2) {

  if ((q1.l) / len != (q2.l) / len) {
    return q1.l / len < q2.l / len;
  } else {
    return q1.r < q2.r;
  }
}

int main(int argc, char const *argv[]) {
  std::vector<int> arr{12, 9, -17, 39};

  len = sqrt(arr.size()) + 1;

  int querySize;

  std::cin >> querySize;
  Query queries[querySize];

  int l, r;

  for (size_t i = 0; i < querySize; i++) {

    std::cin >> l >> r;
    l--, r--;

    queries[i].l = l;
    queries[i].r = r;
    queries[i].idx = i;
  }

  std::sort(queries, queries + querySize, compare);

  std::vector<int> ans(querySize);

  int currl = 0, currR = 0, curAns = 0;

  for (size_t i = 0; i < querySize; i++) {

    l = queries[i].l;
    r = queries[i].r;

    while (currl > l) {
      currl--;
      curAns += arr[currl];
    }

    while (currR > r) {
      currR--;
      curAns += arr[currR];
    }

    while (currl < l) {
      curAns -= arr[currl];
      currR++;
    }

    while (currR < r) {
      curAns -= arr[currR];
      currR--;
    }

    ans[queries[i].idx] = curAns;
  }

  for (size_t i = 0; i < querySize; i++) {
    std::cout << "sum of " << queries[i].l + 1 << " to " << queries[i].r + 1
              << " -> " << ans[i] << "\n";
  }

  return 0;
}
