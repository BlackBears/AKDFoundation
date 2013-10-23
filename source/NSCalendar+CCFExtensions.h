/**
 *   @file NSCalendar+CCFExtensions.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2013-10-17 04:44:53
 *
 *   @note Copyright 2013 Cocoa Factory, LLC.  All rights reserved
 */


/**
 *	A category on \NSCalendar that has methods that are useful to CCF.  
 *
 *  @note   The method \c ojf_isDate:equalToDate:withGranularity is licensed from Oliver Foggin according to the terms
 *          of the Apache license.
 */
@interface NSCalendar (CCFExtensions)

/**
 *	Determines whether two dates are equal with a given granularity
 *
 *	@param	date1	The first date to compare
 *	@param	date2	The other date to compare
 *	@param	granularity	The granularity in \c NSCalendarUnit increments
 *
 *  @note   This method is by Oliver Foggin and is made available under the Apache License.
 *          A similar method was available in the early betas of iOS 7 but removed from the GM and release versions.
 *
 *	@return	\c YES if the two dates are equal within the limits of the granularity provided, otherwise \c no
 */
- (BOOL)ojf_isDate:(NSDate *)date1 equalToDate:(NSDate *)date2 withGranularity:(NSCalendarUnit)granularity;

@end
