//
//  MUPath+NSFileManager.h
//  Tools
//
//  Created by Magic-Unique on 2017/8/8.
//  Copyright © 2017年 Unique. All rights reserved.
//

#import "MUPath.h"

typedef NS_ENUM(NSUInteger, MUPathType) {
	MUPathTypeNone,
	MUPathTypeFile,
	MUPathTypeDirectory,
};

@interface MUPath (NSFileManager)

@property (readonly) MUPathType type;

@property (readonly, getter=isExist) BOOL exist;

@property (readonly, getter=isDirectory) BOOL directory;

@property (readonly, getter=isFile) BOOL file;

@property (readonly, getter=isReadable) BOOL readable;

@property (readonly, getter=isWritable) BOOL writable;

@property (readonly, getter=isExecutable) BOOL executable;

@property (readonly, getter=isDeletable) BOOL deletable;

@property (readonly) NSArray<MUPath *> *contents;
@property (readonly) NSArray<MUPath *> *files;
@property (readonly) NSArray<MUPath *> *directories;

@property (readwrite) NSDictionary *attributes;

- (NSUInteger)enumerateContentsUsingBlock:(void (^)(MUPath *content, BOOL *stop))block;
- (NSArray<MUPath *> *)contentsWithFilter:(BOOL (^)(MUPath *content))filter;
- (NSArray<MUPath *> *)contentsWithPattern:(NSString *)pattern;

- (NSError *)createDirectoryWithCleanContents:(BOOL)contents;

- (NSError *)remove;
- (NSError *)clean;

- (NSError *)copyTo:(MUPath *)destinationPath autoCover:(BOOL)autoCover;
- (NSError *)copyInto:(MUPath *)distinationDirectoryPath autoCover:(BOOL)autoCover;
- (NSError *)copyContentsInto:(MUPath *)distinationDirectoryPath autoCover:(BOOL)autoCover;

- (NSError *)moveTo:(MUPath *)destinationPath autoCover:(BOOL)autoCover;
- (NSError *)moveInto:(MUPath *)distinationDirectoryPath autoCover:(BOOL)autoCover;
- (NSError *)moveContentsInto:(MUPath *)distinationDirectoryPath autoCover:(BOOL)autoCover;

@end


@interface MUPath (NSFastEnumeration) <NSFastEnumeration>

@end
