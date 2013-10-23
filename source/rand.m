#include "rand.h"
#import <Security/SecRandom.h>


int RandomUnder(int topPlusOne)
{
    unsigned two31 = 1U << 31;
	unsigned maxUsable = (two31 / topPlusOne) * topPlusOne;
    uint32_t num;
    while(1) {
        SecRandomCopyBytes(kSecRandomDefault, sizeof(num), (uint8_t *)&num);
        if( num < maxUsable )
            return num % topPlusOne;
    }
}

int RandomInRange(int bottom, int top)
{
    int rangeSize = top - bottom;
    int zeroBased = RandomUnder(rangeSize);
    return zeroBased + bottom;
}

float RandomFloatInRange(float bottom, float top)
{
    float diff = top - bottom;
    return (((float) (arc4random() % ((unsigned)RAND_MAX + 1)) / RAND_MAX) * diff) + bottom;
}