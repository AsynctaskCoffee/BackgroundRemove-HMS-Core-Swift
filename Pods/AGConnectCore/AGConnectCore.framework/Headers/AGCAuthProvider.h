//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import <Foundation/Foundation.h>
#import <HMFoundation/HMFoundation.h>
#import "AGCToken.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AGCAuthProvider <NSObject>

- (HMFTask<AGCToken *> *)getToken;
- (HMFTask<AGCToken *> *)getToken:(BOOL)isForceRefresh;
- (nullable NSString *)getUid;

@end

NS_ASSUME_NONNULL_END
