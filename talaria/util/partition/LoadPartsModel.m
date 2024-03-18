function LoadPartsModel
% LoadPartsModel performs load_system of provided model looking in parts dir
%    Provide just the model name and LoadPartsModel will prefix with the
%    parts folder full path. 
%  **Note that if the return model handle is accepted, then this method will
%  not return an error if the model is not found- instead it returns model
%  handle -1.
%  Usage:
%     modelHandle = LoadPartsModel(modelName);
%     modelHandle = LoadPartsModel(modelName,alsoLoadModelReferences);
%  modelName: char/string name of model
%  alsoLoadModelReferences: default to false if not supplied. When true,
%  searches through model and recursively loads referenced models.