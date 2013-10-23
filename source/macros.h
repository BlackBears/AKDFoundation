/**
 *   @file macros.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2011-07-15 08:26:40
 *   @version 1.0
 *
 *   @note Copyright 2011 Cocoa Factory, LLC.  All rights reserved
 */

#import <Foundation/NSString.h>

#ifndef __CCF_FOUNDATION_MACROS_H
#define __CCF_FOUNDATION_MACROS_H

#if !defined(CCF_INLINE)
    #if defined(__GNUC__) && (__GNUC__ == 4 )
        #define CCF_INLINE static __inline __attribute((always_inline))
    #else
        #define CCF_INLINE static __inline__
    #endif
#endif

#ifndef _CCFCompileAssert
#define _CCFCompileAssertSymbolInner(line, msg) _CCFCOMPILEASSERT ## line ## __ ## msg
#define _CCFCompileAssertSymbol(line, msg) _CCFCompileAssertSymbolInner(line, msg)
#define _CCFCompileAssert(test, msg) \
typedef char _CCFCompileAssertSymbol(__LINE__, msg) [ ((test) ? 1 : -1) ]
#endif

#pragma mark - Logging

#if DEBUG
#define DebugLog(...) NSLog(__VA_ARGS__)
#else
#define DebugLog(...) // Nothing
#endif

extern void QuietLog (NSString *format, ...);
extern void QuietNote( NSString *format, ...);

#define CCFLog(format, ...) NSLog(@"%s:%@", __PRETTY_FUNCTION__,[NSString stringWithFormat:format, ## __VA_ARGS__]);
#define APGLog(format, ...) NSLog(@"%s:%@", __PRETTY_FUNCTION__,[NSString stringWithFormat:format, ## __VA_ARGS__]);

extern float BNRTimeBlock (void (^block)(void));

#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)

#define SuppressDeprecatedMethodWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while(0)

#pragma mark - Bundle support

extern id resourcePath(id owner, NSString *name, NSString *extension);

#pragma mark - Object creation/destruction

#ifndef SUPERINIT
#define SUPERINIT self = [super init]; \
if( !self ) return nil;
#endif

#define CCF_NIL_IF_NO_SELF if( !self ) return nil;

#ifndef _ASSIGN
#define _ASSIGN(targ,newval)		do {\
NSObject* __UKHELPERMACRO_OLDTARG = (NSObject*)(targ);\
(targ) = [(newval) retain];\
[__UKHELPERMACRO_OLDTARG release];\
} while(0)
#endif

#ifndef CCFASSIGN
#define CCFASSIGN(targ,newval)		do {\
NSObject* __UKHELPERMACRO_OLDTARG = (NSObject*)(targ);\
(targ) = [(newval) retain];\
[__UKHELPERMACRO_OLDTARG release];\
} while(0)
#endif


#ifndef CCF_DESTROY_
    #define CCF_DESTROY_
    #define DESTROY(targ)	do {\
    NSObject* __UKHELPERMACRO_OLDTARG = (NSObject*)(targ);\
    (targ) = nil;\
    [__UKHELPERMACRO_OLDTARG release];\
    } while(0)
        
    #define CCFDESTROY(targ)	do {\
    NSObject* __UKHELPERMACRO_OLDTARG = (NSObject*)(targ);\
    (targ) = nil;\
    [__UKHELPERMACRO_OLDTARG release];\
    } while(0)
#endif

#pragma mark - String
#define _(...) NSLocalizedString(__VA_ARGS__,@"")
#define __(X,Y) NSLocalizedStringFromTable(X,Y,@"")

extern NSRange entireStringRange(id string);

//  This is an easy way to define strings, courtesy of Omni Group in its OmniBase framework
#if defined(__GNUC__)
#if __GNUC__ < 3 || (__GNUC__ == 3 && __GNUC_MINOR__ < 3)
// GCC before 3.3 requires this format
#define NSSTRINGIFY(name) @ ## #name
#else
// GCC 3.3 requires this format
#define NSSTRINGIFY(name) @#name
#endif
#endif

// An easy way to define string constants.  For example, "NSSTRINGIFY(foo)" produces @"foo" and "DEFINE_NSSTRING(foo);" produces: NSString *foo = @"foo";

#define DEFINE_NSSTRING(name) \
NSString * const name = NSSTRINGIFY(name)


#define EXTERN_NSSTRING(name) \
extern NSString * const name


#ifndef CCF_RELEASE_
#define CCF_RELEASE_

#define MCRelease(x) [x release], x = nil
#define CCFRelease(x) [x release], x = nil

#endif

#pragma mark - Miscellaneous

#if !defined(SWAP)
#define SWAP(A, B) do { __typeof__(A) __temp = (A); (A) = (B); (B) = __temp;} while(0)
#endif
#define CCFSWAP(A, B) do { __typeof__(A) __temp = (A); (A) = (B); (B) = __temp;} while(0)

#ifdef DEBUG
#define DebugLog(...) NSLog(__VA_ARGS__)
#else
#define DebugLog(...) // Nothing
#endif



#pragma mark - Array
#define ArrayWithObjects(...) [NSArray arrayWithObjects:__VA_ARGS__,nil]

#pragma mark - Notifications

#define CCFPostNotification(a,b) [[NSNotificationCenter defaultCenter] postNotificationName:a object:b]
#define NOTIFIER [NSNotificationCenter defaultCenter]

