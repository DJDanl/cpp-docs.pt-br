---
title: Macros comuns para comandos e propriedades de build | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- VC.Project.VCCLCompilerTool.GenerateXMLDocumentationFiles
- VC.Project.VCCLCompilerTool.XMLDocumentationFileName
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9b94347e48a7b8b134915456c92aea3397f97a1b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33339625"
---
# <a name="common-macros-for-build-commands-and-properties"></a>Macros comuns para comandos e propriedades de build
Dependendo das opções de instalação, o Visual Studio pode disponibilizar centenas de macros para você. Elas correspondem às propriedades do MSBuild definidas por padrão, em arquivos .props ou .targets ou nas configurações de projeto. Use essas macros em qualquer lugar na caixa de diálogo **Páginas de Propriedades** de um projeto no qual cadeias de caracteres são aceitas. Essas macros não diferenciam maiúsculas de minúsculas.  
  
 Para exibir as macros atualmente disponíveis, na coluna à direita de um nome de propriedade, clique na seta suspensa. Se a opção **Editar** estiver disponível, clique nela e, em seguida, na caixa de diálogo de edição, clique em **Macros**. Para obter mais informações, confira a seção **Especificando valores definidos pelo usuário** de [Páginas de Propriedades](../ide/property-pages-visual-cpp.md).  
  
 As macros que são marcadas como "Preteridas" não são mais usadas ou foram substituídas por uma [macro de metadados de item](/visualstudio/msbuild/itemmetadata-element-msbuild) equivalente (**%(***name***)**). As macros que são marcadas como "Preteridas; migradas" também foram preteridas. Além disso, se o projeto que contém a macro é migrado do Visual Studio 2008, o Visual Studio converte a macro na macro atual equivalente.  
  
 A tabela a seguir descreve um subconjunto geralmente usado das macros disponíveis. Essa lista não é completa. Para obter detalhes sobre como as definições de propriedade do MSBuild são criadas e usadas como macros em arquivos .props, .targets e .vcxproj, confira [Propriedades do MSBuild](/visualstudio/msbuild/msbuild-properties).  
  
