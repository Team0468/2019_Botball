#define Rmotor 0
#define Lmotor 2
#define rope 3

void rope_close(int input)
{
    cmpc(3);
    while(gmpc(3)>-input)
    {
        mav(rope,-500);
    }
    mav(rope,0);
}
void drop_yellow()
{
    drive(400);
    mav(Rmotor, 500);
    mav(Lmotor, -250);
    msleep(2250);
    claw_open();
    mav(Rmotor,1500);
    mav(Lmotor,1500);
    msleep(500);
    while(analog(2)<1000)
    {
        mav(Rmotor,-400);
        mav(Lmotor,1500);
    }
    cmpc(0);
    cmpc(2);
    while(gmpc(0)<750)
    {
        mav(Rmotor,.65*(analog(2)));
        mav(Lmotor,.65*(3400-analog(2)));
    }
}
void claw_open()
{
    printf("open\n");
    set_servo_position(2,582);
    msleep(300);
}
void claw_close()
{
    printf("closed\n");
    enable_servos();
    set_servo_position(2,210);
    msleep(300);
}
void first_linefollow()//follows line from start box
{
    int n=0;
    printf("left side card line follow");//loop exits when card is sensed
    cmpc(0);
    cmpc(3);
    while(n<5)
    {
        mav(Rmotor,.65*(analog(2)));
        mav(Lmotor,.65*(3400-analog(2)));
        if(analog(1)>1500)
        {//counting loop
            n=n+1;
        }
        if(analog(1)<1200)
        {
            n=0;
        }
        msleep(1);
    }
    cmpc(0);
    cmpc(2);
    printf("moving to perfect position\n");//moves to center of first card for photo
    while(gmpc(0)<650)
    {
        mav(Rmotor,500);
        mav(Lmotor,500);
    }
    ao();
}
void second_linefollow_a()
{
    int n=0;
    printf("left side card line follow");//loop exits when card is sensed
    cmpc(0);
    cmpc(3);
    while(n<5)
    {
        mav(Rmotor,.62*(analog(2)));
        mav(Lmotor,.62*(3400-analog(2)));
        if(analog(1)>1500)
        {//counting loop
            n=n+1;
        }
        if(analog(1)<1200)
        {
            n=0;
        }
        msleep(1);
    }
    cmpc(0);
    cmpc(2);
    printf("moving to perfect position\n");//moves to photo position of 2nd card
    while(gmpc(0)<650)
    {
        mav(Rmotor,500);
        mav(Lmotor,500);
    }
    ao();
}
void second_linefollow()//moves to 2nd card
{
    cmpc(0);
    cmpc(2);
    while(gmpc(0)<2250)
    {
        mav(Rmotor,1500);
        mav(Lmotor,1500);
    }
    int n=0;
    printf("left side card line follow");//loop exits when card is sensed
    cmpc(0);
    cmpc(3);
    while(n<5)
    {
        mav(Rmotor,.65*(analog(2)));
        mav(Lmotor,.65*(3400-analog(2)));
        if(analog(1)>1500)
        {//counting loop
            n=n+1;
        }
        if(analog(1)<1200)
        {
            n=0;
        }
        msleep(1);
    }
    cmpc(0);
    cmpc(2);
    printf("moving to perfect position\n");//moves to photo position of 2nd card
    while(gmpc(0)<650)
    {
        mav(Rmotor,500);
        mav(Lmotor,500);
    }
    ao();
}
void turn_and_square_up()//squares up for cube grab
{
    int front_ir=2;
    int left_ir=0;
    int right_ir=3;
    printf("90 turn and square up");
    mav(0,500);
    msleep(6450);
    ao();
    while(analog(front_ir)<1000)
    {
        mav(Rmotor,500);
        mav(Lmotor,500);
        ao();
    }
    while(left_ir>1500 && right_ir>1500)
    {
        if(analog(left_ir)<3200)
        {
            mav(Lmotor,500);
        }
        if(analog(right_ir)<3200)
        {
            mav(Rmotor,500);
        }
        msleep(2);
        ao();

    }
}
void backward_linefollow(int user_input)//follows left side line using back ir
{
    printf("Hello World\n");
    int L=0;
    int target=-user_input;

    cmpc(0);
    cmpc(2);

    while(L>target)
    {
        L=(gmpc(0)+gmpc(2))/2;

        if(analog(4)>1830)
        {
            mav(Lmotor,-600);
            mav(Rmotor,-500);
        }
        if(analog(4)<1830)
        {
            mav(Rmotor,-600);
            mav(Lmotor,-500);
        }    
        ao();
    }       
}
void backward_linefollowa(int distance)
{
    cmpc(0);
    cmpc(2);
    while(gmpc(0)>-distance)
    {
        mav(Lmotor,-.55*(analog(4)));
        mav(Rmotor,-.55*(3400-analog(4)));
    }
}
    
