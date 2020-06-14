## Author: SuperKingLol
## Created: 2020-06-11

% Load the map and path CSV files and plot their outputs. This function is 
% only intended for use to assist debugging and developing pathfinding in C&C.
function plot_path(final_path_file, map_file)
  map_vector = csvread(map_file);
  path = csvread(final_path_file);
  
  % Reshape map vector into correctly oriented 2D RGB image data
  map = permute(reshape(map_vector, [64, 64, 3]), [2,1,3]);
  imshow(map);
  hold on;
  plot(path(1:end-1,1) + 1, path(1:end-1,2) + 1,'b','linewidth',4);
endfunction
