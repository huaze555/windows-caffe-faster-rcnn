
@Build\x64\Release\caffe.exe train ^
--gpu 0 ^
--solver models/FRCNN/zf/solver.prototxt ^
--weights models/FRCNN/ZF.v2.caffemodel


@python examples/FRCNN/convert_model.py ^
--model models/FRCNN/zf/test.prototxt  ^
--weights models/FRCNN/snapshot/zf_faster_rcnn_iter_70000.caffemodel ^
--config examples/FRCNN/config/voc_config.json ^
--net_out models/FRCNN/zf_faster_rcnn_final.caffemodel