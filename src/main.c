#include <stdio.h>
#include <unistd.h>

#include "fbmap.h"

#define DEVICE "/dev/video0"

void camera_callback(CameraMap_Struct *cms, uint8_t *mem, int memSize)
{
    int i = 0;
    printf("frame %d %dms -- %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X\r\n",
        memSize, cms->timeStamp,
        mem[i++], mem[i++],
        mem[i++], mem[i++],
        mem[i++], mem[i++],
        mem[i++], mem[i++],
        mem[i++], mem[i++],
        mem[i++], mem[i++]);
}

int main(void)
{
    CameraMap_Struct *cms;
    if (!(cms = cameraMap_open(DEVICE, NULL, &camera_callback)))
    {
        fprintf(stderr, "cameraMap_open failed \r\n");
        return -1;
    }
    sleep(3);
    cameraMap_close(cms);

    // FileMap_Struct *fms;
    // if (!(fms = fileMap_open("/dev/fb0", FMT_RW, 0)))
    // {
    //     fprintf(stderr, "fileMap_open failed \r\n");
    //     return -1;
    // }
    // fileMap_close(fms);

    return 0;
}
