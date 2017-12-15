#include <caffe/common.hpp>
#include "caffe/layers/input_layer.hpp"  
#include "caffe/layers/inner_product_layer.hpp"  
#include "caffe/layers/dropout_layer.hpp"  
#include "caffe/layers/conv_layer.hpp"  
#include "caffe/layers/relu_layer.hpp"  
#include "caffe/layers/prelu_layer.hpp"  
#include "caffe/layers/pooling_layer.hpp"  
#include "caffe/layers/lrn_layer.hpp"  
#include "caffe/layers/softmax_layer.hpp"  
#include "caffe/layers/flatten_layer.hpp"
#include "caffe/layers/concat_layer.hpp"
#include "caffe/layers/reshape_layer.hpp"
#include "caffe/layers/softmax_layer.hpp"
#include "caffe/layers/roi_pooling_layer.hpp"

//faster-rcnn
#include "caffe/FRCNN/frcnn_proposal_layer.hpp""
#include "caffe/api/FRCNN/frcnn_api.hpp"
//×¢²á²ã
namespace caffe
{
	namespace Frcnn{
		extern INSTANTIATE_CLASS(FrcnnProposalLayer);
		REGISTER_LAYER_CLASS(FrcnnProposal);
	}
	extern INSTANTIATE_CLASS(InputLayer);
	REGISTER_LAYER_CLASS(Input);

	extern INSTANTIATE_CLASS(SplitLayer);
	REGISTER_LAYER_CLASS(Split);

	extern INSTANTIATE_CLASS(ConvolutionLayer);
	REGISTER_LAYER_CLASS(Convolution);

	extern INSTANTIATE_CLASS(InnerProductLayer);
	REGISTER_LAYER_CLASS(InnerProduct);

	extern INSTANTIATE_CLASS(DropoutLayer);
	REGISTER_LAYER_CLASS(Dropout);

	extern INSTANTIATE_CLASS(ReLULayer);
	REGISTER_LAYER_CLASS(ReLU);

	extern INSTANTIATE_CLASS(PReLULayer);
	REGISTER_LAYER_CLASS(PReLU);

	extern INSTANTIATE_CLASS(PoolingLayer);
	REGISTER_LAYER_CLASS(Pooling);

	extern INSTANTIATE_CLASS(LRNLayer);
	REGISTER_LAYER_CLASS(LRN);

	extern INSTANTIATE_CLASS(SoftmaxLayer);
	REGISTER_LAYER_CLASS(Softmax);

	extern INSTANTIATE_CLASS(ROIPoolingLayer);
	REGISTER_LAYER_CLASS(ROIPooling);

	extern INSTANTIATE_CLASS(FlattenLayer);
	REGISTER_LAYER_CLASS(Flatten);

	extern INSTANTIATE_CLASS(ConcatLayer);
	REGISTER_LAYER_CLASS(Concat);

	extern INSTANTIATE_CLASS(ReshapeLayer);
	REGISTER_LAYER_CLASS(Reshape);

}