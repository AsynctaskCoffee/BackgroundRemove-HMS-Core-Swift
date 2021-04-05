//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import <HMFoundation/HMFoundation.h>

@class AGCToken;

@protocol AGCCredentialsProvider <NSObject>

- (HMFTask<AGCToken *> *)getToken;
- (HMFTask<AGCToken *> *)getToken:(BOOL)isForceRefresh;

@end
