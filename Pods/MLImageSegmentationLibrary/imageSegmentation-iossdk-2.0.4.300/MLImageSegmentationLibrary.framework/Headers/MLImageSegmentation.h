//
// Copyright (c) Huawei Technologies Co., Ltd. 2020-2028. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface MLImageSegmentation : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// Initialization function
/// @param masks A one-dimensional array that stores the classification mark of each pixel of the picture.
/// @param foreground Portrait foreground image with transparent background.
/// @param grayscale The portrait is white with a black background.
- (instancetype)initWithMasks:(Byte *)masks foreground:(UIImage *)foreground grayscale:(UIImage *)grayscale;

/// Initialization function
/// @param masks A one-dimensional array that stores the classification mark of each pixel of the picture.
/// @param foreground Portrait foreground image with transparent background.
/// @param grayscale The portrait is white with a black background.
/// @param original The original image.
- (instancetype)initWithMasks:(Byte *)masks foreground:(UIImage *)foreground grayscale:(UIImage *)grayscale original:(UIImage *)original;

/// A one-dimensional array that stores the classification mark of each pixel of the picture.
- (Byte *)getMasks;

/// Portrait foreground image with transparent background.
- (UIImage *)getForeground;

/// The portrait is white with a black background.
- (UIImage *)getGrayscale;

/// The original image.
- (UIImage *)getOriginal;

@end

