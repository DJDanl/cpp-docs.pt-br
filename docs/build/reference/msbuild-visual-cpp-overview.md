---
title: Recursos internos do MSBuild para projetos C++ no Visual Studio
ms.date: 05/16/2019
helpviewer_keywords:
- MSBuild overview
ms.assetid: dd258f6f-ab51-48d9-b274-f7ba911d05ca
ms.openlocfilehash: b3348320a1468fea03f39e43cc847f1085f3d319
ms.sourcegitcommit: a10c9390413978d36b8096b684d5ed4cf1553bc8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/17/2019
ms.locfileid: "65837227"
---
# <a name="msbuild-internals-for-c-projects"></a>Recursos internos do MSBuild para projetos C++

Quando você define as propriedades do projeto no IDE e, em seguida, salva o projeto, o Visual Studio grava as configurações do projeto no arquivo de projeto. O arquivo de projeto contém configurações que são exclusivas ao projeto, mas não contém todas as configurações necessárias para compilar o projeto. O arquivo de projeto contém elementos `Import` que incluem uma rede de *arquivos de suporte* adicionais. Os arquivos de suporte contêm as propriedades, os destinos e as configurações restantes necessárias para compilar o projeto.

A maioria dos destinos e das propriedades nos arquivos de suporte existe somente para implementar o sistema de build. A seção a seguir aborda algumas propriedades e alguns destinos úteis que podem ser especificados na linha de comando do MSBuild. Para descobrir mais destinos e propriedades, explore os arquivos nos diretórios de arquivos de suporte.

## <a name="support-file-directories"></a>Diretórios de arquivos de suporte

Por padrão, os arquivos de suporte principais do Visual Studio estão localizados nos diretórios a seguir. Os diretórios do Microsoft Visual Studio são usados pelo Visual Studio 2017 e por versões posteriores, enquanto os diretórios do MSBuild são usados pelo Visual Studio 2015 e por versões anteriores.

|Diretório|Descrição|
|---------------|-----------------|
|*unidade*:\Arquivos de Programas *(x86)* \Microsoft Visual Studio\\*ano*\\*edição*\Common7\IDE\VC\VCTargets\ <br /><br />*unidade*:\Arquivos de Programas *(x86)* \MSBuild\Microsoft.Cpp (x86)\v4.0\\*versão*\ |Contém os arquivos de destino (.targets) e os arquivos de propriedade (.props) principais que são usados pelos destinos. Por padrão, a macro $(VCTargetsPath) referencia esse diretório.|
|*unidade*:\Arquivos de Programas *(x86)* \Microsoft Visual Studio\\*ano*\\*edição*\Common7\IDE\VC\VCTargets\Platforms\\*plataforma*\ <br /><br />*unidade*:\Arquivos de Programas *(x86)* \MSBuild\Microsoft.Cpp\v4.0\\*versão*\Platforms\\*plataforma*\ |Contém os arquivos de destino e de propriedade específicos da plataforma que substituem os destinos e as propriedades no diretório pai. Esse diretório também contém uma DLL que define as tarefas que são usadas pelos destinos nesse diretório.<br /><br /> O espaço reservado *plataforma* representa o subdiretório do ARM, do Win32 ou do x64.|
|*unidade*:\Arquivos de Programas *(x86)* \Microsoft Visual Studio\\*ano*\\*edição*\Common7\IDE\VC\VCTargets\Platforms\\*plataforma*\PlatformToolsets\\*conjunto de ferramentas*\ <br /><br />*unidade*:\Arquivos de Programas *(x86)* \MSBuild\Microsoft.Cpp\v4.0\\*versão*\Platforms\\*plataforma*\PlatformToolsets\\*conjunto de ferramentas*\ <br /><br />*unidade*:\Arquivos de Programas *(x86)* \MSBuild\Microsoft.Cpp\v4.0\Platforms\\*plataforma*\PlatformToolsets\\*conjunto de ferramentas*\ |Contém os diretórios que permitem que o build gere aplicativos C++ usando o *conjunto de ferramentas* especificado.<br /><br /> Os espaços reservados *ano* e *edição* são usados pelo Visual Studio 2017 e por edições posteriores. O espaço reservado *versão* é V110 para Visual Studio 2012, V120 para Visual Studio 2013, V140 para Visual Studio 2015, v141 para Visual Studio 2017 e v142 para Visual Studio 2019. O espaço reservado *plataforma* representa o subdiretório do ARM, do Win32 ou do x64. O espaço reservado *conjunto de ferramentas* representa o subdiretório do conjunto de ferramentas, por exemplo, v140 para compilação de aplicativos do Windows usando o Conjunto de ferramentas do Visual Studio 2015, v120_xp para compilação para o Windows XP usando o Conjunto de ferramentas do Visual Studio 2013.<br /><br />O caminho que contém os diretórios que permitem que o build gere aplicativos do Visual Studio 2008 ou do Visual Studio 2010 não inclui a *versão*, e o espaço reservado *plataforma* representa o subdiretório do Itanium, do Win32 ou do x64. O espaço reservado *conjunto de ferramentas* representa o subdiretório do conjunto de ferramentas v90 ou v100.|

