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
  unsigned char* vm = (unsigned char*) 0xb8000;
  const char* c = "0123456789abcdef";
  int addr = (int) (&vm);
  for (int i = 0; i < 8; i++) {
    vm[2000 + (8 - i) * 2] = c[addr % 16];
    addr /= 10;
  }
  printf("Hello world!");
  for (int i = 0; ; ++i) {
    char s[2] = {'0' + (f(i) % 10), 0};
    printf(s);
  }
}

