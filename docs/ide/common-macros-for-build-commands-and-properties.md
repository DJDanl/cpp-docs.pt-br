---
title: Macros comuns para compilar comandos e propriedades | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- VC.Project.VCCLCompilerTool.GenerateXMLDocumentationFiles
- VC.Project.VCCLCompilerTool.XMLDocumentationFileName
dev_langs: C++
helpviewer_keywords:
- $(FrameworkSDKDir) macro
- ProjectName macro $(ProjectName)
- DevEnvDir macro $(DevEnvDir)
- $(DevEnvDir) macro
- TargetPath macro $(TargetPath)
- VSInstallDir macro $(VSInstallDir)
- $(InputFileName) macro
- $(SolutionFileName) macro
- macros [C++], build macros
- InputFileName macro $(InputFileName)
- $(VCInstallDir) macro
- $(IntDir) macro
- $(ConfigurationName) macro
- SolutionDir macro $(SolutionDir)
- $(TargetPath) macro
- $(Inherit) macro
- $(SolutionPath) macro
- WebDeployRoot macro $(WebDeployRoot)
- WebDeployPath macro $(WebDeployPath)
- StopEvaluating macro $(StopEvaluating)
- $(RootNamespace) macro
- $(WebDeployRoot) macro
- ProjectPath macro $(ProjectPath)
- $(ProjectPath) macro
- $(InputDir) macro
- SolutionName macro $(SolutionName)
- ProjectExt macro $(ProjectExt)
- $(TargetExt) macro
- $(ProjectFileName) macro
- TargetName macro $(TargetName)
- $(References) macro
- References macro $(References)
- TargetExt macro $(TargetExt)
- ProjectDir macro $(ProjectDir)
- $(TargetDir) macro
- SolutionExt macro $(SolutionExt)
- $(SolutionDir) macro
- ProjectFileName macro $(ProjectFileName)
- VCInstallDir macro $(VCInstallDir)
- $(InputExt) macro
- $(TargetFileName) macro
- $(SolutionExt) macro
- PlatformName macro $(PlatformName)
- IntDir macro $(IntDir)
- $(FrameworkVersion) macro
- $(ProjectDir) macro
- build macros [C++]
- InputPath macro $(InputPath)
- $(VSInstallDir) macro
- $(WebDeployPath) macro
- TargetFileName macro $(TargetFileName)
- NoInherit macro $(NoInherit)
- ConfigurationName macro $(ConfigurationName)
- $(ProjectExt) macro
- TargetDir macro $(TargetDir)
- InputName macro $(InputName)
- $(ProjectName) macro
- FrameworkSDKDir macro $(FrameworkSDKDir)
- $(ParentName) macro
- InputExt macro $(InputExt)
- $(SafeRootNamespace) macro
- InputDir macro $(InputDir)
- $(FxCopDir) macro
- $(RemoteMachine) macro
- Inherit macro $(Inherit)
- FrameworkVersion macro $(FrameworkVersion)
- $(StopEvaluating) macro
- $(OutDir) macro
- FrameworkDir macro $(FrameworkDir)
- SolutionFileName macro $(SolutionFileName)
- $(NoInherit) macro
- RemoteMachine macro $(RemoteMachine)
- properties [C++], build property macros
- $(TargetName) macro
- $(SolutionName) macro
- $(InputPath) macro
- ParentName macro $(ParentName)
- OutDir macro $(OutDir)
- SafeRootNamespace macro $(SafeRootNamespace)
- FxCopDir macro $(FxCopDir)
- $(InputName) macro
- RootNamespace macro $(RootNamespace)
- builds [C++], macros
- $(FrameworkDir) macro
- $(PlatformName) macro
- SolutionPath macro $(SolutionPath)
ms.assetid: 239bd708-2ea9-4687-b264-043f1febf98b
caps.latest.revision: "22"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f96e403516d6f85804fa798d7a0c28575482ff43
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="common-macros-for-build-commands-and-properties"></a>Macros comuns para compilar comandos e propriedades
Dependendo de suas opções de instalação, o Visual Studio pode tornar centenas de macros disponíveis para você. Elas correspondem às propriedades de MSBuild são definidas por padrão, ou em arquivos de .props ou. targets ou em suas configurações de projeto. Você pode usar essas macros em qualquer lugar em um projeto **páginas de propriedade** caixa de diálogo onde as cadeias de caracteres são aceitas. Essas macros não diferenciam maiusculas de minúsculas.  
  
 Para exibir as macros disponíveis no momento, na coluna à direita de um nome de propriedade, clique na seta suspensa. Se **editar** estiver disponível, clique nele e, em seguida, na caixa de diálogo de edição, clique em **Macros**. Para obter mais informações, consulte o **Specifying User-Defined valores** seção [páginas de propriedade](../ide/property-pages-visual-cpp.md).  
  
 Macros que são marcados como "Obsoleto" não são mais usadas ou foram substituídas por um equivalente [macro de metadados de item](/visualstudio/msbuild/itemmetadata-element-msbuild) (**%(***nome***)**) . Macros que são marcados como "substituído; migrado"também foram preterido. E, além disso, se o projeto que contém a macro for migrado do Visual Studio 2008, o Visual Studio converte a macro da macro atual equivalente.  
  
 A tabela a seguir descreve um subconjunto usado de macros disponíveis. Esta lista não é exaustiva. Para obter detalhes sobre como as definições de propriedade de MSBuild são criadas e usadas como macros .props. targets e arquivos. vcxproj, consulte [propriedades MSBuild](/visualstudio/msbuild/msbuild-properties).  
  
