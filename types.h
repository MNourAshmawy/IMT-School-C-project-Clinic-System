typedef unsigned int u16 ;
typedef unsigned char u8;
typedef char s8;
typedef int s32;
typedef struct
{
    s8 name[20];
    s8 gender[8];
    s32 age;
    s32 id;
}patient ;
typedef struct
{
    s8 from[7];
    s8 to[7];
    u8 reserved;
    s32 pid;
}slot;
