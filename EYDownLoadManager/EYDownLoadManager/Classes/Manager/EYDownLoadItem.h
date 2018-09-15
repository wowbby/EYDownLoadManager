//
//  EYDownLoadItem.h
//  EYDownLoadManager
//
//  Created by 郑振兴 on 2018/9/15.
//

#import <Foundation/Foundation.h>

@class EYDownLoadItem;
typedef void (^EYSucessBlock)(NSURLRequest *_Nullable, NSHTTPURLResponse *_Nullable, NSURL *_Nonnull);
typedef void (^EYFailureBlock)(NSURLRequest *_Nullable, NSHTTPURLResponse *_Nullable, NSError *_Nonnull);
typedef void (^EYProgressBlock)(NSProgress *_Nonnull, EYDownLoadItem *);

@interface EYDownLoadItem : NSObject
@property (nonatomic, copy, readonly, nonnull) NSString *url;

/**
 资源存储路径
 */
@property (nonatomic, copy, readonly, nonnull) NSString *filePath;

/**
 资源名称--MD5
 */
@property (nonatomic, copy, readonly, nullable) NSString *filename;

/**
 资源真实名称--从资源下载地址中截取
 */
@property (nonatomic, copy, readonly, nullable) NSString *truename;
/*****************下载过程信息********************/

/**
 下载速度
 */
@property (nonatomic, copy, readonly) NSString *speed; // KB/s

/**
 已下载资源大小
 */
@property (assign, nonatomic, readonly) long long totalBytesWritten;

/**
 资源总大小
 */
@property (assign, nonatomic, readonly) long long totalBytesExpectedToWrite;

/**
 下载进度
 */
@property (nonatomic, copy, readonly, nonnull) NSProgress *progress;
/*************************************/
/**
 下载错误信息
 */
@property (nonatomic, strong, readonly, nullable) NSError *error;

/**
 call back
 */
@property (nonatomic, copy) EYSucessBlock successBlock;
@property (nonatomic, copy) EYFailureBlock failureBlock;
@property (nonatomic, copy) EYProgressBlock progressBlock;
@end
