---
title: "AddCommonConfig | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "AddCommonConfig"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método AddCommonConfig"
ms.assetid: 16abad93-6dd0-4daa-bf76-91eb6ffbdffa
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# AddCommonConfig
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Adiciona as configurações padrão para o projeto.  
  
## Sintaxe  
  
```  
  
      function AddCommonConfig(   
   oProj,   
   strProjectName    
);  
```  
  
#### Parâmetros  
 `oProj`  
 O projeto selecionado.  
  
 `strProjectName`  
 O nome do projeto.  
  
## Comentários  
 Chame essa função para adicionar as configurações de modelo de código padrão para o projeto de que seu assistente criar.  Você pode especificar uma configuração Release ou uma configuração de depuração.  As tabelas a seguir listam as configurações de propriedade do objeto de modelo de código padrão para cada tipo de configuração.  
  
### Objeto de ferramenta de compilador do Visual C\+\+  
  
|Propriedade do objeto|Definição de configuração de lançamento|Configuração de depuração.|  
|---------------------------|---------------------------------------------|--------------------------------|  
|<xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.UsePrecompiledHeader%2A>|pchUseUsingSpecific|pchUseUsingSpecific|  
|<xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.WarningLevel%2A>|3|3|  
|<xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.MinimalRebuild%2A>|Não aplicável.|verdadeiro|  
|<xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.DebugInformationFormat%2A>|debugEnabled|debugEditAndContinue|  
|<xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.Optimization%2A>|optimizeMaxSpeed|Não aplicável.|  
|<xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.BasicRuntimeChecks%2A>|Não aplicável.|runtimeBasicCheckAll|  
|<xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.Detect64BitPortabilityProblems%2A>|verdadeiro|verdadeiro|  
|<xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.OmitFramePointers%2A>|verdadeiro|Não aplicável.|  
|<xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.EnableFunctionLevelLinking%2A>|verdadeiro|Não aplicável.|  
|<xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.StringPooling%2A>|verdadeiro|Não aplicável.|  
  
### Objeto de configuração do Visual C\+\+  
  
|Propriedade do objeto|Definição de configuração de lançamento|Configuração de depuração.|  
|---------------------------|---------------------------------------------|--------------------------------|  
|<xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.IntermediateDirectory%2A>|"Liberar"|"Debug"|  
|<xref:Microsoft.VisualStudio.VCProjectEngine.VCConfiguration.OutputDirectory%2A>|"Liberar"|"Debug"|  
  
### Objeto de ferramenta do Visual C\+\+ vinculador  
  
|Propriedade do objeto|Definição de configuração de lançamento|Configuração de depuração.|  
|---------------------------|---------------------------------------------|--------------------------------|  
|<xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.SubSystem%2A>|subSystemWindows|subSystemWindows|  
|<xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TargetMachine%2A>|machineX86|machineX86|  
|<xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.GenerateDebugInformation%2A>|verdadeiro|verdadeiro|  
  
## Exemplo  
  
```  
// Create the Visual C++ project.  
selProj = CreateProject(strProjectName, strProjectPath);  
// Add the common configuration to the project.  
   AddCommonConfig(selProj, strProjectName);  
   selProj.Object.keyword = "MyProj";  
```  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Funções JScript para assistentes do C\+\+](../ide/jscript-functions-for-cpp-wizards.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)