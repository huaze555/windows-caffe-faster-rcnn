@Build\x64\Release\test_frcnn.exe ^
--gpu 0 ^
--model models\FRCNN\vgg_cnn_m_1024\test.prototxt ^
--weights models\FRCNN\vgg_cnn_m_1024_faster_rcnn_final.caffemodel ^
--default_c examples\FRCNN\config\voc_config.json ^
--image_root VOCdevkit\VOC2007\JPEGImages\ ^
--image_list examples\FRCNN\dataset\voc2007.test ^
--out_file examples\FRCNN\results\1.frcnn ^
--max_per_image 100

@echo Calculate mAP
@python examples/FRCNN/calculate_voc_ap.py ^
--gt examples/FRCNN/dataset/voc2007.test ^
--answer examples/FRCNN/results/1.frcnn ^
--overlap 0.5

@echo.
@echo Calculate recall
@python examples/FRCNN/calculate_recall.py ^
--gt examples/FRCNN/dataset/voc2007.test ^
--answer examples/FRCNN/results/1.frcnn ^
--overlap 0.5

@echo.
@echo ############## end ##############
@pause