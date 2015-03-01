#ifndef _C_DURATION_TIMER_
#define _C_DURATION_TIMER_

#include <time.h>
#include <utils/Log.h>

class DurationTimer {
public:
    DurationTimer() {}
    ~DurationTimer() {}
    void start();
    void stop();
    long long durationUsecs() const;
    static long long subtractTimevals(const struct timeval* ptv1,
        const struct timeval* ptv2);
    static void addToTimeval(struct timeval* ptv, long usec);
private:
    struct timeval  mStartWhen;
    struct timeval  mStopWhen;
};

#endif
