//
//  DYYCarwashEnterprise.h
//  DYYStudyCoding
//
//  Created by Yar on 12/8/15.
//  Copyright © 2015 Yaroslav Driuchin. All rights reserved.
//
/*
 Задание 3.
 Условие:
 1. Есть автомойка и есть админ здание;
 2. И то, и другое является зданием;
 3. Каждое из них имеет отдельные помещения;
 4. Каждое помещение рассчитано на определенное количество людей;
 5. У автомойки помещения могут еще вмещать и машины;
 6. Работники автомойки деляцца на мойщиков, бухгалтеров и директоров;
 7. Все они - люди, у которых разная зарплата, опыт работы и обязанности;
 8. Бухгалтера считают деньги;
 9. Директора получают прибыль;
 10. Мойщики моют машины;
 11. Финансовые потоки идут по пути обработки машины - мойщики - бухгалтера - директора;
 12. Есть машины, у которых есть деньги, до мойки они грязные, а после мойки чистые.
 13. Есть одно здание мойки с одной комнатой и одним мойщиком
 14. Есть одно здание администрации с одной комнатой, в которой сидит бухгалтер и директор.
 Задание:
 Придумать и реализовать иерархию классов автомойки, учитывая, что используецца следуюший процесс взаимодействий:
 1. Мойщику мойки отдают машину
 2. Мойщик моет машину
 3. Мойщик забирает деньги у машины
 4. Мойщик отдает деньги бухгалтеру
 5. Бухгалтер считает деньги
 6. Бухгалтер отдает деньги директору
 7. Директор получает прибыль
*/

#import <Foundation/Foundation.h>
#import "DYYCarwashWorker.h"
#import "DYYCarwashBuilding.h"

@class DYYCarwashCar;
@class DYYCarwashEmployee;
@class DYYCarwashRoom;

@interface DYYCarwashEnterprise : NSObject

@property (nonatomic, retain)      NSArray              *carsQueue;
@property (nonatomic, retain)      NSArray              *employees;
@property (nonatomic, retain)      NSArray              *buildings;
@property (nonatomic, retain)      DYYCarwashWorker     *observableWorker;

@property (nonatomic, readonly, assign) NSUInteger queueLimit;

- (DYYCarwashBuilding *)buildCarwashBuilding;
- (void)hireEmployee:(DYYCarwashEmployee *)employee;
- (BOOL)sendEmployee:(DYYCarwashEmployee *)employee
          toBuilding:(DYYCarwashBuilding *)building;
- (void)addCarToQueue:(DYYCarwashCar *)car;
- (void)performCarWash:(DYYCarwashCar *)car;
- (void)setObservableWorker:(DYYCarwashWorker *)worker;

@end
