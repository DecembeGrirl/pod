//
//  KKResourceManager.h
//  Demo
//
//  Created by yangshuyuan on 2021/1/20.
//  Copyright © 2021 yangshuyuan. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface KKResourceLoaderManager : NSObject
/**
 * 资源下载
 * url  下载地址
 * downloadProgressBlock 下载进度
 * completion 下载结束block
 */
+ (void)loadResourceWithUrlString:(NSString *)urlString
                         progress:(nullable void (^)(NSProgress *downloadProgress))downloadProgressBlock
                completionHandler:(nullable void (^)(NSURLResponse *response, NSURL * _Nullable filePath, NSError * _Nullable error))completionHandler;

@end

NS_ASSUME_NONNULL_END
