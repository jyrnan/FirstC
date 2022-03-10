//
//  dvdTracker.h
//  FirstC
//
//  Created by Yong Jin on 2022/3/10.
//

#ifndef dvdTracker_h
#define dvdTracker_h
#define kMaxTitleLength 256
#define kMaxCommentLength 256

struct DVDInfo {
    char rating;
    char title[ kMaxTitleLength ];
    char comment[ kMaxCommentLength ];
    struct DVDInfo *next;
};


#endif /* dvdTracker_h */
