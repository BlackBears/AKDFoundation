/**
 *   @file NSDate+CCFExtensions.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2011-07-14 08:23:20
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

#import <Foundation/NSDate.h>

@interface NSDate(CCFExtensions)

/**
 *	Returns whether a given date is later than another date
 *
 *	@param	otherDate	The NSDate to which the receiver is compared.
 *
 *	@return	Returns \c YES if the receiver is after otherDate.  Otherwise the method returns NO.
 */
- (BOOL)isAfterDate: (NSDate *) otherDate;

/**
 *	Returnes whether a given date is later
 *
 *	@param	otherDate	The NSDate to which the receiver is compared.
 *
 *	@return	Returns \c YES is the receiver is before otherDate.  Otherwise the method returns YES
 */
- (BOOL)isBeforeDate:(NSDate *) otherDate;

/**
 *	Returns a date adjusted to midnight of that day
 *
 *	@return	Returns the date specified by the receiver adjusted to midnight.
 */
- (NSDate *)dateByAdjustingToMidnight;

/**
 *	Returns a date adjusted to 11:59:59 PM of that day.
 *
 *	@return	Returns the date specified by the receiver adjusted to the end of that date (11:59:59 PM)
 */
- (NSDate *)datebyAdjustingToEndOfDay;

/**
 *	Returns a date adjusted by the given number of days
 *
 *	@param	daysToAdd	The number of days to add to the receiver.  This parameter may be negative.
 *
 *	@return	Returns the date specified by the receiver adjusted by the given number of days.
 */
- (NSDate *)dateByAddingDays:(NSInteger)daysToAdd;

/**
 *	Returns a date adjusted to the previous day
 *
 *	@return	Returns the date specified by the receiver with one day subtracted.
 */
- (NSDate *)dateByAdjustingToPreviousDay;

/**
 *	Returns a date adjusted to the next day
 *
 *	@return	Returns the date specified by the receiver with one day added.
 */
- (NSDate *)dateByAdjustingToNextDay;

/**
 *	Creates a date by adjusting receiver to the start of the previous day.
 *
 *	@return	Returns the date specified by the receiver adjusted to the start of the previous day.
 */
- (NSDate *)dateByAdjustingToStartOfPreviousDay;

/**
 *	Creates a date by adjusting the receiver to the end of the next day.
 *
 *	@return	Returns the date specified by the receiver adjusted to the end of the next day.
 */
- (NSDate *)dateByAdjustingToEndOfNextDay;

/**
 *	Creates a random date offset from the receiver, either before or after the receiver as determined by the \c beforeFlag parameter.
 *
 *	@param	maxOffset	The maximum offset in days from the receiver
 *	@param	beforeFlag	Determines whether the offset is applied before or after the receiver.  If \c YES, the random offset
 *                      is applied positively to the receiver, thereby creating a date that is after the receiver.  If \c NO, the 
 *                      random offset is applied after the receiver.
 *
 *	@return	Returns a randomly adjusted date
 */
- (NSDate *)dateByAddingRandomOffset:(NSInteger)maxOffset before:(BOOL)beforeFlag;

@end
