#include "main.h"
#define SLEEP_TIME 3

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "Wrong arguments number" << std::endl;
    return 0;
  }
  int n = atoi(argv[1]);
  int m = atoi(argv[2]);

  if (n <= 0 && m <= 0) {
    std::cerr << "Wrong arguments" << std::endl;
    return 0;
  }

  useconds_t sleepTime = (unsigned long long)(m * n * sizeof(int)) / 10 ; // 10 mbit per second in usec
  Sender sender;
  Generator generator;

  while (true) {
    auto matrix = generator.generate_matrix(n, m);
    sender.sendMatrix(matrix);
    // sleep(SLEEP_TIME);
    usleep(sleepTime);
  }
}
