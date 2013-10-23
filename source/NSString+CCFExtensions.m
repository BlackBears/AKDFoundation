/**
 *   @file NSString+CCFExtensions.m
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2010-11-07 08:55:20
 *   @version 1.0
 *
 *   @note Copyright 2011 Cocoa Factory, LLC.  All rights reserved
 */

#import "NSString+CCFExtensions.h"
#import "Base64Transcoder.h"
#import "CCFUnicodeUtilities.h"

@implementation NSString(CCFExtensions)

BOOL emptyString( NSString *string)
{
    return string == nil || string.length == 0;
}

+ (BOOL)isEmptyString:(NSString *)string;
// Returns YES if the string is nil or equal to @""
{
    // Note that [string length] == 0 can be false when [string isEqualToString:@""] is true, because these are Unicode strings.
    return string == nil || [string isEqualToString:@""];
}


#pragma mark -
#pragma mark url encode/decode functions

- (NSString*)urlencodedValue
{
	NSString* urlencodedString = (NSString*)CFBridgingRelease(CFURLCreateStringByAddingPercentEscapes(NULL, (CFStringRef)self, NULL, CFSTR(":/?#[]@!$&'()*+,;="), kCFStringEncodingUTF8));
	return urlencodedString;
}

- (NSString*)urldecodedValue
{
	NSString* urldecodedString = (NSString *)CFBridgingRelease(CFURLCreateStringByReplacingPercentEscapes(NULL, (CFStringRef)self, (CFStringRef)@""));
	return urldecodedString;
}

#pragma mark -
#pragma mark HMAC-SHA1 digest function

- (NSString*)hmacSha1DigestWithKey:(NSString*)secret
{
	NSData* secretData = [secret dataUsingEncoding:NSUTF8StringEncoding];
	NSData* stringData = [self dataUsingEncoding:NSUTF8StringEncoding];
	
	uint8_t digest[CC_SHA1_DIGEST_LENGTH] = {
		0,
	};
	
	CCHmacContext hmacContext;
	CCHmacInit(&hmacContext, kCCHmacAlgSHA1, secretData.bytes, secretData.length);
	CCHmacUpdate(&hmacContext, stringData.bytes, stringData.length);
	CCHmacFinal(&hmacContext, digest);
	
	char base64Encoded[32];
	size_t base64EncodedLength = 32;
	Base64EncodeData(digest, CC_SHA1_DIGEST_LENGTH, base64Encoded, &base64EncodedLength);
	NSData* encodedData = [NSData dataWithBytes:base64Encoded length:base64EncodedLength];
	NSString* base64EncodedString = [[NSString alloc] initWithData:encodedData encoding:NSUTF8StringEncoding];
	
	return base64EncodedString;
}

#pragma mark -
#pragma mark MD5 digest function

- (NSString*)md5Digest
{
	const char* cStr = [self UTF8String];
	unsigned char result[CC_MD5_DIGEST_LENGTH] = {
		0,
	};
#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE || TARGET_OS_EMBEDDED
	CC_MD5(cStr, strlen(cStr), result);
#else
    CC_MD5(cStr, (int)strlen(cStr), result);
#endif
	
	return [NSString stringWithFormat:@"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
			result[0], result[1], result[2], result[3],
			result[4], result[5], result[6], result[7],
			result[8], result[9], result[10], result[11],
			result[12], result[13], result[14], result[15]];
}

#pragma mark -
#pragma mark Base64 decoding

- (NSData*)base64DecodedBytes
{
	@try
	{
		size_t base64DecodedLength = EstimateBas64DecodedDataSize([self length]);
		char base64Decoded[base64DecodedLength];
		const char* cStringValue = [self UTF8String];
		if(Base64DecodeData(cStringValue, strlen(cStringValue), base64Decoded, &base64DecodedLength))
		{
			NSData* base64DecodedData = [[NSData alloc] initWithBytes:base64Decoded length:base64DecodedLength];
			return base64DecodedData;
		}
	}
	@catch (NSException * e)
	{
		//do nothing
		NSLog(@"exception: %@", [e reason]);
	}
	return nil;
}

+ (NSString*)stringWithUUID {
	CFUUIDRef uuidObj = CFUUIDCreate(nil);
	NSString *uuidString = (NSString *)CFBridgingRelease(CFUUIDCreateString(nil, uuidObj));
	CFRelease(uuidObj);
	return uuidString;
}

- (NSString *)lastCharacter {
	if (!self || [self length] == 0) {return nil;}
	return [self substringWithRange:NSMakeRange([self length]-1, 1)];
}

