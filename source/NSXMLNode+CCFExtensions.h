/**
 *   @file NSXMLNode+CCFExtensions.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2011-07-24 16:22:10
 *   @version 1.0
 *
 *   @note Copyright 2011 Cocoa Factory, LLC.  All rights reserved
 */

#if TARGET_OS_IPHONE
    // NSXMLNode is not supported on iOS
#else

@interface NSXMLNode(CCFExtensions)

- (float)floatValue;
- (NSInteger)integerValue;

@end

#endif
