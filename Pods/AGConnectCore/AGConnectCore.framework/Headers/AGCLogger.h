//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

///AGC日志级别
typedef NS_ENUM(NSInteger, AGCLoggerLevel) {
    AGCLOG_Debug = 0,  //调试级别
    AGCLOG_Info = 1,   //提示级别
    AGCLOG_Warning = 2,//告警级别
    AGCLOG_Error = 3   //错误级别
};

typedef NSString *const AGCLogTag;

///AGC日志回调
typedef void (^AGCLoggerCallback)(AGCLoggerLevel level, NSString *message);

/// 打印Error级别日志
/// @param tag 日志模块
/// @param formate 日志内容
extern void AGCLogError(AGCLogTag tag, NSString *formate, ...) NS_FORMAT_FUNCTION(2, 3);

/// 打印Warning级别日志
/// @param tag 日志模块
/// @param formate 日志内容
extern void AGCLogWarning(AGCLogTag tag, NSString *formate, ...) NS_FORMAT_FUNCTION(2, 3);

/// 打印Info级别日志
/// @param tag 日志模块
/// @param formate 日志内容
extern void AGCLogInfo(AGCLogTag tag, NSString *formate, ...) NS_FORMAT_FUNCTION(2, 3);

/// 打印Debug级别日志
/// @param tag 日志模块
/// @param formate 日志内容
extern void AGCLogDebug(AGCLogTag tag, NSString *formate, ...) NS_FORMAT_FUNCTION(2, 3);

/**
 * AGConnect Framework日志工具类
 */
@interface AGCLogger : NSObject

/// 设置是否打印AGConnect Framework日志
/// 默认不打印
/// @param enable 是否打印
+ (void)enableLog:(BOOL)enable;

/// 设置打印日志级别
/// 默认打印Error级别
/// @param level 日志级别
+ (void)resetLogLevel:(AGCLoggerLevel)level;

@end

NS_ASSUME_NONNULL_END
