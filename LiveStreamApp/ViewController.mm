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
    // Do any additional setup after loading the view, typically from a nib.
    MP3Encoder *encoder = new MP3Encoder();
    encoder->encode();
    delete encoder;
}


@end
