/**
 *   @file NSObject+BlockExtensions.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2010-10-28 08:50:07
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
 *  @note   Some of this source code is based on similar code by Michael Ash
 */

#import <Foundation/Foundation.h>

typedef void (^BasicBlock)(void);
typedef void (^CCFBlock)(void);
typedef void (^CCFStringBlock)(NSString *returnString);
typedef void (^CCFIntegerBlock)(NSInteger returnInteger);
typedef void (^CCFObjectBlock)(id returnObject);
typedef void (^CCFErrorBlock)(NSError *error);

@interface NSObject(BlockExtensions)

void UsingAutoreleasePool(BasicBlock block);
void RunAfterDelay(NSTimeInterval delay, BasicBlock block);
void UsingTimer(BasicBlock block);

- (void)ccf_callBlock;
- (void)ccf_callBlockWithObject:(id)obj;

@end
