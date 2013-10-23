/**
 *   @file assertions.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2011-07-15 07:58:29
 *   @version 1.0
 *
 *   @note Copyright 2011 Cocoa Factory, LLC.  All rights reserved
 */

#import <objc/objc.h>

#if defined(DEBUG) || defined(CCF_FORCE_ASSERTIONS)
    #define CCF_ASSERTIONS_ON
#endif

#if defined(CCF_ASSERTIONS_OFF)
    #undef CCF_ASSERTIONS_ON
    #warning FORCING assertions off!
#endif

// Make sure that we don't accidentally use the ASSERT macro instead of CCFASSERT
#ifdef ASSERT
    #undef ASSERT
#endif

/*
 When building with clang, we want it to understand that some of our assertions mean certain paths through the code shouldn't be analyzed. A very common case is asserting that some CCFject is non-nil and then sending a non-void * sized returning message to it.  In this case we'd like to do:
 
 CCFASSERT(CCFject);
 
 CGFloat thing = [CCFject stuff];
 
 So, we can annotate the body of the assertion failure with a special clang attribute to discontinue the analysis on that path.  Unlike using __attribute__((noreturn)), this doesn't lie to the compiler's data flow and possibly cause prCCFlems due to a function returning when it said it wouldn't.
 */

#ifdef __clang__
    #define CLANG_ANALYZER_NORETURN __attribute__((analyzer_noreturn))
#else
    #define CLANG_ANALYZER_NORETURN
#endif

// This is useful for providing hints to the clang static analyzer about paths that cannot be reached.
static inline void CCFAnalyzerNotReached(void) CLANG_ANALYZER_NORETURN;
static inline void CCFAnalyzerNotReached(void) { }

// Clang extensions -- Compatibility with non-clang compilers.
#ifndef __has_feature
    #define __has_feature(x) 0
#endif
#if __has_feature(attribute_overloadable)
    // Avoid warning about comparison to zero for unsigned arguments
    static inline BOOL __attribute__((overloadable)) _CCFIsNegative(double x) { return x < 0.0; }
    static inline BOOL __attribute__((overloadable)) _CCFIsNegative(float x) { return x < 0.0; }
    static inline BOOL __attribute__((overloadable)) _CCFIsNegative(char x) { return x < 0; }
    static inline BOOL __attribute__((overloadable)) _CCFIsNegative(short x) { return x < 0; }
    static inline BOOL __attribute__((overloadable)) _CCFIsNegative(int x) { return x < 0; }
    static inline BOOL __attribute__((overloadable)) _CCFIsNegative(long x) { return x < 0; }
    static inline BOOL __attribute__((overloadable)) _CCFIsNegative(unsigned char x) { return NO; }
    static inline BOOL __attribute__((overloadable)) _CCFIsNegative(unsigned short x) { return NO; }
    static inline BOOL __attribute__((overloadable)) _CCFIsNegative(unsigned int x) { return NO; }
    static inline BOOL __attribute__((overloadable)) _CCFIsNegative(unsigned long x) { return NO; }
#else
    #define _CCFIsNegative(x) ((x) < 0)
#endif


