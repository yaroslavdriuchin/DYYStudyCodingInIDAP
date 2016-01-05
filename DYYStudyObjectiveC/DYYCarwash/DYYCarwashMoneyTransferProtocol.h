//
//  DYYCarwashMoneyTransferProtocol.h
//  DYYStudyCoding
//
//  Created by Yar on 12/11/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#ifndef DYYCarwashMoneyTransferProtocol_h
#define DYYCarwashMoneyTransferProtocol_h

#import <Foundation/Foundation.h>

@protocol DYYCarwashMoneyTransferProtocol <NSObject>

@property (nonatomic, readonly, assign) uint32_t money;

- (void)payMoneyAmount :(uint32_t)amount;
- (void)takeMoneyAmount:(uint32_t)amount;

@end
#endif /* DYYCarwashMoneyTransferProtocol_h */

