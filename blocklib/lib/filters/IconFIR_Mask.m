function [path w h] = IconFIR_Mask()
%

%   Copyright 2018-2019 Bose Corporation
  path(1).x=[14 14 22 22 14 ];
  path(1).y=[44 36 36 44 44 ];
  path(1).rgb = [-1.000000 -1.000000 -1.000000];
  path(1).stroke = [0.000000 0.000000 0.000000];
  path(2).x=[26 34 30 26 ];
  path(2).y=[26 26 18 26 ];
  path(2).rgb = [-1.000000 -1.000000 -1.000000];
  path(2).stroke = [0.000000 0.000000 0.000000];
  path(3).x=[4 12 8 4 ];
  path(3).y=[26 26 18 26 ];
  path(3).rgb = [-1.000000 -1.000000 -1.000000];
  path(3).stroke = [0.000000 0.000000 0.000000];
  path(4).x=[48 56 52 48 ];
  path(4).y=[26 26 18 26 ];
  path(4).rgb = [-1.000000 -1.000000 -1.000000];
  path(4).stroke = [0.000000 0.000000 0.000000];
  path(5).x=[80 88 84 80 ];
  path(5).y=[26 26 18 26 ];
  path(5).rgb = [-1.000000 -1.000000 -1.000000];
  path(5).stroke = [0.000000 0.000000 0.000000];
  path(6).x=[29 31 33 34 34 33 31 29 27 26 26 27 29 ];
  path(6).y=[8 8 7 5 3 1 0 0 1 3 5 7 8 ];
  path(6).rgb = [-1.000000 -1.000000 -1.000000];
  path(6).stroke = [0.000000 0.000000 0.000000];
  path(7).x=[51 53 55 56 56 55 53 51 49 48 48 49 51 ];
  path(7).y=[8 8 7 5 3 1 0 0 1 3 5 7 8 ];
  path(7).rgb = [-1.000000 -1.000000 -1.000000];
  path(7).stroke = [0.000000 0.000000 0.000000];
  path(8).x=[36 36 44 44 36 ];
  path(8).y=[44 36 36 44 44 ];
  path(8).rgb = [-1.000000 -1.000000 -1.000000];
  path(8).stroke = [0.000000 0.000000 0.000000];
  path(9).x=[72 72 80 80 72 ];
  path(9).y=[44 36 36 44 44 ];
  path(9).rgb = [-1.000000 -1.000000 -1.000000];
  path(9).stroke = [0.000000 0.000000 0.000000];
  path(10).x=[12 14 12 ];
  path(10).y=[38 40 42 ];
  path(10).rgb = [-1.000000 -1.000000 -1.000000];
  path(10).stroke = [0.000000 0.000000 0.000000];
  path(11).x=[34 36 34 ];
  path(11).y=[38 40 42 ];
  path(11).rgb = [-1.000000 -1.000000 -1.000000];
  path(11).stroke = [0.000000 0.000000 0.000000];
  path(12).x=[24 26 24 ];
  path(12).y=[2 4 6 ];
  path(12).rgb = [-1.000000 -1.000000 -1.000000];
  path(12).stroke = [0.000000 0.000000 0.000000];
  path(13).x=[46 48 46 ];
  path(13).y=[2 4 6 ];
  path(13).rgb = [-1.000000 -1.000000 -1.000000];
  path(13).stroke = [0.000000 0.000000 0.000000];
  path(14).x=[78 80 78 ];
  path(14).y=[2 4 6 ];
  path(14).rgb = [-1.000000 -1.000000 -1.000000];
  path(14).stroke = [0.000000 0.000000 0.000000];
  path(15).x=[6 8 10 ];
  path(15).y=[28 26 28 ];
  path(15).rgb = [-1.000000 -1.000000 -1.000000];
  path(15).stroke = [0.000000 0.000000 0.000000];
  path(16).x=[28 30 32 ];
  path(16).y=[28 26 28 ];
  path(16).rgb = [-1.000000 -1.000000 -1.000000];
  path(16).stroke = [0.000000 0.000000 0.000000];
  path(17).x=[50 52 54 ];
  path(17).y=[28 26 28 ];
  path(17).rgb = [-1.000000 -1.000000 -1.000000];
  path(17).stroke = [0.000000 0.000000 0.000000];
  path(18).x=[82 84 86 ];
  path(18).y=[28 26 28 ];
  path(18).rgb = [-1.000000 -1.000000 -1.000000];
  path(18).stroke = [0.000000 0.000000 0.000000];
  path(19).x=[82 84 86 ];
  path(19).y=[10 8 10 ];
  path(19).rgb = [-1.000000 -1.000000 -1.000000];
  path(19).stroke = [0.000000 0.000000 0.000000];
  path(20).x=[50 52 54 ];
  path(20).y=[10 8 10 ];
  path(20).rgb = [-1.000000 -1.000000 -1.000000];
  path(20).stroke = [0.000000 0.000000 0.000000];
  path(21).x=[28 30 32 ];
  path(21).y=[10 8 10 ];
  path(21).rgb = [-1.000000 -1.000000 -1.000000];
  path(21).stroke = [0.000000 0.000000 0.000000];
  path(22).x=[0 14 ];
  path(22).y=[40 40 ];
  path(22).rgb = [-1.000000 -1.000000 -1.000000];
  path(22).stroke = [0.000000 0.000000 0.000000];
  path(23).x=[8 8 ];
  path(23).y=[40 26 ];
  path(23).rgb = [-1.000000 -1.000000 -1.000000];
  path(23).stroke = [0.000000 0.000000 0.000000];
  path(24).x=[8 8 26 ];
  path(24).y=[18 4 4 ];
  path(24).rgb = [-1.000000 -1.000000 -1.000000];
  path(24).stroke = [0.000000 0.000000 0.000000];
  path(25).x=[22 36 ];
  path(25).y=[40 40 ];
  path(25).rgb = [-1.000000 -1.000000 -1.000000];
  path(25).stroke = [0.000000 0.000000 0.000000];
  path(26).x=[30 30 ];
  path(26).y=[40 26 ];
  path(26).rgb = [-1.000000 -1.000000 -1.000000];
  path(26).stroke = [0.000000 0.000000 0.000000];
  path(27).x=[44 58 ];
  path(27).y=[40 40 ];
  path(27).rgb = [-1.000000 -1.000000 -1.000000];
  path(27).stroke = [0.000000 0.000000 0.000000];
  path(28).x=[52 52 ];
  path(28).y=[40 26 ];
  path(28).rgb = [-1.000000 -1.000000 -1.000000];
  path(28).stroke = [0.000000 0.000000 0.000000];
  path(29).x=[30 30 ];
  path(29).y=[18 8 ];
  path(29).rgb = [-1.000000 -1.000000 -1.000000];
  path(29).stroke = [0.000000 0.000000 0.000000];
  path(30).x=[52 52 ];
  path(30).y=[18 8 ];
  path(30).rgb = [-1.000000 -1.000000 -1.000000];
  path(30).stroke = [0.000000 0.000000 0.000000];
  path(31).x=[34 48 ];
  path(31).y=[4 4 ];
  path(31).rgb = [-1.000000 -1.000000 -1.000000];
  path(31).stroke = [0.000000 0.000000 0.000000];
  path(32).x=[56 60 ];
  path(32).y=[4 4 ];
  path(32).rgb = [-1.000000 -1.000000 -1.000000];
  path(32).stroke = [0.000000 0.000000 0.000000];
  path(33).x=[84 84 ];
  path(33).y=[18 8 ];
  path(33).rgb = [-1.000000 -1.000000 -1.000000];
  path(33).stroke = [0.000000 0.000000 0.000000];
  path(34).x=[80 84 84 ];
  path(34).y=[40 40 26 ];
  path(34).rgb = [-1.000000 -1.000000 -1.000000];
  path(34).stroke = [0.000000 0.000000 0.000000];
  path(35).x=[70 72 70 ];
  path(35).y=[38 40 42 ];
  path(35).rgb = [-1.000000 -1.000000 -1.000000];
  path(35).stroke = [0.000000 0.000000 0.000000];
  path(36).x=[60 62 ];
  path(36).y=[40 40 ];
  path(36).rgb = [-1.000000 -1.000000 -1.000000];
  path(36).stroke = [0.000000 0.000000 0.000000];
  path(37).x=[64 66 ];
  path(37).y=[40 40 ];
  path(37).rgb = [-1.000000 -1.000000 -1.000000];
  path(37).stroke = [0.000000 0.000000 0.000000];
  path(38).x=[68 72 ];
  path(38).y=[40 40 ];
  path(38).rgb = [-1.000000 -1.000000 -1.000000];
  path(38).stroke = [0.000000 0.000000 0.000000];
  path(39).x=[62 64 ];
  path(39).y=[4 4 ];
  path(39).rgb = [-1.000000 -1.000000 -1.000000];
  path(39).stroke = [0.000000 0.000000 0.000000];
  path(40).x=[66 68 ];
  path(40).y=[4 4 ];
  path(40).rgb = [-1.000000 -1.000000 -1.000000];
  path(40).stroke = [0.000000 0.000000 0.000000];
  path(41).x=[70 72 ];
  path(41).y=[4 4 ];
  path(41).rgb = [-1.000000 -1.000000 -1.000000];
  path(41).stroke = [0.000000 0.000000 0.000000];
  path(42).x=[74 80 ];
  path(42).y=[4 4 ];
  path(42).rgb = [-1.000000 -1.000000 -1.000000];
  path(42).stroke = [0.000000 0.000000 0.000000];
  path(43).x=[88 94 ];
  path(43).y=[4 4 ];
  path(43).rgb = [-1.000000 -1.000000 -1.000000];
  path(43).stroke = [0.000000 0.000000 0.000000];
  path(44).x=[30 30 ];
  path(44).y=[6 2 ];
  path(44).rgb = [-1.000000 -1.000000 -1.000000];
  path(44).stroke = [0.000000 0.000000 0.000000];
  path(45).x=[84 84 ];
  path(45).y=[6 2 ];
  path(45).rgb = [-1.000000 -1.000000 -1.000000];
  path(45).stroke = [0.000000 0.000000 0.000000];
  path(46).x=[28 32 ];
  path(46).y=[4 4 ];
  path(46).rgb = [-1.000000 -1.000000 -1.000000];
  path(46).stroke = [0.000000 0.000000 0.000000];
  path(47).x=[82 86 ];
  path(47).y=[4 4 ];
  path(47).rgb = [-1.000000 -1.000000 -1.000000];
  path(47).stroke = [0.000000 0.000000 0.000000];
  path(48).x=[92 94 92 ];
  path(48).y=[2 4 6 ];
  path(48).rgb = [-1.000000 -1.000000 -1.000000];
  path(48).stroke = [0.000000 0.000000 0.000000];
  path(49).x=[83 85 87 88 88 87 85 83 81 80 80 81 83 ];
  path(49).y=[8 8 7 5 3 1 0 0 1 3 5 7 8 ];
  path(49).rgb = [-1.000000 -1.000000 -1.000000];
  path(49).stroke = [0.000000 0.000000 0.000000];
  path(50).x=[52 52 ];
  path(50).y=[6 2 ];
  path(50).rgb = [-1.000000 -1.000000 -1.000000];
  path(50).stroke = [0.000000 0.000000 0.000000];
  path(51).x=[50 54 ];
  path(51).y=[4 4 ];
  path(51).rgb = [-1.000000 -1.000000 -1.000000];
  path(51).stroke = [0.000000 0.000000 0.000000];
  path(52).x=[16 18 16 18 ];
  path(52).y=[41 41 38 38 ];
  path(52).rgb = [-1.000000 -1.000000 -1.000000];
  path(52).stroke = [0.000000 0.000000 0.000000];
  path(53).x=[20 20 ];
  path(53).y=[43 41 ];
  path(53).rgb = [-1.000000 -1.000000 -1.000000];
  path(53).stroke = [0.000000 0.000000 0.000000];
  path(54).x=[18 19 ];
  path(54).y=[42 42 ];
  path(54).rgb = [-1.000000 -1.000000 -1.000000];
  path(54).stroke = [0.000000 0.000000 0.000000];
  path(55).x=[38 40 38 40 ];
  path(55).y=[41 41 38 38 ];
  path(55).rgb = [-1.000000 -1.000000 -1.000000];
  path(55).stroke = [0.000000 0.000000 0.000000];
  path(56).x=[42 42 ];
  path(56).y=[43 41 ];
  path(56).rgb = [-1.000000 -1.000000 -1.000000];
  path(56).stroke = [0.000000 0.000000 0.000000];
  path(57).x=[40 41 ];
  path(57).y=[42 42 ];
  path(57).rgb = [-1.000000 -1.000000 -1.000000];
  path(57).stroke = [0.000000 0.000000 0.000000];
  path(58).x=[74 76 74 76 ];
  path(58).y=[41 41 38 38 ];
  path(58).rgb = [-1.000000 -1.000000 -1.000000];
  path(58).stroke = [0.000000 0.000000 0.000000];
  path(59).x=[78 78 ];
  path(59).y=[43 41 ];
  path(59).rgb = [-1.000000 -1.000000 -1.000000];
  path(59).stroke = [0.000000 0.000000 0.000000];
  path(60).x=[76 77 ];
  path(60).y=[42 42 ];
  path(60).rgb = [-1.000000 -1.000000 -1.000000];
  path(60).stroke = [0.000000 0.000000 0.000000];
  w = 93;
  h = 44;
end
