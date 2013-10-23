/**
 *   @file CCFObject.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2013-07-29 20:08:43
 *
 *   @note Copyright 2013 Cocoa Factory, LLC.  All rights reserved
 */

#import <Foundation/Foundation.h>

@interface CCFObject : NSObject

- (NSMutableDictionary *)debugDictionary;
- (NSString *)shortDescription;

@end
