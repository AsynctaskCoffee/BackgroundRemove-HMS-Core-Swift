//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// AGC 服务
@interface AGCService : NSObject

/// 服务的实现类
@property(nonatomic, readonly) Class service;

/// 服务实现的协议
@property(nonatomic, readonly) Protocol *protocol;

/// 是否是单例实现
@property(nonatomic, readonly) BOOL isSingleInstance;

/// 服务初始化回调
@property(nonatomic, nullable, readonly) id (^instanceInitFunction)(void);

/// 初始化
/// @param service 服务实现类
/// @param protocol 服务实现协议
- (instancetype)initWithService:(Class)service protocol:(Protocol *)protocol;

/// 初始化
/// @param service 服务实现类
/// @param protocol 服务实现协议
/// @param isSingle 是否是单例
- (instancetype)initWithService:(Class)service
                       protocol:(Protocol *)protocol
               isSingleInstance:(BOOL)isSingle;

/// 初始化
/// @param service 服务实现类
/// @param protocol 服务实现协议
/// @param isSingle 是否是单例
/// @param initFunction 服务实现类初始化回调
- (instancetype)initWithService:(Class)service
                       protocol:(Protocol *)protocol
               isSingleInstance:(BOOL)isSingle
                   initFunction:(id (^_Nullable)(void))initFunction;

@end

/// 服务注册器协议
@protocol AGCServiceRegistrar <NSObject>

@optional
/// 返回注册的服务
+ (NSArray<AGCService *> *)getService;
/// SDK的初始化回调
+ (void)startUp;
/// 返回SDK版本号
+ (NSString *)sdkVersion;
/// 返回SDK名称
+ (NSString *)sdkName;

@end

/// 需要各个SDK在 +(void)load 方法中注册各自的注册器
@interface AGCServiceRepository : NSObject

/// 注册
/// @param serviceClass 服务注册器
+ (void)registryService:(Class<AGCServiceRegistrar>)serviceClass;

@end

NS_ASSUME_NONNULL_END
