#import "NSString+Encryption.h"
#import "NSString+CCFExtensions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#import "NSData+CCFExtensions.h"

static NSString * const GenericEncryptionKey = @"588061e4f996295baca65dd480dbf5953860e85091e01ad748a4004fda7d8bd87b929b55cf5f92633063e8e0e70cb2ccb1ba924f3e7bf2557ada91a8d53087ece05716fa1bcb18481bcdd5be7ebc3e2c53580d0111f21ab1921eab82908b60b3a835864e5252b90f43b00f2230f889bf9f71ac3706b70fe9d22e947c675402f4b81c95d68c015a01bf582cf84698ed55ce638f891a80e0ceba70f0c36b638ec4f0d114efa75613e9866e31fece17a388f85dac1b310949011dd97c0e873adb3621db95228803d78961deea4cc3ec3394fda255d141d3e33702a9b9839f9afff60ce2cb6b0c99a00caa4006c547aac77e6670a18af6aa59425dfc9a139465d3";
static NSString * const PasswordEncryptionKey = @"0a0ec40befe2caf7c85a9d5d62308d41af159306f0910e85470c53d22f442752e17df3c40ab8219cfa555439131eabc0ad41d636ec0c4a0d7568fc9e1482e8fb516843100607a6f4e23872fd7f6cddc328a2162acd40129bfe9cef7a7d847de0f32f5f688ab44eb06551f31dc01786dbca426da457cf791f56babcc122191bf0cd200abc634f2825abec80c549c7d4aacf5020c66e4a8d455162accbc341fcf46f04c2bbe10e903c8b90469657490b66d6eaa7c3b9ba50b3ead9c25ec5637d0ee3312313d50e405f8fd26ab7cafeabab7d443e82a307dec422acc2631022cc48a2d58428af86561cf360f0ef24e2741dc4112d0cbc2ea30d053e2338f19b0b";
static NSString * const UsernameEncryptionKey = @"aec06fb8bc0f0524d2d313a32900b82e69b718d488e525631791fabcbe66ca956570d3201d9adfc51475b00455edec0e1924ed930ee4db98feb66bc8df38f1f239ad1fe23ba97d1ac2f6b5ad967224623490bc87e9650074a852b90ac8b9c5c0f5b11d1f5b9b4180fa6e75ddb107103022d614694884aec95b5dc15b190d12e06da8946eb8a8625d80adca70d6b285129160d67b185a09e721598da84a6287e509d9009b37659895297e8d4a28b213ef95dcd7b97fe2d6c754e194c1467236fddef69f2b6d4715b886c530ea02ff8f0b72cfb9964406ccbf4c6c3c3dce772b0f0c9a94f597ef0bc352fcb39e74476eb23dd8967c04fb1c78a74cdf72706c31";

@implementation NSString (Encryption)

#pragma mark - Public

- (NSString *)stringEncodedWithKey:(NSString *)key {
    assert(key && "key must be non-nil");
    //  convert ourself and the key to NSData
    NSData *textData = [self dataUsingEncoding:NSUTF8StringEncoding];
    NSData *keyData = [NSData dataWithHexString:key];
    // string to hold output
    NSMutableString *mutableOutString = [[NSMutableString alloc] initWithCapacity:self.length * 2];
    //  get bytes from key data
    unsigned char *xorKey = calloc(keyData.length, sizeof(unsigned char));
    [keyData getBytes:xorKey];
    
    //  xor processing
    for( int i = 0; i < self.length; i++ ) {
        u_int8_t inByte;
        [textData getBytes:&inByte range:(NSRange){ .location = i, .length = 1}];
        u_int8_t xorByte = inByte ^ xorKey[i];
        //  append the processed byte to our output string
        [mutableOutString appendFormat:@"%02x",xorByte];
    }
    return [NSString stringWithString:mutableOutString];
}

- (NSString *)stringEncodedWithScheme:(encoder_scheme_t)scheme {
    assert( ( (scheme == ENCODER_SCHEME_USERNAME) || (scheme == ENCODER_SCHEME_PASSWORD) || (scheme == ENCODER_SCHEME_GENERIC)) && "scheme out of range");
    return [self stringEncodedWithKey:[self keyForScheme:scheme]];
}

- (NSString *)stringBySaltingToMinimumLength:(NSInteger)minLength {
    if( minLength < self.length + 5 ) {
        minLength = self.length + 5;
    }
    NSInteger padLength = minLength - self.length - 1;
    NSString *padString = [NSString randomStringLength:padLength withLowercase:YES specialSymbols:NO];
    NSString *separator = @"ᐛ";
    return [self stringByAppendingFormat:@"%@%@",separator, padString];
}

#pragma mark - Private


- (NSString *)keyForScheme:(encoder_scheme_t)scheme {
    switch( scheme ) {
        case ENCODER_SCHEME_USERNAME:
            return UsernameEncryptionKey;
            break;
        case ENCODER_SCHEME_PASSWORD:
            return PasswordEncryptionKey;
            break;
        case ENCODER_SCHEME_GENERIC:
            return GenericEncryptionKey;
    }
}
@end
