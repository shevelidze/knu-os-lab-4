#include <sys/mman.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <sstream>

int main() {
  int process_pid;
  unsigned long long variable_address;

  std::cout << "Enter the process PID ~> ";
  std::cin >> process_pid;
  std::cout << "Enter the address of the variable ~> ";
  std::cin >> std::hex >> variable_address;

  int value;
  std::ifstream mem = std::ifstream("/proc/" + std::to_string(process_pid) + "/mem", std::ios::binary);

  while (true) {
    ptrace(PTRACE_ATTACH, process_pid, 0);
    waitpid(process_pid, 0, 0);

    mem.seekg(variable_address);
    mem.read((char *)&value, sizeof(int));

    std::cout << "Read value: " << value << "\n";

    ptrace(PTRACE_DETACH, process_pid, 0, 0);
  }

  mem.close();
  return 0;
}
