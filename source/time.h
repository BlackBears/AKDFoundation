

#ifndef __CCF_TIME_H_
#define __CCF_TIME_H_

#ifdef __OBJC__

#import <dispatch/dispatch.h>
#import <Foundation/NSDate.h>

extern const int64_t DISPATCH_DELAY_1_SEC;
extern const int64_t DISPATCH_DELAY_2_SEC;
extern const int64_t DISPATCH_DELAY_1_2_SEC;
extern const int64_t DISPATCH_DELAY_1_10_SEC;
extern const int64_t DISPATCH_DELAY_2_10_SEC;
extern const int64_t DISPATCH_DELAY_3_10_SEC;
extern const int64_t DISPATCH_DELAY_6_10_SEC;
extern const int64_t DISPATCH_DELAY_3_4_SEC;

/**
 *	Returns a \c dispatch_time_t representing the number of nanoseconds from now
 *
 *	@param	nanosec	Delay in nanoseconds
 *
 *	@return	\c dispatch_time_t value for the desired future time
 */
extern dispatch_time_t ccf_dispatch_time(int64_t nanosec);

/**
 *	Enque a block for execution on the main queue after the specified delay
 *
 *	@param	delay	The delay in seconds before execution of the block
 *	@param	block	The block to submit.  This parameter cannot be \c NULL.  A \c Block_copy and \c Block_release is
 *                  performed on behalf of the caller.
 */
extern void ccf_gcd_delay_main_queue(NSTimeInterval delay, dispatch_block_t block);

/**
 *	Enqueue a block for execution on the main queue 2 second3 from now.
 *
 *	@param	block	The block to submit.  This parameter cannot be \c NULL.  A \c Block_copy and \c Block_release is
 *                  performed on behalf of the caller.
 */
extern void ccf_gcd_delay_main_queue_2_sec(dispatch_block_t block);

/**
 *	Enqueue a block for execution on the main queue 1 second from now.
 *
 *	@param	block	The block to submit.  This parameter cannot be \c NULL.  A \c Block_copy and \c Block_release is
 *                  performed on behalf of the caller.
 */
extern void ccf_gcd_delay_main_queue_1_sec(dispatch_block_t block);


/**
 *	Enqueue a block for execution on the main queue 0.75 seconds from now.
 *
 *	@param	block	The block to submit.  This parameter cannot be \c NULL.  A \c Block_copy and \c Block_release is
 *                  performed on behalf of the caller.
 */
extern void ccf_gcd_delay_main_queue_3_4_sec(dispatch_block_t block);

/**
 *	Enqueue a block for execution on the main queue 0.5 seconds from now.
 *
 *	@param	block	The block to submit.  This parameter cannot be \c NULL.  A \c Block_copy and \c Block_release is
 *                  performed on behalf of the caller.
 */
extern void ccf_gcd_delay_main_queue_1_2_sec(dispatch_block_t block);

/**
 *	Enqueue a block for execution on the main queue 0.1 seconds from now
 *
 *	@param	block	The block to submit.  This parameter cannot be \c NULL.  A \c Block_copy and \c Block_release is
 *                  performed on behalf of the caller.
 */
extern void ccf_gcd_delay_main_queue_1_10_sec(dispatch_block_t block);

/**
 *	Enqueue a block for execution on the main queue 0.2 seconds from now.
 *
 *	@param	block	The block to submit.  This parameter cannot be \c NULL.  A \c Block_copy and \c Block_release is
 *                  performed on behalf of the caller.
 */
extern void ccf_gcd_delay_main_queue_2_10_sec(dispatch_block_t block);

/**
 *	Enqueue a block for execution on the main queue 0.3 seconds from now
 *
 *	@param	block	The block to submit.  This parameter cannot be \c NULL.  A \c Block_copy and \c Block_release is
 *                  performed on behalf of the caller.
 */
extern void ccf_gcd_delay_main_queue_3_10_sec(dispatch_block_t block);

extern void ccf_gcd_delay_main_queue_6_10_sec(dispatch_block_t block);

#endif

#endif