|Macro|Descrição|  
|-----------|-----------------|  
|**$(RemoteMachine)**|Definido como o valor da propriedade **Computador Remoto** na página de propriedades de Depuração. Confira [Alterando as configurações do projeto para uma configuração de depuração do C/C++](/visualstudio/debugger/project-settings-for-a-cpp-debug-configuration) para obter mais informações.|  
|**$(Configuration)**|O nome da configuração do projeto atual, por exemplo, “Depurar”.|  
|**$(Platform)**|O nome da plataforma do projeto atual, por exemplo, "Win32".|  
|**$(ParentName)**|(Preterido.) Nome do item que contém esse item de projeto. Esse será o nome da pasta pai, ou o nome do projeto.|  
|**$(RootNameSpace)**|O namespace, se houver, que contém o aplicativo.|  
|**$(IntDir)**|Caminho para o diretório especificado para arquivos intermediários. Se esse for um caminho relativo, os arquivos intermediários acessarão esse caminho acrescentado ao diretório do projeto. Esse caminho deve ter uma barra à direita. Isso é resolvido para o valor da propriedade **Diretório Intermediário**. Não use **$(OutDir)** para definir essa propriedade.|  
|**$(OutDir)**|Caminho para o diretório de arquivo de saída. Se esse for um caminho relativo, os arquivos de saída acessarão esse caminho acrescentado ao diretório do projeto. Esse caminho deve ter uma barra à direita. Isso é resolvido para o valor da propriedade **Diretório de Saída**. Não use **$(IntDir)** para definir essa propriedade.|  
|**$(DevEnvDir)**|O diretório de instalação do Visual Studio (definido como unidade + caminho); inclui a barra invertida à direita '\\'.|  
|**$(InputDir)**|(Preterido; migrado.) O diretório do arquivo de entrada (definido como unidade + caminho); inclui a barra invertida à direita '\\'. Se o projeto é a entrada, essa macro é equivalente a **$(ProjectDir)**.|  
|**$(InputPath)**|(Preterido; migrado.) O nome de caminho absoluto do arquivo de entrada (definido como unidade + caminho + nome base + extensão de arquivo). Se o projeto é a entrada, essa macro é equivalente a **$(ProjectPath)**.|  
|**$(InputName)**|(Preterido; migrado.) O nome base do arquivo de entrada. Se o projeto é a entrada, essa macro é equivalente a **$(ProjectName)**.|  
|**$(InputFileName)**|(Preterido; migrado.) O nome do arquivo de entrada (definido como nome base + extensão de arquivo). Se o projeto é a entrada, essa macro é equivalente a **$(ProjectFileName)**.|  
|**$(InputExt)**|(Preterido; migrado.) A extensão do arquivo de entrada. Inclui o “.” antes da extensão de arquivo. Se o projeto é a entrada, essa macro é equivalente a **$(ProjectExt)**.|  
|**$(ProjectDir)**|O diretório do projeto (definido como unidade + caminho); inclui a barra invertida à direita '\\'.|  
|**$(ProjectPath)**|O nome de caminho absoluto do projeto (definido como unidade + caminho + nome base + extensão de arquivo).|  
|**$(ProjectName)**|O nome de base do projeto.|  
|**$(ProjectFileName)**|O nome de arquivo do projeto (definido como nome base + extensão de arquivo).|  
|**$(ProjectExt)**|A extensão de arquivo do projeto. Inclui o “.” antes da extensão de arquivo.|  
|**$(SolutionDir)**|O diretório da solução (definido como unidade + caminho); inclui a barra invertida à direita '\\'. Definido somente durante o build de uma solução no IDE.|  
|**$(SolutionPath)**|O nome de caminho absoluto da solução (definido como unidade + caminho + nome base + extensão de arquivo). Definido somente durante o build de uma solução no IDE.|  
|**$(SolutionName)**|O nome de base da solução. Definido somente durante o build de uma solução no IDE.|  
|**$(SolutionFileName)**|O nome de arquivo da solução (definido como nome base + extensão de arquivo). Definido somente durante o build de uma solução no IDE.|  
|**$(SolutionExt)**|A extensão de arquivo da solução. Inclui o “.” antes da extensão de arquivo. Definido somente durante o build de uma solução no IDE.|  
|**$(TargetDir)**|O diretório do arquivo de saída primária do build (definido como unidade + caminho); inclui a barra invertida '\\' à direita.|  
|**$(TargetPath)**|O nome de caminho absoluto do arquivo de saída primária do build (definido como unidade + caminho + nome base + extensão de arquivo).|  
|**$(TargetName)**|O nome base do arquivo de saída primária para o build.|  
|**$(TargetFileName)**|O nome do arquivo de saída primária do build (definido como nome base + extensão de arquivo).|  
|**$(TargetExt)**|A extensão de arquivo do arquivo de saída primária para o build. Inclui o “.” antes da extensão de arquivo.|  
|**$(VSInstallDir)**|O diretório no qual você instalou o Visual Studio.<br /><br /> Essa propriedade contém a versão do Visual Studio de destino, que pode ser diferente do host do Visual Studio. Por exemplo, ao compilar com `$(PlatformToolset) = v110`, **$(VSInstallDir)** contém o caminho para a instalação do Visual Studio 2012.|  
|**$(VCInstallDir)**|O diretório no qual você instalou o Visual C++.<br /><br /> Essa propriedade contém a versão do Visual C++ de destino, que pode ser diferente do host do Visual Studio. Por exemplo, ao compilar com `$(PlatformToolset) = v140`, **$(VCInstallDir)** contém o caminho para a instalação do Visual C++ 2015.|  
|**$(FrameworkDir)**|O diretório no qual o .NET Framework foi instalado.|  
|**$(FrameworkVersion)**|A versão do .NET Framework usada pelo Visual Studio. Combinado com **$(FrameworkDir)**, o caminho completo para a versão do uso do .NET Framework pelo Visual Studio.|  
|**$(FrameworkSDKDir)**|O diretório no qual você instalou o .NET Framework. O .NET Framework pode ter sido instalado como parte do Visual Studio ou separadamente.|  
|**$(WebDeployPath)**|O caminho relativo da raiz de implantação da Web ao qual as saídas do projeto pertencem. Retorna o mesmo valor que <xref:Microsoft.VisualStudio.VCProjectEngine.VCWebDeploymentTool.RelativePath%2A>.|  
|**$(WebDeployRoot)**|O caminho absoluto para o local de **\<localhost>**. Por exemplo, c:\inetpub\wwwroot.|  
|**$(SafeParentName)**|(Preterido.) O nome do pai imediato em um formato de nome válido. Por exemplo, um formulário é o pai de um arquivo .resx.|  
|**$(SafeInputName)**|(Preterido.) O nome do arquivo como um nome de classe válido, menos a extensão de arquivo.|  
|**$(SafeRootNamespace)**|(Preterido.) O nome do namespace no qual os assistentes de projeto adicionarão o código. Esse nome de namespace conterá somente os caracteres permitidos em um identificador válido do C++.|  
|**$(FxCopDir)**|O caminho para o arquivo fxcop.cmd. O arquivo fxcop.cmd não está instalado em todas as edições do Visual C++.|  
  
## <a name="see-also"></a>Consulte também  
 [Compilando projetos do C++ no Visual Studio](../ide/building-cpp-projects-in-visual-studio.md)