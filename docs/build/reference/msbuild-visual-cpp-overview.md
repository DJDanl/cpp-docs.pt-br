---
title: Projetos de componentes internos do MSBuild para C++ no Visual Studio
ms.date: 12/08/2018
helpviewer_keywords:
- MSBuild overview
ms.assetid: dd258f6f-ab51-48d9-b274-f7ba911d05ca
ms.openlocfilehash: 6c8e891f6bf6ed6b3bb3d1c84dbc13b64ab7b868
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62320884"
---
# <a name="msbuild-internals-for-c-projects"></a>Recursos internos de MSBuild para projetos do C++

Quando você definir as propriedades do projeto no IDE e, em seguida, salve o projeto, o Visual Studio grava as configurações do projeto ao arquivo de projeto. O arquivo de projeto contém configurações que são exclusivas ao seu projeto, mas ele não contém todas as configurações que são necessários para compilar seu projeto. Contém o arquivo de projeto `Import` elementos que incluem uma rede adicionais *dão suporte a arquivos.* Os arquivos de suporte contêm as propriedades, destinos e as configurações necessárias para compilar o projeto restantes.

A maioria dos destinos e propriedades nos arquivos de suporte existem somente para implementar o sistema de compilação. A seção a seguir aborda alguns destinos e propriedades úteis que você pode especificar na linha de comando MSBuild. Para descobrir mais destinos e propriedades, explore os arquivos nos diretórios de arquivos de suporte.

## <a name="support-file-directories"></a>Diretórios de arquivos de suporte

Por padrão, os arquivos de suporte principais do Visual Studio estão localizados nos diretórios a seguir. Os diretórios sob o Microsoft Visual Studio são usados pelo Visual Studio 2017 e versões posteriores, enquanto os diretórios sob o MSBuild são usados pelo Visual Studio 2015 e versões anteriores.

|Diretório|Descrição|
|---------------|-----------------|
|*unidade*: \Program Files *(x86)* \Microsoft Visual Studio\\*ano*\\*edition*\Common7\IDE\VC\VCTargets\ <br /><br />*drive*:\Program Files *(x86)* \MSBuild\Microsoft.Cpp (x86)\v4.0\\*version*\ |Contém os arquivos de destino principal (. targets) e arquivos de propriedade (. Props) que são usados pelos destinos. Por padrão, a macro $ (vctargetspath) referencia este diretório.|
|*unidade*: \Program Files *(x86)* \Microsoft Visual Studio\\*ano*\\*edition*\Common7\IDE\VC\VCTargets\ Plataformas\\*plataforma*\ <br /><br />*unidade*: \Program Files *(x86)* \MSBuild\Microsoft.Cpp\v4.0\\*versão*\Platforms\\*plataforma*\ |Contém arquivos de destino e a propriedade específica da plataforma que substituem destinos e propriedades em seu diretório pai. Este diretório também contém uma DLL que define as tarefas que são usadas pelos destinos neste diretório.<br /><br /> O *plataforma* espaço reservado representa o ARM, Win32 ou x64 subdiretório.|
|*unidade*: \Program Files *(x86)* \Microsoft Visual Studio\\*ano*\\*edition*\Common7\IDE\VC\VCTargets\ Plataformas\\*plataforma*\PlatformToolsets\\*conjunto de ferramentas*\ <br /><br />*drive*:\Program Files *(x86)* \MSBuild\Microsoft.Cpp\v4.0\\*version*\Platforms\\*platform*\PlatformToolsets\\*toolset*\ <br /><br />*unidade*: \Program Files *(x86)* \MSBuild\Microsoft.Cpp\v4.0\Platforms\\*plataforma*\PlatformToolsets\\*conjunto de ferramentas*\ |Contém diretórios que permitem a compilação para gerar aplicativos C++ usando especificado *conjunto de ferramentas*.<br /><br /> O *ano* e *edition* espaços reservados são usados pelo Visual Studio 2017 e edições posteriores. O *versão* espaço reservado é V110 para Visual Studio 2012, V120 para Visual Studio 2013 ou V140 para Visual Studio 2015. O *plataforma* espaço reservado representa o ARM, Win32 ou x64 subdiretório. O *conjunto de ferramentas* espaço reservado representa o subdiretório do conjunto de ferramentas, por exemplo, v140 para a criação de aplicativos do Windows usando o conjunto de ferramentas do Visual Studio 2015, v120_xp para compilar para o XP do Windows usando o conjunto de ferramentas do Visual Studio 2013 ou v110_wp80 para Crie aplicativos Windows Phone 8.0, usando o conjunto de ferramentas do Visual Studio 2012.<br /><br />O caminho que contém os diretórios que permitem a compilação para gerar aplicativos do Visual Studio 2008 ou no Visual Studio 2010 não inclui o *versão*e o *plataforma* espaço reservado representa o Itanium, Win32 ou x64 subdiretório. O *conjunto de ferramentas* espaço reservado representa o subdiretório do conjunto de ferramentas v90 ou v100.|

## <a name="support-files"></a>Arquivos de suporte

Os diretórios de arquivos de suporte contêm arquivos com essas extensões:

