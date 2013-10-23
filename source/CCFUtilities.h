/**
 *   @file CCFUtilities.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2011-07-11 08:39:22
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

#import "objc/runtime.h"

/**
 *  @brief      NSCoding macros
 *  @details    Makes NSCoding methods simpler.  Note that if 'var' is an object, you DO NOT
 *              have to retain it afterward a decode; -decodeValueOfObjCType:at: retains it
 *              for you.
 *  
 */
#define CCFEncode(coder, var) [coder encodeValueOfObjCType: @encode(typeof(var)) at: &(var)];
#define CCFDecode(coder, var) [coder decodeValueOfObjCType: @encode(typeof(var)) at: &(var)];

/**
 *  @brief    Root class
 *  @details  Returns the root class for the class tree of which aClass is a member
 */
static inline Class OFRootClassForClass(Class aClass)
{
    Class superClass;
    while ((superClass = class_getSuperclass(aClass)))
        aClass = superClass;
    return superClass;
}

#ifdef NS_BLOCKS_AVAILABLE
    typedef BOOL (^CCFPredicateBlock)(id object);
    typedef id (^CCFObjectToObjectBlock)(id anObject);
#endif

/*
#if defined (TARGET_OS_IPHONE) && TARGET_OS_IPHONE
    //  iOS has only one bundle
    #define  CCF_BUNDLE [NSBundle mainBundle]
#else
    //  this uses the CCF_BUNDLE_IDENTIFIER compiler setting set by the xcconfig to look up the bundle for the calling code

    #define CCF_BUNDLE _CCFBundleWithIdentifier(CCF_BUNDLE_IDENTIFIER)
    static inline NSBundle *_CCFBundleWithIdentifier(NSString *identifier)
    {
        NSAssert( [identifier length] > 0, @"Did you forget to set CCF_BUNDLE_IDENTIFIER in your target");
        NSBundle *bundle = [NSBundle bundleWithIdentifier:identifier];
        NSAssert( bundle, @"Did you set CCF_BUNDLE_IDENTIFIER to the wrong value in your target config?");
        return bundle;
    }
#endif
*/
