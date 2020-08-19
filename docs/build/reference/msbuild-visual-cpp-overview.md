---
title: Recursos internos do MSBuild para projetos C++ no Visual Studio
ms.date: 02/26/2020
helpviewer_keywords:
- MSBuild overview
ms.assetid: dd258f6f-ab51-48d9-b274-f7ba911d05ca
ms.openlocfilehash: c52434fa4b652d52baea70df705920db4ee68a5f
ms.sourcegitcommit: 65fead53d56d531d71be42216056aca5f44def11
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/19/2020
ms.locfileid: "88610836"
---
# <a name="msbuild-internals-for-c-projects"></a>Recursos internos do MSBuild para projetos C++

Quando você define as propriedades do projeto no IDE e, em seguida, salva o projeto, o Visual Studio grava as configurações do projeto no arquivo de projeto. O arquivo de projeto contém configurações que são exclusivas do seu projeto. No entanto, ele não contém todas as configurações necessárias para compilar seu projeto. O arquivo de projeto contém elementos `Import` que incluem uma rede de *arquivos de suporte* adicionais. Os arquivos de suporte contêm as propriedades, os destinos e as configurações restantes necessárias para compilar o projeto.

A maioria dos destinos e das propriedades nos arquivos de suporte existe somente para implementar o sistema de build. Este artigo discute destinos e propriedades úteis que você pode especificar na linha de comando do MSBuild. Para descobrir mais destinos e propriedades, explore os arquivos nos diretórios de arquivos de suporte.

## <a name="support-file-directories"></a>Diretórios de arquivos de suporte

Por padrão, os arquivos de suporte principais do Visual Studio estão localizados nos diretórios a seguir. Essas informações são específicas da versão.

### <a name="visual-studio-2019"></a>Visual Studio 2019

- % VSINSTALLDIR% MSBuild \\ Microsoft \\ vc \\ *versão*\\

  Contém os arquivos de destino (.targets) e os arquivos de propriedade (.props) principais que são usados pelos destinos. Por padrão, a macro $(VCTargetsPath) referencia esse diretório. O espaço reservado de *versão* refere-se à versão do Visual Studio: V160 para visual Studio 2019, V150 para visual Studio 2017.

- % VSINSTALLDIR% MSBuild \\ \\ plataforma de \\ *version* \\ plataformas de \\ *platform* versão Microsoft vc\\

  Contém os arquivos de destino e de propriedade específicos da plataforma que substituem os destinos e as propriedades no diretório pai. Esse diretório também contém uma DLL que define as tarefas que são usadas pelos destinos nesse diretório. O espaço reservado *plataforma* representa o subdiretório do ARM, do Win32 ou do x64.

- % VSINSTALLDIR% MSBuild \\ Microsoft \\ vc \\ *versão* \\ plataformas \\ *plataforma* \\ PlatformToolsets \\ *conjunto de ferramentas*\\

  Contém os diretórios que permitem que o build gere aplicativos C++ usando o *conjunto de ferramentas* especificado. O espaço reservado *plataforma* representa o subdiretório do ARM, do Win32 ou do x64. O espaço reservado do *conjunto de ferramentas* representa o subdiretório do conjunto de ferramentas.

### <a name="visual-studio-2017"></a>Visual Studio 2017

- % VSINSTALLDIR% Common7 \\ IDE \\ vc \\ VCTargets\\

  Contém os arquivos de destino (.targets) e os arquivos de propriedade (.props) principais que são usados pelos destinos. Por padrão, a macro $(VCTargetsPath) referencia esse diretório.

- % VSINSTALLDIR% Common7 \\ IDE \\ vc \\ VCTargets \\ plataformas \\ *plataforma*\\

  Contém os arquivos de destino e de propriedade específicos da plataforma que substituem os destinos e as propriedades no diretório pai. Esse diretório também contém uma DLL que define as tarefas que são usadas pelos destinos nesse diretório. O espaço reservado *plataforma* representa o subdiretório do ARM, do Win32 ou do x64.

- % VSINSTALLDIR% Common7 \\ IDE \\ vc \\ VCTargets \\ plataformas \\ *plataforma* \\ PlatformToolsets \\ *conjunto de ferramentas*\\

  Contém os diretórios que permitem que o build gere aplicativos C++ usando o *conjunto de ferramentas* especificado. O espaço reservado *plataforma* representa o subdiretório do ARM, do Win32 ou do x64. O espaço reservado do *conjunto de ferramentas* representa o subdiretório do conjunto de ferramentas.

### <a name="visual-studio-2015-and-earlier"></a>Visual Studio 2015 e anteriores

- *unidade*: \\ arquivos *de programas (x86)* \\ MSBuild \\ Microsoft. cpp (x86) \\ \\ *versão* v 4.0\\

  Contém os arquivos de destino (.targets) e os arquivos de propriedade (.props) principais que são usados pelos destinos. Por padrão, a macro $(VCTargetsPath) referencia esse diretório.

