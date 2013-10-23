/**
 *   @file NSDictionary+CCFExtensions.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2010-11-27 08:48:37
 *
 *   @note Copyright 2013 Cocoa Factory, LLC.  All rights reserved
 */

#import <Foundation/Foundation.h>
#if TARGET_OS_IPHONE || TARGET_IPHONE_SIMULATOR
#import <CoreGraphics/CGGeometry.h>
#endif

@interface NSDictionary(CCFExtensions)

+ (NSDictionary *)dictionaryWithContentsOfData:(NSData *)data;
- (NSInteger)integerForKey:(NSString *)key;
- (NSInteger)integerForKey:(NSString *)key defaultValue:(NSInteger)defaultValue;

- (float)floatForKey:(NSString *)key;
- (float)floatForKey:(NSString *)key defaultValue:(float)defaultValue;

- (BOOL)boolForKey:(NSString *)key;
- (BOOL)boolForKey:(NSString *)key defaultValue:(BOOL)defaultValue;

- (NSString *)keyForObjectEqualTo:(id)anObj;
- (id)objectForKey:(NSString *)key defaultObject:(id)defaultObject;

//- (CGPoint)pointForKey:(NSString *)key defaultValue:(CGPoint)defaultValue;
//- (CGPoint)pointForKey:(NSString *)key;
//- (CGSize)sizeForKey:(NSString *)key defaultValue:(CGSize)defaultValue;
//- (CGSize)sizeForKey:(NSString *)key;
//- (CGRect)rectForKey:(NSString *)key defaultValue:(CGRect)defaultValue;
//- (CGRect)rectForKey:(NSString *)key;

@end
