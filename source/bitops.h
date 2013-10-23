/**
 *   @file bitops.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2013-10-12 09:01:46
 *
 *   @note Copyright 2013 Cocoa Factory, LLC.  All rights reserved
 */

#include <stdint.h>
#include <stdbool.h>

#pragma mark - Circular rotation

/**
 *	Rotate the bits of an unsigned integer in the leftward direction
 *
 *	@param	value	The value to rotate
 *	@param	shift	The number of bits to rotate
 *
 *	@return	The provided value with bits rotated \c shift bits to the left.
 */
extern unsigned int rotl(unsigned int value, int shift);

/**
 *	Rotate the bits of an unsigned integer in the rightward direction
 *
 *	@param	value	The value to rotate
 *	@param	shift	The number of bits to rotate
 *
 *	@return	The provided value with bits rotated \c shift bits to the right.
 */
extern unsigned int rotr(unsigned int value, int shift);

/**
 *	Rotate the bits of an unsigned 32-bit integer in the leftward direction
 *
 *	@param	value	The value to rotate
 *	@param	shift	The number of bits to rotate
 *
 *	@return	The provided value with bits rotated \c shift bits to the left.
 */
extern uint32_t rotl32(uint32_t value, int shift);

/**
 *	Rotate the bits of an unsigned 32-bit integer in the rightward direction
 *
 *	@param	value	The value to rotate
 *	@param	shift	The number of bits to rotate
 *
 *	@return	The provided value with bits rotated \c shift bits to the right.
 */
extern uint32_t rotr32(uint32_t value, int shift);

/**
 *	Rotate the bits of an unsigned 8-bit integer in the leftward direction
 *
 *	@param	value	The value to rotate
 *	@param	shift	The number of bits to rotate
 *
 *	@return	The provided value with bits rotated \c shift bits to the left.
 */
extern uint8_t rotl8(uint8_t value, int shift);

/**
 *	Rotate the bits of an unsigned 8-bit integer in the rightward direction
 *
 *	@param	value	The value to rotate
 *	@param	shift	The number of bits to rotate
 *
 *	@return	The provided value with bits rotated \c shift bits to the right.
 */
extern uint8_t rotr8(uint8_t value, int shift);

#pragma mark - Setting and clearing bits

/**
 *	Sets the given bit in a signed integer
 *
 *	@param	value	A pointer to the integer to set
 *	@param	bit	The index of the bit to be set
 */
extern void sbi(int *value, uint8_t bit);

/**
 *	Clears a specific bit in an integer
 *
 *	@param	value	The value whose bits are to be modified
 *	@param	bit	The index of the bit to be cleared
 *
 *	@return	The provided value with the bit cleared.
 */
extern int cbi(int value, uint8_t bit);

#pragma mark - Testing signedness

/**
 *	Determines whether two 32-bit integers have opposite signs
 *
 *	@param	x	The first integer to compare
 *	@param	y	The other integer to compare
 *
 *	@return	bool true if the integers have the same sign
 */
extern bool signs_opposite32(int32_t x, int32_t y);

/**
 *	Determines whether two 64-bit integers have opposite signs
 *
 *	@param	x	The first integer to compare
 *	@param	y	The other integer to compare
 *
 *	@return	bool true if the integers have the same sign
 */
extern bool signs_opposite64(int64_t x, int64_t y);

#pragma mark - Minimum and maximum

/**
 *	Returns the minimum of two 32-bit integers
 *
 *	@param	x	The first integer to compare
 *	@param	y	The other integer to compare
 *
 *	@return	Returns the minimum of the two integers
 */
extern int32_t min32(int32_t x, int32_t y);

/**
 *	Returns the minimum of two 64-bit integers
 *
 *	@param	x	The first integer to compare
 *	@param	y	The other integer to compare
 *
 *	@return	Returns the minimum of the two integers
 */
extern int64_t min64(int64_t x, int64_t y);

/**
 *	Returns the maximum of two 32-bit integers
 *
 *	@param	x	The first integer to compare
 *	@param	y	The other integer to compare
 *
 *	@return	Returns the maximum of the two integers
 */
extern int32_t max32(int32_t x, int32_t y);

/**
 *	Returns the maximum of two 64-bit integers
 *
 *	@param	x	The first integer to compare
 *	@param	y	The other integer to compare
 *
 *	@return	Returns the maximum of the two integers
 */
extern int64_t max64(int64_t x, int64_t y);

/**
 *	Determines if an unsigned 32-bit integer is a power of 2
 *
 *	@param	v	The integer to test
 *
 *	@return	Boolean true if the provided integer is a power of 2
 */
extern bool is2power32(uint32_t v);

/**
 *	Determines if an unsigned 64-bit integer is a power of 2
 *
 *	@param	v	The integer to test
 *
 *	@return	Boolean true if the provided integer is a power of 2
 */
extern bool is2power64(uint64_t v);

#pragma mark - Testing for ranges of bytes in a word

/**
 *	Determines whether a 32-bit word has any 8-bit byte range of 0
 *
 *	@param	v	The 32-bit word to examine
 *
 *	@return	Boolean true if the provided word has any 8-bit range of 0
 */
extern bool haszero32(uint32_t v);


#pragma mark - Round up power of 2

/**
 *	Rounds a 32-bit integer up to the next highest power of 2
 *
 *	@param	v	The unsigned 32-bit integer to round
 *
 *	@return	The value of \c v rounded up to the next highest power of 2
 */
extern uint32_t round2pwr32(uint32_t v);

/**
 *	Rounds a 64-bit integer up to the next highest power of 2
 *
 *	@param	v	The unsigned 64-bit integer to round
 *
 *	@return	The value of \c v rounded up to the next highest power of 2
 */
extern uint64_t round2pwr64(uint64_t v);

#pragma mark - Count bits set

extern uint32_t bitcount32(uint32_t v);


#define nothing