- *unidade*: \\ arquivos *de programas (x86)* \\ MSBuild \\ Microsoft. cpp \\ v 4.0 \\ *versão* \\ plataformas \\ *plataforma*\\

  Contém os arquivos de destino e de propriedade específicos da plataforma que substituem os destinos e as propriedades no diretório pai. Esse diretório também contém uma DLL que define as tarefas que são usadas pelos destinos nesse diretório. O espaço reservado *plataforma* representa o subdiretório do ARM, do Win32 ou do x64.

- *unidade*: \\ arquivos *de programas (x86)* \\ MSBuild \\ Microsoft. cpp \\ v 4.0 \\ *versão* \\ plataformas \\ *plataforma* \\ PlatformToolsets \\ *conjunto de ferramentas*\\

  Contém os diretórios que permitem que o build gere aplicativos C++ usando o *conjunto de ferramentas* especificado. O espaço reservado da *versão* é V110 para visual Studio 2012, V120 para Visual Studio 2013 e v140 para visual Studio 2015. O espaço reservado *plataforma* representa o subdiretório do ARM, do Win32 ou do x64. O espaço reservado do *conjunto de ferramentas* representa o subdiretório do conjunto de ferramentas. Por exemplo, é v140 para criar aplicativos do Windows usando o conjunto de ferramentas do Visual Studio 2015. Ou, v120_xp para compilar para o Windows XP usando o conjunto de ferramentas Visual Studio 2013.

- *unidade*: \\ arquivos *de programas (x86)* \\ MSBuild \\ Microsoft. cpp \\ v 4.0 \\ plataformas \\ *plataforma* \\ PlatformToolsets \\ *conjunto de ferramentas*\\

  Os caminhos que permitem que a compilação gere aplicativos do Visual Studio 2008 ou do Visual Studio 2010 não incluem a *versão*. Nessas versões, o espaço reservado da *plataforma* representa o subdiretório do Itanium, Win32 ou x64. O espaço reservado *conjunto de ferramentas* representa o subdiretório do conjunto de ferramentas v90 ou v100.

## <a name="support-files"></a>Arquivos de suporte

Os diretórios dos arquivos de suporte contêm arquivos com estas extensões:

| Extensão | Descrição |
| --------- | ----------- |
| .targets | Contém elementos XML `Target` que especificam as tarefas que são executadas pelo destino. Também pode conter elementos `PropertyGroup`, `ItemGroup`, `ItemDefinitionGroup` e `Item` definidos pelo usuário que são usados para atribuir arquivos e opções de linha de comando a parâmetros de tarefa.<br /><br /> Para obter mais informações, confira [Elemento Target (MSBuild)](/visualstudio/msbuild/target-element-msbuild). |
| .props | Contém elementos XML `Property Group` e `Property` definidos pelo usuário que especificam as configurações de arquivo e parâmetro usadas durante um build.<br /><br /> Também pode conter elementos XML `ItemDefinitionGroup` e `Item` definidos pelo usuário que especificam configurações adicionais. Os itens definidos em um grupo de definição de item se assemelham a propriedades, mas não podem ser acessados na linha de comando. Os arquivos de projeto do Visual Studio frequentemente usam itens em vez de propriedades para representar configurações.<br /><br /> Para obter mais informações, consulte elemento [dogroup (MSBuild)](/visualstudio/msbuild/itemgroup-element-msbuild), [elemento ItemDefinitionGroup (MSBuild)](/visualstudio/msbuild/itemdefinitiongroup-element-msbuild)e [elemento item (MSBuild)](/visualstudio/msbuild/item-element-msbuild). |
| .xml | Contém elementos XML que declaram e inicializam elementos da interface do usuário do IDE. Por exemplo, folhas de propriedades, páginas de propriedades, controles de caixa de texto e controles ListBox.<br /><br /> Os arquivos .xml dão suporte direto ao IDE, não ao MSBuild. No entanto, os valores das propriedades do IDE são atribuídos para compilar propriedades e itens.<br /><br /> A maioria dos arquivos .xml está localizada em um subdiretório específico da localidade. Por exemplo, os arquivos para a região inglês-EUA estão em $ (VCTargetsPath) \\ 1033 \\ . |

## <a name="user-targets-and-properties"></a>Propriedades e destinos de usuário

Para usar o MSBuild com eficiência, ele ajuda a saber quais propriedades e destinos são úteis e relevantes. A maioria das propriedades e destinos ajuda a implementar o sistema de compilação do Visual Studio e, consequentemente, não é relevante para o usuário. Esta seção descreve as propriedades e os destinos orientados ao usuário que vale a pena conhecer.

### <a name="platformtoolset-property"></a>Propriedade PlatformToolset

