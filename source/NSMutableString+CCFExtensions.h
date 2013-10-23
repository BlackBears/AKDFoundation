/**
 *   @file NSMutableString+CCFExtensions.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2010-11-19 14:23:39
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
 */

#import <Foundation/NSString.h>

/**
 *  @brief    Category on NSMutableString for Cocoa Factory, LLC extensions
 *  @details  Extensions to NSMutableString
 */
@interface NSMutableString(CCFExtensions)

/**
 *  @brief    Deletes last character of string
 *  @details  Deletes the terminal character of a mutable string
 */
- (void)deleteLastCharacter;

@end
