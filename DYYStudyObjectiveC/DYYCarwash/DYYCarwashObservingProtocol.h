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

@protocol DYYCarwashObservingProtocol <NSObject>

- (BOOL)itemIsFree:(id<DYYCarwashObservingProtocol>)employee;

@end
#endif /* DYYCarwashObservingProtocol_h */
