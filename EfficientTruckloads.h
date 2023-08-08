#ifndef EFFECIENTTRUCKLOADS
#define EFFECIENTTRUCKLOADS

#include <vector>
#include <map>

class EfficientTruckloads{
    private:
        int memo[100][100] = {0};
        int tester = 0;
    public:
        EfficientTruckloads();
        int numTrucks(int numCrates, int loadSize);
};

#endif