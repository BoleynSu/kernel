#include "vga.h"

void kernel_init() {
}

void print_str(const char* str) {
  unsigned char* vm = (unsigned char*) 0xb8000;
  for (int i = 0; str[i]; ++i) {
    set_color(i % 15 + 1,VGA_COLOR_BLACK);
    draw_next(str[i]);
  }
}

void print_int(int x) {
  char buffer[12];
  int cur = 0;
  if (x < 0) {
    buffer[cur++] = '-';
    x = -x;
  }
  do {
    buffer[cur++] = '0' + x % 10;
    x /= 10;
  } while(x != 0);
  buffer[cur++] = 0;
  print_str(buffer);
}

int f(int x) {
  if (x <= 1) return x;
  else return f(x - 1) + f(x - 2);
}

void kernel_main(void* ptr, int magic) {
  kernel_init();
  print_str("Hello world!");
  for (int i = 0; i < 1000000000; ++i) {
    print_str(" ");
    print_int(f(i % 30));
  }
}

