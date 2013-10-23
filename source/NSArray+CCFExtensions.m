#import "NSArray+CCFExtensions.h"


@implementation NSArray(CCFExtensions)

- (id)firstObject {
	return [self objectAtIndex:0];
}

// -------------------------------------------------------------------------------
//  containsObjectIdenticalTo:obj:
// -------------------------------------------------------------------------------
- (BOOL)containsObjectIdenticalTo:(id)obj
{ 
    return [self indexOfObjectIdenticalTo:obj] != NSNotFound; 
}

// -------------------------------------------------------------------------------
//  containsAnyObjectsIdenticalTo:objects:
// -------------------------------------------------------------------------------
- (BOOL)containsAnyObjectsIdenticalTo:(NSArray*)objects
{
    NSEnumerator *e = [objects objectEnumerator];
    id obj;
    while (obj = [e nextObject])
    {
        if ([self containsObjectIdenticalTo:obj])
            return YES;
    }
    return NO;
}

// -------------------------------------------------------------------------------
//  indexesOfObjects:objects:
// -------------------------------------------------------------------------------
- (NSIndexSet *)indexesOfObjects:(NSArray*)objects
{
    NSMutableIndexSet *indexSet = [NSMutableIndexSet indexSet];
    NSEnumerator *enumerator = [objects objectEnumerator];
    id obj = nil;
    NSInteger index;
    while (obj = [enumerator nextObject])
    {
        index = [self indexOfObject:obj];
        if (index != NSNotFound)
            [indexSet addIndex:index];
    }
    return indexSet;
}
/*
#ifdef NS_BLOCKS_AVAILABLE

- (NSDictionary *)indexByBlock:(CCFObjectToObjectBlock)block;
{
    NSMutableDictionary *dict = [[NSMutableDictionary alloc] initWithCapacity:[self count]];
    
    for( id object in self )
    {
        id key;
        if(( key = block(object) ) != nil)
            [dict setObject:object forKey:key];
    }
    
    NSDictionary *result = [NSDictionary dictionaryWithDictionary:dict];
    [dict release];
    return result;
}

- (NSArray *)arrayByPerformingBlock:(CCFObjectToObjectBlock)block;
{
    NSMutableArray *result = [NSMutableArray arrayWithCapacity:[self count]];
    
    for( id singleObject in self )
    {
        id selectorResult = block(singleObject);
        if( selectorResult )
            [result addObject:selectorResult];
    }
    
    return result;
}

#endif
 */

@end
