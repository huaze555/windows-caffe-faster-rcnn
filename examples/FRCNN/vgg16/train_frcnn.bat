
@Build\x64\Release\caffe.exe train ^
--gpu 0 ^
--solver models/FRCNN/vgg16/solver.prototxt ^
--weights models/FRCNN/VGG16.v2.caffemodel


@python examples/FRCNN/convert_model.py ^
--model models/FRCNN/vgg16/test.prototxt  ^
--weights models/FRCNN/snapshot/vgg16_faster_rcnn_iter_70000.caffemodel ^
--config examples/FRCNN/config/voc_config.json ^
--net_out models/FRCNN/vgg16_faster_rcnn_final.caffemodel