#pragma mark - User defaults
#define DEFAULTS [NSUserDefaults standardUserDefaults]
#define DefaultSet(X,Y) [[NSUserDefaults standardUserDefaults] setValue:X forKey:Y]
#define DEFAULT_SET_INTEGER(X,Y) [[NSUserDefaults standardUserDefaults] setInteger:X forKey:Y]
#define SyncDefaults [[NSUserDefaults standardUserDefaults] synchronize]
#define DefaultNum2Bool(k) [[[NSUserDefaults standardUserDefaults] objectForKey:k] boolValue]
#define DefaultBool(k) [[[NSUserDefaults standardUserDefaults] objectForKey:k] boolValue]
#define DefaultNum2Integer(k) [[[NSUserDefaults standardUserDefaults] objectForKey:k] integerValue]
#define DefaultNum2Int(k) [[[NSUserDefaults standardUserDefaults] objectForKey:k] intValue]
#define DefaultNum2Float(k) [[[NSUserDefaults standardUserDefaults] objectForKey:k] floatValue]

#define CCFDefaultBool(k) [[NSUserDefaults standardUserDefaults] boolForKey:k]
#define CCFDefaultInteger(k) [[NSUserDefaults standardUserDefaults] integerForKey:k]
#define CCFDefaultFloat(k) [[NSUserDefaults standardUserDefaults] floatForKey:k]

#pragma mark - NSNumber conversions

#define Int2NSNumber(...) [NSNumber numberWithInt:__VA_ARGS__]
#define Bool2NSNumber(...) [NSNumber numberWithBool:__VA_ARGS__]
#define Float2NSNumber(...) [NSNumber numberWithFloat:__VA_ARGS__]
#define Integer2NSNumber(...) [NSNumber numberWithInteger:__VA_ARGS__]

#define Num2Int(...) [__VA_ARGS__ intValue]
#define Num2Bool(...) [__VA_ARGS__ boolValue]
#define Num2Float(...) [__VA_ARGS__ floatValue]
#define Num2Integer(...) [__VA_ARGS__ integerValue]

#define BOOL_YES [NSNumber numberWithBool:YES]
#define BOOL_NO [NSNumber numberWithBool:NO]

#define CCFIntToNSNumber(...) [NSNumber numberWithInt:__VA_ARGS__]
#define CCFIntegerToNSNumber(...) [NSNumber numberWithInteger:__VA_ARGS__]
#define CCFBoolToNSNumber(...) [NSNumber numberWithBool:__VA_ARGS__]
#define CCFFloatToNSNumber(...) [NSNumber numberWithFloat:__VA_ARGS__]
#define CCFDoubleToNSNumber(...) [NSNumber numberWithDouble:__VA_ARGS__]

#define CCFNumberToInt(...) [__VA_ARGS__ intValue]
#define CCFNumberToInteger(...) [__VA_ARGS__ integerValue]
#define CCFNumberToBool(...) [__VA_ARGS__ boolValue]
#define CCFNumberToFloat(...) [__VA_ARGS__ floatValue]
#define CCFNumberToDouble(...) [__VA_ARGS__ doubleValue]

#if defined(TARGET_OS_IPHONE) && TARGET_OS_IPHONE
#pragma mark - UITableView
#define GetRowAndSection(indexPath) NSUInteger row = [indexPath row]; \
NSUInteger section = [indexPath section];
#define GetRow(indexPath) NSUInteger row = [indexPath row];
#endif

#pragma mark - Animation
#define SET_LAYER_PROPERTY_WITHOUT_ANIMATION(...) \
[CATransaction begin]; \
[CATransaction setValue:(id)kCFBooleanTrue forKey:kCATransactionDisableActions]; \
__VA_ARGS__ \
[CATransaction commit]; 

#define CCFWithoutAnimation(...) \
[CATransaction begin]; \
[CATransaction setValue:(id)kCFBooleanTrue forKey:kCATransactionDisableActions]; \
__VA_ARGS__ \
[CATransaction commit]; 

#pragma mark - Constants

#define SECONDS_PER_DAY 86400
#define SECONDS_PER_HOUR 3600
#define SECONDS_PER_MINUTE 60
#define SECONDS_PER_WEEK 604800
#define SECONDS_PER_MONTH 18144000

#pragma mark - NS_NAMESPACE support

/*  To use this namespace-like feature, instead of writing your classes this way:
 
 @interface Foo : NSObject
 @property(strong) NSString *bar;
 @end
 
 You will write them as: 
 
 @interface NS(Foo) : NSObject
 @property(strong) NSString *bar;
 @end
 #define Foo NS(Foo)
 
 Now your code supports compile-time prefix insertion. If you don’t do anything else, your classes will remain unprefixed.
 However, you can now prefix all participating classes with one easy flick of a preprocessor definition:
 -D NS_NAMESPACE=MyFramework
 That turns the code above into:
 MyFramework_Person *p = [MyFramework_Person new];
 With judicious targeting of your -D NS_NAMESPACE= use, this should enable you to work-around class collisions at both compile-time and runtime.
 
 See: http://rentzsch.tumblr.com/post/40806448108/ns-poor-mans-namespacing-for-objective-c
 
 */

#ifndef NS
    #ifdef NS_NAMESPACE
        #define JRNS_CONCAT_TOKENS(a,b) a##_##b
        #define JRNS_EVALUATE(a,b) JRNS_CONCAT_TOKENS(a,b)
        #define NS(original_name) JRNS_EVALUATE(NS_NAMESPACE, original_name)
    #else
        #define NS(original_name) original_name
    #endif
#endif

#endif
