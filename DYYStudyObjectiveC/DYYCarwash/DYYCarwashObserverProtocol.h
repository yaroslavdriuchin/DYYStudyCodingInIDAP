//
//  DYYCarwashObservingProtocol.h
//  DYYStudyCoding
//
//  Created by Yar on 12/15/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//

#ifndef DYYCarwashObservingProtocol_h
#define DYYCarwashObservingProtocol_h

#import <Foundation/Foundation.h>

@protocol DYYCarwashObserverProtocol <NSObject>

- (void)employeeDidStartWork:(id)employee;
- (void)employeeDidBecomeStandBy:(id)employee;
- (void)employeeDidBecomeFree:(id)employee;

@end
#endif /* DYYCarwashObservingProtocol_h */
