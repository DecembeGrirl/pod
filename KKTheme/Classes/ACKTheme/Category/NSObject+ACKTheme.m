//
//  UIView+ACKThem.m
//  Demo
//
//  Created by yangshuyuan on 2021/1/18.
//  Copyright © 2021 yangshuyuan. All rights reserved.
//

#import "NSObject+ACKTheme.h"
#import "NSObject+KKTheme.h"
#import "ACKThemeManager.h"

@implementation NSObject (ACKThem)

- (void)addObserverThemeChanged:(ACKThemeObserverChangedBlock)observeThemBlock
{
    [self addObserverThemeChanged:observeThemBlock defualtThemeBlock:nil];
}

- (void)addObserverThemeChanged:(ACKThemeObserverChangedBlock)observeThemeBlock
              defualtThemeBlock:(ACKThemeDefualtBlock)defualtThemeBlock {
    
    @KKWeakify(self);
    [self addObserveThemeChangeWithBlock:^{
        @KKStrongify(self);
        ACKThemeModel *currentThemeModel = [ACKThemeManager shareInstance].currentThemeModel;
        if (observeThemeBlock && currentThemeModel) {
            observeThemeBlock(currentThemeModel, self);
        } else {
            if (defualtThemeBlock) {
                defualtThemeBlock(self);
            }
        }
    }];
}

@end
