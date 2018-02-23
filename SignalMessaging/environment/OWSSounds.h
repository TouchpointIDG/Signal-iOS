//
//  Copyright (c) 2018 Open Whisper Systems. All rights reserved.
//

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, OWSSound) {
    OWSSound_Default = 0,

    // Notification Sounds
    OWSSound_Aurora,
    OWSSound_Bamboo,
    OWSSound_Chord,
    OWSSound_Circles,
    OWSSound_Complete,
    OWSSound_Hello,
    OWSSound_Input,
    OWSSound_Keys,
    OWSSound_Note,
    OWSSound_Popcorn,
    OWSSound_Pulse,
    OWSSound_Synth,
    OWSSound_ClassicNotification,

    // Ringtone Sounds
    OWSSound_Opening,

    // Calls
    OWSSound_CallConnecting,
    OWSSound_CallOutboundRinging,
    OWSSound_CallBusy,
    OWSSound_CallFailure,

    // Other
    OWSSound_None,
    OWSSound_DefaultiOSIncomingRingtone = OWSSound_Opening,
};

@class AVAudioPlayer;
@class TSThread;
@class YapDatabaseReadWriteTransaction;

@interface OWSSounds : NSObject

- (instancetype)init NS_UNAVAILABLE;

+ (NSString *)displayNameForSound:(OWSSound)sound;

+ (nullable NSString *)filenameForSound:(OWSSound)sound;

+ (void)playSound:(OWSSound)sound;
+ (void)playSound:(OWSSound)sound quiet:(BOOL)quiet;

#pragma mark - Notifications

+ (NSArray<NSNumber *> *)allNotificationSounds;

+ (OWSSound)globalNotificationSound;
+ (void)setGlobalNotificationSound:(OWSSound)sound;
+ (void)setGlobalNotificationSound:(OWSSound)sound transaction:(YapDatabaseReadWriteTransaction *)transaction;

+ (OWSSound)notificationSoundForThread:(TSThread *)thread;
+ (void)setNotificationSound:(OWSSound)sound forThread:(TSThread *)thread;

#pragma mark - AudioPlayer

+ (nullable AVAudioPlayer *)audioPlayerForSound:(OWSSound)sound;

@end

NS_ASSUME_NONNULL_END
