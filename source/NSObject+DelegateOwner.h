/**
 *   @file NSObject+DelegateOwner.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2010-10-13 08:52:33
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


/*!
    @category     NSObject(DelegateOwner)
    @abstract    A category on NSObject that simplifies confirmation of delegate protocol conformity
    @discussion  A single method comprises this category which extends NSObject to evaluate whether it conforms
 to a protocol having the name of the class with "Delegate" appended.  So, if the class name is Foo; then the method <tt>- (BOOL)delegateConforms</tt>
 returns, \c YES if the class conforms to the protocol \c FooDelegate. Otherwise, it returns NO.
*/
@interface NSObject(DelegateOwner)


/*!
    @method     delegateConforms
    @abstract   Returns conformity with delegate protocol
    @discussion Returns YES if class conforms to protocol having same name as class with Delegate appended
    @result     YES if conforms, NO if it doesn't conform
*/
- (BOOL)delegateConforms;

- (void)performSelectorOnDelegateIfConforms:(SEL)aSelector;

- (void)performSelectorOnDelegateIfConforms:(SEL)aSelector withObject:(id)obj;

- (void)performSelectorOnDelegateIfConforms:(SEL)aSelector withObject:(id)obj onMainThread:(BOOL)isMainThread;
- (void)performSelectorOnDelegateIfConforms:(SEL)aSelector onMainThread:(BOOL)isMainThread;

@end
