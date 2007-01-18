#ifndef __QVIEW_HPP__
#define __QVIEW_HPP__
/*
qview.hpp

Quick view panel

*/

#include "panel.hpp"
#include "CriticalSections.hpp"

class Viewer;

class QuickView:public Panel
{
  private:
    Viewer *QView;

    string strCurFileName;
    string strCurFileType;
    string strTempName;

    CriticalSection CS;

    int Directory;
    int PrevMacroMode;
    unsigned long DirCount,FileCount,ClusterSize;
    unsigned __int64 FileSize,CompressedFileSize,RealFileSize;
    int OldWrapMode;
    int OldWrapType;

  private:
    void DisplayObject();
    void PrintTextW(const wchar_t *Str);

    void SetMacroMode(int Restore = FALSE);
    /* $ 30.04.2001 DJ */
    void DynamicUpdateKeyBar();
    /* DJ $ */

  public:
    QuickView();
    ~QuickView();

  public:
    int ProcessKey(int Key);
    int ProcessMouse(MOUSE_EVENT_RECORD *MouseEvent);
    void Update(int Mode);
    void ShowFile(const wchar_t *FileName,int TempFile,HANDLE hDirPlugin);
    void CloseFile();
    void QViewDelTempName();

    virtual int UpdateIfChanged(int UpdateMode);
    virtual void SetTitle();
    virtual void GetTitle(string &Title,int SubLen=-1,int TruncSize=0);
    virtual void SetFocus();
    virtual void KillFocus();
    virtual BOOL UpdateKeyBar();
    virtual int GetCurNameW(string &strName, string &strShortName);
};


#endif  // __QVIEW_HPP__
