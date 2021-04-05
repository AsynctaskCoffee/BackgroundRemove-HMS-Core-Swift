//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AGCToken : NSObject

@property(nonatomic, readonly) long expiration;
@property(nonatomic, readonly, nullable) NSString *tokenString;

- (instancetype)initWithToken:(NSString *)token expiration:(long)expiration;

@end

NS_ASSUME_NONNULL_END
