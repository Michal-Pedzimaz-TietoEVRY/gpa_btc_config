classdef SpeedBoundsConfig < BtcBaseClass
    % SpeedBoundsConfig
    % Configuration Parameters for the Speed Bounds module

    properties(Constant = true, Hidden = true)
        % These are the properties that are not allowed to be changed.
        % NOTE: symfun should read this parameter.
        MaxSpeed        = 508; 
        TableSize       = 128;
    end
    
    properties(Dependent = true, Hidden = true)
        StepSize ;
    end
    
    properties (GetObservable,SetObservable)
        % These are the settable properties that will be used directly by
        % the block.
        SpeedBoundsAxis         single {mustBeNonnegative};
        SpeedBoundsMindBSPL     single {mustBeNonnegative};
        SpeedBoundsMaxdBSPL     single {mustBeNonnegative}
        SpeedBoundsOn           single {mustBe0or1}     =   1;
    end
      
    methods
        function obj = SpeedBoundsConfig()
            % Constructor that creates an instance of the SpeedBoundsConfig class.            
            obj.SpeedBoundsAxis ...
                = reshape(0:obj.StepSize:obj.MaxSpeed,obj.TableSize,1);
            obj.SpeedBoundsMindBSPL ...
                = reshape(3*(1:obj.TableSize),obj.TableSize,1);
            obj.SpeedBoundsMaxdBSPL ...
                = reshape(3*(1:obj.TableSize),obj.TableSize,1);
            
        end
        
        function value = get.StepSize(obj)
              value= obj.MaxSpeed/(obj.TableSize - 1);
        end
        
        function set.SpeedBoundsAxis(obj,value)
            % Check that the table entered is of the correct size
            if any(size(value) ~= [obj.TableSize,1])
                error(['The table has to be of length '...
                    num2str(obj.TableSize)]);
            else
                obj.SpeedBoundsAxis = value;
            end
        end
        
        function set.SpeedBoundsMindBSPL(obj,value)
            % Check that the table entered is of the correct size
            if any(size(value) ~= [obj.TableSize,1])
                error(['The bounds table has to be of length '...
                    num2str(obj.TableSize)]);
            else
                obj.SpeedBoundsMindBSPL = value;
            end
        end
        
        function set.SpeedBoundsMaxdBSPL(obj,value)
            % Check that the table entered is of the correct size
            if any(size(value) ~= [obj.TableSize,1])
                error(['The bounds table has to be of length '...
                    num2str(obj.TableSize)]);
            else
                obj.SpeedBoundsMaxdBSPL = value;
            end
        end
    
        function Validate(obj)           
            if any(obj.SpeedBoundsMindBSPL > obj.SpeedBoundsMaxdBSPL)
                error(['Each entry for max bound must be greater than ' ...
                    'or equal to the min bound.']);
            end
            
            obj.Validate@BtcBaseClass();
        end
    end
end

function mustBe0or1(a)
    % This is a property validation function
    if ((a~=0)&&(a~=1))
        error('Value assigned must be 0 or 1');
    end
end