## <a name="support-files"></a>Arquivos de suporte

Os diretórios dos arquivos de suporte contêm arquivos com estas extensões:

|Extensão|Descrição|
|---------------|-----------------|
|.targets|Contém elementos XML `Target` que especificam as tarefas que são executadas pelo destino. Também pode conter elementos `PropertyGroup`, `ItemGroup`, `ItemDefinitionGroup` e `Item` definidos pelo usuário que são usados para atribuir arquivos e opções de linha de comando a parâmetros de tarefa.<br /><br /> Para obter mais informações, confira [Elemento Target (MSBuild)](/visualstudio/msbuild/target-element-msbuild).|
|.props|Contém elementos XML `Property Group` e `Property` definidos pelo usuário que especificam as configurações de arquivo e parâmetro usadas durante um build.<br /><br /> Também pode conter elementos XML `ItemDefinitionGroup` e `Item` definidos pelo usuário que especificam configurações adicionais. Os itens definidos em um grupo de definições de itens são semelhantes a propriedades, mas não podem ser acessados na linha de comando. Os arquivos de projeto do Visual Studio frequentemente usam itens em vez de propriedades para representar configurações.<br /><br /> Para obter mais informações, confira [Elemento ItemGroup (MSBuild)](/visualstudio/msbuild/itemgroup-element-msbuild), 
[Elemento ItemDefinitionGroup (MSBuild)](/visualstudio/msbuild/itemdefinitiongroup-element-msbuild) e [Elemento Item (MSBuild)](/visualstudio/msbuild/item-element-msbuild).|
|.xml|Contém elementos XML que declaram e inicializam elementos de interface do usuário do IDE, como folhas de propriedades e páginas de propriedades, e controles de caixa de listagem e caixa de texto.<br /><br /> Os arquivos .xml dão suporte direto ao IDE, não ao MSBuild. No entanto, os valores das propriedades do IDE são atribuídos para compilar propriedades e itens.<br /><br /> A maioria dos arquivos .xml está localizada em um subdiretório específico da localidade. Por exemplo, os arquivos para a região Inglês – EUA estão em $(VCTargetsPath)\1033\\.|

## <a name="user-targets-and-properties"></a>Propriedades e destinos de usuário

Para usar o MSBuild mais efetivamente na linha de comando, é útil saber quais propriedades e destinos são úteis e relevantes. A maioria das propriedades e dos destinos ajuda a implementar o sistema de build do Visual Studio e, consequentemente, não é relevante para o usuário. Esta seção descreve algumas propriedades e alguns destinos proveitosos orientados ao usuário.

### <a name="platformtoolset-property"></a>Propriedade PlatformToolset

A propriedade `PlatformToolset` determina qual Conjunto de ferramentas do MSVC é usado no build. Por padrão, o conjunto de ferramentas atual é usado. Quando essa propriedade é definida, o valor da propriedade é concatenado com cadeias de caracteres literais para formar o caminho de um diretório que contém os arquivos de propriedade e de destino necessários para compilar um projeto para uma plataforma específica. O Conjunto de ferramentas da plataforma precisa estar instalado para o build usando essa versão do Conjunto de ferramentas da plataforma.

Por exemplo, defina a propriedade `PlatformToolset` como `v140` para usar as ferramentas e as bibliotecas do Visual Studio 2015 para compilar seu aplicativo:

