/**
 *   @file CCFUnicodeUtilities.h
 *   @author Alan Duncan (www.cocoafactory.com)
 *
 *   @date 2011-07-20 08:42:56
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

#ifndef CCFFoundation_CCFUnicodeUtilities_h
#define CCFFoundation_CCFUnicodeUtilities_h

// Copyright 2000-2008, 2010-2011 Omni Development, Inc.  All rights reserved.
//
// This software may only be used and reproduced according to the
// terms in the file OmniSourceLicense.html, which should be
// distributed with this project and can also be found at
// <http://www.omnigroup.com/developer/sourcecode/sourcelicense/>.
//
// $Id$

/* From the Unicode standard:
 * U+FFFD REPLACEMENT CHARACTER 
 * used to replace an incoming character whose value is unknown or unrepresentable in Unicode
 */
#define CCF_UNICODE_REPLACEMENT_CHARACTER ((unichar)0xFFFD)

/* A hopefully-unused CFStringEncoding value, which we use for scanning strings which are in an unknown ASCII superset (e.g. Latin-1, UTF-8, etc.). Non-ASCII bytes are mapped up into a range in the Supplemental Use Area A. This is useful for the annoying situation in which one part of a string tells us how to interpret another part of the string, and different parts may be in different character sets; the supplemental-use area keeps the unknown bytes out of the way (and hopefully unmolested) until we can re-encode them. To re-encode a string which was scanned in the "deferred ASCII superset encoding", see -[NSString stringByApplyingDeferredEncoding:], as well as the functions in this file. */
#define CCFDeferredASCIISupersetStringEncoding (0x10000001U)

#define CCFDeferredASCIISupersetBase (0xFA00)  /* Base value for the deferred decoding mentioned above. Don't use this value directly; use a helper function. This is here so that it can be included in inlined helper functions. */

/* General string utilities for dealing with surrogate pairs (UTF-16 encodings of UCS-4 characters) */
enum CCFIsSurrogate {
    CCFIsSurrogate_No = 0,
    CCFIsSurrogate_HighSurrogate = 1,
    CCFIsSurrogate_LowSurrogate = 2
};

/* Determines whether a given 16-bit unichar is part of a surrogate pair */
static inline enum CCFIsSurrogate CCFCharacterIsSurrogate(unichar ch)
{
    /* The surrogate ranges are conveniently lined up on power-of-two boundaries.
     ** Since the common case is that a character is not a surrogate at all, we
     ** test for that first.
     */
    if (__builtin_expect((ch & 0xF800) == 0xD800, 0)) {
        if ((ch & 0x0400) == 0)
            return CCFIsSurrogate_HighSurrogate;
        else
            return CCFIsSurrogate_LowSurrogate;
    } else
        return CCFIsSurrogate_No;
}

/* Combines a high and a low surrogate character into a 21-bit Unicode character value */
static inline UnicodeScalarValue CCFCharacterFromSurrogatePair(unichar high, unichar low)
{
    return 0x10000 + (
                      ( (UnicodeScalarValue)(high & 0x3FF) << 10 ) |
                      (UnicodeScalarValue)(low & 0x3FF)
                      );
}

/* Splits a Supplementary Plane character into two UTF-16 surrogate characters */
/* Do not use this for characters in the Basic Multilinugal Plane */
static inline void CCFCharacterToSurrogatePair(UnicodeScalarValue inCharacter, unichar *outUTF16)
{
    UnicodeScalarValue supplementaryPlanePoint = inCharacter - 0x10000;
    
    outUTF16[0] = 0xD800 | ( supplementaryPlanePoint & 0xFFC00 ) >> 10; /* high surrogate */
    outUTF16[1] = 0xDC00 | ( supplementaryPlanePoint & 0x003FF );       /* low surrogate */
}


// Some defines for Unicode characters
enum {
    CCFLeftQuoteCharacter = 8220,
    CCFRightQuoteCharacter = 8221,
};


#endif
