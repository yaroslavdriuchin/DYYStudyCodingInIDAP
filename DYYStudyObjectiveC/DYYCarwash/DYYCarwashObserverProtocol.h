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

- (void)employeeStartedWork:(id)employee;
- (void)employeeBecameStandBy:(id)employee;
- (void)employeeBecameBusy:(id)employee;

@end
#endif /* DYYCarwashObservingProtocol_h */
