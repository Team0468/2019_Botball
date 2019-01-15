#include <kipr/botball.h>

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    char cmd[25];
    //remove existing networks
    for (i = 0; i < 10; i++)
    {
        sprintf(cmd, "wpa_cli delete_network %d",i);
        system(cmd);
    }
    msleep(100);
    //scan for networks
    system("wpa_cli scan");
    
    //connect to network
    system("wpa_cli add_network");
    system("wpa_cli set_network 0 ssid \'\"4180-wallaby\"\'");
    system("wpa_cli set_network 0 key_mgmt 3b96b900");
    system("wpa_cli enable_network 0");
    
    //machine should be connected to passwordless network XYZ
    system("wpa_cli save");
system("dhclient -v -r wlan0");
    return 0;
}
