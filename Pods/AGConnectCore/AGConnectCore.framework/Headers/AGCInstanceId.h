//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import <Foundation/Foundation.h>
#import <HMFoundation/HMFoundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
 * 设备唯一标识
 */
@interface AGCInstanceId : NSObject

/**
 * 获取uuid
 */
@property(nonatomic, readonly, nullable)NSString *uuid;

/**
 * uuid生成时间
 */
@property(nonatomic,readonly, nullable)NSDate *createTime;

/**
 * 获取单例
 * @return 单例
 */
+ (instancetype)sharedInstance;

/**
 * 获取uuid
 * @return 获取uuid的Task
 */
- (HMFTask<NSString *> *)getUUID;

/**
 * 删除uuid
 */
- (void)deleteUUID;

@end

NS_ASSUME_NONNULL_END
