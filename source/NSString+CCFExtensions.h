/**
 *   @file NSString+CCFExtensions.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2010-11-07 08:55:20
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
 */

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonHMAC.h>
#import <CommonCrypto/CommonDigest.h>

#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#else
#import <Cocoa/Cocoa.h>
#endif

/*!
 @category NSString(CCFExtensions)
 @brief A category on NSString to support common features
 */

@interface NSString(CCFExtensions)

extern BOOL emptyString( NSString *string);

/**
 * returns urlencoded value of this string
 */
- (NSString*)urlencodedValue;

/**
 * returns urldecoded value of this string
 */
- (NSString*)urldecodedValue;

/**
 * returns HMAC-SHA1 digest value of this string
 */
- (NSString*)hmacSha1DigestWithKey:(NSString*)secret;

/**
 * returns MD5 digest value of this string
 */
- (NSString*)md5Digest;

/**
 * returns Base64 decoded bytes
 */
- (NSData*)base64DecodedBytes;

//	a category on NSString to return a UUID string

+ (NSString *)stringWithUUID;									/*!< Returns a string with a UUID (unique identifier) */
- (NSString *)lastCharacter;	/*!< Returns the last character in a string */

- (NSString *)chop;	/*!< similar to perl's chop function - removes the last character */

/*!
 @method stringByStrippingCharacter:(NSString *)character
 Returns the receiver with the specified character stripped out of every occurrence
 @param character (NSString *) the character to be stripped as a string
 */
- (NSString *)stringByStrippingCharacter:(NSString *)character;
- (NSString *)stringByStrippingNewLines;						/*!< Returns the receiver with new line characters stripped out of it */
- (NSString *)stringByStrippingTabs;							/*!< Returns the receiver with tab characters stripped out of it */
- (NSString *)stringByStrippingTabsAndNewLines;					/*!< Returns receiver with tabs and new line stripped out of it */

/*!
 @method     pluralizeFromCount:
 @brief      Take a count and pluralizes receiver if more than 1
 
 @param      count 
 */
- (NSString *)pluralizeFromCount:(int)count;

/*!
 @method     stringByTruncatingToLength:withEllipsis:
 @brief      returns string truncated to length; optionally adding ellipsis to end
 
 @param      length characters in returned string, excluding the ellipsis character
 @param      useEllipsis shoud return string end with ellipsis
 @return     a modified string
 */
- (NSString *)stringByTruncatingToLength:(NSUInteger)length withEllipsis:(BOOL)useEllipsis;

- (NSString *)md5;						/*!< generate md5 hash */

+ (NSString *)hmsStringFromLatLong:(float)position isLatitude:(BOOL)isLat;

- (NSString *)reverseString;

+ (BOOL)isEmptyString:(NSString *)string;

+ (NSString *)stringWithCharacter:(UnicodeScalarValue)aCharacter;

+ (NSString *)randomStringLength:(NSInteger)count withLowercase:(BOOL)lower specialSymbols:(BOOL)special;

@end
