/**
 *   @file NSDate+CCFExtensions.m
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2011-07-14 08:23:10
 *   @version 1.0
 *
 *   @note Copyright 2011 Cocoa Factory, LLC.  All rights reserved
 */


#import "NSDate+CCFExtensions.h"

@implementation NSDate(CCFExtensions)

- (NSDate *)dateByAddingRandomOffset:(NSInteger)maxOffset before:(BOOL)beforeFlag {
    u_int32_t dayOffset = arc4random_uniform((u_int32_t)maxOffset);
    u_int32_t hour = arc4random_uniform(23);
    u_int32_t minute = arc4random_uniform(59);
    u_int32_t second = arc4random_uniform(59);
    
    NSCalendar *gregorian = [[NSCalendar alloc] initWithCalendarIdentifier:NSGregorianCalendar];
    NSDateComponents *components = [[NSDateComponents alloc] init];
    components.day = dayOffset * (beforeFlag)?-1:1;
    components.hour = hour;
    components.minute = minute;
    components.second = second;
    
    NSDate *date = [gregorian dateByAddingComponents:components toDate:self options:0];
    return date;
}

- (BOOL)isAfterDate:(NSDate *)otherDate
{
    return [self compare:otherDate] == NSOrderedDescending;
}

- (BOOL)isBeforeDate:(NSDate *)otherDate
{
    return [self compare:otherDate] == NSOrderedAscending;
}

- (NSDate *)dateByAdjustingToMidnight;
{
    unsigned unitFlags = NSHourCalendarUnit | NSMinuteCalendarUnit | NSSecondCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit | NSYearCalendarUnit;
    NSDateComponents *components = [[NSCalendar currentCalendar] components:unitFlags fromDate:self];
    [components setHour:0];
    [components setMinute:0];
    [components setSecond:0];
    NSDate *adjustedDate = [[NSCalendar currentCalendar] dateFromComponents:components];
    return adjustedDate;
}

- (NSDate *)datebyAdjustingToEndOfDay;
{
    unsigned unitFlags = NSHourCalendarUnit | NSMinuteCalendarUnit | NSSecondCalendarUnit | NSMonthCalendarUnit | NSDayCalendarUnit | NSYearCalendarUnit;
    NSDateComponents *components = [[NSCalendar currentCalendar] components:unitFlags fromDate:self];
    [components setHour:23];
    [components setMinute:59];
    [components setSecond:59];
    NSDate *adjustedDate = [[NSCalendar currentCalendar] dateFromComponents:components];
    return adjustedDate;
}

- (NSDate *)dateByAddingDays:(NSInteger)daysToAdd;
{
    NSDateComponents *components = [[NSDateComponents alloc] init];
    [components setDay:daysToAdd];
    
    NSCalendar *gregorian = [[NSCalendar alloc] initWithCalendarIdentifier:NSGregorianCalendar];
    NSDate *newDate = [gregorian dateByAddingComponents:components toDate:self options:0];
    
    return newDate;
}

- (NSDate *)dateByAdjustingToPreviousDay;
{
    return [self dateByAddingDays:-1];
}

- (NSDate *)dateByAdjustingToNextDay;
{
    return [self dateByAddingDays:1];
}

- (NSDate *)dateByAdjustingToStartOfPreviousDay;
{
    NSDate *yesterday = [self dateByAdjustingToPreviousDay];
    return [yesterday dateByAdjustingToMidnight];
}

- (NSDate *)dateByAdjustingToEndOfNextDay;
{
    NSDate *tomorrow = [self dateByAddingDays:1];
    return [tomorrow datebyAdjustingToEndOfDay];
}

@end