A propriedade `PlatformToolset` determina qual Conjunto de ferramentas do MSVC é usado no build. Por padrão, o conjunto de ferramentas atual é usado. Quando essa propriedade é definida, seu valor é concatenado com cadeias de caracteres literais para formar o caminho. É o diretório que contém os arquivos de propriedade e de destino necessários para criar um projeto para uma plataforma específica. O Conjunto de ferramentas da plataforma precisa estar instalado para o build usando essa versão do Conjunto de ferramentas da plataforma.

Por exemplo, defina a propriedade `PlatformToolset` como `v140` para usar as ferramentas e as bibliotecas do Visual Studio 2015 para compilar seu aplicativo:

`msbuild myProject.vcxproj /p:PlatformToolset=v140`

### <a name="preferredtoolarchitecture-property"></a>Propriedade PreferredToolArchitecture

A propriedade `PreferredToolArchitecture` determina se as ferramentas e o compilador de 32 ou 64 bits são usados no build. Essa propriedade não afeta a arquitetura da plataforma de saída ou a configuração. Por padrão, o MSBuild usa a versão x86 do compilador e as ferramentas se essa propriedade não estiver definida.

Por exemplo, defina a propriedade `PreferredToolArchitecture` como `x64` para usar as ferramentas e o compilador de 64 bits para compilar seu aplicativo:

`msbuild myProject.vcxproj /p:PreferredToolArchitecture=x64`

### <a name="useenv-property"></a>Propriedade UseEnv

Por padrão, as configurações específicas da plataforma para o projeto atual substituem as variáveis de ambiente PATH, INCLUDE, LIB, LIBPATH, CONFIGURATION e PLATFORM. Defina a `UseEnv` propriedade como **`true`** para garantir que as variáveis de ambiente não sejam substituídas.

`msbuild myProject.vcxproj /p:UseEnv=true`

### <a name="targets"></a>Destinos

Há centenas de destinos nos arquivos de suporte do Visual Studio. No entanto, a maioria são destinos orientados ao sistema que o usuário pode ignorar. A maioria dos destinos de sistema são prefixados por um sublinhado ( `_` ) ou têm um nome que começa com "PrepareFor", "Compute", "Before", "After", "pre" ou "post".

A tabela a seguir lista vários destinos úteis orientados ao usuário.

| Destino | Descrição |
| ------ | ----------- |
| BscMake | Executa a ferramenta Utilitário de Manutenção de Informações de Procura da Microsoft, bscmake.exe. |
| Build | Compila o projeto.<br /><br /> Esse destino é o padrão para um projeto. |
| ClCompile | Executa a ferramenta de compilador do MSVC, cl.exe. |
| Clean | Exclui arquivos de build temporários e intermediários. |
| Lib | Executa a ferramenta Gerenciador de Biblioteca de 32 Bits da Microsoft, lib.exe. |
| Link | Executa a ferramenta de vinculador do MSVC, link.exe. |
| ManifestResourceCompile | Extrai uma lista de recursos de um manifesto e, em seguida, executa a ferramenta do Compilador de Recurso do Microsoft Windows, rc.exe. |
| Midl | Executa a ferramenta do compilador da MIDL (linguagem IDL da Microsoft), midl.exe. |
| Recompilar | Limpa e, em seguida, compila o projeto. |
| ResourceCompile | Executa a ferramenta do Compilador de Recurso do Microsoft Windows, rc.exe. |
| XdcMake | Executa a ferramenta de Documentação XML, xdcmake.exe. |
| Xsd | Executa a ferramenta de Definição de Esquema XML, xsd.exe. *Veja a observação abaixo.* |

> [!NOTE]
> No Visual Studio 2017 e posterior, o suporte em projetos C++ para arquivos **xsd** foi preterido. Você ainda pode usar **Microsoft.VisualC.CppCodeProvider** adicionando **CppCodeProvider.dll** manualmente ao cache de assembly global.

## <a name="see-also"></a>Veja também

[Referência de tarefa do MSBuild](/visualstudio/msbuild/msbuild-task-reference)\
[Tarefa BscMake](/visualstudio/msbuild/bscmake-task)\
[Tarefa CL](/visualstudio/msbuild/cl-task)\
[Tarefa CPPClean](/visualstudio/msbuild/cppclean-task)\
[Tarefa LIB](/visualstudio/msbuild/lib-task)\
[Vincular tarefa](/visualstudio/msbuild/link-task)\
[Tarefa MIDL](/visualstudio/msbuild/midl-task)\
[Tarefa MT](/visualstudio/msbuild/mt-task)\
[Tarefa RC](/visualstudio/msbuild/rc-task)\
[Tarefa SetEnv](/visualstudio/msbuild/setenv-task)\
[Tarefa VCMessage](/visualstudio/msbuild/vcmessage-task)\
[Tarefa XDCMake](/visualstudio/msbuild/xdcmake-task)
