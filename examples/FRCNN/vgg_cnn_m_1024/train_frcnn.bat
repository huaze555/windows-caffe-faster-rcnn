
@Build\x64\Release\caffe.exe train ^
--gpu 0 ^
--solver models/FRCNN/vgg_cnn_m_1024/solver.prototxt ^
--weights models/FRCNN/vgg_cnn_m_1024.v2.caffemodel


@python examples/FRCNN/convert_model.py ^
--model models/FRCNN/vgg_cnn_m_1024/test.prototxt  ^
--weights models/FRCNN/snapshot/vgg_cnn_m_1024_iter_70000.caffemodel ^
--config examples/FRCNN/config/voc_config.json ^
--net_out models/FRCNN/vgg_cnn_m_1024_faster_rcnn_final.caffemodel