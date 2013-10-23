#import "NSCalendar+CCFExtensions.h"

@implementation NSCalendar (CCFExtensions)

- (BOOL)ojf_isDate:(NSDate *)date1 equalToDate:(NSDate *)date2 withGranularity:(NSCalendarUnit)granularity
{
    if ([date1 isEqualToDate:date2]) {
        return YES;
    }
    
    int componentFlags = [self ojf_componentFlagsWithGranularity:granularity];
    
    date1 = [self ojf_dateFromDate:date1 withComponentFlags:componentFlags];
    date2 = [self ojf_dateFromDate:date2 withComponentFlags:componentFlags];
    
    return [date1 isEqualToDate:date2];
}

- (int)ojf_componentFlagsWithGranularity:(NSCalendarUnit)granularity
{
    int componentFlags = 0;
    
    for (int i = 1<<1 ; i <= granularity ; i = i<<1) {
        componentFlags = componentFlags | i;
    }
    
    return componentFlags;
}

- (NSDate *)ojf_dateFromDate:(NSDate *)date withComponentFlags:(int)componentFlags
{
    NSDateComponents *components = [self components:componentFlags fromDate:date];
    
    return [self dateFromComponents:components];
}

@end
