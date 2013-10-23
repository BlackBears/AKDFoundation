/**
 *   @file NSMutableString+CCFExtensions.m
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2010-11-19 14:23:39
 *   @version 1.0
 *
 *   @note Copyright 2011 Cocoa Factory, LLC.  All rights reserved
 */

#import "NSMutableString+CCFExtensions.h"


@implementation NSMutableString(CCFExtensions)

- (void)deleteLastCharacter;
{
	NSRange lastCharRange = NSMakeRange(self.length-1,1);
	return [self deleteCharactersInRange:lastCharRange];
}

@end
