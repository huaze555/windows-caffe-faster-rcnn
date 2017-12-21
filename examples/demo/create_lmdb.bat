@echo Create train lmdb..
@if exist img_train_lmdb (@RD /S /Q img_train_lmdb)

@..\..\Build\x64\Release\convert_imageset.exe ^
--shuffle=true --gray=false --resize_height=224 --resize_width=224 ^
data\train\ ^
train.txt ^
img_train_lmdb

@echo Create val lmdb..
@if exist img_val_lmdb (@RD /S /Q img_val_lmdb)
@..\..\Build\x64\Release\convert_imageset.exe ^
--shuffle=true --gray=false --resize_height=224 --resize_width=224 ^
data\val\ ^
val.txt ^
img_val_lmdb

@echo compute mean.binaryproto
@..\..\Build\x64\Release\compute_image_mean.exe ^
img_train_lmdb ^
mean.binaryproto

@pause