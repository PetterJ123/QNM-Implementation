#ifndef DISK1_HPP
#define DISK1_HPP
#include <queue>
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

class Disk {
	public:
		Disk(float pv)
		{
			this->p_value = pv;
			srand((unsigned) time(0));
			
			// Puts the data at a random place at every run
			this->storage[(rand() % 100)] = 44.4123;
		}

		float searchData(float data)
		{
			// Search for data asked for
			for(int i=0; i<asize; i++)
			{
				if(this->storage[i] == data)
				{
					std::cout << "Here it is! At index " << i << ", and the value is " << this->storage[i] << "\n";
					this->cache = this->storage[i];
				}
			}
			return this->cache;
		}

	private:
		std::queue<float> q;
		float p_value;
		float storage[100] = {0};
		size_t asize = sizeof(this->storage) / sizeof(this->storage[0]);
		float cache = 0.0;
};

#endif