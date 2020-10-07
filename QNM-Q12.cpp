#include <iostream>

struct Node
{
    double D;           //Service demand
    double Rprime[200]; //Residence time
    double Q[200];      //Queue length
    double U;           //Utilization
};

int main(int argc, char *argv[]){
   
    Node nodes[5];
    /*nodes[0].D = 0.0394;
    nodes[1].D = 0.0771;
    nodes[2].D = 0.1238;
    nodes[3].D = 0.0804;
    nodes[4].D = 0.235;*/

	nodes[0].D = 0.0394;
	nodes[1].D = 0.0771;
	nodes[2].D = 0.1238;
	nodes[3].D = 0.0804;
	nodes[4].D = 0.235;
	/*nodes[5].D = 0.00329;
	nodes[6].D = 0.00984;
	nodes[7].D = 0.01287;
	nodes[8].D = 0.00758;
	nodes[9].D = 0.0219;*/

    double X[200];                  //Throughput
    double XSum[200] = { 0 };       //For total throughput
    int m = 5;                      // # of queuing node
    int n = 100;                    // # of customers
    double Z = 0.3;                 // think time
    double R0[200] = { 0 };         //System average response time.


    for (int j = 0; j < m; j++)
    {
        nodes[j].Q[0] = 0;
        
        std::cout << "Node: " << j << "\n===========================\n";

        for (int i = 1; i < n; i++) {
            //Residence, Response times.
            nodes[j].Rprime[i] = nodes[j].D * (1.0 + nodes[j].Q[i - 1]);
            R0[i] += nodes[j].Rprime[i];

            //Throughput and queue length.
            X[i] = i / (Z + nodes[j].Rprime[i]);
            XSum[i] += X[i];
            nodes[j].Q[i] = X[i] * nodes[j].Rprime[i];

            //Open model. (Are these necessary?)
            double Ui = X[i] * nodes[j].D * 100;
            double Ri = nodes[j].D / (1.0 - Ui * 0.01);

            //Print out.
            std::cout << "i=" << i << "\tUi=" << (int)Ui << "\tRprime[i]=" 
                << nodes[j].Rprime[i] << "\tRi= " << Ri
                << "\tQ[i]=" << nodes[j].Q[i] 
                << "\n===========================\n";
        }
         
    }

    std::cout << "Throughput for the system" << "\n";

    for (int i = 1; i < n; i++)
    {
        std::cout << "i=" << i << "\tX[n]=" << XSum[i]  << "\tR0[n]=" << R0[i] << "\n";
    }
    

    return 0;
}

