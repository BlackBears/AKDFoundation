
#import "macros.h"
#import <mach/mach_time.h>

/**
 *	Prints a log item without extract cruft
 *
 *	@param	format	The print string format
 *	@param	...	The contents to print
 */
void QuietLog (NSString *format, ...)
{
#if DEBUG == 1
    if (format == nil) {
        printf("nil\n");
        return;
    }
    // Get a reference to the arguments that follow the format parameter
    va_list argList;
    va_start(argList, format);
    // Perform format string argument substitution, reinstate %% escapes, then print
    NSString *s = [[NSString alloc] initWithFormat:format arguments:argList];
    printf("%s\n", [[s stringByReplacingOccurrencesOfString:@"%%" withString:@"%%%%"] UTF8String]);
    va_end(argList);
#endif
}

/**
 *	Prints a log note without extra cruft
 *
 *	@param	format	The print log string format
 *	@param	...	The contents to print
 */
void QuietNote( NSString *format, ...)
{
#if DEBUG == 1
    if (format == nil) {
        printf("nil\n");
        return;
    }
    // Get a reference to the arguments that follow the format parameter
    va_list argList;
    va_start(argList, format);
    // Perform format string argument substitution, reinstate %% escapes, then print
    NSMutableString *mutableNote = [[NSMutableString alloc] initWithString:@"NOTE | "];
    NSString *s = [[NSString alloc] initWithFormat:format arguments:argList];
    [mutableNote appendString:s];
    [mutableNote replaceOccurrencesOfString:@"%%" withString:@"%%%%" options:NSLiteralSearch range:NSMakeRange(0, [mutableNote length])];
    printf("%s\n", [mutableNote UTF8String]);
    va_end(argList);
#endif
}

/**
 *	Accurately times a block of code
 *
 *	@param	^block	The block to be executed and timed
 *
 *	@return	Returns the time required to execute the block in seconds
 */
float BNRTimeBlock (void (^block)(void)) {
    mach_timebase_info_data_t info;
    if (mach_timebase_info(&info) != KERN_SUCCESS) return -1.0;
    
    uint64_t start = mach_absolute_time ();
    block ();
    uint64_t end = mach_absolute_time ();
    uint64_t elapsed = end - start;
    
    uint64_t nanos = elapsed * info.numer / info.denom;
    return (float)nanos / NSEC_PER_SEC;
    
}

/**
 *	Returns the entire range of a string
 *
 *	@param	string	The strings whose range should be returned
 *
 *	@return	The range of the entire string as an NSRange struct.
 */
NSRange entireStringRange(id string) {
    return NSMakeRange(0, [string length] );
}


/**
 *	Returns the path to a given resources
 *
 *	@param	owner	The object whose class the bundle belongs to
 *	@param	name	The name of the resource as a string
 *	@param	extension	The extension type of the resource
 *
 *	@return	Returns the path to the resource
 */
id resourcePath(id owner, NSString *name, NSString *extension) {
    return [[NSBundle bundleForClass:[owner class]] pathForResource:name ofType:extension];
}

/**
 *	Returns the path to a given resource in a subdirectory
 *
 *	@param	owner	The object to whose class the bundle belongs
 *	@param	name	The name of the resource as a string
 *	@param	extension	The extension type of the resource
 *	@param	subdirectory	The name of the subdirectory in the bundle
 *
 *	@return	Returns the path to the specified resource
 */
id resourcePathInDirectory( id owner, NSString *name, NSString *extension, NSString *subdirectory)
{
    return [[NSBundle bundleForClass:[owner class]] pathForResource:name ofType:extension inDirectory:subdirectory];
}