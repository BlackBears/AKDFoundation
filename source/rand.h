//
//  rand.h
//  CCFFoundation
//
//  Created by Duncan Alan on 1/23/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef CCFFoundation_rand_h
#define CCFFoundation_rand_h

/**
 *	Returns a random integer under a given value.
 *
 *	@param	topPlusOne	The bounding value for the random number.  The returned integer will always be at most one less than this value.
 *
 *
 *	@return	The random value
 */
int RandomUnder(int topPlusOne);

/**
 *	Returns a random integer within a given range
 *
 *	@param	bottom	The bottom value for the range, inclusive.
 *	@param	top	The top value for the range, exclusive
 *
 *	@return	The random value
 */
int RandomInRange(int bottom, int top);

/**
 *	Returns a random float value within a given range
 *
 *	@param	bottom	The bottom of the float range
 *	@param	top	The top of the float range
 *
 *	@return	The random floating point value
 */
float RandomFloatInRange(float bottom, float top);

#endif
