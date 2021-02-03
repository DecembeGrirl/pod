//
//  ACKThemeBusinessModel.h
//  Kuaikan
//
//  Created by yangshuyuan on 2021/1/27.
//  Copyright © 2021 Anny. All rights reserved.
//

#import "ACKThemeBaseModel.h"

NS_ASSUME_NONNULL_BEGIN
/** ACKThemeSocialBusinessModel  定义社区业务主题数据模型，内部可按页面细化。
 */

// 页面维度的主题model 如下为帖子详情页的主题model
@interface ACKThemePostDetailPageModel : ACKThemeBaseModel
@property (nonatomic, strong) NSString *followBtnTitleColor;
@property (nonatomic, strong) NSString *followBtnIcon;
@end


// 业务维度的主题model
@interface ACKThemeSocialBusinessModel : ACKThemeBaseModel
@property (nonatomic, strong) NSString *likeIcon;
@property (nonatomic, strong) NSString *likeAnimation;
@property (nonatomic, strong) ACKThemePostDetailPageModel *postDetailResouce;
@end





NS_ASSUME_NONNULL_END
