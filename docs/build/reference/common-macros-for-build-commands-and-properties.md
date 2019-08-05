---
title: Macros comuns para comandos e propriedades do MSBuild
ms.date: 08/02/2019
f1_keywords:
- VC.Project.VCCLCompilerTool.GenerateXMLDocumentationFiles
- VC.Project.VCCLCompilerTool.XMLDocumentationFileName
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
- $(PlatformShortName) macro
- SolutionPath macro $(SolutionPath)
ms.assetid: 239bd708-2ea9-4687-b264-043f1febf98b
ms.openlocfilehash: 0de96306e645ec85562e414a96283923e93a00ad
ms.sourcegitcommit: af4ab63866ed09b5988ed53f1bb6996a54f02484
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/05/2019
ms.locfileid: "68787096"
---
# <a name="common-macros-for-msbuild-commands-and-properties"></a>Macros comuns para comandos e propriedades do MSBuild

Dependendo das opções de instalação, o Visual Studio pode disponibilizar centenas de macros disponíveis para você em um projeto do Visual Studio (baseado no MSBuild). Eles correspondem às propriedades do MSBuild que são definidas por padrão ou nos arquivos. props ou. targets ou nas configurações do projeto. Use essas macros em qualquer lugar na caixa de diálogo **Páginas de Propriedades** de um projeto no qual cadeias de caracteres são aceitas. Essas macros não diferenciam maiúsculas de minúsculas.

## <a name="view-the-current-properties-and-macros"></a>Exibir as macros e as propriedades atuais

Para exibir todas as macros disponíveis no momento, na caixa de diálogo **páginas de propriedades** , em **diretórios do vc + +** , escolha a seta suspensa no final de uma linha de propriedade. Clique em **Editar** e, na caixa de diálogo Editar, escolha o botão macros. O conjunto atual de propriedades e macros visíveis para o Visual Studio é listado junto com o valor atual de cada uma. Para obter mais informações, consulte a seção **especificando valores definidos pelo usuário** na [ C++ referência de página de propriedades do projeto](property-pages-visual-cpp.md).

![Botão de macros do vc + +](../media/vcppdir_libdir_macros.png "Menu") de macros

## <a name="list-of-common-macros"></a>Lista de macros comuns

Esta tabela descreve um subconjunto comumente usado das macros disponíveis; Há muitos outros não listados aqui. Vá para a caixa de diálogo macros para ver todas as propriedades e seus valores atuais em seu projeto. Para obter detalhes sobre como as definições de propriedade do MSBuild são criadas e usadas como macros em arquivos .props, .targets e .vcxproj, confira [Propriedades do MSBuild](/visualstudio/msbuild/msbuild-properties).

