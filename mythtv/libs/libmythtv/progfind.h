/*
        MythProgramFind
        Version 0.8
        January 19th, 2003
        Updated: 4/8/2003, Added support for new ui.xml 

        By John Danner

        Note: Portions of this code taken from MythMusic
*/


#ifndef PROGFIND_H_
#define PROGFIND_H_

#include <qdatetime.h>

#include "libmyth/uitypes.h"
#include "libmyth/xmlparse.h"
#include "libmyth/mythwidgets.h"

class QListView;
class ProgramInfo;
class QSqlDatabase;
class QWidget;
class TV;

void RunProgramFind(bool thread = false);

class ProgFinder : public MythDialog
{
  struct showRecord {

        QString title;
        QString subtitle;
        QString description;
        QString channelID;
        QString startDisplay;
        QString endDisplay;
        QString channelNum;
        QString channelCallsign;
        QString starttime;
        QString endtime;
	QDateTime startdatetime;
	int recording;
	QString recText;

};

struct recordingRecord {

        QString chanid;
        QDateTime startdatetime;
        QString title;
        QString subtitle;
        QString description;
        int type;

};
    Q_OBJECT
  public:
    ProgFinder(QWidget *parent = 0, const char *name = 0);
    ~ProgFinder();

  protected:
    void hideEvent(QHideEvent *e);

  signals:
    void killTheApp();

  private slots:
    void update_timeout();
    void escape();
    void cursorLeft();
    void cursorRight();
    void cursorDown();
    void cursorUp();
    void getInfo();
    void showGuide();
    void pageUp();
    void pageDown();

  protected:
    void paintEvent(QPaintEvent *);

  private:
    void LoadWindow(QDomElement &);
    void parseContainer(QDomElement &);
    XMLParse *theme;
    QDomElement xmldata;

    void updateBackground();
    void updateList(QPainter *);
    void updateInfo(QPainter *);
   
    int showProgramBar;
    int showsPerListing;
    int curSearch;
    int curProgram;
    int curShow;
    int recordingCount;
    int searchCount;
    int listCount;
    int showCount;
    int inSearch;
    bool showInfo;
    bool pastInitial;
    bool running;
    int *gotInitData;

    QTimer *update_Timer;

    showRecord *showData;
    recordingRecord *curRecordings;

    QAccel *accel;

    TV *m_player;

    QString baseDir;
    QString curDateTime;
    QString curChannel;
    QString *searchData;
    QString *initData;
    QString *progData;

    QSqlDatabase *m_db;

    int rectListLeft;
    int rectListTop;
    int rectListWidth;
    int rectListHeight;
    int rectInfoLeft;
    int rectInfoTop;
    int rectInfoWidth;
    int rectInfoHeight;

    void showSearchList();
    void showProgramList();
    void showShowingList();
    void clearProgramList();
    void clearShowData();
    void selectSearchData();
    void selectShowData(QString);
    int checkRecordingStatus(int);
    void getRecordingInfo();
    void getSearchData(int);
    void getInitialProgramData();

    QRect infoRect() const;
    QRect listRect() const;
};

#endif
