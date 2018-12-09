//
//  ViewController.m
//  LiveStreamApp
//
//  Created by Sihang Huang on 12/8/18.
//  Copyright © 2018 Sihang Huang. All rights reserved.
//

#import "ViewController.h"
#import "MP3Encoder.hpp"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    NSString *pcmPath = [[NSBundle mainBundle] pathForResource:@"test" ofType:@"pcm"];
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = paths[0];
    NSString *mp3Path = [documentsDirectory stringByAppendingPathComponent:@"vocal.mp3"];
    
    MP3Encoder *encoder = new MP3Encoder();
    encoder->Init([pcmPath cStringUsingEncoding:[NSString defaultCStringEncoding]],
                  [mp3Path cStringUsingEncoding:[NSString defaultCStringEncoding]],
                  44100, 2, 64000);
    encoder->Encode();
    delete encoder;
    
    if([[NSFileManager defaultManager] fileExistsAtPath:mp3Path]) {
        NSLog(@"mp3文件存在");
    } else {
        NSLog(@"mp3文件不存在");
    }
    
}


@end
