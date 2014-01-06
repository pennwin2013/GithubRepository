#ifndef  __PUBFUNC_H_
#define  __PUBFUNC_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <stdarg.h>
#include <sys/types.h>
#include "errdef.h"
#include "pubdef.h"
#include "pubdb.h"
#include "cpucard.h"
#include <string>
#include <iomanip>


#ifdef HEX_FMT
#undef HEX_FMT
#endif

#define HEX_FMT(w) std::hex<<std::uppercase<<std::setw(w)<<std::setfill('0')
#define HEX_BYTE_FMT HEX_FMT(2)


//#ifdef __cplusplus
//extern "C" {
//#endif

void getpos( char* v_filename, int v_lineno );
void errlog( int level, char* fmt, ... );
extern char gszExeName[128];
extern int  giLogClass;

#define des2src(des,src)  	strncpy(des,src,sizeof(des)-1),ntrim(des,sizeof(des))
#define src2des(src,des)  	strncpy(des,src,sizeof(des)-1),ntrim(des,sizeof(des))
int amtcmp( double amt1, double amt2 );

/*
 *
            writelog  level  ����    �Ž�

LOG_EMERG   ָ��������Ϣ��LOG_EMERG������Щ��Ϣ���Ƿַ��������û������Խ� LOG_EMERG ���ȼ���Ϣ��¼�������ļ����顣
LOG_ALERT   ָ����Ҫ����Ϣ��LOG_ALERT���������ص�Ӳ��������Щ��Ϣ�ַ��������û���
LOG_CRIT    ָ������Ϊ����Ĺؼ���Ϣ��LOG_CRIT�����粻�ʵ��ĵ�¼���ԡ�LOG_CRIT �ͽϸ����ȼ���Ϣ�ᷢ�͵�ϵͳ����̨��
LOG_ERR     ָ����ʾ�����������Ϣ��LOG_ERR��������ʧ�ܵĴ���д�롣
LOG_WARNING ָ���������ɻָ����������Ϣ��LOG_WARNING����
LOG_NOTICE  ָ����Ҫ����Ϣ����Ϣ��LOG_NOTICE����û��ָ�����ȼ�����Ϣ��ӳ��Ϊ�����ȼ�����Ϣ��
LOG_INFO    ָ����Ϣ����Ϣ��LOG_INFO������Щ��Ϣ���Է������������ڷ���ϵͳ�Ǻ����á�
LOG_DEBUG   ָ��������Ϣ��LOG_DEBUG������Щ��Ϣ���Է�����

 *
 */

#define writelog getpos(__FILE__,__LINE__),errlog
void set_4byte_int( unsigned char*  value_str, int num );
void get_random( char* randomstr );
int get_int_random();

//trim: trim string left space and right space
char* trim( char* str );
//ltrim: trim string left space
char* ltrim( char* str );
//rtrim: trim string right space
char* rtrim( char* str );
char* ntrim( char* str, int len );
//getsystime,out date format:yyyymmdd
char* getsysdate( char* v_date );

//getsystime, out time format:hhmmss
char* getsystime( char* v_time );
void toupper_word( char word[] );
void tolower_word( char word[] );
int getweekday();

//getsysdatetime, out time format:yyyymmddhhmmss
char* getsysdatetime( char v_time[15] );
//getdatetime, out time format:yyyy-mm-dd hh:mm:ss
char* getdatetime( char v_datetime[20] );
char* getsystimestamp( char* v_timestamp );
//�������ܣ����ݴ���ʱ����룬�õ�����ʱ��֮ǰ��ʱ��
//���룺cur_time  char[7] ����ʱ���ʽΪ��hhmmss
//���룺second    int	   ʱ����		��λΪ��
//�����pre_time  char[7] ��cur_time֮ǰsecond���ʱ�䣬��ʽΪhhmmss
int GetPreTime( char cur_time[7], int second, char pre_time[7] );
//�������ܣ����ݴ���ʱ����룬�õ�����ʱ��֮ǰ��ʱ��
//���룺cur_time  char[7] ����ʱ���ʽΪ��hhmmss
//���룺second    int	   ʱ����		��λΪ��
//�����next_time  char[7] ��cur_time֮��second���ʱ�䣬��ʽΪhhmmss
int GetNextTime( char cur_time[7], int second, char next_time[7] );

