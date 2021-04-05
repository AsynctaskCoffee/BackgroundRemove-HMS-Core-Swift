//
// Copyright (c) Huawei Technologies Co., Ltd. 2020-2028. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MLImageSegmentationScene.h"
#import "MLImageSegmentationAnalyzerType.h"

NS_ASSUME_NONNULL_BEGIN

@interface MLImageSegmentationSetting : NSObject

/// Return the detection mode result.
/// 0: MLImageSegmentationAnalyzerTypeBody represents the portrait detection mode (supports the distinction between people and background);
/// 1: MLImageSegmentationAnalyzerTypeImage represents the image multi-category mode (supports all item classifications in MLImageSegmentationClassification).
@property(nonatomic, assign) MLImageSegmentationAnalyzerType analyzerType;

/// 0: All capability scenarios.
/// 1: As long as the pixel marking ability.
/// 2: As long as the ability to cut out portrait foreground.
@property(nonatomic, assign) MLImageSegmentationScene scene;

/// Returns whether it is currently in fine detection mode.
/// YES: fine detection;
/// NO: non-fine detection.
@property(nonatomic, assign) BOOL exact;

/// Return the detection mode result.
/// 0: MLImageSegmentationAnalyzerTypeBody represents the portrait detection mode (supports the distinction between people and background);
/// 1: MLImageSegmentationAnalyzerTypeImage represents the image multi-category mode (supports all item classifications in MLImageSegmentationClassification).
- (MLImageSegmentationAnalyzerType)getAnalyzerType;

/// 0: All capability scenarios.
/// 1: As long as the pixel marking ability.
/// 2: As long as the ability to cut out portrait foreground.
- (MLImageSegmentationScene)getScene;

/// Returns whether it is currently in fine detection mode.
/// YES: fine detection;
/// NO: non-fine detection.
- (BOOL)isExact;

@end

NS_ASSUME_NONNULL_END
