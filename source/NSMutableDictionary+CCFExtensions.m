/**
 *   @file NSDictionary+CCFExtensions.m
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2011-07-13 11:11:07
 *   @version 1.0
 *
 *   @note Copyright 2011 Cocoa Factory, LLC.  All rights reserved
 */

#import "NSMutableDictionary+CCFExtensions.h"

#if !defined(TARGET_OS_IPHONE) || !TARGET_OS_IPHONE
#define CGPointValue pointValue
#define CGRectValue rectValue
#define CGSizeValue sizeValue

//    #define CGPointEqualToPoint NSEqualPoints
//    #define CGSizeEqualToSize NSEqualSizes
#define CGRectEqualToRect NSEqualRects
#else
#define NSStringFromPoint NSStringFromCGPoint
#define NSStringFromRect NSStringFromCGRect
#define NSStringFromSize NSStringFromCGSize
#import <UIKit/UIGeometry.h>
#endif

@implementation NSMutableDictionary(CCFExtensions)

- (void)setObject:(id)anObject forKeys:(NSArray *)keys;
{
    for (NSString *key in keys)
        [self setObject:anObject forKey:key];
}

- (void)setFloatValue:(float)value forKey:(id)key;
{
    NSNumber *number = [[NSNumber alloc] initWithFloat:value];
    [self setObject:number forKey:key];
}

- (void)setDoubleValue:(double)value forKey:(id)key;
{
    NSNumber *number = [[NSNumber alloc] initWithDouble:value];
    [self setObject:number forKey:key];
}

- (void)setIntValue:(int)value forKey:(id)key;
{
    NSNumber *number = [[NSNumber alloc] initWithInt:value];
    [self setObject:number forKey:key];
}

- (void)setUnsignedIntValue:(unsigned int)value forKey:(id)key;
{
    NSNumber *number = [[NSNumber alloc] initWithUnsignedInt:value];
    [self setObject:number forKey:key];
}

- (void)setIntegerValue:(NSInteger)value forKey:(id)key;
{
    NSNumber *number = [[NSNumber alloc] initWithInteger:value];
    [self setObject:number forKey:key];
}

- (void)setUnsignedIntegerValue:(NSUInteger)value forKey:(id)key;
{
    NSNumber *number = [[NSNumber alloc] initWithUnsignedInteger:value];
    [self setObject:number forKey:key];
}

- (void)setUnsignedLongLongValue:(unsigned long long)value forKey:(id)key;
{
    NSNumber *number = [[NSNumber alloc] initWithUnsignedLongLong:value];
    [self setObject:number forKey:key];
}

- (void)setBoolValue:(BOOL)value forKey:(id)key;
{
    NSNumber *number = [[NSNumber alloc] initWithBool:value];
    [self setObject:number forKey:key];
}

/*
- (void)setPointValue:(CGPoint)value forKey:(id)key;
{
    [self setObject:NSStringFromPoint(value) forKey:key];
}

- (void)setSizeValue:(CGSize)value forKey:(id)key;
{
    [self setObject:NSStringFromSize(value) forKey:key];
}

- (void)setRectValue:(CGRect)value forKey:(id)key;
{
    [self setObject:NSStringFromRect(value) forKey:key];
}
 */

// Set values with defaults

- (void)setObject:(id)object forKey:(id)key defaultObject:(id)defaultObject;
{
    if (!object || [object isEqual:defaultObject]) {
        [self removeObjectForKey:key];
        return;
    }
    
    [self setObject:object forKey:key];
}

- (void)setFloatValue:(float)value forKey:(id)key defaultValue:(float)defaultValue;
{
    if (value == defaultValue) {
        [self removeObjectForKey:key];
        return;
    }
    
    [self setFloatValue:value forKey:key];
}

- (void)setDoubleValue:(double)value forKey:(id)key defaultValue:(double)defaultValue;
{
    if (value == defaultValue) {
        [self removeObjectForKey:key];
        return;
    }
    
    [self setDoubleValue:value forKey:key];
}

- (void)setIntValue:(int)value forKey:(id)key defaultValue:(int)defaultValue;
{
    if (value == defaultValue) {
        [self removeObjectForKey:key];
        return;
    }
    
    [self setIntValue:value forKey:key];
}

- (void)setUnsignedIntValue:(unsigned int)value forKey:(id)key defaultValue:(unsigned int)defaultValue;
{
    if (value == defaultValue) {
        [self removeObjectForKey:key];
        return;
    }
    
    [self setUnsignedIntValue:value forKey:key];
}

- (void)setIntegerValue:(NSInteger)value forKey:(id)key defaultValue:(NSInteger)defaultValue;
{
    if (value == defaultValue) {
        [self removeObjectForKey:key];
        return;
    }
    
    [self setIntegerValue:value forKey:key];
}

- (void)setUnsignedIntegerValue:(NSUInteger)value forKey:(id)key defaultValue:(NSUInteger)defaultValue;
{
    if (value == defaultValue) {
        [self removeObjectForKey:key];
        return;
    }
    
    [self setUnsignedIntegerValue:value forKey:key];
}

- (void)setUnsignedLongLongValue:(unsigned long long)value forKey:(id)key defaultValue:(unsigned long long)defaultValue;
{
    if (value == defaultValue) {
        [self removeObjectForKey:key];
        return;
    }
    
    [self setUnsignedLongLongValue:value forKey:key];
}

- (void)setBoolValue:(BOOL)value forKey:(id)key defaultValue:(BOOL)defaultValue;
{
    if (value == defaultValue) {
        [self removeObjectForKey:key];
        return;
    }
    
    [self setBoolValue:value forKey:key];
}
/*
- (void)setPointValue:(CGPoint)value forKey:(id)key defaultValue:(CGPoint)defaultValue;
{
    if (CGPointEqualToPoint(value, defaultValue)) {
        [self removeObjectForKey:key];
        return;
    }
    
    [self setPointValue:value forKey:key];
}

- (void)setSizeValue:(CGSize)value forKey:(id)key defaultValue:(CGSize)defaultValue;
{
    if (CGSizeEqualToSize(value, defaultValue)) {
        [self removeObjectForKey:key];
        return;
    }
    
    [self setSizeValue:value forKey:key];
}

- (void)setRectValue:(CGRect)value forKey:(id)key defaultValue:(CGRect)defaultValue;
{
    if (CGRectEqualToRect(value, defaultValue)) {
        [self removeObjectForKey:key];
        return;
    }
    
    [self setRectValue:value forKey:key];
}
*/

@end
