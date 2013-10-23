#import "NSData+CCFExtensions.h"

@implementation NSData (CCFExtensions)

+ (NSData *)dataWithHexString:(NSString *)hexString {
    //  normalize to lowercase
    hexString = [hexString lowercaseString];
    NSMutableData *mutableData = [NSMutableData data];
    unsigned char whole_byte;
    char byte_chars[3] = {'\0','\0','\0'};
    int i = 0;
    NSUInteger length = hexString.length;
    while (i < length-1) {
        char c = [hexString characterAtIndex:i++];
        if (c < '0' || (c > '9' && c < 'a') || c > 'f')
            continue;
        byte_chars[0] = c;
        byte_chars[1] = [hexString characterAtIndex:i++];
        whole_byte = strtol(byte_chars, NULL, 16);
        [mutableData appendBytes:&whole_byte length:1];
    }
    return [NSData dataWithData:mutableData];
}

@end