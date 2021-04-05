//
//  Copyright (c) Huawei Technologies Co., Ltd. 2020. All rights reserved
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// AGC的存储类
@interface AGCUserDefaults : NSObject

/// 单例
+ (instancetype)standard;

/// 初始化
/// @param name 名称
- (instancetype)initWithName:(NSString *)name;

/// 保存数据
/// @param value 数据
/// @param key key值
- (BOOL)saveObject:(nullable id)value forKey:(NSString *)key;

/// 加密保存数据
/// @param value 数据
/// @param key key值
- (BOOL)saveCryptoObject:(nullable id)value forKey:(NSString *)key;

/// 读取数据
/// @param key key值
- (nullable id)objectForKey:(NSString *)key;

/// 读取加密数据
/// @param key key值
- (nullable id)objectCryptoForKey:(NSString *)key;

/// 删除数据
/// @param key key值
- (void)removeObjectForKey:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
