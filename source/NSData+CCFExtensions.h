/*
 *	@file NSData+CCFExtensions.h
 *	@author Alan Duncan (www.cocoafactory.com)
 *
 *	@date	2010-12-26
 *	@version	1.0
 *
 *	@note Imports all headers in CCFFoundation NSData categories
 *  @note  Copyright (c) 2011 Cocoa Factory, LLC. All rights reserved.
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
 */

#ifndef __NSDATA_CCFEXTENSIONS
#define __NSDATA_CCFEXTENSIONS

#import "NSData+Base64.h"
#import "Base64Transcoder.h"

/**
 *	Category on NSData that provides CCF-specific extensions
 */
@interface NSData (CCFExtensions)

/**
 *	Factory method that creates an NSData instance from a hex string
 *
 *	@param	hexString	A string containing 2 hex digit sequences of characters, e.g. @"aa01d7"
 *
 *	@return	Returns an NSData instance from the 2 digit sequences in the hex string
 */
+ (NSData *)dataWithHexString:(NSString *)hexString;

@end

#endif