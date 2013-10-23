/**
 *   @file NSString+CCFConversions.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2011-07-11 08:56:03
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


#import <Foundation/NSString.h>

#import <Foundation/NSDecimal.h>
#import <CoreFoundation/CFString.h>

@class NSData, NSDecimalNumber;

@interface NSString(CCFConversions)

+ (NSString *)stringWithData:(NSData *)data encoding:(NSStringEncoding)encoding;

- (BOOL)boolValue;
- (long long int)longLongValue;
- (unsigned long long int)unsignedLongLongValue;
- (unsigned long)unsignedLongValue;
- (unsigned int)unsignedIntValue;
- (intmax_t)maxIntegerValue;
- (uintmax_t)maxUnsignedIntegerValue;
- (NSDecimal)decimalValue;
- (NSDecimalNumber *)decimalNumberValue;
- (NSNumber *)numberValue;
- (NSArray *)arrayValue;
- (NSDictionary *)dictionaryValue;
- (NSData *)dataValue;

- (unsigned int)hexValue;
- (uintmax_t)maxHexValue;



@end