void backward_r_linefollow(int user_input)
{
    int L=0;
    int target=-user_input;

    cmpc(0);
    cmpc(2);

    while(L>target)
    {
        L=(gmpc(0)+gmpc(2))/2;

        if(analog(4)>1830)
        {
            mav(Rmotor,-500);
            mav(Lmotor,-200);
        }
        if(analog(4)<1830)
        {
            mav(Lmotor,-500);
            mav(Rmotor,-200);
        }    
        ao();
    }       
}
void grabber_open()
{
    //open 0 
    //close 582
    set_servo_position(Rmotor,410);
    msleep(300);
}
void grabber_close()
{
    set_servo_position(Lmotor,770);
    msleep(300);
}
void botguy_linefollow(int distance)
{
    //black=3300
    //white=200?
    printf("left side no card line follow");//keeps following loop

    cmpc(0);
    cmpc(2);
    while(gmpc(0)<distance)
    {
        mav(Rmotor,.65*(analog(2)));
        mav(Lmotor,.65*(3400-analog(2)));
    }
}
void botguy_approach(){
    mav(Rmotor,530);
    mav(Lmotor,470);
    msleep(1250);
}
void pvc_linefollow()
{

    //black=3300
    //white=200?
    printf("left side no card line follow");//keeps following loop

    cmpc(0);
    cmpc(2);
    while(analog(1)<1700)
    {
        mav(Rmotor,.65*(analog(2)));
        mav(Lmotor,.65*(3400-analog(2)));
        if(gmpc(0)>2000 && gmpc(0)<2225)
        {
            grabber_open();
        }
    }
}
void drive(int distance)
{
    while(gmpc(0)<distance)
    {
        mav(Lmotor, (distance+50)-gmpc(2));
        mav(Rmotor, (distance+50)-gmpc(0));
    }
}
void turn_two(int angle)
{
    int total_distance=angle * 18;
    cmpc(0);
    cmpc(2);
    while(gmpc(2)<total_distance)
    {
        mav(Lmotor,500);
        mav(Rmotor,-500);
    }
}
/*void turn_one(int angle)
{
    int total_distance=angle * 36;
    cmpc(0);
    cmpc(2);
    while(gmpc(2)<total_distance)
    {
        mav(2,500);
        mav(0,-500);
    }
}
*/
void back_linefollow(int user_input)
{
    printf("Hello World\n");
    int L=0;
    int target=-user_input;

    cmpc(0);
    cmpc(2);

    while(L>target)
    {
        L=(gmpc(0)+gmpc(2))/2;

        if(analog(4)>1830)
        {
            mav(Lmotor,-500);
            mav(Rmotor,-200);
        }
        if(analog(4)<1830)
        {
            mav(Rmotor,-500);
            mav(Lmotor,-200);
        }    
        ao();
    }       
}
void UPS_HQ()
{
    enable_servos();
    //backwards righthand
    int freeze = 0;
    int left = 2;
    int right = 0; 
    //----------
    cmpc(left);
    cmpc(right); //backs up before turning towards cubes
    drive(1300);
    //----------
    mav(left, freeze);
    mav(right, -1200);//turns towards cubes
    msleep(2604);
    //----------
    cmpc(left);
    cmpc(right);
    while(gmpc(0)>-500)
    {
        mav(right, -600); //drive towards linefollow
        mav(left,-600);
    }
    //----------
    //---while(analog(4)<1500)
    //{
    //    mav(left, -1000);//drives forward until the back sensor senses black
    //    mav(right, -1000);
    //}---
    //----------
    //mav(right,-1500);
    //msleep(100);
    //----------
    while(analog(0)<2800 || analog(3)<2800)
    {
        if(analog(0)<2800)
        {
            mav(left, -1000);
        }						//squares up with left and right ir sensors
        if(analog(3)<2800)
        {
            mav(right, -1000);
        }
        if(analog(0)>2800)
        {
            mav(left,freeze);
        }
        if(analog(3)>2800)
        {
            mav(right,freeze);
        }
    }
    //----------
    //claw_open(); ------FOR TESTING BOT GUY, ADD BACK LATER
    //----------
    back_linefollow(3200);
    //----------
    //claw_close(); ------FOR TESTING BOT GUY, ADD BACK LATER
    //----------
    cmpc(left);
    cmpc(right); //drive away with yellow cubes and turn around to grab bot guy
    drive(2000);
    turn_two(180);
    ao();
    while(analog(0)<2500 || analog(3)<2500)
    {
        mav(left,-1000);
        mav(right,-1000);
    }
    ao();
    rope_open(1250);
   cmpc(right);
    cmpc(left);
    while(gmpc(right)<2600)
    {
         mav(Rmotor,.65*(analog(2)));
        mav(Lmotor,.65*(3400-analog(2)));
    }
    mav(right,750);
    mav(left,500);
    msleep(1400);
    mav(left,750);
    mav(right,600);
    msleep(550);
    rope_close(1700);
    mav(right,-1500);
    mav(left,-1500);
    msleep(500);
    //----------
    /*mav(right,-1500);
    mav(left,-1500);
    msleep(750);    //back up to open up the rope
    ao();
    rope_open(1300);
    //----------
    //pvc_linefollow();
    //ao();
    //grabber_open();
    /*botguy_linefollow(950);*/  //ignore this
    //botguy_approach();
    //ao();
    //----------
    //mav(Rmotor, 800); //angle to pick up bot guy
    //msleep(750);
    //----------
   /* mav(Rmotor,800);
    mav(Lmotor,800);
    msleep(4400);
    ao();
    mav(Lmotor,800);
    msleep(900);
    ao();*/
    //mav(Rmotor,-250);
    //mav(Lmotor,-250);
    //msleep(850);
    //rope_close(1300);
    //grabber_close();

    //use et sensor to get to pvc
    //go grab bot guy
    //claw_open();
    backward_linefollowa(2000);
    //claw_close();
    // while(analog(0)>1500 || analog(3)>1500 || analog(4)<1830)
    //{
    while(analog(3)<3300 || analog(0)<3300)
    {
        if(analog(3)<3300)
        {
            mav(right,-1000);
        }
        if(analog(0)<3300)
        {
            mav(left,-1000);
        }
    }
    while(analog(3)>3000 || analog(0)>3000)
    {
        if(analog(3)>3000)
        {
            mav(right,-700);
        }
        if(analog(0)>3000)
        {
            mav(left,-700);
        }
    }
    //mav(left,-1000);
    //mav(right, -1000);
    //msleep(5125);
    //  }
    //^^go backwards until the side sensors sense black and the back ir sees white
    /* while(analog(0)<3300 || analog(3)<3300)
    {
        if(analog(0)<3300)
        {
            mav(left, 500);
        }
        if(analog(3)<3300)
        {
            mav(right, 500);
        }
        ao();
    }*/
    /*cmpc(0);
    cmpc(2);
    while(analog(0)>3200 || analog(3)>3200)
    {
        if(analog(0)>3200)
        {
            mav(left, -250);
        }
        if(analog(3)>3200)
        {
            mav(right, -250);
        }
        if(analog(3)<3200)
        {
            mav(right, freeze);
        }
        if(analog(0)<3200)
        {
            mav(left,freeze);
        }
        if(gmpc(0)<-200)
        {
            break;
        }
    }
    ao();*/
    turn_two(90);
    while(analog(4)<1830)
    {
        mav(left, -1000);
        mav(right,-1000);
    }
    //squares it up
    while(analog(0)<3200)
    {
        mav(left,-1125);//3
        mav(right,-1500);//4
    }
    //gets back to starting area
    while(analog(2)<2000)
    {
        mav(left,600);
        mav(right, 120);
    }
    //square front ir with tape
}

void UPS()
{   
    enable_servos();
    if(zone1 == 0)
    {
        first_linefollow();
        printf("zone 1 yellow\n");
        drop_yellow();
    }
    if(zone1 == 1)
    {
        cmpc(Lmotor);
        cmpc(Rmotor);
        while(gmpc(0)<5000)
        {
            mav(Rmotor,.62*(analog(2)));
            mav(Lmotor,.62*(3400-analog(2)));
        }
    }
    if(zone1 == 2)
    {
        //insert Botguy drop here
    }
    second_linefollow_a();
    if (zone2 == 1)
    {
        cmpc(Lmotor);
        cmpc(Rmotor);
        while(gmpc(0)<5000)
        {
            mav(Rmotor,.62*(analog(2)));
            mav(Lmotor,.62*(3400-analog(2)));
        }
    }
    if(zone2 == 0)
    {
        drop_yellow();
        second_linefollow_a();
    }
    if(zone2 == 2)
    {
        second_linefollow();
    }
    if(zone3 == 1)
    {
        
    }
    if(zone3 == 0)
    {
        drop_yellow();
    }
    if(zone3 == 2)
    {

    }
}