|Macro|Descrição|
|-----------|-----------------|
|**$(Configuration)**|O nome da configuração do projeto atual, por exemplo, “Depurar”.|
|**$(DevEnvDir)**|O diretório de instalação do Visual Studio (definido como unidade + caminho); inclui a barra invertida à direita '\\'.|
|**$(FrameworkDir)**|O diretório no qual o .NET Framework foi instalado.|
|**$(FrameworkSDKDir)**|O diretório no qual você instalou o .NET Framework. O .NET Framework pode ter sido instalado como parte do Visual Studio ou separadamente.|
|**$(FrameworkVersion)**|A versão do .NET Framework usada pelo Visual Studio. Combinado com **$(FrameworkDir)** , o caminho completo para a versão do uso do .NET Framework pelo Visual Studio.|
|**$(FxCopDir)**|O caminho para o arquivo fxcop.cmd. O arquivo fxcop. cmd não está instalado com todas as edições do Visual Studio.|
|**$(IntDir)**|Caminho para o diretório especificado para arquivos intermediários. Se for um caminho relativo, os arquivos intermediários vão para esse caminho anexado ao diretório do projeto. Esse caminho deve ter uma barra à direita. Ele resolve para o valor da propriedade de **diretório intermediário** . Não use **$ (OutDir)** para definir essa propriedade.|
|**$(OutDir)**|Caminho para o diretório de arquivo de saída. Se for um caminho relativo, os arquivos de saída vão para esse caminho anexado ao diretório do projeto. Esse caminho deve ter uma barra à direita. Ele resolve para o valor da propriedade diretório de **saída** . Não use **$ (IntDir)** para definir essa propriedade.|
|**$(Platform)**|O nome da plataforma do projeto atual, por exemplo, "Win32".|
|**$(PlatformShortName)**|O nome curto da arquitetura atual, por exemplo, "x86" ou "x64".|
|**$(ProjectDir)**|O diretório do projeto (definido como unidade + caminho); inclui a barra invertida à direita '\\'.|
|**$(ProjectExt)**|A extensão de arquivo do projeto. Inclui o “.” antes da extensão de arquivo.|
|**$(ProjectFileName)**|O nome de arquivo do projeto (definido como nome base + extensão de arquivo).|
|**$(ProjectName)**|O nome de base do projeto.|
|**$(ProjectPath)**|O nome de caminho absoluto do projeto (definido como unidade + caminho + nome base + extensão de arquivo).|
|**$ (PublishDir)**|O local de saída para o destino de publicação; inclui a barra invertida à direita\\' '. O padrão é a pasta **$ (OutDir) app.\\ Publish** .|
|**$(RemoteMachine)**|Definido como o valor da propriedade **Computador Remoto** na página de propriedades de Depuração. Confira [Alterando as configurações do projeto para uma configuração de depuração do C/C++](/visualstudio/debugger/project-settings-for-a-cpp-debug-configuration) para obter mais informações.|
|**$(RootNameSpace)**|O namespace, se houver, que contém o aplicativo.|
|**$(SolutionDir)**|O diretório da solução (definido como unidade + caminho); inclui a barra invertida à direita '\\'. Definido somente durante o build de uma solução no IDE.|
|**$(SolutionExt)**|A extensão de arquivo da solução. Inclui o “.” antes da extensão de arquivo. Definido somente durante o build de uma solução no IDE.|
|**$(SolutionFileName)**|O nome de arquivo da solução (definido como nome base + extensão de arquivo). Definido somente durante o build de uma solução no IDE.|
|**$(SolutionName)**|O nome de base da solução. Definido somente durante o build de uma solução no IDE.|
|**$(SolutionPath)**|O nome de caminho absoluto da solução (definido como unidade + caminho + nome base + extensão de arquivo). Definido somente durante o build de uma solução no IDE.|
|**$(TargetDir)**|O diretório do arquivo de saída primária do build (definido como unidade + caminho); inclui a barra invertida '\\' à direita.|
|**$(TargetExt)**|A extensão de arquivo do arquivo de saída primária para o build. Inclui o “.” antes da extensão de arquivo.|
|**$(TargetFileName)**|O nome do arquivo de saída primária do build (definido como nome base + extensão de arquivo).|
|**$(TargetName)**|O nome base do arquivo de saída primária para o build.|
|**$(TargetPath)**|O nome de caminho absoluto do arquivo de saída primária do build (definido como unidade + caminho + nome base + extensão de arquivo).|
|**$(VCInstallDir)**|O diretório que contém o conteúdo do C++ da instalação do Visual Studio. Essa propriedade contém a versão do conjunto de ferramentas C++ de destino da Microsoft (MSVC), que pode ser diferente do Visual Studio do host. Por exemplo, ao compilar com `$(PlatformToolset) = v140`, **$ (VCInstallDir)** contém o caminho para a instalação do Visual Studio 2015.|
|**$(VSInstallDir)**|O diretório no qual você instalou o Visual Studio. Essa propriedade contém a versão do conjunto de ferramentas do Visual Studio de destino, que pode ser diferente do Visual Studio de host. Por exemplo, ao compilar com `$(PlatformToolset) = v110`, **$(VSInstallDir)** contém o caminho para a instalação do Visual Studio 2012.|
|**$(WebDeployPath)**|O caminho relativo da raiz de implantação da Web ao qual as saídas do projeto pertencem. Retorna o mesmo valor que <xref:Microsoft.VisualStudio.VCProjectEngine.VCWebDeploymentTool.RelativePath%2A>.|
|**$(WebDeployRoot)**|O caminho absoluto para o local de **\<localhost>** . Por exemplo, c:\inetpub\wwwroot.|

