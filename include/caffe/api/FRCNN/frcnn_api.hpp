#ifndef CAFFE_FRCNN_API_HPP_
#define CAFFE_FRCNN_API_HPP_

#include <vector>
#include <string>
#include <boost/make_shared.hpp>
#include <boost/shared_ptr.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "caffe/blob.hpp"
#include "caffe/common.hpp"
#include "caffe/layer.hpp"
#include "caffe/net.hpp"
#include "caffe/FRCNN/util/frcnn_param.hpp"
#include "caffe/FRCNN/util/frcnn_helper.hpp"



namespace FRCNN_API{
	using std::vector;
	using caffe::Blob;
	using caffe::Net;
	using caffe::Frcnn::FrcnnParam;
	using caffe::Frcnn::Point4f;
	using caffe::Frcnn::BBox;

	class Detector {
	public:
		//构造函数
		Detector(const std::string &proto_file, const std::string &model_file, const std::string& config_file,
			bool useGPU = true, bool ignoreLog = true);
		//对一张图片进行检测
		vector<BBox<float> > predict(const cv::Mat& img_in);

	private:
		void Set_Model(const std::string &proto_file, const std::string &model_file);
		void predict_original(const cv::Mat &img_in, vector<BBox<float> > &results);
		void predict_iterative(const cv::Mat &img_in, vector<BBox<float> > &results);

		void preprocess(const cv::Mat &img_in, const int blob_idx); //将图片img_in 填充进网络的输入层的第blob_idx个blob
		void preprocess(const vector<float> &data, const int blob_idx);//将图片的结构信息(高，宽，缩放比例)存入网络的输入层的第blob_idx的blob
		vector<boost::shared_ptr<Blob<float> > > predict(const vector<std::string> blob_names); //网络进行前向传播，将blob_names中的每个blob返回
		boost::shared_ptr<Net<float> > net_;
		float mean_[3];
		int roi_pool_layer;
	};
}

#endif