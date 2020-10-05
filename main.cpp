#include <iostream>
#include <queue>
#include <string>
#include "CPU.hpp"

int main(int argc, char *argv[]) {
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	CPU cpu = CPU();
	float reqData = 44.4123;
	// Take in a filename to download
	cpu.HandleFetchData(reqData);

	// Place file-download-request in a queue for the CPU

	// After an specific amount of time the CPU will handele the request

	// After the request is handled, ask one disk for the data
		// If the disk don't have the data, return 0 (or something)
		// The disk will ask the next disk for the data until the data is found
	
	// After the CPU have recieved the data send it back to the user (print it out)
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "\n";
	return 0;
}