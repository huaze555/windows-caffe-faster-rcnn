![image](https://github.com/huaze555/windows-caffe-faster-rcnn/raw/master/demo_image/1.jpg)  

### 如果由于工程需要使用c++的faster-rcnn，同时需要在windows环境下，那么这个版本适合你。  

## 介绍
该windows下的c++版faster-rcnn是建立在两个版本基础之上的：
一: [Microsoft's windows-caffe](https://github.com/Microsoft/caffe) 
    这个版本是微软的windows下caffe版本    
二: [D-X-Y's caffe-faster-rcnn version](https://github.com/D-X-Y/caffe-faster-rcnn/tree/dev) 
    这个是D-X-Y大神linux下c++版faster-rcnn
    
## 该版本特性
结合以上两个后，这是在windows下的c++版faster-rcnn，无python，支持训练和测试。   
在NVIDIA GTX1060显卡，用VGG16模型测试一张图片大约200ms

## 编译（x64 release模式）
跟配置[微软版caffe](https://github.com/Microsoft/caffe)一模一样，或者参考[博客](http://www.cnblogs.com/love6tao/p/5706830.html)  
这里为了方便，我已经把cudnn的文件放在工程里了，就是主目录下的cuda文件夹  
如果需要配置cudnn的话，记得在“.\windows\CommonSettings.props”中“CuDnnPath”的配置好cuda文件夹的路径

## 训练模型
具体训练模型的步骤，跟[D-X-Y's caffe-faster-rcnn version](https://github.com/D-X-Y/caffe-faster-rcnn/tree/dev)是一模一样的  
但经过比较后，发现这个版本训练的速度比python版[py-faster-rcnn](https://github.com/rbgirshick/py-faster-rcnn)要慢一点点。

## 配置到VS2013
编译完成后，生成的所有跟faster-rcnn的依赖项都在"caffe-master\Build\x64\Release\"下  
而第三方依赖库，比如OpenCV、Glog、protobuf等都在和caffe-master同目录下的"NugetPackages\"下  
就像VS2013配置OpenCV一样，配置faster-rcnn只要把faster-rcnn和第三方库的include文件放置到VS2013的VC++目录，lib文件放到库目录，然后链接器->输入->附加依赖项，填上

libboost_date_time-vc120-mt-1_59.lib  
libboost_filesystem-vc120-mt-1_59.lib  
libboost_system-vc120-mt-1_59.lib  
libglog.lib  
libcaffe.lib  
gflags.lib  
gflags_nothreads.lib  
hdf5.lib  
hdf5_hl.lib  
libprotobuf.lib  
libopenblas.dll.a  
Shlwapi.lib  
opencv_core2410.lib  
opencv_highgui2410.lib  
opencv_imgproc2410.lib  
LevelDb.lib  
lmdb.lib  
opencv_video2410.lib  
opencv_objdetect2410.lib  
cublas.lib  
cuda.lib  
cublas_device.lib  
cudart.lib  
cudart_static.lib  
curand.lib  
kernel32.lib  

详细可参考博客: http://blog.csdn.net/auto1993/article/details/70198435  

因为第三方库比较多配置起来麻烦，为了方便，我将NugetPackages文件中第三方库文件打包好了放在[百度网盘](https://pan.baidu.com/s/1gfjc3n1)上，密码: eotf   
共分为三个文件夹： bin、include、lib，分别对应可执行文件，头文件，库文件

## 对图片进行测试
VS2013配置成功后，就可以在VS2013中编写代码，对图片进行测试了。  
检测类在文件caffe-master\include\caffe\api\FRCNN\frcnn_api.hpp 定义，接口为：  
  
  
#include <caffe\api\FRCNN\frcnn_api.hpp>  //目标检测头文件  
#include <opencv2\opencv.hpp>   
#include "Register.h"           //这个文件不能少，用于注册相关caffe层  
using namespace std;  
using namespace cv;  
using namespace caffe::Frcnn;  
int main(){  
		 	Mat frame = imread("1.jpg);  //图片  
				//初始化目标检测器，构造函数中，四个参数分别为  
				//1、网络配置文件  
				//2、训练好的检测model  
				//3、目标检测参数文件，比如目标检测阈值，NMS阈值  
				//4、是否开启GPU模型，默认为true，表示开启GPU，false表示用CPU  
      	FRCNN_API::Detector detect("VGG16.prototxt", "VGG16.caffemodel", "config_file.json",true); 		 
	vector<BBox<float> > boxes;  //检测结果保存在这  
	detect.predict(frame, boxes);    //对图片帧frame进行目标检测，保存的结果框，存在boxes中  
	for (int i = 0; i < boxes.size(); i++)   //画框  
	     cv::rectangle(frame, cv::Point(boxes[i][0], boxes[i][1]), cv::Point(boxes[i][2], boxes[i][3]), Scalar(0, 0, 255)); 
	imshow("", frame);  
        waitKey(1);  
	return 0;  
}

## Register.h、VGG16.prototxt、VGG16.caffemodel、config_file.json文件
需要添加Register.h这个头文件，否则会报错说没有注册相关的layer，该文件我放在了工程主目录下  
VGG16.prototxt 文件是网络描述文件  在 caffe-master\models\FRCNN\vgg16\ 下  
VGG16.caffemodel文件是训练好的model
config_file.json是训练以及测试时需要用到的配置文件，有涉及到目标类别数，NMS阈值等等，在caffe-master\examples\FRCNN\config\下  


## 其它
我的csdn博客地址：http://blog.csdn.net/zxj942405301/article/details/78602671  
如果该版本对你有帮助，希望你给我个星星，谢谢~

