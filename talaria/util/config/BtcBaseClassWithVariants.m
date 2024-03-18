classdef BtcBaseClassWithVariants < BtcBaseClass
% BtcBaseClassWithVariants Base class for build-time classes that include
% variants. This class requires the constructor to specify the name of the
% enumeration classdef that lists all supported variants. The enumeration
% classdef must itself derive from BtcVariantEnum. With everything properly
% configured, BtcBaseClassWithVariants introduces two new properties:
%   Variant : A property to control which type of variant is present
%   VariantObj : A component property of the appropriate class for the
%      selected variant, discovered via the enumeration.
% Usage:
%    classdef MyBlockConfig < BtcBaseClassWithVariants
%      methods
%        function this = MyBlockConfig()
%           this@BtcBassClassWithVariants(NameOfVariantEnumClass)
%        end
%      end
%    end

%   Copyright 2022 Bose Corporation

properties (Dependent)
    Variant % this propery's classname is specified in our constructor
end
properties (SetAccess=private)
    VariantObj BtcVariant % this property is allocated based on the value of the Variant property above
end
properties (Hidden,SetAccess=immutable)
    VariantEnumClassName string % set by constructor, this names the class of the Variant property above
end
methods
    function this = BtcBaseClassWithVariants(variantEnumClassName,initialVariant)
        % Constructor requires name of the enumerated class used to specify
        % the type of VariantProps component. Optionally, also specify the
        % default variant with which to start. If none specified, the first
        % member of the enumeration will serve as the default.

        % Give helpful error message if a derived class is not properly
        % specifying it's enumerated class in its constructor
        if (nargin < 1)
            exampleName = regexprep(class(this),'Config$','');
            exampleName = [exampleName 'VariantEnum'];
            error(['The %s constructor must pass the name of the enumerated ' ...
                'class e.g. this@BtcBaseClassWithVariants(''%s'');'], ...
                class(this),exampleName);
        end

        % Remember the associated enumerated class
        this.VariantEnumClassName = variantEnumClassName;

        % Set the variant immediately to allocate the VariantObj
        if (nargin < 2)
            % Default to first enumerated element if none specified.
            initialVariant = feval(this.VariantEnumClassName,1);
        end
        this.Variant = initialVariant;
    end
    function value = get.Variant(this)
        % The selected variant is stored in the instance of the Variant
        % class:
        value = this.VariantObj.EnumValue;
    end
    function theMatch = SelectVariant(this,varargin)
        % SelectVariant chooses a variant from prioritized name fragments.
        % Specify one or more char-vector arguments that each represent a
        % partial match of the desired variant name. The specified order 
        % of these name fragments is critical as each one narrows down the
        % remaining choices for the next fragment to match against. If at
        % any point a name fragment results in zero remaining matches, the
        % fragment is ignored. The returned match has the lowest integer
        % equivalent among those choices remaining. In other words, if no
        % matches are ever made, the lowest value option gets selected,
        % which is usually the "Generic" variant. All string comparisons
        % are case insensitive.
        % Usage:
        %    theMatch = TheObject.SelectVariant('sharc','accel');
        %    i.e. Find a SHARC variant with accelerator if possible
        %
        %    qualities = {'sharc','core','gul'};
        %    theMatch = TheObject.SelectVariant(qualities{:});
        %    i.e. passes in the name fragments via a cell array
        %
        %    badMatch = TheObject.SelectVariant('accel','hexagon')
        %    i.e the order of these fragments is likely *BAD* and might
        %    return a SHARC variant that likely would not work with a
        %    SnapDragon processor!

        % Retrieve a list of all enumeration element names sorted by their
        % integer equivalents.
        allOptions = enumeration(this.VariantEnumClassName);
        sortedOptions = sort(allOptions);
        allStrings = string(sortedOptions);

        % Be super flexible and allow people to use String objects instead
        % of char vectors:
        inputFragments = cellfun(@char,varargin,'UniformOutput',false);

        % Case insensitive: To perform case-insensitive matches, make
        % everything lower case
        fragments = lower(inputFragments);
        allStrings = lower(allStrings);

        % Loop through each fragment specified, narrowing down the choices.
        % To start off, all options have a chance to match
        active = true(numel(allStrings),1);
        numFragments = numel(fragments);
        for i=1:numFragments
            aFragment = fragments{i};
            % Among the active strings, search for partial matches
            thisMatch = contains(allStrings,aFragment);
            stillActive = active & thisMatch;
            if any(stillActive)
                % Something still matches, so narrow down the active
                % choices to those that are still matching
                active = stillActive;
            else
                % Nothing matched after this fragment, so ignore it and
                % leave the currently active choices in place
            end
        end
        % Choose the first remaining option, which will be the lowest #
        theMatch = sortedOptions(find(active,1));
        % ... and set the selected variant
        this.Variant = theMatch;
    end
    function set.Variant(this,value)
        % Ensure/convert value to the supported enumeration type
        enumValue = feval(this.VariantEnumClassName,value);

        % Retrieve the associated classname from this variant enumeration
        intValue = int32(enumValue);
        requiredClassName = BtcVariantEnum.ClassNameCache( ...
            this.VariantEnumClassName, intValue);

        % Ensure the VariantProps property is of the correct type
        currentClass = class(this.VariantObj);
        if (false == isequal(currentClass,requiredClassName) || ...
                isempty(this.VariantObj))
            % The correct class is not in place! Clobber whatever is there
            % and replace with the correct class
            if (false == isempty(this.VariantObj))
                fprintf('replacing class [%s] with [%s]\n',currentClass,requiredClassName);
            end
            oldObj = this.VariantObj;
            % Construct the BtcVariant object, passing in this as parent so
            % the variant could perform lock/default operations.
            this.VariantObj = feval(requiredClassName,this);
            % Attempt to transfer properties from old variant to this one
            if (false == isempty(oldObj))
                this.VariantObj.CopyOldProperties(oldObj);
            end
        end
        % Regardless of whether the class changed, the enumeration might
        % have changed:
        this.VariantObj.EnumValue = enumValue;
    end
    %----------------------------------------------------------------------
    function Validate(this)
        % Validate also invokes active variant's validation before finally
        % calling the BtcBaseClass
        this.VariantObj.VariantValidate();
        Validate@BtcBaseClass(this);
    end
    %----------------------------------------------------------------------
    function DoMaskInit(this,blockHandle)
        % DoMaskInit is where BTC classes can perform automation of code
        % generation settings (e.g. CscUtil) or otherwise interact with the
        % Simulink canvas. Avoid making design-time changes if possible
        % (e.g. avoid calling: set_param, add_block, replace_block). 
        % The expected callstack arriving at this function starts with a
        % block's mask initialization code automated by BTConfig.

        % Invoke mask initialization for the currently selected variant
        this.VariantObj.VariantDoMaskInit(blockHandle);

        % ... and for our own base class
        DoMaskInit@BtcBaseClass(this,blockHandle);
    end

end
end
