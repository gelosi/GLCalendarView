//
//  GLPeriodCalendarView.h
//  GLPeriodCalendar
//
//  Created by ltebean on 15-4-16.
//  Copyright (c) 2015 glow. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GLCalendarDateRange.h"

@class GLCalendarView;
enum RANGE_DISPLAY_MODE;

@protocol GLCalendarViewDelegate <NSObject>
- (BOOL)calenderView:(GLCalendarView *)calendarView canAddRangeWithBeginDate:(NSDate *)beginDate;
- (GLCalendarDateRange *)calenderView:(GLCalendarView *)calendarView rangeToAddWithBeginDate:(NSDate *)beginDate;
- (void)calenderView:(GLCalendarView *)calendarView beginToEditRange:(GLCalendarDateRange *)range;
- (void)calenderView:(GLCalendarView *)calendarView finishEditRange:(GLCalendarDateRange *)range continueEditing:(BOOL)continueEditing;
- (BOOL)calenderView:(GLCalendarView *)calendarView canUpdateRange:(GLCalendarDateRange *)range toBeginDate:(NSDate *)beginDate endDate:(NSDate *)endDate;
- (void)calenderView:(GLCalendarView *)calendarView didUpdateRange:(GLCalendarDateRange *)range toBeginDate:(NSDate *)beginDate endDate:(NSDate *)endDate;
@optional
- (NSArray*) calendarViewWeekDayTitles;
@end


@interface GLCalendarView : UIView
@property (nonatomic) CGFloat padding;
@property (nonatomic) CGFloat rowHeight;
@property (nonatomic, strong) NSDictionary *weekDayTitleAttributes UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) NSDictionary *monthCoverAttributes UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) NSDictionary *monthCoverYearAttributes UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) NSDictionary *selectedDayTitleAttributes UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) NSDictionary *selectedMonthTitleAttributes UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIImage *backToTodayButtonImage UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *backToTodayButtonColor UI_APPEARANCE_SELECTOR;
@property (nonatomic, strong) UIColor *backToTodayButtonBorderColor UI_APPEARANCE_SELECTOR;

//cell appearance
@property (nonatomic, strong) UIColor *cellEvenMonthBackgroundColor;
@property (nonatomic, strong) UIColor *cellOddMonthBackgroundColor;
@property (nonatomic, strong) UIColor *cellGridNormalColor;
@property (nonatomic, strong) UIColor *cellGridSeparatorColor;
@property (nonatomic, strong) NSDictionary *cellDayLabelAttributes;
@property (nonatomic, strong) NSDictionary *cellMonthLabelAttributes;

@property (nonatomic, strong) NSDictionary *cellTodayLabelAttributes;
@property (nonatomic, strong) NSDictionary *cellTodayMonthAttributes;

@property (nonatomic, strong) NSDictionary *cellDayDisabledLabelAttributes;
@property (nonatomic, strong) UIColor *cellTodayBackgroundColor;

@property (nonatomic) CGFloat cellEditCoverPadding;
@property (nonatomic) CGFloat cellEditCoverBorderWidth;
@property (nonatomic, strong) UIColor *cellEditCoverBorderColor;
@property (nonatomic) CGFloat cellEditCoverPointSize;
@property (nonatomic) CGFloat cellEditCoverPointScale;

@property (weak, nonatomic, readonly) UIView *weekDayTitle;

@property (nonatomic, readonly) NSCalendar *calendar;
@property (nonatomic, copy) NSDate *firstDate;
@property (nonatomic, copy) NSDate *lastDate;
@property (nonatomic, strong) NSMutableArray *ranges;
@property (nonatomic) BOOL showMaginfier;
@property (nonatomic, weak) id<GLCalendarViewDelegate> delegate;
@property (nonatomic, strong) GLCalendarDateRange *restrictSelectionWithRange;
- (void)reload;
- (void)addRange:(GLCalendarDateRange *)range;
- (void)removeRange:(GLCalendarDateRange *)range;
- (void)updateRange:(GLCalendarDateRange *)range withBeginDate:(NSDate *)beginDate endDate:(NSDate *)endDate;
- (void)forceFinishEdit;
- (void)beginToEditRange:(GLCalendarDateRange *)range;
- (void)scrollToDate:(NSDate *)date animated:(BOOL)animated;
@end
