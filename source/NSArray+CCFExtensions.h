/**
 *   @file NSArray+CCFExtensions.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2009-12-30 08:46:47
 *
 *   @note Copyright 2013 Cocoa Factory, LLC.  All rights reserved
 *
 
 */

#import <Foundation/NSArray.h>

/**
 *	A category on NSArray to support some common features needed by CCF
 */
@interface NSArray(CCFExtensions)

/**
 *	The equivalent of objectAtIndex:0, just easier to write
 *
 *	@return	The first element of an array
 */
- (id)firstObject;

/**
 *	Receiver contains an object whose address is the same as the provided object
 *
 *	@param	obj	The object whose address is being looked for in the array
 *
 *	@return	Returns YES if the receiver contains an object with the same address as obj
 */
- (BOOL)containsObjectIdenticalTo:(id)obj;

/**
 *	Receiver contains any object identical to provided object
 *
 *	@param	objects	The NSArray containing object to compare to the objects in the receiver
 *
 *	@return	Returns YES if the receiver contains any object whose address is that same as any object in obj.
 */
- (BOOL)containsAnyObjectsIdenticalTo:(NSArray*)objects;

/**
 *	Returns an index set representing the indices of the objects in the receiver
 *
 *	@param	objects	The comparison object array
 *
 *	@return	Returns an index set whose indices are the indices of objects in the receiver.
 */
- (NSIndexSet *)indexesOfObjects:(NSArray*)objects;

/*
#ifdef NS_BLOCKS_AVAILABLE
- (NSDictionary *)indexByBlock:(CCFObjectToObjectBlock)block;
- (NSArray *)arrayByPerformingBlock:(CCFObjectToObjectBlock)block;
#endif
 */

@end
