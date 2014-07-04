//
//  UIScrollView+APParallaxHeader.h
//
//  Created by Mathias Amnell on 2013-04-12.
//  Copyright (c) 2013 Apping AB. All rights reserved.
//

#import <UIKit/UIKit.h>

@class APParallaxView;
@class ShadowView;

@interface UIScrollView (APParallaxHeader)

- (void)addParallaxWithImage:(UIImage *)image andHeight:(CGFloat)height;

@property (nonatomic, strong, readonly) APParallaxView *parallaxView;
@property (nonatomic, assign) BOOL showsParallax;

@end

enum {
    APParallaxTrackingActive = 0,
    APParallaxTrackingInactive
};

typedef NSUInteger APParallaxTrackingState;

@protocol APParallaxViewDelegate <NSObject>
@optional
-(void)APParallaxView:(APParallaxView *)view willChangeFrame:(CGRect)frame;
-(void)APParallaxView:(APParallaxView *)view didChangeFrame:(CGRect)frame;
+@end

@interface APParallaxView : UIView

@property (weak) id<APParallaxViewDelegate> delegate;

@property (nonatomic, readonly) APParallaxTrackingState state;
@property (nonatomic, strong) UIImageView *imageView;
@property (nonatomic, strong) ShadowView *shadowView;

-(void) showShadowView:(BOOL)show;

@end
