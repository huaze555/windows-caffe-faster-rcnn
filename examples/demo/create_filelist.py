# -*- coding:utf-8 -*-
import os

if __name__ == "__main__":
    root = 'data'
    phases = ['train', 'val']
    for phase in phases:
        print('create {} file list'.format(phase))
        with open(phase + '.txt', 'w') as f:
            for dir, dirnames, filenames in os.walk(os.path.join(root, phase)):
                if len(dirnames) == 0:
                    label = dir.split(os.sep)[-1]
                    for file in filenames:
                        f.write('{} {}\n'.format(os.path.join(label, file), label))
    print('finished!')

