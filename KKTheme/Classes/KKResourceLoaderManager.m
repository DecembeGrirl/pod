//
//  KKResourceManager.m
//  Demo
//
//  Created by yangshuyuan on 2021/1/20.
//  Copyright © 2021 yangshuyuan. All rights reserved.
//

#import "KKResourceLoaderManager.h"
@implementation KKResourceLoaderManager

+ (void)loadResourceWithUrlString:(NSString *)urlString
                         progress:(nullable void (^)(NSProgress *downloadProgress))downloadProgressBlock
                completionHandler:(nullable void (^)(NSURLResponse *response, NSURL * _Nullable filePath, NSError * _Nullable error))completionHandler
{
    AFHTTPSessionManager *manager = [AFHTTPSessionManager new];
    NSURL *url = [NSURL URLWithString:urlString];
    NSURLRequest *request = [NSURLRequest requestWithURL:url];
    NSURLSessionDownloadTask *task = [manager downloadTaskWithRequest:request progress:downloadProgressBlock destination:^NSURL * _Nonnull(NSURL * _Nonnull targetPath, NSURLResponse * _Nonnull response) {
        NSString *cachePath = NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).firstObject;
        NSString *filePath =  [cachePath stringByAppendingPathComponent:[response suggestedFilename]];
        return [NSURL fileURLWithPath:filePath];
    } completionHandler:completionHandler];
    [task resume];
}


@end
