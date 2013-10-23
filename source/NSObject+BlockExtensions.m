/**
 *   @file NSObject+BlockExtensions.m
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2010-10-28 08:50:07
 *   @version 1.0
 *
 *   @note Copyright 2011 Cocoa Factory, LLC.  All rights reserved
 */

#import "NSObject+BlockExtensions.h"


@implementation NSObject(BlockExtensions)

void UsingAutoreleasePool(BasicBlock block) {
    @autoreleasepool {
        block();
    }
    block();
};

void RunAfterDelay(NSTimeInterval delay, BasicBlock block){
	[[block copy] performSelector: @selector(my_callBlock) withObject: nil afterDelay: delay];
}

- (void)my_callBlock
{
	void (^block)(void) = (id)self;
	block();
}

void UsingTimer(BasicBlock block) {
	NSTimeInterval __start = [NSDate timeIntervalSinceReferenceDate];
	block();
	NSTimeInterval __stop = [NSDate timeIntervalSinceReferenceDate];
	NSLog(@"%s - Time = %f", __FUNCTION__, __stop - __start);
}

- (void)ccf_callBlock
{
    void (^block)(void) = (id)self;
    block();
}

- (void)ccf_callBlockWithObject:(id)obj
{
    void (^block)(id obj) = (id)self;
    block(obj);
}

@end

