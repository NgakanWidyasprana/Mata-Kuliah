#include <stdio.h>
#include <time.h>
#include <unistd.h>
#define TIME 1000000000.0

int max(int a, int b) { return (a > b) ? a : b; }


int knapSack(int W, int wt[], int val[], int n)
{
	if (n == 0 || W == 0)
		return 0;
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);
	else
		return max(
			val[n - 1]
				+ knapSack(W - wt[n - 1],
						wt, val, n - 1),
			knapSack(W, wt, val, n - 1));
}

int main()
{
    //  Counter Time Start
        struct timespec mulai,akhir;
        clock_gettime(CLOCK_REALTIME,&mulai);

        int val[] = {	20,20,20,20,10,20,30,30,30,20, 
						30,30,10,20,10,20,10,20,10,20, 
						10,10,30,20,30,30,10,20,30,30	};

        int wt[]  = {   45,92,20,53,10,60,94,55,25,15, 
                        50,62,70,63,91,80,67,40,75,66,
                        70,48,68,75,49,69,90,81,40,90   };
        int W = 500;
        int n = sizeof(val) / sizeof(val[0]);
        printf("# Optimal Solution : %d", knapSack(W, wt, val, n));

    //  Counter Time End
        sleep(3);
        clock_gettime(CLOCK_REALTIME,&akhir);

    //  Running Time
        double running=(akhir.tv_sec-mulai.tv_sec)+(akhir.tv_nsec-mulai.tv_nsec)/TIME;
        printf ("\n# Running Test : %f s",running);

	return 0;
}