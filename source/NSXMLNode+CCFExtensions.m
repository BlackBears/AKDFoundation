/**
 *   @file NSXMLNode+CCFExtensions.m
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2011-07-24 16:22:19
 *   @version 1.0
 *
 *   @note Copyright 2011 Cocoa Factory, LLC.  All rights reserved
 */

#import "NSXMLNode+CCFExtensions.h"

#if TARGET_OS_IPHONE
    //  NSXMLNode is not supported on iOS
#else

@implementation NSXMLNode(CCFExtensions)

- (float)floatValue;
{
    return [[self stringValue] floatValue];
}

- (NSInteger)integerValue;
{
    return [[self stringValue] integerValue];
}

@end

#endif
