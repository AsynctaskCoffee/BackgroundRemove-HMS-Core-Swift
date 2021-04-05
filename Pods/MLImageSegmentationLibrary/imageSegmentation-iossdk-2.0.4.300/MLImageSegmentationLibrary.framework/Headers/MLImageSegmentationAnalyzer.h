//
// Copyright (c) Huawei Technologies Co., Ltd. 2020-2028. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MLImageSegmentationSetting;
@class MLFrame;
@class MLImageSegmentation;

NS_ASSUME_NONNULL_BEGIN

@interface MLImageSegmentationAnalyzer : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/// Image segmentation detector singleton
+ (instancetype)sharedInstance;

/// Image segmentation detector setting parameters
/// @param setting Image segmentation detector settings
- (void)setImageSegmentationAnalyzer:(MLImageSegmentationSetting *)setting;

/// Call the synchronization method to segment the collected images
/// @param frame Image to be detected
- (MLImageSegmentation *)analyseFrame:(MLFrame *)frame;

/// Image segmentation of the provided image, asynchronous call method
/// @param frame Image to be detected
/// @param successHandler Detect successful
/// @param failureHandler Detect failure
- (void)asyncAnalyseFrame:(MLFrame *)frame
     addOnSuccessListener:(void (^)(MLImageSegmentation *imagesegmentation))successHandler
     addOnFailureListener:(void (^)(NSInteger errCode, NSString *errMsg))failureHandler;

/// Release resources
- (void)stop;

@end

NS_ASSUME_NONNULL_END
