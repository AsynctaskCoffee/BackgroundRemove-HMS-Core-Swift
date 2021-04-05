//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// HMFTask中要执行的代码块封装，调用此回调会触发Task执行
typedef void (^HMFRunnable)(void);

/// 执行代码块方式协议
NS_SWIFT_NAME(Executor)
@protocol HMFExecutor <NSObject>

/// 在自定义的线程或者队列执行代码块
/// @param runnable 触发要执行的代码块
- (void)run:(HMFRunnable)runnable;

@end

/// 执行线程封装
NS_SWIFT_NAME(Executors)
@interface HMFExecutors : NSObject

/// 在主线程执行
+ (id<HMFExecutor>)main;

/// 在任务执行线程立刻执行
+ (id<HMFExecutor>)immediate;

/// 在后台并行队列执行
+ (id<HMFExecutor>)background;

/// 在后台并行队列执行
/// @param label 队列名称
+ (id<HMFExecutor>)concurrent:(NSString *)label;

/// 在后台串行队列执行
/// @param label 队列名称
+ (id<HMFExecutor>)serial:(NSString *)label;

@end

NS_ASSUME_NONNULL_END
