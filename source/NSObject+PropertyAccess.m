/**
 *   @file NSObject+PropertyAccess.m
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2010-10-26 08:54:16
 *   @version 1.0
 *
 *   @note Copyright 2011 Cocoa Factory, LLC.  All rights reserved
 */

#import "NSObject+PropertyAccess.h"
#import <objc/runtime.h>

@implementation NSObject(PropertyAccess)


#ifndef __clang_analyzer__
CFStringRef _nameForObjCProperty(objc_property_t property)
{
	const char *name = property_getName(property);
	CFStringRef propertyNameRef = CFStringCreateWithCString(NULL, name,kCFStringEncodingUTF8);
	return propertyNameRef;
}

CFStringRef _attributesForObjProperty(objc_property_t property)
{
	const char *attributes = property_getAttributes(property);
	CFStringRef propertyAttributes = CFStringCreateWithCString(NULL, attributes, kCFStringEncodingUTF8);
	return propertyAttributes;
}
#endif

@end
