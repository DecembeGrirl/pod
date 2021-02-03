//
//  ACKThemeManager.h
//  Demo
//
//  Created by yangshuyuan on 2021/1/20.
//  Copyright © 2021 yangshuyuan. All rights reserved.
//

#import "KKThemeManager.h"
#import "ACKThemeModel.h"
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

// 获取主题图片 使用方式:ACKThemeImage(currentThemModel, socialResource.postDetailResouce.followBtnIcon)
#define ACKThemeImage(TARGET,KEYPATH)\
({\
    NSString *string = TARGET.KEYPATH; \
    NSString *imagePath = @KKThemKeyPath(TARGET,KEYPATH);\
    NSMutableArray *array = [[imagePath componentsSeparatedByString:@"."] mutableCopy];\
    NSString *tempPath = @"";\
    if (string){\
        [array replaceObjectAtIndex:array.count-1 withObject:string];\
        for (int i = 0; i < array.count; i++) {\
            if (tempPath.length > 0) {\
                tempPath = [tempPath stringByAppendingPathComponent:array[i]];\
            } else {\
                tempPath = array[i];  \
            }\
        }\
    }\
    [[ACKThemeManager shareInstance] imageWithFilePath:tempPath];\
})\

// 获取主题颜色 使用方式：ACKThemeColor(currentThemModel, socialResource.postDetailResouce.followBtnTitleColor)
#define ACKThemeColor(TARGET,KEYPATH)\
({\
    NSString *colorStr = TARGET.KEYPATH;\
    UIColor *color = nil;\
    if(colorStr.length == 7) {\
       color = [UIColor colorWithHexString:colorStr];\
    }else {\
       color = [UIColor colorWithHexAlphaString:colorStr];\
    }\
    color;\
})\

#define KKThemKeyPath(OBJ, PATH) \
(((void)(NO && ((void)OBJ.PATH, NO)), # PATH))

@interface ACKThemeManager : KKThemeManager

+ (instancetype)shareInstance;

@property (nonatomic, strong, readonly) ACKThemeModel *currentThemeModel; // 当前使用的主题model

@end

NS_ASSUME_NONNULL_END