|Extensão|Descrição|
|---------------|-----------------|
|.targets|Contém `Target` elementos XML que especificam as tarefas que são executadas pelo destino. Também pode conter `PropertyGroup`, `ItemGroup`, `ItemDefinitionGroup`e definidos pelo usuário `Item` elementos que são usados para atribuir arquivos e opções de linha de comando a parâmetros de tarefa.<br /><br /> Para obter mais informações, consulte [elemento Target (MSBuild)](/visualstudio/msbuild/target-element-msbuild).|
|. Props|Contém `Property Group` definidas pelo usuário `Property` elementos XML que especificam as configurações de arquivo e de parâmetro que são usadas durante uma compilação.<br /><br /> Também pode conter `ItemDefinitionGroup` definidas pelo usuário `Item` elementos XML que especificam configurações adicionais. Os itens definidos em um grupo de definições de item são semelhantes a propriedades, mas não podem ser acessados a partir da linha de comando. Arquivos de projeto do Visual Studio frequentemente usam itens em vez de propriedades para representar configurações.<br /><br /> Para obter mais informações, consulte [elemento ItemGroup (MSBuild)](/visualstudio/msbuild/itemgroup-element-msbuild), 
[Elemento ItemDefinitionGroup (MSBuild)](/visualstudio/msbuild/itemdefinitiongroup-element-msbuild), e [elemento Item (MSBuild)](/visualstudio/msbuild/item-element-msbuild).|
|.xml|Contém elementos XML que declara e inicializa os elementos de interface de usuário do IDE, como folhas de propriedades e páginas de propriedades e os controles de caixa de lista e de caixa de texto.<br /><br /> Os arquivos. XML suportam diretamente o IDE, não o MSBuild. No entanto, os valores das propriedades do IDE são atribuídos para criar propriedades e itens.<br /><br /> A maioria dos arquivos. XML estão em um subdiretório específico de localidade. Por exemplo, os arquivos para a região de inglês-EUA estão em $(VCTargetsPath) \1033\\.|

## <a name="user-targets-and-properties"></a>Propriedades e destinos de usuário

Para usar o MSBuild mais efetivamente na linha de comando, é útil para saber quais propriedades e destinos são úteis e relevantes. A maioria das propriedades e destinos ajudam a implementar o sistema de compilação do Visual Studio e, consequentemente, não são relevantes para o usuário. Esta seção descreve algumas propriedades que vale a pena orientado ao usuário e destinos.

### <a name="platformtoolset-property"></a>Propriedade de PlatformToolset

O `PlatformToolset` propriedade determina qual conjunto de ferramentas do MSVC é usado na compilação. Por padrão, o conjunto de ferramentas atual é usado. Quando essa propriedade é definida, o valor da propriedade é concatenado com cadeias de caracteres literais para formar o caminho de um diretório que contém os arquivos de propriedade e de destino que são necessários para compilar um projeto para uma plataforma específica. O conjunto de ferramentas da plataforma deve estar instalado para compilar usando essa versão do conjunto de ferramentas de plataforma.

Por exemplo, defina as `PlatformToolset` propriedade para `v140` usar bibliotecas e ferramentas do Visual Studio 2015 para criar seu aplicativo:

`msbuild myProject.vcxproj /p:PlatformToolset=v140`

### <a name="preferredtoolarchitecture-property"></a>Propriedade de PreferredToolArchitecture

O `PreferredToolArchitecture` propriedade determina se o compilador de 32 bits ou 64 bits e ferramentas são usadas na compilação. Essa propriedade não afeta a arquitetura da plataforma de saída ou a configuração. Por padrão, o MSBuild usa x86 versão do compilador e ferramentas se essa propriedade não está definida.

Por exemplo, defina as `PreferredToolArchitecture` propriedade para `x64` para usar as ferramentas e o compilador de 64 bits para compilar seu aplicativo:

`msbuild myProject.vcxproj /p:PreferredToolArchitecture=x64`

### <a name="useenv-property"></a>Propriedade UseEnv

Por padrão, as configurações específicas da plataforma para o projeto atual substituem as variáveis de ambiente PATH, INCLUDE, LIB, LIBPATH, configuração e plataforma. Defina a `UseEnv` propriedade para **verdadeiro** para garantir que as variáveis de ambiente não são substituídas.

`msbuild myProject.vcxproj /p:UseEnv=true`

### <a name="targets"></a>Destinos

Há centenas de destinos nos arquivos de suporte do Visual Studio. No entanto, a maioria são destinos orientados ao sistema que o usuário pode ignorar. A maioria dos destinos de sistema são precedidos por um sublinhado (_) ou tem um nome que começa com "PrepareFor", "Compute", "Before", "After", "Pre" ou "Post".

A tabela a seguir lista vários destinos útil orientado ao usuário.

|Destino|Descrição|
|------------|-----------------|
|BscMake|Executa a ferramenta Microsoft procurar informações utilitário de manutenção, bscmake.exe.|
|Build|Compila o projeto.<br /><br /> Isso é o destino padrão para um projeto.|
|ClCompile|Executa a ferramenta de compilador MSVC, cl.exe.|
|Limpar|Criar arquivos de exclusões temporárias e intermediárias.|
|Lib|Executa a ferramenta de Gerenciador de biblioteca da Microsoft de 32 bits, lib.exe.|
|Link|Executa a ferramenta de vinculador MSVC, link.exe.|
|ManifestResourceCompile|Extrai uma lista de recursos de um manifesto e, em seguida, executa a ferramenta de compilador de recurso do Microsoft Windows, rc.exe.|
|Midl|Executa a ferramenta de compilador de linguagem de definição de Interface da Microsoft (MIDL), midl.exe.|
|Recompilar|Limpa e, em seguida, compila seu projeto.|
|ResourceCompile|Executa a ferramenta de compilador de recurso do Microsoft Windows, rc.exe.|
|XdcMake|Executa a ferramenta de documentação XML, xdcmake.exe.|
|Xsd|Executa a ferramenta de definição de esquema XML, xsd.exe. *Consulte a observação abaixo.*|

> [!NOTE]
> No Visual Studio 2017, suporte para o projeto C++ **xsd** arquivos foi preterido. Você ainda pode usar **Microsoft.VisualC.CppCodeProvider** adicionando **CppCodeProvider.dll** manualmente ao GAC.

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
