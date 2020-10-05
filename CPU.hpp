#ifndef CPU_HPP
#define CPU_HPP
#include <queue>
#include "Disk.hpp"
#include <chrono>
#include <thread>

class CPU {
	public:
		CPU(){ }
		void HandleFetchData(float rqData)
		{
			this->q.push(rqData);
			std::this_thread::sleep_for(std::chrono::milliseconds(this->p_value));
			float ans = d1.searchData(this->q.front());
		}

	private:
		std::queue <float> q;
		size_t p_value = 39.4;
		Disk d1 = Disk(77.1);
		Disk d2 = Disk(123.8);
		Disk d3 = Disk(80.4);
		Disk d4 = Disk(235);
};

#endif