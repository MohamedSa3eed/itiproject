#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#define TRIES 3
#define PASS_LONG 4
typedef enum
{
	user1 =1 ,
	user2 =2 ,
	user3 =3
}USER;

typedef enum
{
	Rooms =1 ,
	Door  =2 ,
	Air   =3 ,
	Back  =4
}OPTIONS;
typedef enum
{
	Room1 =1 ,
	Room2 =2 ,
	Room3 =3
}ROOMS;
typedef enum
{
	on  =1 ,
	off =2
}STATE;
#endif /* APP_CONFIG_H_ */
