//
//  ACKThemeManager.m
//  Demo
//
//  Created by yangshuyuan on 2021/1/20.
//  Copyright © 2021 yangshuyuan. All rights reserved.
//

#import "ACKThemeManager.h"
#import "KKResourceLoaderManager.h"

static ACKThemeManager *instance = nil;
@interface ACKThemeManager ()<KKThemeManagerDelegate>


@property (nonatomic, strong) ACKThemeModel *currentThemeModel;
@property (nonatomic, strong) ACKThemeModel *lightModeThemeModel;
@property (nonatomic, strong) ACKThemeModel *darkModeThemeModel;

@end

@implementation ACKThemeManager
+ (instancetype)shareInstance
{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[ACKThemeManager alloc] init];
        instance.delegate = instance;
        [instance switchThemeModelWithIdentifier:instance.currentThemeIdentifier];
    });
    return instance;
}

// 获取主题配置文件并转为数据model
- (NSDictionary *)resourceConfigDictionaryWithIdentifier:(NSString *)themIdentifier
{
    NSString *configPath = [NSString stringWithFormat:@"%@/%@",[self themePathWithThemeIndentifier:themIdentifier],@"config.json"];
    NSDictionary *jsonDict = nil;
    if ([[NSFileManager defaultManager] fileExistsAtPath:configPath]) {
        NSData *data = [[NSData alloc] initWithContentsOfFile:configPath];
        NSError *error = nil;
        jsonDict = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableLeaves error:&error];
        NSAssert(!error, @"----主题配置json解析错误----");
    }
    return jsonDict;
}

- (void)switchThemeModelWithIdentifier:(NSString *)themeIdentifier
{
    NSDictionary *dic = [self resourceConfigDictionaryWithIdentifier:themeIdentifier];
    ACKThemeConfigModel *configModel = [ACKThemeConfigModel yy_modelWithJSON:dic];
    self.lightModeThemeModel = configModel.lightMode;
    self.darkModeThemeModel = configModel.darkMode;
    [self switchThemeModelWithDarkMode:self.isDarkMode];
}

- (void)switchThemeModelWithDarkMode:(BOOL)isDarkMode
{
    if(isDarkMode) {
        self.currentThemeModel = self.darkModeThemeModel;
    } else {
        self.currentThemeModel = self.lightModeThemeModel;
    }
}

#pragma mark - KKThemeManagerDelegate
- (void)themeManagerLoadResource:(KKThemeManager *)themeManager
                             url:(NSString *)urlString
                        progress:(void (^)(NSProgress * _Nonnull))downloadProgressBlock
                      completion:(void (^)(NSURLResponse *, NSURL * _Nullable, NSError * _Nullable))completion
{
    [KKResourceLoaderManager loadResourceWithUrlString:urlString progress:downloadProgressBlock completionHandler:completion];
}

- (void)themeManagerDidSwitchedTheme:(KKThemeManager *)themeManager indentifier:(NSString *)identifier
{
    [self switchThemeModelWithIdentifier:identifier];
}

- (void)themeManagerDidSwitchedDarkMode:(KKThemeManager *)themeManager
{
    [self switchThemeModelWithDarkMode:self.isDarkMode];
}

@end
