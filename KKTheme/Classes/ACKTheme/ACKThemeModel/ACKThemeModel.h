//
//  ACKThemModel.h
//  Demo
//
//  Created by yangshuyuan on 2021/1/17.
//  Copyright © 2021 yangshuyuan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ACKThemeSocialBusinessModel.h"
#import "ACKThemeAppModel.h"

/** 建议model中定义的字段与主题的配置json文件中定义的字段一一对应**/

NS_ASSUME_NONNULL_BEGIN

@interface ACKThemeModel : NSObject

@property (nonatomic, strong) ACKThemeAppModel *appResource;
@property (nonatomic, strong) ACKThemeSocialBusinessModel *socialResource;

@end

@interface ACKThemeConfigModel : NSObject

@property (nonatomic, strong) ACKThemeModel *lightMode;
@property (nonatomic, strong) ACKThemeModel *darkMode;

@end


NS_ASSUME_NONNULL_END
