disp('Running NEARSimEvents')

% Create RTC Simulation Object
RTC_SIM_OBJ = RTC_SimData();

front_left  = [0,0];
front_right = [1,0];
back_left   = [0,1];
back_right  = [1,1];
sim_time = 1;

if exist('isNEARTest', 'var') % NEAR Branch
    prefix = 'Test_';
    clear isNEARTest
else % Bernstein Branch
    prefix = 'NEAR_';
end

NEAR_location1_RTC =    [prefix 'Channel1_Location'];
NEAR_location2_RTC =    [prefix 'Channel2_Location'];
NEAR_location3_RTC =    [prefix 'Channel3_Location'];
NEAR_location4_RTC =    [prefix 'Channel4_Location'];
NEAR_enable_RTC =       [prefix 'Enable'];
NEAR_mute1_RTC =        [prefix 'Mute1Set'];
NEAR_mute2_RTC =        [prefix 'Mute2Set'];
NEAR_mute3_RTC =        [prefix 'Mute3Set'];
NEAR_mute4_RTC =        [prefix 'Mute4Set'];
NEAR_volume1_RTC =      [prefix 'Volume1Set'];
NEAR_volume2_RTC =      [prefix 'Volume2Set'];
NEAR_volume3_RTC =      [prefix 'Volume3Set'];
NEAR_volume4_RTC =      [prefix 'Volume4Set'];

% VNC
if 0
    RTC_SIM_OBJ.AddREQ( 'Test_NEARAnnNoiseLevel', sim_time/2, [0001 [0]])
end

% Enable
if 0
    t_i = sim_time/2;
    RTC_SIM_OBJ.AddREQ( NEAR_enable_RTC, 0,    [0001 [1]]);
    RTC_SIM_OBJ.AddREQ( NEAR_enable_RTC, t_i,  [0001 [0]]);
end

% Mute
if 0
    RTC_SIM_OBJ.AddREQ( NEAR_mute1_RTC,   sim_time/5, [0001, 1, 0, 0.001]);
    RTC_SIM_OBJ.AddREQ( NEAR_mute2_RTC, 2*sim_time/5, [0001, 1, 0, 0.001]);
    RTC_SIM_OBJ.AddREQ( NEAR_mute3_RTC, 3*sim_time/5, [0001, 1, 0, 0.001]);
    RTC_SIM_OBJ.AddREQ( NEAR_mute4_RTC, 4*sim_time/5, [0001, 1, 0, 0.001]);
end

% Volume
if 0
%     RTC_SIM_OBJ.AddREQ( NEAR_volume1_RTC, sim_time/8, [0001, 0, 0, 0.001]);
    RTC_SIM_OBJ.AddREQ( NEAR_volume1_RTC,   sim_time/5, [0001, 128, 0, 0.001]);
    RTC_SIM_OBJ.AddREQ( NEAR_volume2_RTC, 2*sim_time/5, [0001, 128, 0, 0.001]);
    RTC_SIM_OBJ.AddREQ( NEAR_volume3_RTC, 3*sim_time/5, [0001, 128, 0, 0.001]);
    RTC_SIM_OBJ.AddREQ( NEAR_volume4_RTC, 4*sim_time/5, [0001, 128, 0, 0.001]);
end

% Default
if 0
    location_of_choice = front_left;
        RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 0,     [0001 location_of_choice]);
        RTC_SIM_OBJ.AddREQ( NEAR_location2_RTC, 0,     [0001 location_of_choice]);
        RTC_SIM_OBJ.AddREQ( NEAR_location3_RTC, 0,     [0001 location_of_choice]);
        RTC_SIM_OBJ.AddREQ( NEAR_location4_RTC, 0,     [0001 location_of_choice]);
end

