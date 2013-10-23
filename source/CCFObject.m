//
//  CCFObject.m
//  CCFFoundation
//
//  Created by alanduncan on 2/4/13.
//  Copyright (c) 2013 Cocoa Factory, LLC. All rights reserved.
//

#import "CCFObject.h"

@implementation CCFObject

#ifdef DEBUG_INITIALIZE
static NSMutableDictionary *InitializedClasses;
#endif

+ (void)initialize {
    static BOOL Initialized = NO;
    
    [super initialize];
    
    if( !Initialized ) {
        Initialized = YES;
    }
    
#ifdef DEBUG_INITIALIZE
#warning CCFObject initialize debugging enabled
    NSLog(@"+[CCFObject initialize] debugging enabled -- ",@"Should disable in production code");
    InitializedClasses = [[NSMutableDictionary alloc] initWithCapacity:512];
#endif
    
    //  ?postloader
    
#ifdef DEBUG_INITIALIZE
    [InitializedClasses setObject:self forKey:NSStringFromClass(self)];
#endif
}

/*
 Returns a mutable dictionary describing the contents of the object. Subclasses should override this method, call the superclass implementation, and then add their contents to the returned dictionary. This is used for debugging purposes. It is highly recommended that you subclass this method in order to add information about your custom subclass (if appropriate), as this has no performance or memory requirement issues (it is never called unless you specifically call it, presumably from withing a gdb debugging session).
 
 See also: - shortDescription (NSObject)
 */
- (NSMutableDictionary *)debugDictionary;
{
    NSMutableDictionary *dict = [NSMutableDictionary dictionary];
    [dict setObject:[self shortDescription] forKey:@"__self__"];
    return dict;
}

/*"
 Returns -description but can be customized to return some small amount of extra information about the instance itself (though not its contents).
 
 See also: - description (NSObject)
 "*/
- (NSString *)shortDescription;
{
    return [self description];
}

@end
