//
//  ACKThemeAppModel.h
//  Kuaikan
//
//  Created by yangshuyuan on 2021/1/27.
//  Copyright © 2021 Anny. All rights reserved.
//

#import "ACKThemeBaseModel.h"

NS_ASSUME_NONNULL_BEGIN

/**app全局通用的主题字段
 */
@interface ACKThemeAppModel : ACKThemeBaseModel
@property (nonatomic, strong) NSString *likeIcon;       // 举例字段，业务接入后可删除
@property (nonatomic, strong) NSString *likeAnimation;  // 举例字段，业务接入后可删除
@property (nonatomic, strong) NSString *backgroundColor;  // 举例字段，业务接入后可删除
@end

NS_ASSUME_NONNULL_END