//�������ܣ�������������ʱ�䣬�õ���������ʱ��֮��ļ��ʱ��
//���룺tim1  char[15] ����ʱ���ʽΪ��yyyymmddhhmmss
//���룺tim2  char[15] ����ʱ���ʽΪ��yyyymmddhhmmss
//�����second   double*	   ʱ����		��λΪ��

int DiffTime( char time1[], char time2[], double* second );
// �Ƚ����ڲ�
int DiffDay( char day1[9], char day2[9], int* days );
//	getdbtime,out date format:yyyy-mm-dd
//	var length: v_date[11];
char* getdbdate( char* date );
//	getdbtime,out date format:hh.mm.ss
//	var length: v_time[16];
char* getdbtime( char* v_time );
//	getdbtimestamp,out date format:yyyy-mm-dd-hh.mm.ss
//	var length: v_timestamp[27];
char* getdbtimestamp( char* v_timestamp );

int UssetConvert( int nType, char* usset, char* menuset, int nUssetSize, int nMenusetSize );
//int getNewVocNo(int iType,char *sVocNo);
//int getNewActNo(char *sNewActno);
//int IsActnoInvalid(char *actno);

//in  : 	origin,datetime,format:yyyymmddhhmmss
//out :	timestamp,format:yyyy-mm-dd hh:mm:ss
int ConvertDate( char* origin, char* timestamp );
//author:xunzhang huang
//date:2004-08-30 17��11
//flag==0 yyyy-mm-dd  -->>  yyyymmdd
//flag==1 yyyymmdd    -->>  yyyy-mm-dd
int ConvertDateLen( char* out, const char* in, int flag );

//flag=0,Encode,	clearpwd to secretpwd,	min length of secretpwd is 29
//flag=1,Decode,	secretpwd to clearpwd,	min length of secretpwd is 29

int EncodePwd(const char* key, char* clearpwd, char* secretpwd, int flag );

int GetInitKey( char* s_init_key, char* key );

int GetDynaKey( char* Dyna_Key );

int CheckInitKey( char* s_init_key, int sysid, char* key );

int GetReadCardKey( int deviceid, int sysid, char* read_card_key, char* key );


int dateConvert( char* str, char* buf );

//��������	: ���ݸ�ʽת��Ϊ��⣲��������
//����		:   old_date  char[11]��������
//����		:   old_fmt 	 �����ַ��������ڸ�ʽ���������ڸ�ʽΪ:"YYMMDD","YYYYMMDD"
//���		:   new_date  char[11]��DB2 ���ڡ�yyyy-mm-dd
//����ֵ	:   0	 --�ɹ�
//����ֵ	:  �ǣ�--��Ӧ�Ĵ�����
int str2dbdate( char* new_date, char* old_date, char* old_fmt );

//��������	: ���ݸ�ʽת��Ϊ��⣲����ʱ��
//����		:   old_time  char[11]����ʱ��
//����		:   old_fmt 	 �����ַ�����ʱ���ʽ���������ڸ�ʽΪ:"HHMMSS"
//���		:   new_time  char[11]��DB2 ʱ�䡡hh:mm:ss
//����ֵ	:   0	 --�ɹ�
//����ֵ	:  �ǣ�--��Ӧ�Ĵ�����
char* getfmtsysdatetime( char v_datetime[30] );

