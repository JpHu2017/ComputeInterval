#include <iostream>
#include <sys/time.h>

using namespace std;

/**
  * 计算两个时间的间隔，得到时间差(us,微妙)
  * @param struct timeval* resule 返回计算出来的时间
  * @param struct timeval* x 需要计算的前一个时间
  * @param struct timeval* y 需要计算的后一个时间
  * return -1 failure ,0 success
**/
int timeval_subtract(struct timeval* result, struct timeval* x, struct timeval* y)
{
    int nsec;

    if ( x->tv_sec>y->tv_sec )
        return -1;

    if ( (x->tv_sec==y->tv_sec) && (x->tv_usec>y->tv_usec) )
        return -1;

    result->tv_sec = ( y->tv_sec-x->tv_sec );
    result->tv_usec = ( y->tv_usec-x->tv_usec );

    if (result->tv_usec<0)
    {
        result->tv_sec--;
        result->tv_usec+=1000000;
    }

    return 0;
}


int main() {
    timeval start_time, end_time,diff_time;
    // start time
    gettimeofday(&start_time, 0);

    cout << "Hello, World!" << endl;

    // end time
    gettimeofday(&end_time, 0);
    // compute the interval
    timeval_subtract(&diff_time,&start_time,&end_time);

    cout <<" Spend " << diff_time.tv_usec/1000 << " ms" << endl;
    return 0;
}
