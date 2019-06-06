void printf(const char* str) {
  static int cur = 0;
  unsigned char* vm = (unsigned char*) 0xb8000;
  for (int i = 0; str[i]; ++i) {
    vm[cur] = str[i];
    cur += 2;
    if (cur == 1000) cur = 0;
  }
  cur += 2;
  if (cur == 1000) cur = 0;
}

int f(int x) {
  if (x <= 1) return x;
  else return f(x - 1) + f(x - 2);
}

void kernel_main() {
  printf("Hello world!");
  for (int i = 0; ; ++i) {
    char s[2] = {'0' + (f(i) % 10), 0};
    printf(s);
  }
}
