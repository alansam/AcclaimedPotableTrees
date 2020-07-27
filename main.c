#include <stdio.h>
#include <stdint.h>
#include <stdalign.h>
#include <inttypes.h>

typedef struct pair pair;
struct pair {
  alignas(16)
  int32_t first;
  //alignas(8)
  int32_t second;
};

pair f1(void) {
  pair pr = { .first = 10, .second = -5, };
  return pr;
}
void f2(pair * pp) {
  pp->first = 42;
  pp->second = -904;
}

inline
static
int f3(int x) {
  return x * x;
}

int main(void) {

  pair rp;
  rp = f1();
  printf("%4" PRIdPTR " %4" PRId32 " %4" PRId32 "\n",
          sizeof(rp), rp.first, rp.second);
  f2(&rp);
  printf("%4" PRIdPTR " %4" PRId32 " %4" PRId32 "\n",
          sizeof(&rp), rp.first, rp.second);
  return 0;
}