#if defined(__cplusplus)
    extern "C" {
#endif    
    
typedef void (*CCFAssertionFailureHandler)(const char *type, const char *expression, const char *file, unsigned int lineNumber);
    
extern void CCFLogAssertionFailure(const char *type, const char *expression, const char *file, unsigned int lineNumber); // in case you want to integrate the normal behavior with your handler
    
#if defined(CCF_ASSERTIONS_ON)
    
    extern void CCFSetAssertionFailureHandler(CCFAssertionFailureHandler handler);
    
    extern void CCFInvokeAssertionFailureHandler(const char *type, const char *expression, const char *file, unsigned int lineNumber) CLANG_ANALYZER_NORETURN;
    extern void CCFAssertFailed(void) __attribute__((noinline)); // This is a convenience breakpoint for in the debugger.
    
    extern BOOL CCFEnableExpensiveAssertions;
    
    #define CCFPRECONDITION(expression)                                            \
        do {                                                                        \
            if (!(expression))                                                      \
                CCFInvokeAssertionFailureHandler("PRECONDITION", #expression, __FILE__, __LINE__); \
        } while (NO)
        
    #define CCFPOSTCONDITION(expression)                                           \
        do {                                                                        \
            if (!(expression))                                                      \
                CCFInvokeAssertionFailureHandler("POSTCONDITION", #expression, __FILE__, __LINE__); \
        } while (NO)
        
    #define CCFINVARIANT(expression)                                               \
        do {                                                                        \
            if (!(expression))                                                      \
                CCFInvokeAssertionFailureHandler("INVARIANT", #expression, __FILE__, __LINE__); \
        } while (NO)
        
    #define CCFASSERT(expression)                                                  \
        do {                                                                        \
            if (!(expression))                                                      \
                CCFInvokeAssertionFailureHandler("ASSERT", #expression, __FILE__, __LINE__); \
        } while (NO)
        
    #define CCFASSERT_NOT_REACHED(reason)                                        \
        do {                                                                        \
            CCFInvokeAssertionFailureHandler("NOTREACHED", reason, __FILE__, __LINE__); \
        } while (NO)
        
    #define CCFPRECONDITION_EXPENSIVE(expression) do { \
        if (CCFEnableExpensiveAssertions) \
            CCFPRECONDITION(expression); \
        } while(NO)
        
    #define CCFPOSTCONDITION_EXPENSIVE(expression) do { \
        if (CCFEnableExpensiveAssertions) \
            CCFPOSTCONDITION(expression); \
        } while(NO)
        
    #define CCFINVARIANT_EXPENSIVE(expression) do { \
        if (CCFEnableExpensiveAssertions) \
            CCFINVARIANT(expression); \
        } while(NO)
        
    #define CCFASSERT_EXPENSIVE(expression) do { \
        if (CCFEnableExpensiveAssertions) \
            CCFASSERT(expression); \
        } while(NO)
        
        // Scalar-taking variants that also do the test at compile time to just signal clang attributes.  The input must be a scalar l-value to avoid evaluation of code.  This will mark the value as referenced, though, so we don't get unused variable warnings.
    #define CCFASSERT_NULL(pointer) do { \
        if (pointer) { \
            void *valuePtr __attribute__((unused)) = &pointer; /* have compiler check that it is an l-value */ \
            CCFInvokeAssertionFailureHandler("CCFASSERT_NULL", #pointer, __FILE__, __LINE__); \
        } \
    } while(NO);
    #define CCFASSERT_NOTNULL(pointer) do { \
        if (!pointer) { \
            void *valuePtr __attribute__((unused)) = &pointer; /* have compiler check that it is an l-value */ \
            CCFInvokeAssertionFailureHandler("CCFASSERT_NOTNULL", #pointer, __FILE__, __LINE__); \
        } \
    } while(NO);
        
        // Useful for cases where we *currently* have unsigned values that we want to assert are non-negative but that might later become signed. For exmaple, array indexes -- if we switch between NSUInteger and CFIndex.
    #define CCFASSERT_NONNEGATIVE(x) do { \
        if (_CCFIsNegative(x)) { \
            CCFInvokeAssertionFailureHandler("CCFASSERT_NONNEGATIVE", #x, __FILE__, __LINE__); \
        } \
    } while (NO);
        
    #ifdef __OBJC__
        // Useful if you are subclassing a parent class that conforms to a protcocol with @optional methods; can assert that they *still* don't have the superclass method.
        // +instanceMethodForSelector: returns OBJC_msgForward now.
        #define CCFASSERT_NO_SUPER do { \
            Class super__ = [[self class] superclass]; \
            Method method__ = class_getInstanceMethod(super__, _cmd); \
            if (method__) \
                CCFInvokeAssertionFailureHandler("CCFASSERT_NO_SUPER", __PRETTY_FUNCTION__, __FILE__, __LINE__); \
        } while (NO)
        
        #import <Foundation/NSObject.h>
        // Useful when you are changing subclass or delegate API and you want to ensure there aren't lingering implementations of API that will no longer get called.  Uses 'const char *' to avoid warnings from -Wundeclared-selector.
        extern void _CCFAssertNotImplemented(id self, const char *selName);
        #define CCFASSERT_NOT_IMPLEMENTED(CCFj, selName) _CCFAssertNotImplemented(CCFj, #selName)
    #endif
    
#else	// else insert blank lines into the code
    
    #define CCFPRECONDITION(expression) do {} while(0)
    #define CCFPOSTCONDITION(expression) do {} while(0)
    #define CCFINVARIANT(expression) do {} while(0)
    #define CCFASSERT(expression) do {} while(0)
    #define CCFASSERT_NOT_REACHED(reason) do {} while(0)
        
    #define CCFPRECONDITION_EXPENSIVE(expression) do {} while(0)
    #define CCFPOSTCONDITION_EXPENSIVE(expression) do {} while(0)
    #define CCFINVARIANT_EXPENSIVE(expression) do {} while(0)
    #define CCFASSERT_EXPENSIVE(expression) do {} while(0)
        
        // Pointer checks to satisfy clang scan-build in non-assertion builds too.
    #define CCFASSERT_NULL(pointer) do { \
        if (pointer) { \
            void *valuePtr __attribute__((unused)) = &pointer; /* have compiler check that it is an l-value */ \
            CCFAnalyzerNotReached(); \
        } \
    } while(NO);
    #define CCFASSERT_NOTNULL(pointer) do { \
        if (!pointer) { \
            void *valuePtr __attribute__((unused)) = &pointer; /* have compiler check that it is an l-value */ \
            CCFAnalyzerNotReached(); \
        } \
    } while(NO);
        
    #define CCFASSERT_NONNEGATIVE(x) do {} while (0)
        
    #ifdef __OBJC__
        #define CCFASSERT_NO_SUPER
        #define CCFASSERT_NOT_IMPLEMENTED(CCFj, sel)
    #endif
#endif
        
#if defined(__cplusplus)
} // extern "C"
#endif
