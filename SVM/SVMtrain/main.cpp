#include <iostream>
#include <opencv2/opencv.hpp>
#include "sys/stat.h"
using namespace std;
using namespace cv;
int main()
{
    cout << "Hello World!" << endl;
    Mat img;
    img=imread("/home/wj/桌面/SVM/SpiltImage/digits.png");
    imshow("show",img);
    mkdir("/home/wj/桌面/SVM/SpiltImage/data",S_IRWXU);//00700权限，代表该文件所有者拥有读，写和执行操作的权限

    waitKey(0);
    return 0;
}
