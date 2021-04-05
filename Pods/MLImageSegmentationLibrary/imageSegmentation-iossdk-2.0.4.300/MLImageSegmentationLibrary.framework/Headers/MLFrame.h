//
// Copyright (c) Huawei Technologies Co., Ltd. 2020-2028. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MLFrame : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// The image to be detected
@property(nonatomic, strong, readonly) UIImage *image;

/// Initialization function
/// @param image The image to be detected
- (instancetype)initWithImage:(UIImage *)image;

@end

NS_ASSUME_NONNULL_END
