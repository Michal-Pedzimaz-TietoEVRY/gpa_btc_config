classdef PropertyEntry < handle
%PROPERTYENTRY Data structure used to adjust a sub-property
%   BtcLockAndDefaultClass uses this class to achieve modifications to
%   component class properties such as updating default values, locking
%   values, and "hiding" properties altogether (from exporting scripts
%   only of course because properties cannot be actually hidden).
    
%   Copyright 2020 Bose Corporation

    properties (SetAccess=immutable)
        % String expression to access property relative containing object
        PropertyPath (1,:) string

        % Copied validation from property's class definition
        % applies to values generated by calculated locks and defaults
        Validation meta.Validation
    end
    properties
        % Indicates whether lock is present
        HasLock logical = false
        % If HasLock, then holds the lock value expression
        LockValue
        % Records which object created the lock
        LockControllingObject BtcLockAndDefaultClass

        % Indicates whether default is present
        HasDefault logical = false
        % If HasDefault, then holds the default value expression
        DefaultValue
        % Records which object created the default
        DefaultControllingObject BtcLockAndDefaultClass

        % Tracks if property value is explictly set, or just filled in by
        % Lock/Default logic. To "Set" a value, something other than
        % a Lock or Default must make the assignment. To clear the flag,
        % set the value to empty [] which will un-set the property
        IsSet logical = false;
    end
    methods
        %------------------------------------------------------------------
        function this = PropertyEntry(propertyPath,propValidation)
            this.PropertyPath = propertyPath;
            this.Validation = propValidation;
        end
        %------------------------------------------------------------------
        function [theValue,isCalculated] = GetLockValue(this)
            [theValue,isCalculated] = this.GetEncodedValue( ...
                this.LockValue, ...
                this.LockControllingObject);
        end
        %------------------------------------------------------------------
        function [theValue,isCalculated] = GetDefaultValue(this)
            [theValue,isCalculated] = this.GetEncodedValue( ...
                this.DefaultValue, ...
                this.DefaultControllingObject);
        end
    end
    methods (Access=protected)
        %------------------------------------------------------------------
        function [theValue,isCalculated] = GetEncodedValue(this,encodedValue,controllingObject)
            switch class(encodedValue)
                case 'meta.property'
                    % meta.property values are from the old LockAsAlias mechanism
                    theValue = controllingObject.(encodedValue.Name);
                    isCalculated = true;
                case 'function_handle'
                    % function_handle values just get called
                    % ... but be helpful and complain if the function handle looks
                    % like something other than "anonymous"
                    funcStr = func2str(encodedValue);
                    if (funcStr(1:2) ~= "@(")
                        warning('BTCBASECLASS:DEPRECATED','Recommend using @() for function handle values instead of %s',funcStr);
                    end
                    theValue = encodedValue();
                    isCalculated = true;
                otherwise
                    % otherwise, the value should be just something "normal"
                    theValue = encodedValue;
                    isCalculated = false;
            end
            % If the property has validation, run it on this value
            if (false == isempty(this.Validation))
                theValue = this.Validation.validateValue(theValue);
            end
        end
    end
end
