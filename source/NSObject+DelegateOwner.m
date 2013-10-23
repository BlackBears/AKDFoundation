/**
 *   @file NSObject+DelegateOwner.m
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2010-10-13 08:52:33
 *   @version 1.0
 *
 *   @note Copyright 2011 Cocoa Factory, LLC.  All rights reserved
 */

#import "NSObject+DelegateOwner.h"


@implementation NSObject(DelegateOwner)

- (BOOL)delegateConforms;
{
	NSString *className = NSStringFromClass([self class]);
	NSString *delegateProtocolName = [className stringByAppendingString:@"Delegate"];
	id classDelegate = [self valueForKey:@"delegate"];
	BOOL delegateExists = (classDelegate != nil );
	BOOL delegateConforms = [classDelegate conformsToProtocol:NSProtocolFromString(delegateProtocolName)];
	return (delegateExists && delegateConforms );
}

- (void)performSelectorOnDelegateIfConforms:(SEL)aSelector;
{
	if( [self delegateConforms] )
	{
		id classDelegate = [self valueForKey:@"delegate"];
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
		[classDelegate performSelector:aSelector];
#pragma clang diagnostic pop
	}
}

- (void)performSelectorOnDelegateIfConforms:(SEL)aSelector withObject:(id)obj;
{
	if( [self delegateConforms] )
	{
		id classDelegate = [self valueForKey:@"delegate"];
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
		[classDelegate performSelector:aSelector withObject:obj];
#pragma clang diagnostic pop
	}
}

- (void)performSelectorOnDelegateIfConforms:(SEL)aSelector withObject:(id)obj onMainThread:(BOOL)isMainThread;
{
	if( [self delegateConforms] )
	{
		id classDelegate = [self valueForKey:@"delegate"];
		if( !isMainThread )
		{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
			[classDelegate performSelector:aSelector withObject:obj];
#pragma clang diagnostic pop
		}
		else
		{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
			[classDelegate performSelectorOnMainThread:aSelector withObject:obj waitUntilDone:YES];
#pragma clang diagnostic pop
		}
	}
}

- (void)performSelectorOnDelegateIfConforms:(SEL)aSelector onMainThread:(BOOL)isMainThread;
{
	if( [self delegateConforms] )
	{
		id classDelegate = [self valueForKey:@"delegate"];
		if( !isMainThread )
		{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
			[classDelegate performSelector:aSelector];
#pragma clang diagnostic pop
		}
		else
		{
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"
			[classDelegate performSelectorOnMainThread:aSelector withObject:nil waitUntilDone:YES];
#pragma clang diagnostic pop
		}
	}
}

@end
