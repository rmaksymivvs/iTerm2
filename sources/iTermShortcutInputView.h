//
//  iTermShortcutInputView.h
//  iTerm
//
//  Created by George Nachman on 4/7/14.
//
//

#import <Cocoa/Cocoa.h>

@class iTermShortcutInputView;

@protocol iTermShortcutInputViewDelegate <NSObject>

- (void)shortcutInputView:(iTermShortcutInputView *)view didReceiveKeyPressEvent:(NSEvent *)event;

@end

// Use this class for text fields that take a shortcut as input. Any keydown
// event will be sent to -handleShortcutEvent: while this field's NSTextView is
// the first responder. Events are immediately passed to the shortcutDelegate.
// You can assign the shortcutDelegate in IB as it is an IBOutlet.
@interface iTermShortcutInputView : NSView

@property(nonatomic, assign) IBOutlet id<iTermShortcutInputViewDelegate> shortcutDelegate;
@property(nonatomic, assign) BOOL disableKeyRemapping;
@property(nonatomic, assign, getter=isEnabled) BOOL enabled;
@property(nonatomic, copy) NSString *stringValue;
@property(nonatomic, assign) NSBackgroundStyle backgroundStyle;

- (void)handleShortcutEvent:(NSEvent *)event;

- (void)setKeyCode:(NSUInteger)code
         modifiers:(NSEventModifierFlags)modifiers
         character:(NSUInteger)theChar;

- (NSString *)identifierForCode:(NSUInteger)code
                      modifiers:(NSEventModifierFlags)modifiers
                      character:(NSUInteger)character;
@end
