#import "NSDictionary+CCFExtensions.h"
#import "NSString+CCFExtensions.h"

#if !defined(TARGET_OS_IPHONE) || !TARGET_OS_IPHONE
    #define CGPointValue pointValue
    #define CGRectValue rectValue
    #define CGSizeValue sizeValue
#else
#import <UIKit/UIGeometry.h>
    #define NSPointFromString CGPointFromString
    #define NSRectFromString CGRectFromString
    #define NSSizeFromString CGSizeFromString
    #define NSZeroPoint CGPointZero
    #define NSZeroSize CGSizeZero
    #define NSZeroRect CGRectZero
#endif

@implementation NSDictionary(CCFExtensions)

+ (NSDictionary *)dictionaryWithContentsOfData:(NSData *)data
{
	// uses toll-free bridging for data into CFDataRef and CFPropertyList into NSDictionary
	CFPropertyListRef plist =  CFPropertyListCreateFromXMLData(kCFAllocatorDefault, (__bridge CFDataRef)data, kCFPropertyListImmutable, NULL);
	// we check if it is the correct type and only return it if it is
	if( [(__bridge id)plist isKindOfClass:[NSDictionary class]] ) {
        NSDictionary *returnDictionary = [NSDictionary dictionaryWithDictionary:(__bridge id)plist];
        CFRelease(plist);
		return returnDictionary;
	}
	else
	{
		if( plist != nil )
		{
			CFRelease(plist);
		}
		return nil;
	}
}

- (NSInteger)integerForKey:(NSString *)key;
{
	return [[self valueForKey:key] integerValue];
}

- (NSInteger)integerForKey:(NSString *)key defaultValue:(NSInteger)defaultValue;
{
    id value = [self objectForKey:key];
    if( !value )
        return defaultValue;
    return [value integerValue];
}

- (float)floatForKey:(NSString *)key;
{
	return [[self valueForKey:key] floatValue];
}

- (float)floatForKey:(NSString *)key defaultValue:(float)defaultValue;
{
    id value = [self objectForKey:key];
    if( !value )
        return defaultValue;
    return [value floatValue];
}

- (BOOL)boolForKey:(NSString *)key;
{
    return [[self valueForKey:key] boolValue];
}

- (BOOL)boolForKey:(NSString *)key defaultValue:(BOOL)defaultValue;
{
    id value = [self objectForKey:key];
    if( !value )
        return defaultValue;
    return [value boolValue];
}

/*
- (CGPoint)pointForKey:(NSString *)key defaultValue:(CGPoint)defaultValue;
{
    id value = [self objectForKey:key];
    if ([value isKindOfClass:[NSString class]] && ![NSString isEmptyString:value])
        return NSPointFromString(value);
    else if ([value isKindOfClass:[NSValue class]])
        return [value CGPointValue];
    else
        return defaultValue;
}

- (CGPoint)pointForKey:(NSString *)key;
{
    return [self pointForKey:key defaultValue:NSZeroPoint];
}

- (CGSize)sizeForKey:(NSString *)key defaultValue:(CGSize)defaultValue;
{
    id value = [self objectForKey:key];
    if ([value isKindOfClass:[NSString class]] && ![NSString isEmptyString:value])
        return NSSizeFromString(value);
    else if ([value isKindOfClass:[NSValue class]])
        return [value CGSizeValue];
    else
        return defaultValue;
}

- (CGSize)sizeForKey:(NSString *)key;
{
    return [self sizeForKey:key defaultValue:NSZeroSize];
}

- (CGRect)rectForKey:(NSString *)key defaultValue:(CGRect)defaultValue;
{
    id value = [self objectForKey:key];
    if ([value isKindOfClass:[NSString class]] && ![NSString isEmptyString:value])
        return NSRectFromString(value);
    else if ([value isKindOfClass:[NSValue class]])
        return [value CGRectValue];
    else
        return defaultValue;
}

- (CGRect)rectForKey:(NSString *)key;
{
    return [self rectForKey:key defaultValue:NSZeroRect];
}
*/
- (NSString *)keyForObjectEqualTo:(id)anObject;
{
#if NS_BLOCKS_AVAILABLE
    __block NSString *foundKey = nil;
    [self enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
        if( [obj isEqual:anObject] )
        {
            foundKey = key;
            *stop = YES;
        }
    }];
    return foundKey;
#else
    for (NSString *key in self)
        if ([[self objectForKey:key] isEqual:anObject])
            return key;
    return nil;
#endif
    
}

- (id)objectForKey:(NSString *)key defaultObject:(id)defaultObject;
{
    id value = [self objectForKey:key];
    if( value )
        return value;
    return defaultObject;
}

@end
