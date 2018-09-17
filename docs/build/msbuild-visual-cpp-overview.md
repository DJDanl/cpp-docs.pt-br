---
title: Visão geral do MSBuild (Visual C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MSBuild overview
ms.assetid: dd258f6f-ab51-48d9-b274-f7ba911d05ca
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ad6feef707d991d07fa4e086bc8535f32b991825
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45716842"
---
# <a name="msbuild-visual-c-overview"></a>Visão geral de MSBuild (Visual C++)

O MSBuild é o padrão de sistema de build para projetos do Visual C++. Quando você compila um projeto no ambiente de desenvolvimento integrado (IDE) do Visual Studio, ele usa a ferramenta msbuild.exe, um arquivo de projeto baseado em XML e arquivos de configurações opcionais. Embora você possa usar msbuild.exe e um arquivo de projeto na linha de comando, o IDE fornece uma interface do usuário para que você pode definir as configurações e compilar um projeto com mais facilidade. Esta visão geral descreve como o Visual C++ usa o sistema MSBuild.

## <a name="prerequisites"></a>Pré-requisitos

Leia os documentos a seguir sobre o MSBuild.

- [MSBuild](/visualstudio/msbuild/msbuild) conceitos de visão geral do MSBuild.

- [Referência do MSBuild](/visualstudio/msbuild/msbuild-reference) informações de referência sobre o sistema MSBuild.

- [Referência de esquema de arquivo de projeto](/visualstudio/msbuild/msbuild-project-file-schema-reference) lista os elementos de esquema XML do MSBuild, juntamente com seus atributos e elementos pai e filho. Observe especialmente os [ItemGroup](/visualstudio/msbuild/itemgroup-element-msbuild), [PropertyGroup](/visualstudio/msbuild/propertygroup-element-msbuild), [destino](/visualstudio/msbuild/target-element-msbuild), e [tarefa](/visualstudio/msbuild/task-element-msbuild) elementos.

- [Referência de linha de comando](/visualstudio/msbuild/msbuild-command-line-reference) descreve os argumentos de linha de comando e opções que você pode usar com msbuild.exe.

- [Referência de tarefa](/visualstudio/msbuild/msbuild-task-reference) tarefas do MSBuild descreve. Observe especialmente estas tarefas, que são específicas para o Visual C++: [tarefa BscMake](/visualstudio/msbuild/bscmake-task), [tarefa CL](/visualstudio/msbuild/cl-task), [tarefa CPPClean](/visualstudio/msbuild/cppclean-task), [tarefa LIB](/visualstudio/msbuild/lib-task), [Vincular tarefas](/visualstudio/msbuild/link-task), [tarefa MIDL](/visualstudio/msbuild/midl-task), [tarefa MT](/visualstudio/msbuild/mt-task), [tarefa RC](/visualstudio/msbuild/rc-task), [tarefa SetEnv](/visualstudio/msbuild/setenv-task), [ Tarefa VCMessage](/visualstudio/msbuild/vcmessage-task), [tarefa XDCMake](/visualstudio/msbuild/xdcmake-task), [tarefa XSD](/visualstudio/msbuild/xsd-task).

## <a name="msbuild-on-the-command-line"></a>MSBuild na linha de comando

A instrução a seguir da [referência de linha de comando do MSBuild](/visualstudio/msbuild/msbuild-command-line-reference) ilustra que a ferramenta msbuild.exe leva um implícita ou explícita *project_file* argumento (um arquivo. vcxproj para projetos do Visual C++) e zero ou mais de linha de comando *opções* argumentos.

> **MSBuild.exe** [ *project_file* ] [ *opções* ]

Use o **/Target** (ou **/t**) e **/p.** (ou **p**) opções de linha de comando para substituir as propriedades específicas e os destinos que estão especificado no arquivo de projeto.

Uma função essencial do arquivo de projeto é especificar uma *destino*, que é uma operação específica aplicada ao seu projeto e as entradas e saídas que são necessárias para executar essa operação. Um arquivo de projeto pode especificar um ou mais destinos, que podem incluir um destino padrão.

Cada destino consiste em uma sequência de um ou mais *tarefas*. Cada tarefa é representada por uma classe do .NET Framework que contém um comando executável. Por exemplo, o [tarefa CL](/visualstudio/msbuild/cl-task) contém o [cl.exe](../build/reference/compiling-a-c-cpp-program.md) comando.

Um *parâmetro de tarefa* é uma propriedade da tarefa de classe e normalmente representa uma opção de linha de comando do comando executável. Por exemplo, o `FavorSizeOrSpeed` parâmetro do `CL` tarefa corresponde à **/Os** e **/Ot** opções do compilador.

Parâmetros adicionais de tarefa dão suporte a infraestrutura do MSBuild. Por exemplo, o `Sources` parâmetro de tarefa especifica um conjunto de tarefas que podem ser consumidos por outras tarefas. Para obter mais informações sobre tarefas do MSBuild, consulte [referência da tarefa](/visualstudio/msbuild/msbuild-task-reference).

A maioria das tarefas exige entradas e saídas, como nomes de arquivos, caminhos e cadeia de caracteres, parâmetros numéricos ou booleanos. Por exemplo, uma entrada comum é o nome de um arquivo de origem. cpp para compilar. Um parâmetro de entrada importante é uma cadeia de caracteres que especifica a configuração de compilação e a plataforma, por exemplo, "depurar\|Win32". Entradas e saídas são especificadas por um ou mais XML definidos pelo usuário `Item` elementos contidos em um `ItemGroup` elemento.

Um arquivo de projeto também pode especificar definidos pelo usuário *propriedades* e `ItemDefinitionGroup` *itens*. Propriedades e itens formam pares nome/valor que podem ser usados como variáveis na compilação. O componente de nome de um par define uma *macro*, e o componente value declara o *valor de macro*. Uma macro de propriedade é acessada usando $(*nome*) notação e uma macro de item é acessado usando %(*nome*) notação.

Outros elementos XML em um arquivo de projeto podem testar macros e, em seguida, defina o valor de qualquer macro ou condicionalmente controlar a execução da compilação. Nomes de macro e cadeias de caracteres literais podem ser concatenadas para gerar construções como um nome de arquivo e caminho. Na linha de comando, o **/p.** opção define ou substitui uma propriedade de projeto. Itens não podem ser referenciados na linha de comando.

O sistema MSBuild pode executar condicional um destino antes ou após outro destino. Além disso, o sistema pode criar um destino com base em se os arquivos que o destino consome são mais recentes que os arquivos que ele emite.

## <a name="msbuild-in-the-ide"></a>MSBuild no IDE

Quando você definir as propriedades do projeto no IDE e, em seguida, salve o projeto, o Visual C++ grava as configurações do projeto ao arquivo de projeto. O arquivo de projeto contém configurações que são exclusivas ao seu projeto, mas ele não contém todas as configurações que são necessários para compilar seu projeto. Contém o arquivo de projeto `Import` elementos que incluem uma rede adicionais *dão suporte a arquivos.* Os arquivos de suporte contêm as propriedades, destinos e as configurações necessárias para compilar o projeto restantes.

A maioria dos destinos e propriedades nos arquivos de suporte existem somente para implementar o sistema de compilação. A seção a seguir aborda alguns destinos e propriedades úteis que você pode especificar na linha de comando MSBuild. Para descobrir mais destinos e propriedades, explore os arquivos nos diretórios de arquivos de suporte.

### <a name="support-file-directories"></a>Diretórios de arquivos de suporte

Por padrão, os arquivos de suporte principais do Visual C++ estão localizados nos diretórios a seguir. Os diretórios sob o Microsoft Visual Studio são usados pelo Visual Studio 2017 e versões posteriores, enquanto os diretórios sob o MSBuild são usados pelo Visual Studio 2015 e versões anteriores.

|Diretório|Descrição|
|---------------|-----------------|
|*unidade*: \Program Files *(x86)* \Microsoft Visual Studio\\*ano*\\*edition*\Common7\IDE\VC\VCTargets\ <br /><br />*unidade*: \Program Files *(x86)* \MSBuild\Microsoft.Cpp (x86) \v4.0\\*versão*\ |Contém os arquivos de destino principal (. targets) e arquivos de propriedade (. Props) que são usados pelos destinos. Por padrão, a macro $ (vctargetspath) referencia este diretório.|
|*unidade*: \Program Files *(x86)* \Microsoft Visual Studio\\*ano*\\*edition*\Common7\IDE\VC\VCTargets\ Plataformas\\*plataforma*\ <br /><br />*unidade*: \Program Files *(x86)* \MSBuild\Microsoft.Cpp\v4.0\\*versão*\Platforms\\*plataforma*\ |Contém arquivos de destino e a propriedade específica da plataforma que substituem destinos e propriedades em seu diretório pai. Este diretório também contém uma DLL que define as tarefas que são usadas pelos destinos neste diretório.<br /><br /> O *plataforma* espaço reservado representa o ARM, Win32 ou x64 subdiretório.|
|*unidade*: \Program Files *(x86)* \Microsoft Visual Studio\\*ano*\\*edition*\Common7\IDE\VC\VCTargets\ Plataformas\\*plataforma*\PlatformToolsets\\*conjunto de ferramentas*\ <br /><br />*unidade*: \Program Files *(x86)* \MSBuild\Microsoft.Cpp\v4.0\\*versão*\Platforms\\*plataforma*\ PlatformToolsets\\*conjunto de ferramentas*\ <br /><br />*unidade*: \Program Files *(x86)* \MSBuild\Microsoft.Cpp\v4.0\Platforms\\*plataforma*\PlatformToolsets\\*conjunto de ferramentas*\ |Contém diretórios que permitem a compilação para gerar aplicativos do Visual C++ usando especificado *conjunto de ferramentas*.<br /><br /> O *ano* e *edition* espaços reservados são usados pelo Visual Studio 2017 e edições posteriores. O *versão* espaço reservado é V110 para Visual Studio 2012, V120 para Visual Studio 2013 ou V140 para Visual Studio 2015. O *plataforma* espaço reservado representa o ARM, Win32 ou x64 subdiretório. O *conjunto de ferramentas* espaço reservado representa o subdiretório do conjunto de ferramentas, por exemplo, v140 para a criação de aplicativos do Windows usando o conjunto de ferramentas do Visual Studio 2015, v120_xp para compilar para o XP do Windows usando o conjunto de ferramentas do Visual Studio 2013 ou v110_wp80 para Crie aplicativos Windows Phone 8.0, usando o conjunto de ferramentas do Visual Studio 2012.<br /><br />O caminho que contém os diretórios que permitem a compilação para gerar aplicativos do Visual C++ 2008 ou o Visual C++ 2010 não inclui o *versão*e o *plataforma* espaço reservado representa o Itanium, Win32 ou x64 subdiretório. O *conjunto de ferramentas* espaço reservado representa o subdiretório do conjunto de ferramentas v90 ou v100.|

### <a name="support-files"></a>Arquivos de suporte

Os diretórios de arquivos de suporte contêm arquivos com essas extensões:

|Extensão|Descrição|
|---------------|-----------------|
|. targets|Contém `Target` elementos XML que especificam as tarefas que são executadas pelo destino. Também pode conter `PropertyGroup`, `ItemGroup`, `ItemDefinitionGroup`e definidos pelo usuário `Item` elementos que são usados para atribuir arquivos e opções de linha de comando a parâmetros de tarefa.<br /><br /> Para obter mais informações, consulte [elemento Target (MSBuild)](/visualstudio/msbuild/target-element-msbuild).|
|. Props|Contém `Property Group` definidas pelo usuário `Property` elementos XML que especificam as configurações de arquivo e de parâmetro que são usadas durante uma compilação.<br /><br /> Também pode conter `ItemDefinitionGroup` definidas pelo usuário `Item` elementos XML que especificam configurações adicionais. Os itens definidos em um grupo de definições de item são semelhantes a propriedades, mas não podem ser acessados a partir da linha de comando. Arquivos de projeto do Visual C++ usa com frequência itens em vez de propriedades para representar configurações.<br /><br /> Para obter mais informações, consulte [elemento ItemGroup (MSBuild)](/visualstudio/msbuild/itemgroup-element-msbuild), [elemento ItemDefinitionGroup (MSBuild)](/visualstudio/msbuild/itemdefinitiongroup-element-msbuild), e [elemento Item (MSBuild)](/visualstudio/msbuild/item-element-msbuild).|
|. XML|Contém elementos XML que declara e inicializa os elementos de interface de usuário do IDE, como folhas de propriedades e páginas de propriedades e os controles de caixa de lista e de caixa de texto.<br /><br /> Os arquivos. XML suportam diretamente o IDE, não o MSBuild. No entanto, os valores das propriedades do IDE são atribuídos para criar propriedades e itens.<br /><br /> A maioria dos arquivos. XML estão em um subdiretório específico de localidade. Por exemplo, os arquivos para a região de inglês-EUA estão em $(VCTargetsPath) \1033\\.|

## <a name="user-targets-and-properties"></a>Propriedades e destinos de usuário

Para usar o MSBuild mais efetivamente na linha de comando, é útil para saber quais propriedades e destinos são úteis e relevantes. A maioria das propriedades e destinos ajudam a implementar o sistema de compilação do Visual C++ e, consequentemente, não são relevantes para o usuário. Esta seção descreve algumas propriedades que vale a pena orientado ao usuário e destinos.

### <a name="platformtoolset-property"></a>Propriedade de PlatformToolset

O `PlatformToolset` propriedade determina qual conjunto de ferramentas do Visual C++ é usado na compilação. Por padrão, o conjunto de ferramentas atual é usado. Quando essa propriedade é definida, o valor da propriedade é concatenado com cadeias de caracteres literais para formar o caminho de um diretório que contém os arquivos de propriedade e de destino que são necessários para compilar um projeto para uma plataforma específica. O conjunto de ferramentas da plataforma deve estar instalado para compilar usando essa versão do conjunto de ferramentas de plataforma.

Por exemplo, defina as `PlatformToolset` propriedade para `v140` usar bibliotecas e ferramentas do Visual C++ 2015 para criar seu aplicativo:

`msbuild myProject.vcxproj /p:PlatformToolset=v140`

### <a name="preferredtoolarchitecture-property"></a>Propriedade de PreferredToolArchitecture

O `PreferredToolArchitecture` propriedade determina se o compilador de 32 bits ou 64 bits e ferramentas são usadas na compilação. Essa propriedade não afeta a arquitetura da plataforma de saída ou a configuração. Por padrão, o MSBuild usa x86 versão do compilador e ferramentas se essa propriedade não está definida.

Por exemplo, defina as `PreferredToolArchitecture` propriedade para `x64` para usar as ferramentas e o compilador de 64 bits para compilar seu aplicativo:

`msbuild myProject.vcxproj /p:PreferredToolArchitecture=x64`

### <a name="useenv-property"></a>Propriedade UseEnv

Por padrão, as configurações específicas da plataforma para o projeto atual substituem as variáveis de ambiente PATH, INCLUDE, LIB, LIBPATH, configuração e plataforma. Defina as `UseEnv` propriedade para `true` para garantir que as variáveis de ambiente não são substituídas.

`msbuild myProject.vcxproj /p:UseEnv=true`

### <a name="targets"></a>Destinos

Há centenas de destinos nos arquivos de suporte do Visual C++. No entanto, a maioria são destinos orientados ao sistema que o usuário pode ignorar. A maioria dos destinos de sistema são precedidos por um sublinhado (_) ou tem um nome que começa com "PrepareFor", "Compute", "Before", "After", "Pre" ou "Post".

A tabela a seguir lista vários destinos útil orientado ao usuário.

|Destino|Descrição|
|------------|-----------------|
|BscMake|Executa a ferramenta Microsoft procurar informações utilitário de manutenção, bscmake.exe.|
|Build|Compila o projeto.<br /><br /> Isso é o destino padrão para um projeto.|
|ClCompile|Executa a ferramenta de compilador do Visual C++, cl.exe.|
|Limpar|Criar arquivos de exclusões temporárias e intermediárias.|
|Lib|Executa a ferramenta de Gerenciador de biblioteca da Microsoft de 32 bits, lib.exe.|
|Link|Executa a ferramenta de vinculador do Visual C++, link.exe.|
|ManifestResourceCompile|Extrai uma lista de recursos de um manifesto e, em seguida, executa a ferramenta de compilador de recurso do Microsoft Windows, rc.exe.|
|MIDL|Executa a ferramenta de compilador de linguagem de definição de Interface da Microsoft (MIDL), midl.exe.|
|Recompilar|Limpa e, em seguida, compila seu projeto.|
|ResourceCompile|Executa a ferramenta de compilador de recurso do Microsoft Windows, rc.exe.|
|XdcMake|Executa a ferramenta de documentação XML, xdcmake.exe.|
|XSD|Executa a ferramenta de definição de esquema XML, xsd.exe. *Consulte a observação abaixo.*|

> [!NOTE]
> No Visual Studio 2017, suporte para o projeto C++ **xsd** arquivos foi preterido. Você ainda pode usar **Microsoft.VisualC.CppCodeProvider** adicionando **CppCodeProvider.dll** manualmente ao GAC.

## <a name="see-also"></a>Consulte também

[MSBuild (Visual C++)](../build/msbuild-visual-cpp.md)
