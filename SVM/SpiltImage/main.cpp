#include <opencv2/opencv.hpp>
#include <iostream>
#include "sys/stat.h"
//imwrite函数中的路径必须是真实存在的！！
/*
https://blog.csdn.net/yinjian1013/article/details/78611009?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522161666605216780261962344%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=161666605216780261962344&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_v2~rank_v29-6-78611009.pc_search_result_cache&utm_term=mkdir%E5%87%BD%E6%95%B0
*/
using namespace std;
using namespace cv;

int main()
{
    char ad[128]={0};
    int  filename = 0,filenum=0;
    Mat img = imread("/home/wj/桌面/SVM/SpiltImage/digits.png");
    Mat gray;
    cvtColor(img, gray, CV_BGR2GRAY);
    int b = 20;
    int m = gray.rows / b;   //原图为1000*2000   50
    int n = gray.cols / b;   //裁剪为5000个20*20的小图块  100
    //创建文件夹
    mkdir("/home/wj/桌面/SVM/SpiltImage/data",S_IRWXU);//00700权限，代表该文件所有者拥有读，写和执行操作的权限
    mkdir("/home/wj/桌面/SVM/SpiltImage/data/0",S_IRWXU);
    for (int i = 0; i < m; i++)
    {
        int offsetRow = i*b;  //行上的偏移量
        if(i%5==0&&i!=0)
        {
            filename++;
            sprintf(ad, "/home/wj/桌面/SVM/SpiltImage/data/%d",filename);
            mkdir(ad,S_IRWXU);
            filenum=0;
        }
        for (int j = 0; j < n; j++)
        {
            int offsetCol = j*b; //列上的偏移量
            sprintf(ad, "/home/wj/桌面/SVM/SpiltImage/data/%d/%d.jpg",filename,filenum++);
            //截取20*20的小块
            Mat tmp;
            gray(Range(offsetRow, offsetRow + b), Range(offsetCol, offsetCol + b)).copyTo(tmp);
            imwrite(ad,tmp);
            imwrite("/home/wj/桌面/SVM/SpiltImage/data2/1.png",img);
            imshow("展示",tmp);
            printf("写入中...\n");
        }
    }
    printf("裁减完成\n");
    waitKey(0);
    return 0;
}