if 0
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, sim_time/2, [0001 [0, 0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location2_RTC, sim_time/2, [0001 [0, 0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location3_RTC, sim_time/2, [0001 [0, 0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location4_RTC, sim_time/2, [0001 [0, 0]]);
end

% Out of bounds location
if 0
    RTC_SIM_OBJ.AddREQ( location1_RTC, 0,     [0001 [.5,    .5]]);
    RTC_SIM_OBJ.AddREQ( location1_RTC, 1,     [0001 [-1,    .5]]);
    RTC_SIM_OBJ.AddREQ( location1_RTC, 2,     [0001 [.5,    .5]]);
    RTC_SIM_OBJ.AddREQ( location1_RTC, 3,     [0001 [.5,     2]]);
    RTC_SIM_OBJ.AddREQ( location1_RTC, 4,     [0001 [.5,    .5]]);
end

% Diagonal sweep
if 1
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 0,                [0001 [0,      0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, sim_time/5,       [0001 [.25,  .25]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 2*sim_time/5,     [0001 [.5,    .5]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 3*sim_time/5,     [0001 [.75,  .75]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 4*sim_time/5,     [0001 [1,      1]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location2_RTC, 0,                [0001 [0,      0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location2_RTC, sim_time/5,       [0001 [.25,  .25]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location2_RTC, 2*sim_time/5,     [0001 [.5,    .5]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location2_RTC, 3*sim_time/5,     [0001 [.75,  .75]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location2_RTC, 4*sim_time/5,     [0001 [1,      1]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location3_RTC, 0,                [0001 [0,      0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location3_RTC, sim_time/5,       [0001 [.25,  .25]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location3_RTC, 2*sim_time/5,     [0001 [.5,    .5]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location3_RTC, 3*sim_time/5,     [0001 [.75,  .75]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location3_RTC, 4*sim_time/5,     [0001 [1,      1]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location4_RTC, 0,                [0001 [0,      0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location4_RTC, sim_time/5,       [0001 [.25,  .25]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location4_RTC, 2*sim_time/5,     [0001 [.5,    .5]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location4_RTC, 3*sim_time/5,     [0001 [.75,  .75]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location4_RTC, 4*sim_time/5,     [0001 [1,      1]]);
end


% Large location
if 0
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 0,    [0001 [0, 0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 1,    [0001 [10, 10]]);
end

% Two locations at the same time
if 0
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 0,    [0001 [0, 0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 1,    [0001 [0, 1]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 1,    [0001 [0, .5]]);
end

% Perimeter sweep
if 0
    t_i = sim_time/32
    % Front left to back left    
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 0,      [0001 [0,    0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 1*t_i,  [0001 [.125, 0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 2*t_i,  [0001 [.25,  0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 3*t_i,  [0001 [.375, 0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 4*t_i,  [0001 [.5,   0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 5*t_i,  [0001 [.625, 0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 6*t_i,  [0001 [.75,  0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 7*t_i,  [0001 [.875, 0]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 8*t_i,  [0001 [1,    0]]);
    % Back left to back right*
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 9*t_i,  [0001 [1, .125]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 10*t_i, [0001 [1, .25]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 11*t_i, [0001 [1, .375]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 12*t_i, [0001 [1, .5]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 13*t_i, [0001 [1, .625]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 14*t_i, [0001 [1, .75]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 15*t_i, [0001 [1, .875]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 16*t_i, [0001 [1, 1]]);
    % Back right to front right*
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 17*t_i, [0001 [.875, 1]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 18*t_i, [0001 [.75,  1]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 19*t_i, [0001 [.625, 1]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 20*t_i, [0001 [.5,   1]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 21*t_i, [0001 [.375, 1]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 22*t_i, [0001 [.25,  1]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 23*t_i, [0001 [.125, 1]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 24*t_i, [0001 [0,    1]]);
    % Front right to front left*
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 25*t_i, [0001 [0, .875]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 26*t_i, [0001 [0, .75]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 27*t_i, [0001 [0, .625]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 28*t_i, [0001 [0, .5]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 29*t_i, [0001 [0, .375]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 30*t_i, [0001 [0, .25]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 31*t_i, [0001 [0, .125]]);
    RTC_SIM_OBJ.AddREQ( NEAR_location1_RTC, 32*t_i, [0001 [0, 0]]);
end