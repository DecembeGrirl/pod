//
//  UIView+ACKThem.h
//  Demo
//
//  Created by yangshuyuan on 2021/1/18.
//  Copyright © 2021 yangshuyuan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "ACKThemeModel.h"

typedef void(^ACKThemeObserverChangedBlock)(ACKThemeModel * _Nullable currentThemModel, NSObject *sender);
typedef void(^ACKThemeDefualtBlock)(NSObject *sender);

@interface NSObject (ACKTheme)

- (void)addObserverThemeChanged:(ACKThemeObserverChangedBlock)observeThemBlock;

// 提供默认主题设置
- (void)addObserverThemeChanged:(ACKThemeObserverChangedBlock)observeThemBlock
              defualtThemeBlock:(ACKThemeDefualtBlock)defualtThemeBlock;
@end


