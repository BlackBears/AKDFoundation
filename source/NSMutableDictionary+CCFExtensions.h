/**
 *   @file NSDictionary+CCFExtensions.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2011-07-13 11:10:48
 *   @version 1.0
 *
 *   @note  Copyright (c) 2011 Cocoa Factory, LLC. All rights reserved.
 *          Permission is hereby granted, free of charge, to any person obtaining a copy of this
 *          software and associated documentation files (the "Software"), to deal in the
 *          Software without restriction, including without limitation the rights to use, copy,
 *          modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
 *          and to permit persons to whom the Software is furnished to do so, subject to the
 *          following conditions:
 *          The above copyright notice and this permission notice shall be included in all
 *          copies or substantial portions of the Software.
 *          THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 *          INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
 *          PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *          HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 *          CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE 
 *          OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 *   @note  Some of the source code in this file is heavily based on the OmniFrameworks, so the
 *          license for those frameworks is included in this file:
 *          Omni Source Code software is available from The Omni Group on their web site at www.omnigroup.com. 
 *          Permission is hereby granted, free of charge, to any person obtaining a copy of this software and 
 *          associated documentation files (the "Software"), to deal in the Software without restriction, including 
 *          without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
 *          copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the 
 *          following conditions: Any original copyright notices and this permission notice shall be included in all 
 *          copies or substantial portions of the Software. THE SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY 
 *          KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
 *          PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 *          ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
 *          OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * 
 */

#import <Foundation/NSDictionary.h>
#import "NSDictionary+CCFExtensions.h"

@interface NSMutableDictionary(CCFExtensions)

- (void)setObject:(id)anObject forKeys:(NSArray *)keys;

// These are nice for ease of use
- (void)setFloatValue:(float)value forKey:(id)key;
- (void)setDoubleValue:(double)value forKey:(id)key;
- (void)setIntValue:(int)value forKey:(id)key;
- (void)setUnsignedIntValue:(unsigned int)value forKey:(id)key;
- (void)setIntegerValue:(NSInteger)value forKey:(id)key;
- (void)setUnsignedIntegerValue:(NSUInteger)value forKey:(id)key;
- (void)setUnsignedLongLongValue:(unsigned long long)value forKey:(id)key;
- (void)setBoolValue:(BOOL)value forKey:(id)key;
//- (void)setPointValue:(CGPoint)value forKey:(id)key;
//- (void)setSizeValue:(CGSize)value forKey:(id)key;
//- (void)setRectValue:(CGRect)value forKey:(id)key;

// Setting with default values
- (void)setObject:(id)object forKey:(id)key defaultObject:(id)defaultObject;
- (void)setFloatValue:(float)value forKey:(id)key defaultValue:(float)defaultValue;
- (void)setDoubleValue:(double)value forKey:(id)key defaultValue:(double)defaultValue;
- (void)setIntValue:(int)value forKey:(id)key defaultValue:(int)defaultValue;
- (void)setUnsignedIntValue:(unsigned int)value forKey:(id)key defaultValue:(unsigned int)defaultValue;
- (void)setIntegerValue:(NSInteger)value forKey:(id)key defaultValue:(NSInteger)defaultValue;
- (void)setUnsignedIntegerValue:(NSUInteger)value forKey:(id)key defaultValue:(NSUInteger)defaultValue;
- (void)setUnsignedLongLongValue:(unsigned long long)value forKey:(id)key defaultValue:(unsigned long long)defaultValue;
- (void)setBoolValue:(BOOL)value forKey:(id)key defaultValue:(BOOL)defaultValue;
//- (void)setPointValue:(CGPoint)value forKey:(id)key defaultValue:(CGPoint)defaultValue;
//- (void)setSizeValue:(CGSize)value forKey:(id)key defaultValue:(CGSize)defaultValue;
//- (void)setRectValue:(CGRect)value forKey:(id)key defaultValue:(CGRect)defaultValue;

@end
