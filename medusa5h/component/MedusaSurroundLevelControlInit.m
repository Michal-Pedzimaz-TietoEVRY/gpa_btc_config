function SurroundConfig = MedusaSurroundLevelControlInit
    %% Init script for MedusaFullRateMixer block
    %
    % Returns:
    % Structs that can be passed to the Simulink block 
    %   SurroundConfig : config struct to interface with library block 
    %%
    
    % Default values for Surround Level Control parameters
    defaultSurroundIndex = 128;                         % Default Surround Index
    defaultRampRate = 100;                              % Default Ramp Rate in dB per second
    defaultRampTime = 0;                                % Default Ramp Time in milliseconds
    
    % Constructing the SurroundConfig struct
    SurroundConfig = struct('defaultSurroundIndex', defaultSurroundIndex, ...
                            'defaultRampRate', defaultRampRate, ...
                            'defaultRampTime', defaultRampTime);
end