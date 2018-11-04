#include <stdio.h>
typedef struct Node {
  int address, data, next;
} Node;
void reverse(Node arr[], int start, int length) {
  for (int i = 0; i < length / 2; i++) {
    Node tmp = arr[i + start];
    arr[i + start] = arr[length - i - 1 + start];
    arr[length - i - 1 + start] = tmp;
  }
}
int main() {
  int head, N, K, length = 0;
  scanf("%d %d %d", &head, &N, &K);
  Node unSorted[(int)1e5], sorted[N];
  for (int i = 0; i < N; i++) {
    int address;
    scanf("%d", &address);
    unSorted[address].address = address;
    scanf("%d %d", &unSorted[address].data, &unSorted[address].next);
  }
  for (int current = head; current != -1; current = unSorted[current].next)
    sorted[length++] = unSorted[current];
  for (int i = 0; i + K - 1 < length; i += K) reverse(sorted, i, K);
  for (int i = 0; i < length; i++) {
    sorted[i].next = i == length - 1 ? -1 : sorted[i + 1].address;  // 修正 next
    printf(sorted[i].next == -1 ? "%05d %d -1\n" : "%05d %d %05d\n",
           sorted[i].address, sorted[i].data, sorted[i].next);  // 打印当前节点
  }
  return 0;
}