int str2dbtime( char* new_time, char* old_time, char* old_fmt );
int str2dbtimestamp( char* new_timestamp, char* old_timestamp, char* old_fmt );
int IsInvalidDateTime( char* sdatetime,  char* fmt );
int datetime2second( const char* datetime, char* fmt, double* second );
int second2datetime( double second, char* datetime, char* fmt );
int GetXmlValue( char value[], int size, char* key, char* buf );
void  AddXmlItemDbl( char* buf, char* key, double value );
void  AddXmlItemInt( char* buf, char* key, int value );
void  AddXmlItemStr( char* buf, char* key, char* value );
//������ʾ����
int GetNewShowCardNo( char* sNewCardno, int iCustType, int iCardId );
//У����ʾ�����Ƿ���Ч
int IsShowCardNoInvalid( char* sCardno );
//�������뺯��,����numλС��
double D4U5( double value, int num = 2 );
int D2I( double value );

//���������ӣ�����mac�ķ���
int	generate_mac( char* buf, int len, char* mac );

int	check_mac( char* buf, int len );

int GetValueFromFmtBuf( char* buf, char* separator, int pos, char* value );

int SpanOfDate( const char* start, const char* end );
int GetNextDay( const char start[9], int span, char next[9] );
int OffsetDatetime( const char begin_dt[13], int second, char end_dt[13] );

int DecodeHDPhyId( const char* encoded, char* text );
int EncodeHDPhyId( const char* text, char* encodeId );
int CheckPwdChar( const char* pwd, char newpwd[7] );
void CalcMD5( unsigned char* buf, unsigned int len, unsigned char md5[16] );
unsigned long  CardPhyIdHex2Dec( const char* phyid );

int CheckUserPswd( const char* input_pwd, const char* db_pwd );

void RealSleep( int secs );

void  InitDaemonProcess();
int StartAsDaemon();
//////////////////////////////////////////
// ���ܲ��Թ��ܺ���
typedef struct
{
  pid_t current_id;
  struct timeval time_stamp;
  struct timeval start_stamp;
} time_probe_t;

int time_probe_now( time_probe_t* probe );
int time_probe_finish( time_probe_t* probe );
void time_probe_print( const time_probe_t* probe, const char* msg );

int startup_lock_file( const char* uni_identify );
int test_process_lock_file( const char* uni_identify );

int is_validate_sexno( char sexno );
int GenOldCardPwd(const char* man_id, char* passwd);
int get_init_passwd_by_man_id( const char* man_id, char* passwd );
#define  unlike_tbl_id(idval)  ((idval) > 0 ?  0 : 1)

// ���������ID��, ������ĸ,����,������
void gen_session_id( char* session, int len );
int calcEndDate( const char* begindate, int days, char* enddate );
void getNextShowCardNo( char* curshowcardno, int nextcnt, char* nextshowcardno );


typedef struct
{
  int length; // ��ǰ����
  int size; // ��󳤶�
  char* data; // ����
} my_string_t;

// �����µ� my_string_t,
my_string_t alloc_mystring();
// �ͷ� my_string_t
void free_mystring( my_string_t* str );
// ���� my_string_t �Ĵ�С
void resize_mystring( my_string_t* str, int newsize );
// �� my_string_t ת����Сд
void lowercase_my_string( my_string_t* str );
// ɾ�� my_string_t ��ʼ���β�Ŀո�/�Ʊ���
int trim_line( my_string_t* str );
// ���ļ��ж�ȡһ��
// ���� 1 ��ʾ��ȡ���ļ���β, 0 ��ʾ�ɹ���ȡһ��, -1 ��ʾ��ȡ�ļ�ʧ��
int read_file_line( my_string_t* str, FILE* fp );
//����Ǯ�����ܺ���
int decrypt_elec_card_pwd( int cut_id, const char seedkey[32], const char mpwd[64], char pwd[8] );


void str2hex( char* str, int len, char* hex );
void hex2str( char* hex, int len, char* str );
int str2bcd( char* str, int len, char* bcd );
void dec2hex(unsigned char *sDec,int dec_len,char *sHex);
void hex2dec(char *sHex,unsigned char * sDec,int dec_len);
void chomp(char *s,char c='\n');

void encode_hex(const unsigned char* data,size_t datalen,std::string& hexstr);
size_t decode_hex(const std::string& hexstr,unsigned char* data);

//#ifdef __cplusplus
//}
//#endif
#endif
