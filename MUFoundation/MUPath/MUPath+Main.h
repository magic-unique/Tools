//
//  MUPath.h
//  WeChat
//
//  Created by Magic-Unique on 2017/8/7.
//
//

#import <Foundation/Foundation.h>

@interface MUPath : NSObject

@property (readonly) NSString *string;
@property (readonly) NSURL *fileURL;

@property (readonly) MUPath *superpath;

@property (readonly) NSString *pathExtension;
@property (nonatomic, strong, readonly) NSArray<NSString *> *pathComponents;
@property (readonly) NSString *lastPathComponent;

- (instancetype)init;
+ (instancetype)path;

- (instancetype)initWithString:(NSString *)string;
+ (instancetype)pathWithString:(NSString *)string;

- (instancetype)initWithComponents:(NSArray<NSString *> *)components;
+ (instancetype)pathWithComponents:(NSArray<NSString *> *)components;

- (instancetype)subpathWithComponent:(NSString *)component;

- (instancetype)pathByReplacingPathExtension:(NSString *)pathExtension;
- (instancetype)pathByReplacingLastPathComponent:(NSString *)lastPathComponent;

- (NSString *)relativeStringToPath:(MUPath *)path;

- (id)objectAtIndexedSubscript:(NSInteger)idx; // API_AVAILABLE(macos(10.8), ios(6.0), watchos(2.0), tvos(9.0))

@end
