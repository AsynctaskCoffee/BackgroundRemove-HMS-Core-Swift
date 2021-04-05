//
// Copyright (c) Huawei Technologies Co., Ltd. 2020-2028. All rights reserved.
//

#ifndef MLImageSegmentationScene_h
#define MLImageSegmentationScene_h

typedef NS_ENUM(NSUInteger, MLImageSegmentationScene) {
    MLImageSegmentationSceneAll,                // Get all results by default
    MLImageSegmentationSceneMaskOnly,           // Get pixel-level tag information
    MLImageSegmentationSceneForegroundOnly,     // Get the foreground portrait cutout with transparent background
    MLImageSegmentationSceneGrayscaleOnly       // Get a grayscale image with a white portrait and a black background
};

#endif /* MLImageSegmentationScene_h */
