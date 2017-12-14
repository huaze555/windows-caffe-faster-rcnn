This repository contains a C++ implementation under windows7, this version combine [Microsoft's windows-caffe](https://github.com/Microsoft/caffe) and [D-X-Y's caffe-faster-rcnn version](https://github.com/D-X-Y/caffe-faster-rcnn/tree/dev) which runs under linux and c++. 

This version can run(include train,test) under windows and absolute c++ environment,no python at all.

Setup follows Microsoft's windows-caffe step: 
## Windows Setup
**Requirements**: Visual Studio 2013
### Pre-Build Steps
Copy `.\windows\CommonSettings.props.example` to `.\windows\CommonSettings.props`

By defaults Windows build requires `CUDA` and `cuDNN` libraries.
Both can be disabled by adjusting build variables in `.\windows\CommonSettings.props`.
3rd party dependencies required by Caffe are automatically resolved via NuGet.

### CUDA
Download `CUDA Toolkit 7.5` [from nVidia website](https://developer.nvidia.com/cuda-toolkit).
If you don't have CUDA installed, you can experiment with CPU_ONLY build.
In `.\windows\CommonSettings.props` set `CpuOnlyBuild` to `true` and set `UseCuDNN` to `false`.

### cuDNN
The cudnn files are already in main fold,which rename the cuda,include the bin,lib,include 3 folders 
Importantly, you must set `CuDnnPath` to point to this location in `.\windows\CommonSettings.props`.
`CuDnnPath` defined in `.\windows\CommonSettings.props`.
Also, you can disable cuDNN by setting `UseCuDNN` to `false` in the property file.

#### Remark
After you have built solution, in order to use it you have to:
* add `<caffe_root>\Build\x64\Release` to your system path.

## License and Citation

Caffe is released under the [BSD 2-Clause license](https://github.com/BVLC/caffe/blob/master/LICENSE).
The BVLC reference models are released for unrestricted use.

Please cite Caffe in your publications if it helps your research:

    @article{jia2014caffe,
      Author = {Jia, Yangqing and Shelhamer, Evan and Donahue, Jeff and Karayev, Sergey and Long, Jonathan and Girshick, Ross and Guadarrama, Sergio and Darrell, Trevor},
      Journal = {arXiv preprint arXiv:1408.5093},
      Title = {Caffe: Convolutional Architecture for Fast Feature Embedding},
      Year = {2014}
    }
