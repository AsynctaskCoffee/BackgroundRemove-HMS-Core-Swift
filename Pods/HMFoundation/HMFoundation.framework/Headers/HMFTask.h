//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import <Foundation/Foundation.h>
#import "HMFExecutors.h"

NS_ASSUME_NONNULL_BEGIN

/// 异步回调封装，便于回调异步任务的结果
/// TResult 任务执行成功返回的数据类型
NS_SWIFT_NAME(Task)
@interface HMFTask<__covariant TResult> : NSObject

/// 任务是否结束
@property(nonatomic, readonly) BOOL isComplete;

/// 任务是否成功
@property(nonatomic, readonly) BOOL isSuccessful;

/// 任务是否已取消
@property(nonatomic, readonly) BOOL isCanceled;

/// 任务成功的结果
@property(nonatomic, nullable, readonly) TResult result;

/// 任务失败的错误
@property(nonatomic, nullable, readonly) NSError *error;

/// 添加任务成功触发的回调事件
/// @param successCallback 成功的回调
/// @result 当前任务
- (HMFTask<TResult> *)addOnSuccessCallback:(void (^)(TResult _Nullable result))successCallback
    NS_SWIFT_NAME(onSuccess(callback:));

/// 添加任务成功触发的回调事件
/// @param executor 回调事件执行的队列
/// @param successCallback 成功的回调
/// @result 当前任务
- (HMFTask<TResult> *)addOnSuccessAt:(id<HMFExecutor>)executor
                            callback:(void (^)(TResult _Nullable result))successCallback
    NS_SWIFT_NAME(onSuccess(at:callback:));

/// 添加任务失败触发的回调事件
/// @param failureCallback 失败的回调
/// @result 当前任务
- (HMFTask<TResult> *)addOnFailureCallback:(void (^)(NSError *error))failureCallback
    NS_SWIFT_NAME(onFailure(callback:));

/// 添加任务失败触发的回调事件
/// @param executor 回调事件执行的队列
/// @param failureCallback 失败的回调
/// @result 当前任务
- (HMFTask<TResult> *)addOnFailureAt:(id<HMFExecutor>)executor
                            callback:(void (^)(NSError *error))failureCallback
    NS_SWIFT_NAME(onFailure(at:callback:));

/// 添加任务完成触发的回调事件，无论成功失败都会触发
/// @param completeCallback 完成的回调
/// @result 当前任务
- (HMFTask<TResult> *)addOnCompleteCallback:(void (^)(HMFTask<TResult> *task))completeCallback
    NS_SWIFT_NAME(onComplete(callback:));

/// 添加任务完成触发的回调事件，无论成功失败都会触发
/// @param executor 回调事件执行的队列
/// @param completeCallback 完成的回调
/// @result 当前任务
- (HMFTask<TResult> *)addOnCompleteAt:(id<HMFExecutor>)executor
                             callback:(void (^)(HMFTask<TResult> *task))completeCallback
    NS_SWIFT_NAME(onComplete(at:callback:));

/// 添加当任务取消时触发的回调事件
/// @param cancelCallback 取消的回调
/// @result 当前任务
- (HMFTask<TResult> *)addOnCanceledCallback:(void (^)(void))cancelCallback
    NS_SWIFT_NAME(onCancel(callback:));

/// 添加当任务取消时触发的回调事件
/// @param executor 回调事件执行的队列
/// @param cancelCallback 取消的回调
/// @result 当前任务
- (HMFTask<TResult> *)addOnCanceledAt:(id<HMFExecutor>)executor
                             callback:(void (^)(void))cancelCallback
    NS_SWIFT_NAME(onCancel(at:callback:));

/// 取消当前任务
- (BOOL)cancel;

@end

/// 用于开发者自定义任务
/// TResult 任务执行成功返回的数据类型
NS_SWIFT_NAME(TaskCompletionSource)
@interface HMFTaskCompletionSource<__covariant TResult> : NSObject

/// 设置任务执行成功
/// @param result 任务执行的结果
- (void)setResult:(TResult _Nullable)result;

/// 设置任务执行失败
/// @param error 任务失败的错误
- (void)setError:(NSError *)error;

/// 返回异步任务
- (HMFTask<TResult> *)getTask;

@end

NS_ASSUME_NONNULL_END
