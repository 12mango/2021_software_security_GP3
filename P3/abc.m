%{
ptcloud=pcread('E:\titan\272056_3289689��ֵ\xyz+��ͨ��ǿ������.pcd');
Location=ptcloud.Location;
Intensity=ptcloud.Intensity;
Normal=ptcloud.Normal;
Location=double(Location);
%figure
%pcshow(ptcloud)
save("E:\titan\272056_3289689��ֵ\Intensity.mat","Location","Intensity","Normal")
%}

ptcloud=pcread('E:\titan\��ֵ1.pcd');
Location=ptcloud.Location;
Color=ptcloud.Color;
Intensity=ptcloud.Intensity;
Normal=ptcloud.Normal;
Location=double(Location);
%save("E:\titan\true_value.mat","Location","Color","Intensity","Normal")

%{
ptcloud=pcread('E:\titan\272056_3289689��ֵ\�������ֵ\����.pcd');
Location=ptcloud.Location;
Intensity=ptcloud.Intensity;
Normal=ptcloud.Normal;
Location=double(Location);
save("E:\titan\car_true_value.mat","Location","Intensity","Normal")
%}