## <a name="obsolete-macros"></a>Macros obsoletas

O sistema de build para o C++ foi alterado de maneira significativa entre o Visual Studio 2008 e o Visual Studio 2010. Muitas macros usadas em tipos de projeto anteriores foram alteradas para novas. Essas macros não são mais usadas ou foram substituídas por uma ou mais propriedades ou valores de [macro de metadados de item](/visualstudio/msbuild/itemmetadata-element-msbuild) ( **%(** _name_ **)** ) equivalentes. As macros marcadas como "migradas" podem ser atualizadas pela ferramenta de migração do projeto. Além disso, se o projeto que contém a macro é migrado do Visual Studio 2008 ou anterior para o Visual Studio 2010, o Visual Studio converte a macro na macro atual equivalente. As versões posteriores do Visual Studio não podem converter projetos do Visual Studio 2008 e anterior para o novo tipo de projeto. É necessário converter esses projetos em duas etapas; primeiro convertê-los no Visual Studio 2010 e, em seguida, converter o resultado para a versão mais recente do Visual Studio. Para obter mais informações, consulte [Visão geral de possíveis problemas de atualização](../../porting/overview-of-potential-upgrade-issues-visual-cpp.md).

|Macro|Descrição|
|-----------|-----------------|
|**$(InputDir)**|(Migrado.) O diretório do arquivo de entrada (definido como unidade + caminho); inclui a barra invertida à direita '\\'. Se o projeto é a entrada, essa macro é equivalente a **$(ProjectDir)** .|
|**$(InputExt)**|(Migrado.) A extensão do arquivo de entrada. Inclui o “.” antes da extensão de arquivo. Se o projeto é a entrada, essa macro é equivalente a **$(ProjectExt)** . Para arquivos de origem, isso é **%(Extension)** .|
|**$(InputFileName)**|(Migrado.) O nome do arquivo de entrada (definido como nome base + extensão de arquivo). Se o projeto é a entrada, essa macro é equivalente a **$(ProjectFileName)** . Para arquivos de origem, isso é **%(Identity)** .|
|**$(InputName)**|(Migrado.) O nome base do arquivo de entrada. Se o projeto é a entrada, essa macro é equivalente a **$(ProjectName)** . Para arquivos de origem, isso é **%(Filename)** .|
|**$(InputPath)**|(Migrado.) O nome de caminho absoluto do arquivo de entrada (definido como unidade + caminho + nome base + extensão de arquivo). Se o projeto é a entrada, essa macro é equivalente a **$(ProjectPath)** . Para arquivos de origem, isso é **%(FullPath)** .|
|**$(ParentName)**|Nome do item que contém esse item de projeto. Esse será o nome da pasta pai, ou o nome do projeto.|
|**$(SafeInputName)**|O nome do arquivo como um nome de classe válido, menos a extensão de arquivo. Essa propriedade não tem uma equivalência exata.|
|**$(SafeParentName)**|O nome do pai imediato em um formato de nome válido. Por exemplo, um formulário é o pai de um arquivo .resx. Essa propriedade não tem uma equivalência exata.|
|**$(SafeRootNamespace)**|O nome do namespace no qual os assistentes de projeto adicionarão o código. Esse nome de namespace conterá somente os caracteres permitidos em um identificador válido do C++. Essa propriedade não tem uma equivalência exata.|

## <a name="see-also"></a>Consulte também

[Projetos do Visual Studio-C++](../creating-and-managing-visual-cpp-projects.md)\
[Guia C++ de atualização e portabilidade do Visual](../../porting/visual-cpp-porting-and-upgrading-guide.md)\
[Visão geral de possíveis problemas de atualização](../../porting/overview-of-potential-upgrade-issues-visual-cpp.md)