- (NSString *)chop;
{
	return [self stringByTruncatingToLength:[self length]-1 withEllipsis:NO];
}

- (NSString *)stringByStrippingCharacter:(NSString *)string
{
	if (!self) {return nil;}
	NSMutableString *mstring = [NSMutableString stringWithString:self];
    NSRange wholeShebang = NSMakeRange(0, [mstring length]);
	
    [mstring replaceOccurrencesOfString: string
							 withString: @""
								options: 0
								  range: wholeShebang];
	
    return [NSString stringWithString: mstring];
}

- (NSString *)stringByStrippingNewLines
{
	return [self stringByStrippingCharacter:@"\n"];
}

- (NSString *)stringByStrippingTabs
{
	return [self stringByStrippingCharacter:@"\t"];
}

- (NSString *)stringByStrippingTabsAndNewLines;
{
	return [[self stringByStrippingTabs] stringByStrippingNewLines];
}

- (NSString *)pluralizeFromCount:(int)count {
	return (count==1)?self:[NSString stringWithFormat:@"%@s",self];
}

- (NSString *)md5
{
	//const char *cStr = [self UTF8String];
	const char *cStr = [self cStringUsingEncoding:NSUTF8StringEncoding];
	unsigned char result[16];
#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE || TARGET_OS_EMBEDDED
	CC_MD5(cStr, strlen(cStr), result);
#else
    CC_MD5(cStr, (int)strlen(cStr), result);
#endif
	return [NSString stringWithFormat:
			@"%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X%02X",
			result[0], result[1], result[2], result[3], 
			result[4], result[5], result[6], result[7],
			result[8], result[9], result[10], result[11],
			result[12], result[13], result[14], result[15]
			];  
}

- (NSString *)stringByTruncatingToLength:(NSUInteger)length withEllipsis:(BOOL)useEllipsis
{
	if (length > [self length]) {
		return self;
	}
	NSMutableString *_mod = [[self substringToIndex:length] mutableCopy];
	if (useEllipsis) {
		[_mod appendString:@"…"];
	}
	return (NSString *)_mod;
}

+ (NSString *)hmsStringFromLatLong:(float)position isLatitude:(BOOL)isLat;
{
	int iDegrees = floor(position);
	float fDec = position - (float)iDegrees;
	float fMinsSecs = fDec * 60.0f;
	int iMinutes = floor(fMinsSecs);
	float fSecDec = fMinsSecs - (float)iMinutes;
	float fSecs = fSecDec * 60.0f;
	int iSeconds = floor(fSecs);
	
	NSString *ref = nil;
	if( isLat )
	{
		ref = (iDegrees < 0)?@"S":@"N";
	}
	else
	{
		ref = (iDegrees < 0)?@"W":@"E";
	}
	NSString *format = [NSString stringWithFormat:@"%02d°%02d'%02d\"%@",iDegrees,iMinutes,iSeconds,ref];
	return format;
}

- (NSString *)reverseString;
{
	NSMutableString *reversedStr;
	int len = (int)[self length];
	
	// Auto released string
	reversedStr = [NSMutableString stringWithCapacity:len];     
	
	// Probably woefully inefficient...
	while (len > 0)
		[reversedStr appendString:
         [NSString stringWithFormat:@"%C", [self characterAtIndex:--len]]];   
	
	return reversedStr;
}

+ (NSString *)stringWithCharacter:(UnicodeScalarValue)aCharacter;
{
    unichar utf16[2];
    NSString *result;
    
    if (aCharacter <= 0xFFFF) {
        utf16[0] = (unichar)aCharacter;
        result = [[self alloc] initWithCharacters:utf16 length:1];
    } else {
        /* Convert Unicode characters in supplementary planes into pairs of UTF-16 surrogates */
        CCFCharacterToSurrogatePair(aCharacter, utf16);
        result = [[self alloc] initWithCharacters:utf16 length:2];
    }
    return result;
}

+ (NSString *)randomStringLength:(NSInteger)count withLowercase:(BOOL)lower specialSymbols:(BOOL)special;
{
    NSMutableString *chars = [[NSMutableString alloc] initWithString:@"ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"];
    if( lower )
        [chars appendString:@"abcdefghijklmnopqrstuvwxyz"];
    if( special )
        [chars appendString:@"!@#$%^&*<>?+_-="];
    NSMutableString *s = [[NSMutableString alloc] initWithCapacity:count];
    for( NSUInteger i = 0U; i < count; i++ )
    {
        uint32_t r = arc4random() % [chars length];
        unichar c = [chars characterAtIndex:r];
        [s appendFormat:@"%C",c];
    }
    return (NSString *)s;
}


@end
