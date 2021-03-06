#pragma once
#include "include.h"
#include "DlgPlayList.h"
#include "DlgEqualizer.h"
class Application
{
private:
	DlgPlayList dlg;								//Class object PlayList
	DlgEqualizer equalizer;							//Class object Equalizer
	HWND hTBSoundVolume;							//TRackBar - volume 
	HWND hTBPlayingSong;							//TRackBAr - current time songs
	UINT id_timer;									//ID timer time by current playing songs
	UINT idTimerBySpectr;							//ID timer by Spectr
	INT secPlaying;									//Count of seconds played of the current song
	HWND spectrs[44];								//Columns spectrs
	HICON hIcon;									//Icon pleer
	BOOL IsRepeatSong;								//Replay
public:
	HSTREAM hStream;								//����� ��������������� �����
	Application(VOID);							//����������� �� ���������
	~Application();								//����������
	static Application* _this;					//����������� ���������
	static INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);				//���������� ��������� ��� ����������� ����
	
	VOID Cls_OnCommand(HWND hwnd, INT id, HWND hwndCtl, UINT codeNotify);								//WM_COMMAND
	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);									//WM_INITDIALOG
	VOID Cls_OnHScroll(HWND hwnd, HWND hwndCtl, UINT code, INT pos);									//WM_HSCROLL
	VOID Cls_OnTimer(HWND hwnd, UINT id);
	VOID Cls_OnSysCommand(HWND hwnd, UINT cmd, INT x, INT y);
	
	INT runProgramm();										//����� ���������
	INT CheckedInitBASS();									//�������� ������������� BASS
	BOOL openFile_LoadMusic(HWND hWnd);						//�������� ����� � ���������� OPENFILENAME
	VOID setRangeTrackBarPlaySong(HSTREAM stream);

	VOID stop(HSTREAM stream);		//Stop
	VOID play(HSTREAM stream);		//Play
	VOID pause();					//Pause
	VOID next();					//Next Song
	VOID prev();					//Prev Song

	VOID ControlSpectr(HWND hWnd);				//�������� �������� ������ ��� ������������
	VOID SetSpectrColor(HWND hWnd);				//��������� ����� ������������
	VOID SetNullPosSpectr();					//��������� ������������ �� 0 (��� ������� �� �����/����)
		
	VOID DeleteIconOfTray(HWND hWnd);			//�������������� ���� �� ����
	VOID AddIconInTray(HWND hWnd);				//������������ ���� � ����

	friend class DlgPlayList;
};