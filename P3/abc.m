%{
ptcloud=pcread('E:\titan\272056_3289689真值\xyz+三通道强度数据.pcd');
Location=ptcloud.Location;
Intensity=ptcloud.Intensity;
Normal=ptcloud.Normal;
Location=double(Location);
%figure
%pcshow(ptcloud)
save("E:\titan\272056_3289689真值\Intensity.mat","Location","Intensity","Normal")
%}

ptcloud=pcread('E:\titan\真值1.pcd');
Location=ptcloud.Location;
Color=ptcloud.Color;
Intensity=ptcloud.Intensity;
Normal=ptcloud.Normal;
Location=double(Location);
%save("E:\titan\true_value.mat","Location","Color","Intensity","Normal")

%{
ptcloud=pcread('E:\titan\272056_3289689真值\各类别真值\车辆.pcd');
Location=ptcloud.Location;
Intensity=ptcloud.Intensity;
Normal=ptcloud.Normal;
Location=double(Location);
save("E:\titan\car_true_value.mat","Location","Intensity","Normal")
%}