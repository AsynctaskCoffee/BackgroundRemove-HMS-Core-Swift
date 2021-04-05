//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import <Foundation/Foundation.h>
#import "HMFTask.h"

NS_ASSUME_NONNULL_BEGIN

/// 任务调用封装
NS_SWIFT_NAME(Tasks)
@interface HMFTasks<__covariant TResult> : NSObject

/// 同步等待任务结果，不可以在主线程调用
/// @param task 要等待的任务
/// @param error 任务超时或者在主线程调用错误
/// @result 任务执行结果
+ (id _Nullable)await:(HMFTask<TResult> *)task error:(NSError *_Nullable __autoreleasing *)error;

/// 同步等待任务结果，不可以在主线程调用
/// @param task 要等待的任务
/// @param timeout 等待超时时间
/// @param error 任务超时或者在主线程调用错误
/// @result 任务执行结果
+ (id _Nullable)await:(HMFTask<TResult> *)task
              timeout:(dispatch_time_t)timeout
                error:(NSError *_Nullable __autoreleasing *)error;

/// 在立刻执行代码
/// 代码块执行成功后调用[source setResult:]
/// 代码块执行失败后调用[source setError:]
/// @param callable 要执行的代码块
/// @result 代码块的执行任务
+ (HMFTask<TResult> *)call:(void (^)(HMFTaskCompletionSource<TResult> *source))callable
    NS_SWIFT_NAME(call(callable:));

/// 在后台队列执行代码
/// 代码块执行成功后调用[source setResult:]
/// 代码块执行失败后调用[source setError:]
/// @param callable 要执行的代码块
/// @result 代码块的执行任务
+ (HMFTask<TResult> *)callInBackground:(void (^)(HMFTaskCompletionSource<TResult> *source))callable
    NS_SWIFT_NAME(callInBackground(callable:));

/// 在指定线程执行代码
/// 代码块执行成功后调用[source setResult:]
/// 代码块执行失败后调用[source setError:]
/// @param executor 代码块执行的队列
/// @param callable 要执行的代码块
/// @result 代码块的执行任务
+ (HMFTask<TResult> *)callAt:(id<HMFExecutor>)executor
                    callable:(void (^)(HMFTaskCompletionSource<TResult> *source))callable
    NS_SWIFT_NAME(call(at:callable:));

/// 创建一个成功的任务
/// @param result 任务的结果
/// @result 成功任务
+ (HMFTask<TResult> *)fromResult:(TResult _Nullable)result;

/// 创建一个失败的任务
/// @param error 任务失败的错误
/// @result 失败任务
+ (HMFTask *)fromError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
