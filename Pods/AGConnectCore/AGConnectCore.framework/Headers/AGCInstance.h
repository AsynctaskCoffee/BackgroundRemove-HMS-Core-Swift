//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//
#import <Foundation/Foundation.h>
#import "AGCServicesConfig.h"

NS_ASSUME_NONNULL_BEGIN

/// AGConnect SDK 实例
@interface AGCInstance : NSObject

/// AGC的配置信息
@property(nonatomic,strong,readonly)AGCServicesConfig *config;

/// SDK初始化接口，需要在应用的AppDelegate的Launch中调用
+ (void)startUp;

/// SDK初始化接口，需要在应用的AppDelegate的Launch中调用
/// @param config 使用指定配置初始化
+ (void)startUp:(AGCServicesConfig *)config;

/// 返回单例
+ (instancetype)sharedInstance;

/// 获取指定服务
/// @param protocol 服务接口
- (id _Nullable)getService:(Protocol *)protocol;

@end

NS_ASSUME_NONNULL_END
