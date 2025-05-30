//
//     Generated by class-dump 3.5 (64 bit).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2013 by Steve Nygard.
//

#import <TargetConditionals.h>

#import <UIKit/UIKit.h>

#import <CDStructures.h>

@class XCSynthesizedEventRecord;

typedef void (^XCEventGeneratorHandler)(XCSynthesizedEventRecord *record, NSError *error);

@interface XCEventGenerator : NSObject
{
  NSObject<OS_dispatch_queue> *_eventQueue;
  struct __CFRunLoopObserver *_generationObserver;
  unsigned long long _generation;
}

+ (id)sharedGenerator;
@property unsigned long long generation; // @synthesize generation=_generation;
//@property(readonly) NSObject<OS_dispatch_queue> *eventQueue; // @synthesize eventQueue=_eventQueue;

#if TARGET_OS_TV
// TODO: tvOS-specific headers

#elif TARGET_OS_IPHONE
- (double)rotateInRect:(CGRect)arg1 withRotation:(double)arg2 velocity:(double)arg3 orientation:(UIInterfaceOrientation)arg4 handler:(XCEventGeneratorHandler)arg5;
- (double)pinchInRect:(CGRect)arg1 withScale:(double)arg2 velocity:(double)arg3 orientation:(UIInterfaceOrientation)arg4 handler:(XCEventGeneratorHandler)arg5;
- (double)pressAtPoint:(CGPoint)arg1 forDuration:(double)arg2 liftAtPoint:(CGPoint)arg3 velocity:(double)arg4 orientation:(UIInterfaceOrientation)arg5 name:(NSString *)arg6 handler:(XCEventGeneratorHandler)arg7;
- (double)pressAtPoint:(CGPoint)arg1 forDuration:(double)arg2 orientation:(UIInterfaceOrientation)arg3 handler:(XCEventGeneratorHandler)arg4;

// iOS 9.x specific, gone in iOS 10.3
- (double)tapWithNumberOfTaps:(unsigned long long)arg1 numberOfTouches:(unsigned long long)arg2 inRect:(CGRect)arg3 orientation:(UIInterfaceOrientation)arg4 handler:(XCEventGeneratorHandler)arg5;
- (double)twoFingerTapInRect:(CGRect)arg1 orientation:(UIInterfaceOrientation)arg2 handler:(XCEventGeneratorHandler)arg3;
- (double)doubleTapAtPoint:(CGPoint)arg1 orientation:(UIInterfaceOrientation)arg2 handler:(XCEventGeneratorHandler)arg3;
- (double)tapAtPoint:(CGPoint)arg1 orientation:(UIInterfaceOrientation)arg2 handler:(XCEventGeneratorHandler)arg3;

// iOS 10.x specific
- (double)tapAtTouchLocations:(NSArray *)locations numberOfTaps:(NSInteger)numberOfTaps orientation:(UIInterfaceOrientation)orientation handler:(XCEventGeneratorHandler)handler;

// iOS 10.3 specific
- (double)forcePressAtPoint:(struct CGPoint)arg1 orientation:(long long)arg2 handler:(CDUnknownBlockType)arg3;

#elif TARGET_OS_MAC
- (double)sendKeyboardInputs:(id)arg1 layout:(id)arg2 handler:(CDUnknownBlockType)arg3;
- (double)sendKey:(id)arg1 modifierFlags:(unsigned long long)arg2 handler:(CDUnknownBlockType)arg3;
- (double)sendString:(id)arg1 handler:(CDUnknownBlockType)arg2;
- (double)setModifiers:(unsigned long long)arg1 merge:(BOOL)arg2 original:(unsigned long long *)arg3 handler:(CDUnknownBlockType)arg4;
- (double)sendKey:(unsigned short)arg1 down:(BOOL)arg2 modifiers:(unsigned long long)arg3 string:(id)arg4 handler:(CDUnknownBlockType)arg5;
- (double)hitKey:(unsigned short)arg1 handler:(CDUnknownBlockType)arg2;
- (double)scrollByX:(double)arg1 y:(double)arg2 handler:(CDUnknownBlockType)arg3;
- (double)clickAtPoint:(CGPoint)arg1 forDuration:(double)arg2 releaseAtPoint:(CGPoint)arg3 velocity:(double)arg4 handler:(CDUnknownBlockType)arg5;
- (double)clickAndDragFromPoint:(CGPoint)arg1 toPoint:(CGPoint)arg2 handler:(CDUnknownBlockType)arg3;
- (double)rightClickAtPoint:(CGPoint)arg1 handler:(CDUnknownBlockType)arg2;
- (double)doubleClickAtPoint:(CGPoint)arg1 handler:(CDUnknownBlockType)arg2;
- (double)clickAtPoint:(CGPoint)arg1 handler:(CDUnknownBlockType)arg2;
- (double)hoverAtPoint:(CGPoint)arg1 handler:(CDUnknownBlockType)arg2;
- (CGPoint)_currentMousePosition;
- (void)_clickMouseButton:(unsigned int)arg1 withCount:(unsigned long long)arg2 atPoint:(CGPoint)arg3 handleCompletion:(CDUnknownBlockType)arg4;
- (void)_moveMouseToPoint:(CGPoint)arg1 handleCompletion:(CDUnknownBlockType)arg2;
- (void)_postCGEvent:(struct __CGEvent *)arg1 handleCompletion:(CDUnknownBlockType)arg2;
#endif

- (void)_startEventSequenceWithSteppingCallback:(CDUnknownBlockType)arg1;
- (void)_scheduleCallback:(CDUnknownBlockType)arg1 afterInterval:(double)arg2;
- (id)init;

@end
