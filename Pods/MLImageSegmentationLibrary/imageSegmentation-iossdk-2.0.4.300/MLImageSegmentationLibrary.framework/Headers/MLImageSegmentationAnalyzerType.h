//
// Copyright (c) Huawei Technologies Co., Ltd. 2020-2028. All rights reserved.
//

#ifndef MLImageSegmentationAnalyzerType_h
#define MLImageSegmentationAnalyzerType_h

typedef NS_ENUM(NSInteger, MLImageSegmentationAnalyzerType) {
    MLImageSegmentationAnalyzerTypeNone = -1,       // None
    MLImageSegmentationAnalyzerTypeBody,            // Portrait detection mode (support the distinction between people and background)
    MLImageSegmentationAnalyzerTypeImage,           // Image multi-category mode (supports classification of all items in MLImageSegmentationClassification)
};

#endif /* MLImageSegmentationAnalyzerType_h */
