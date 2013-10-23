#ifdef __OBJC__

#import "time.h"

#define NSEC_CONVERT(x) (int64_t)(x * NSEC_PER_SEC)

const int64_t DISPATCH_DELAY_1_SEC = NSEC_CONVERT(1);
const int64_t DISPATCH_DELAY_2_SEC = NSEC_CONVERT(2);
const int64_t DISPATCH_DELAY_1_2_SEC = NSEC_CONVERT(0.5);
const int64_t DISPATCH_DELAY_2_10_SEC = NSEC_CONVERT(0.2);
const int64_t DISPATCH_DELAY_3_4_SEC = NSEC_CONVERT(0.75);
const int64_t DISPATCH_DELAY_3_10_SEC = NSEC_CONVERT(0.30);
const int64_t DISPATCH_DELAY_1_10_SEC = NSEC_CONVERT(0.10);
const int64_t DISPATCH_DELAY_6_10_SEC = NSEC_CONVERT(0.60);

dispatch_time_t ccf_dispatch_time(int64_t nanosec)
{
    return dispatch_time(DISPATCH_TIME_NOW, nanosec);
}

void ccf_gcd_delay_main_queue(NSTimeInterval delay, dispatch_block_t block)
{
    int64_t nsec_delay = (int64_t)(delay * NSEC_PER_SEC);
    dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, nsec_delay);
    dispatch_after(popTime, dispatch_get_main_queue(), block);
}

void ccf_gcd_delay_main_queue_1_sec(dispatch_block_t block)
{
    dispatch_after(ccf_dispatch_time(DISPATCH_DELAY_1_SEC), dispatch_get_main_queue(), block);
}

void ccf_gcd_delay_main_queue_2_sec(dispatch_block_t block)
{
    dispatch_after(ccf_dispatch_time(DISPATCH_DELAY_2_SEC), dispatch_get_main_queue(), block);
}

void ccf_gcd_delay_main_queue_1_2_sec(dispatch_block_t block)
{
    dispatch_after(ccf_dispatch_time(DISPATCH_DELAY_1_2_SEC), dispatch_get_main_queue(), block);
}

void ccf_gcd_delay_main_queue_2_10_sec(dispatch_block_t block)
{
    dispatch_after(ccf_dispatch_time(DISPATCH_DELAY_2_10_SEC), dispatch_get_main_queue(), block);
}

void ccf_gcd_delay_main_queue_3_4_sec(dispatch_block_t block)
{
    dispatch_after(ccf_dispatch_time(DISPATCH_DELAY_3_4_SEC), dispatch_get_main_queue(), block);
}

void ccf_gcd_delay_main_queue_3_10_sec(dispatch_block_t block)
{
    dispatch_after(ccf_dispatch_time(DISPATCH_DELAY_3_10_SEC), dispatch_get_main_queue(), block);
}

void ccf_gcd_delay_main_queue_1_10_sec(dispatch_block_t block)
{
    dispatch_after(ccf_dispatch_time(DISPATCH_DELAY_1_10_SEC), dispatch_get_main_queue(), block);
}

void ccf_gcd_delay_main_queue_6_10_sec(dispatch_block_t block)
{
    dispatch_after(ccf_dispatch_time(DISPATCH_DELAY_6_10_SEC), dispatch_get_main_queue(), block);
}

#endif