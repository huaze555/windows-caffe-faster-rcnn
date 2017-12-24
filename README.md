![image](https://github.com/huaze555/windows-caffe-faster-rcnn/raw/master/demo_image/1.jpg)  

### This version is for you if you have to use C++ version faster-rcnn in the windows environment because the project needs.

## Introduction
The windows C ++ version of faster-rcnn is based on two versions:  
### 一: [Microsoft's windows-caffe](https://github.com/Microsoft/caffe)  
This version is Microsoft's windows caffe version    
### 二: [D-X-Y's caffe-faster-rcnn version](https://github.com/D-X-Y/caffe-faster-rcnn/tree/dev)  
This is the D-X-Y's Linux c ++ version of faster-rcnn
    
## Features
- After combining the above two, this is the C ++ version faster-rcnn base on windows, no python, support training and testing.  
- It takes about 180ms to test a image, under the NVIDIA GTX1060 , using the VGG16 model. 

## Compile（VS2013 x64 release mode）
- Same as [Microsoft Caffe](https://github.com/Microsoft/caffe), or refer to [Blog](http://www.cnblogs.com/love6tao/p/5706830.html)  
- Here for convenience, I have put the cudnn files under the project, the cuda folder under the main directory.  
- If you want to configure cudnn, remember write the right cuda folder path in the "cuDnnPath" in the ".\Windows\CommonSettings.props" .

## Train model
- The steps to train the model are exactly the same as [D-X-Y's caffe-faster-rcnn version](https://github.com/D-X-Y/caffe-faster-rcnn/tree/dev).  
- You can read the script "caffe-master\examples\FRCNN\vgg16\train_frcnn.bat" for detail.  
- Of course, you can train your model under [python version](https://github.com/rbgirshick/py-faster-rcnn).   


## Test the model, calculate mAP and Recall
Run the script "caffe-master\examples\FRCNN\vgg16\test_frcnn.bat" for detail.

## Use Faster-rcnn like OpenCV in VS2013
- After compiling, all dependencies generated with faster-rcnn are under "caffe-master\Build\x64\Release\".  
- Third-party dependencies, such as OpenCV, Glog, protobuf, etc. are in the "NugetPackages".  
- Just as VS2013 configures OpenCV, configure faster-rcnn as long as the include-files for faster-rcnn and third-party libraries are placed into the VC ++ directory of VS2013, the lib files are placed into the library directory, and linker-> input-> additional dependencies, input:

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

- Refer to the blog: http://blog.csdn.net/auto1993/article/details/70198435 for detail.  
- Because the third-party libraries are configured more trouble, for convenience, I packaged the NugetPackages files in the third-party library on [Baidu network disk](https://pan.baidu.com/s/1gfCjiJh), the password : sj7f 
- There are three folders in the packaged folder: bin, include, lib, respectively, corresponding to the executable file, header files, library files. 

## Test images
After VS2013 configuration successful, you can write code in VS2013 to test the pictures.
The detector was defined in  file caffe-master\include\caffe\api\FRCNN\frcnn_api.hpp:  

```c++
#include <caffe\api\FRCNN\frcnn_api.hpp>  //Detect head file  
#include "Register.h"           //This file is necessary used to register the relevant caffe layer 
using namespace std;  
using namespace cv;  
using namespace caffe::Frcnn;  
int main(){    
        Mat frame = imread("1.jpg);  //image  
	/* Initiaze the detector, the four parameters were:  
	1. network file   
	2. trained model file  
	3. config file  
	4. whether to open the GPU mode, default true  
	5. whether to ignore print log, default true
	*/
	FRCNN_API::Detector detect("VGG16.prototxt", "VGG16.caffemodel", "config_file.json", true, true);  
	vector<BBox<float> > boxes = detect.predict(frame);    // forward, detect results saved here 
	for (int i = 0; i < boxes.size(); i++)   //draw rects  
	     rectangle(frame, cv::Point(boxes[i][0], boxes[i][1]), cv::Point(boxes[i][2], boxes[i][3]), Scalar(0, 0, 255)); 
	imshow("demo", frame);  
        waitKey(0);  
	return 0;  
}
```  

## Register.h、VGG16.prototxt、VGG16.caffemodel、config_file.json files
- Need to add Register.h to your code, otherwise it will complain that no registration related layer, I had put this file in the main project directory.  
- "VGG16.prototxt" -- a network description file  under path "caffe-master\models\FRCNN\vgg16"   
- "VGG16.caffemodel" -- trained model file  
- "config_file.json" -- training and testing need to use the configuration file, it involves the number of target categories, NMS threshold, etc. under "caffe-master\examples\FRCNN\config\" 


## others
- My csdn blog address: http://blog.csdn.net/zxj942405301/article/details/78602671  
- If this version is helpful to you, give me a star, thank you ~