`msbuild myProject.vcxproj /p:PlatformToolset=v140`

### <a name="preferredtoolarchitecture-property"></a>Propriedade PreferredToolArchitecture

A propriedade `PreferredToolArchitecture` determina se as ferramentas e o compilador de 32 ou 64 bits são usados no build. Essa propriedade não afeta a arquitetura da plataforma de saída nem a configuração. Por padrão, o MSBuild usa a versão x86 do compilador e das ferramentas se essa propriedade não está definida.

Por exemplo, defina a propriedade `PreferredToolArchitecture` como `x64` para usar as ferramentas e o compilador de 64 bits para compilar seu aplicativo:

`msbuild myProject.vcxproj /p:PreferredToolArchitecture=x64`

### <a name="useenv-property"></a>Propriedade UseEnv

Por padrão, as configurações específicas da plataforma para o projeto atual substituem as variáveis de ambiente PATH, INCLUDE, LIB, LIBPATH, CONFIGURATION e PLATFORM. Defina a propriedade `UseEnv` como **true** para garantir que as variáveis de ambiente não sejam substituídas.

`msbuild myProject.vcxproj /p:UseEnv=true`

### <a name="targets"></a>Destinos

Há centenas de destinos nos arquivos de suporte do Visual Studio. No entanto, a maioria são destinos orientados ao sistema que o usuário pode ignorar. A maioria dos destinos do sistema é prefixada por um sublinhado (_) ou tem um nome que começa com "PrepareFor", "Compute", "Before", "After", "Pre" ou "Post".

A tabela a seguir lista vários destinos úteis orientados ao usuário.

|Destino|Descrição|
|------------|-----------------|
|BscMake|Executa a ferramenta Utilitário de Manutenção de Informações de Procura da Microsoft, bscmake.exe.|
|Build|Compila o projeto.<br /><br /> Esse é o destino padrão para um projeto.|
|ClCompile|Executa a ferramenta de compilador do MSVC, cl.exe.|
|Limpar|Exclui arquivos de build temporários e intermediários.|
|Lib|Executa a ferramenta Gerenciador de Biblioteca de 32 Bits da Microsoft, lib.exe.|
|Link|Executa a ferramenta de vinculador do MSVC, link.exe.|
|ManifestResourceCompile|Extrai uma lista de recursos de um manifesto e, em seguida, executa a ferramenta do Compilador de Recurso do Microsoft Windows, rc.exe.|
|Midl|Executa a ferramenta do compilador da MIDL (linguagem IDL da Microsoft), midl.exe.|
|Recompilar|Limpa e, em seguida, compila o projeto.|
|ResourceCompile|Executa a ferramenta do Compilador de Recurso do Microsoft Windows, rc.exe.|
|XdcMake|Executa a ferramenta de Documentação XML, xdcmake.exe.|
|Xsd|Executa a ferramenta de Definição de Esquema XML, xsd.exe. *Consulte a observação abaixo.*|

> [!NOTE]
> No Visual Studio 2017 e posterior, o suporte em projetos C++ para arquivos **xsd** foi preterido. Você ainda pode usar **Microsoft.VisualC.CppCodeProvider** adicionando **CppCodeProvider.dll** manualmente ao cache de assembly global.

## <a name="see-also"></a>Consulte também

[Referência de tarefas do MSBuild](/visualstudio/msbuild/msbuild-task-reference)<br/>
[Tarefa BscMake](/visualstudio/msbuild/bscmake-task)<br/>
[Tarefa CL](/visualstudio/msbuild/cl-task)<br/>
[Tarefa CPPClean](/visualstudio/msbuild/cppclean-task)<br/>
[Tarefa LIB](/visualstudio/msbuild/lib-task)<br/>
[Tarefa Link](/visualstudio/msbuild/link-task)<br/>
[Tarefa MIDL](/visualstudio/msbuild/midl-task)<br/>
[Tarefa MT](/visualstudio/msbuild/mt-task)<br/>
[Tarefa RC](/visualstudio/msbuild/rc-task)<br/>
[Tarefa SetEnv](/visualstudio/msbuild/setenv-task)<br/>
[Tarefa VCMessage](/visualstudio/msbuild/vcmessage-task)<br/>
[Tarefa XDCMake](/visualstudio/msbuild/xdcmake-task)<br/>
