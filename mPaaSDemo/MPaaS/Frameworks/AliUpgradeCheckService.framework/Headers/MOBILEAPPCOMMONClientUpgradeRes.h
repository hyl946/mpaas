
@class MOBILEAPPCOMMONClientUpgradeRes;

@interface MOBILEAPPCOMMONClientUpgradeRes : NSObject

@property(nonatomic, assign) SInt32 resultStatus;
@property(nonatomic, strong) NSString* memo;
@property(nonatomic, strong) NSString* downloadURL;
@property(nonatomic, strong) NSString* newestVersion;
@property(nonatomic, strong) NSString* guideMemo;
@property(nonatomic, strong) NSString* fullMd5;
@property(nonatomic, strong) NSString* upgradeVersion;
@property(nonatomic, strong) NSString* netType;
@property(nonatomic, strong) NSString* userId;

@end