|Macro|Descrição|  
|-----------|-----------------|  
|**$ (RemoteMachine)**|Definido como o valor da **máquina remota** propriedade na página de propriedade de depuração. Consulte [alterando configurações do projeto para uma configuração de depuração do C/C++](/visualstudio/debugger/project-settings-for-a-cpp-debug-configuration) para obter mais informações.|  
|**$(Configuration)**|O nome da configuração do projeto atual, por exemplo, “Depurar”.|  
|**$(Platform)**|O nome da plataforma atual do projeto, por exemplo, "Win32".|  
|**$ (ParentName)**|(Preterido). Nome do item que contém esse item de projeto. Esse será o nome da pasta pai ou o nome do projeto.|  
|**$ (RootNamespace)**|O namespace, se houver, que contém o aplicativo.|  
|**$ (IntDir)**|Caminho para o diretório especificado para arquivos intermediários. Se esse for um caminho relativo, arquivos intermediários acessem esse caminho ao diretório do projeto. Esse caminho deve ter uma barra à direita. Isso resolve para o valor para o **diretório intermediário** propriedade. Não use **$ (OutDir)** para definir essa propriedade.|  
|**$ (OutDir)**|Caminho para o diretório de arquivo de saída. Se esse for um caminho relativo, arquivos de saída acessem esse caminho ao diretório do projeto. Esse caminho deve ter uma barra à direita. Isso resolve para o valor para o **diretório de saída** propriedade. Não use **$ (IntDir)** para definir essa propriedade.|  
|**$ (Devenvdir)**|O diretório de instalação do Visual Studio (definido como unidade + caminho); inclui a barra invertida '\\'.|  
|**$ (Inputdir)**|(Preterido; migrados). O diretório do arquivo de entrada (definido como unidade + caminho); inclui a barra invertida '\\'. Se o projeto é a entrada, essa macro é equivalente a **projectdir**.|  
|**$ (InputPath)**|(Preterido; migrados). O nome de caminho absoluto do arquivo de entrada (definido como unidade + caminho + nome de base + extensão de arquivo). Se o projeto é a entrada, essa macro é equivalente a **ProjectPath**.|  
|**$ (InputName)**|(Preterido; migrados). O nome base do arquivo de entrada. Se o projeto é a entrada, essa macro é equivalente a **ProjectName**.|  
|**$ (Inputfilename)**|(Preterido; migrados). O nome do arquivo do arquivo de entrada (definido como o nome de base + a extensão de arquivo). Se o projeto é a entrada, essa macro é equivalente a **ProjectFileName**.|  
|**$ (Inputext)**|(Preterido; migrados). A extensão de arquivo do arquivo de entrada. Inclui o “.” antes da extensão de arquivo. Se o projeto é a entrada, essa macro é equivalente a **projectext**.|  
|**$ (Projectdir)**|O diretório do projeto (definido como unidade + caminho); inclui a barra invertida '\\'.|  
|**$ (ProjectPath)**|O nome de caminho absoluto do projeto (definido como unidade + caminho + nome de base + extensão de arquivo).|  
|**$ (ProjectName)**|O nome de base do projeto.|  
|**$ (ProjectFileName)**|O nome do arquivo do projeto (definido como o nome de base + a extensão de arquivo).|  
|**$ (Projectext)**|A extensão de arquivo do projeto. Inclui o “.” antes da extensão de arquivo.|  
|**$ (Solutiondir)**|O diretório da solução (definido como unidade + caminho); inclui a barra invertida '\\'. Definido somente quando a criação de uma solução no IDE.|  
|**$ (SolutionPath)**|O nome de caminho absoluto da solução (definido como unidade + caminho + nome de base + extensão de arquivo). Definido somente quando a criação de uma solução no IDE.|  
|**$ (Solutionname)**|O nome de base da solução. Definido somente quando a criação de uma solução no IDE.|  
|**$ (Solutionfilename)**|O nome do arquivo da solução (definido como o nome de base + a extensão de arquivo). Definido somente quando a criação de uma solução no IDE.|  
|**$ (Solutionext)**|A extensão de arquivo da solução. Inclui o “.” antes da extensão de arquivo. Definido somente quando a criação de uma solução no IDE.|  
|**$ (TARGETDIR)**|O diretório do arquivo de saída primária da compilação (definido como unidade + caminho); inclui a barra invertida '\\'.|  
|**$ (TargetPath)**|O nome de caminho absoluto do arquivo de saída primária da compilação (definido como unidade + caminho + nome de base + extensão de arquivo).|  
|**$ (TargetName)**|O nome base do arquivo de saída primária para o build.|  
|**$ (TargetFileName)**|O nome do arquivo do arquivo de saída primária da compilação (definido como o nome de base + a extensão de arquivo).|  
|**$ (TargetExt)**|A extensão de arquivo do arquivo de saída primária para o build. Inclui o “.” antes da extensão de arquivo.|  
|**$ (Vsinstalldir)**|O diretório em que você instalou o Visual Studio.<br /><br /> Esta propriedade contém a versão de destino Visual Studio, que pode ser diferente que o host do Visual Studio. Por exemplo, ao compilar com `$(PlatformToolset) = v110`, **vsinstalldir** contém o caminho para a instalação do Visual Studio 2012.|  
|**$ (Vcinstalldir)**|O diretório em que você instalou o Visual C++.<br /><br /> Esta propriedade contém a versão de destino Visual C++, que pode ser diferente que o host do Visual Studio. Por exemplo, ao compilar com `$(PlatformToolset) = v140`, **vcinstalldir** contém o caminho para a instalação do Visual C++ 2015.|  
|**$ (Frameworkdir)**|O diretório em que o .NET Framework foi instalado.|  
|**$ (FrameworkVersion)**|A versão do .NET Framework usado pelo Visual Studio. Combinado com **frameworkdir**, o caminho completo para a versão do uso do .NET Framework pelo Visual Studio.|  
|**$ (Frameworksdkdir)**|O diretório em que você instalou o .NET Framework. O .NET Framework pode ter sido instalado como parte do Visual Studio ou separadamente.|  
|**$ (Webdeploypath)**|O caminho relativo da raiz de implantação da web para onde o projeto gera pertence. Retorna o mesmo valor que <xref:Microsoft.VisualStudio.VCProjectEngine.VCWebDeploymentTool.RelativePath%2A>.|  
|**$ (Webdeployroot)**|O caminho absoluto para o local do  **\<localhost >**. Por exemplo, c:\inetpub\wwwroot.|  
|**$(SafeParentName)**|(Preterido). O nome do pai imediato no formato de nome válido. Por exemplo, um formulário é o pai de um arquivo. resx.|  
|**$(SafeInputName)**|(Preterido). O nome do arquivo como um nome de classe válido, menos a extensão de arquivo.|  
|**$ (Saferootnamespace)**|(Preterido). O nome do namespace no qual os assistentes de projeto irá adicionar o código. Esse nome de namespace conterá somente os caracteres que seriam permitidos em um identificador válido do C++.|  
|**$ (Fxcopdir)**|O caminho para o arquivo fxcop.cmd. O arquivo fxcop.cmd não está instalado em todas as edições do Visual C++.|  
  
## <a name="see-also"></a>Consulte também  
 [Compilando projetos do C++ no Visual Studio](../ide/building-cpp-projects-in-visual-studio.md)