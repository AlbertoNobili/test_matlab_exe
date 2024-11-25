%% Generate executable
cfg = coder.config('exe');
%codegen -report -config cfg sobel main.c main.h

%% Test executable
im = imread('hello.jpg');
gray = (0.2989 * double(im(:,:,1)) + 0.5870 * double(im(:,:,2)) + 0.1140 * double(im(:,:,3)))/255;
fid = fopen('gray.bin', 'w');
fwrite(fid, gray, 'double');
fclose(fid);
system('sobel.exe gray.bin 0.7');

%% Show results
fd = fopen('edge.bin', 'r');
edgeImExe = fread(fd, size(gray), 'uint8');
fclose(fd);
im3Exe = repmat(edgeImExe, [1 1 3]);
figure
image(im3Exe);
title('Exe result')