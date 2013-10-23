/**
 *   @file NSString+Encryption.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2013-07-24 08:36:09
 *
 *   @note Copyright 2013 Cocoa Factory, LLC.  All rights reserved
 */

typedef enum {
    ENCODER_SCHEME_USERNAME,
    ENCODER_SCHEME_PASSWORD,
    ENCODER_SCHEME_GENERIC
} encoder_scheme_t;

/**
 *	A category on NSString that handles certain encryption tasks
 */
@interface NSString (Encryption)

- (NSString *)stringEncodedWithKey:(NSString *)key;
- (NSString *)stringEncodedWithScheme:(encoder_scheme_t)scheme;

- (NSString *)stringBySaltingToMinimumLength:(NSInteger)minLength;

@end
