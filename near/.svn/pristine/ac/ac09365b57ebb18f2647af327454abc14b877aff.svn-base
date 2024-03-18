classdef Upmixer1p1TuneConfig < TuneConfigClass
    % Upmixer1p1TuneConfig Default TuneVar values for Upmixer1p1 block
    % Note that this class does *NOT* have the ablity to Validate, but it can
    % lock and default property values. Do not create a Validate method here!
    %.This is because TuneVar values must be validated by their translations
    %.instead of by build-time logic. During tunings or data builds, only the
    %.translation code (in a DLL) is available to ensure the TuneVars are good.
    %.TuneVars are inherently variable size, but their maximum dimensions are
    %.set by either their build-time default value, or explicitly set in the
    %.TuneVar block (TuneTOPs only support automatic size from default value).
    % This class simply holds startup values for TuneVars that are used during
    % simulation or translated into TOPs and built into the generated code.
    %.To calculate default values using multiple properties, use anonymous
    %.functions in a call to Default in this constructor.
    %.e.g. the provided default value will start with @().
    %.Usage:
    %. The BTConfig.AddAllTuneVars method automates the addition of properties
    %.for this class by parsing the Simulink canvas content.

    %   Copyright 2023 Bose Corporation
    properties (Description='TuneDefault',GetObservable,SetObservable)
        f1_mix single = [4 3 2 1 0; 3 2.25 1.5 .75 0; 2 1.5 1 .5 0; 1 .75 .5 .25 0; 0 0 0 0 0] % [3 2 1 0; 2.25 1.5 .75 0; 1.5 1 .5 0; .75 .5 .25 0];
        f2_mix 
        f3_mix 
        f4_mix 
        f5_mix 
        f6_mix
        f7_mix 
        LFI0_mix  
        LFT0_mix 
        RFI0_mix 
        RFT0_mix 
        LSI0_mix 
        LST0_mix 
        RSI0_mix 
        RST0_mix 
        LCI0_mix 
        LCT0_mix 
        RCI0_mix 
        RCT0_mix 
        LFI1_mix 
        LFT1_mix 
        RFI1_mix 
        RFT1_mix 
        LSI1_mix
        LST1_mix 
        RSI1_mix 
        RST1_mix
        LCI1_mix 
        LCT1_mix 
        RCI1_mix 
        RCT1_mix
        nv0l_mix 
        nv0r_mix 
        nv1l_mix
        nv1r_mix 
    end
    methods
        function this = Upmixer1p1TuneConfig(constructingParentObj)
            % Upmixer1p1TuneConfig Constructor. Lock and Default properties
            %.Parent property available for use, but only calculated @() values
            %.are recommended because the parent object might not be fully
            %.constructed yet. If there are no property Lock/Default actions
            %.this entire method could be removed. <<Insert code below>>

            this@TuneConfigClass(constructingParentObj);
            
            this.Default(@this.f1_mix,  @()single([4 3 2 1 0; 3 2.25 1.5 .75 0; 2 1.5 1 .5 0; 1 .75 .5 .25 0; 0 0 0 0 0]));
            this.Default(@this.f2_mix,  @()flip((this.f1_mix), 2));
            this.Default(@this.f3_mix,  @()flip((this.f1_mix), 1));
            this.Default(@this.f4_mix,  @()flip((this.f2_mix), 1));
            this.Default(@this.f5_mix,  @()this.f1_mix+ 5);
            this.Default(@this.f6_mix,  @()this.f2_mix+ 5);
            this.Default(@this.f7_mix,  @()this.f3_mix+ 5);
            this.Default(@this.LFI0_mix,@()this.f4_mix+ 5);
            this.Default(@this.LFT0_mix,@()this.f1_mix+ 10);
            this.Default(@this.RFI0_mix,@()this.f2_mix+ 10);
            this.Default(@this.RFT0_mix,@()this.f3_mix+ 10);
            this.Default(@this.LSI0_mix,@()this.f4_mix+ 10);
            this.Default(@this.LST0_mix,@()this.f1_mix+ 15);
            this.Default(@this.RSI0_mix,@()this.f2_mix+ 15);
            this.Default(@this.RST0_mix,@()this.f3_mix+ 15);
            this.Default(@this.LCI0_mix,@()this.f4_mix+ 15);
            this.Default(@this.LCT0_mix,@()this.f1_mix+ 20);
            this.Default(@this.RCI0_mix,@()this.f2_mix+ 20);
            this.Default(@this.RCT0_mix,@()this.f3_mix+ 20);
            this.Default(@this.LFI1_mix,@()this.f4_mix+ 20);
            this.Default(@this.LFT1_mix,@()this.f1_mix+ 25);
            this.Default(@this.RFI1_mix,@()this.f2_mix+ 25);
            this.Default(@this.RFT1_mix,@()this.f3_mix+ 25);
            this.Default(@this.LSI1_mix,@()this.f4_mix+ 25);
            this.Default(@this.LST1_mix,@()this.f1_mix+ 30);
            this.Default(@this.RSI1_mix,@()this.f2_mix+ 30);
            this.Default(@this.RST1_mix,@()this.f3_mix+ 30);
            this.Default(@this.LCI1_mix,@()this.f4_mix+ 30);
            this.Default(@this.LCT1_mix,@()this.f1_mix+ 35);
            this.Default(@this.RCI1_mix,@()this.f2_mix+ 35);
            this.Default(@this.RCT1_mix,@()this.f3_mix+ 35);
            this.Default(@this.nv0l_mix,@()this.f4_mix+ 35);
            this.Default(@this.nv0r_mix,@()this.f1_mix+ 40);
            this.Default(@this.nv1l_mix,@()this.f2_mix+ 40);
            this.Default(@this.nv1r_mix,@()this.f3_mix+ 40);
        end  
    end
end
