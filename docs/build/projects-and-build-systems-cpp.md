---
title: Projetos C/C++ e sistemas de compilação no Visual Studio
description: Use o Visual Studio para compilar e compilar projetos C++ para Windows, ARM ou Linux com base em qualquer sistema de projeto.
ms.date: 07/17/2019
helpviewer_keywords:
- builds [C++]
- C++ projects, building
- projects [C++], building
- builds [C++], options
- C++, build options
ms.assetid: fa6ed4ff-334a-4d99-b5e2-a1f83d2b3008
ms.topic: overview
ms.openlocfilehash: 193230ef393aa83d7ce4b9aec11a1fa2cb5052ce
ms.sourcegitcommit: f19f02f217b80804ab321d463c76ce6f681abcc6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/19/2020
ms.locfileid: "92176067"
---
# <a name="cc-projects-and-build-systems-in-visual-studio"></a>Projetos C/C++ e sistemas de compilação no Visual Studio

Você pode usar o Visual Studio para editar, compilar e criar qualquer base de código C++ com suporte total ao IntelliSense sem a necessidade de converter esse código em um projeto do Visual Studio ou compilar com o conjunto de ferramentas MSVC. Por exemplo, você pode editar um projeto CMake de plataforma cruzada no Visual Studio em um computador Windows e compilá-lo para Linux usando o g + + em um computador Linux remoto.

## <a name="c-compilation"></a>Compilação em C++

*Criar* um programa em C++ significa compilar o código-fonte de um ou mais arquivos e, em seguida, vincular esses arquivos em um arquivo executável (. exe), uma biblioteca de carregamento dinâmico (. dll) ou uma biblioteca estática (. lib).

A compilação básica do C++ envolve três etapas principais:

- O pré-processador de C++ transforma todas as definições de #directives e macro em cada arquivo de origem. Isso cria uma *unidade de tradução*.
- O compilador C++ compila cada unidade de tradução em arquivos de objeto (. obj), aplicando quaisquer opções de compilador definidas.
- O *vinculador* mescla os arquivos de objeto em um único executável, aplicando as opções de vinculador que foram definidas.

## <a name="the-msvc-toolset"></a>O conjunto de ferramentas MSVC

O compilador do Microsoft C++, o vinculador, as bibliotecas padrão e os utilitários relacionados compõem o conjunto de ferramentas do compilador MSVC (também chamado de ferramentas ou "ferramentas de Build"). Eles estão incluídos no Visual Studio. Você também pode baixar e usar o conjunto de ferramentas como um pacote autônomo gratuito das [ferramentas de Build para o download do Visual Studio 2019](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019).

Você pode criar programas simples invocando o compilador MSVC (cl.exe) diretamente da linha de comando. O comando a seguir aceita um único arquivo de código-fonte e invoca cl.exe para criar um executável chamado *hello.exe*:

```cmd
cl /EHsc hello.cpp
```

Aqui, o compilador (cl.exe) invoca automaticamente o pré-processador do C++ e o vinculador para produzir o arquivo de saída final. Para obter mais informações, consulte [criando na linha de comando](building-on-the-command-line.md).

## <a name="build-systems-and-projects"></a>Compilar sistemas e projetos

A maioria dos programas do mundo real usa algum tipo de *sistema de compilação* para gerenciar complexidades de compilação de vários arquivos de origem para várias configurações (debug vs. Release), várias plataformas (x86, x64, ARM e assim por diante), etapas de compilação personalizadas e até mesmo vários executáveis que devem ser compilados em uma determinada ordem. As configurações são feitas em um ou mais arquivos de configuração de compilação, e o sistema de compilação aceita esse arquivo como entrada antes de invocar o compilador. O conjunto de arquivos de código-fonte e arquivos de configuração de compilação necessários para criar um arquivo executável é chamado de *projeto*.

A lista a seguir mostra várias opções para projetos do Visual Studio-C++:

- Crie um projeto do Visual Studio usando o IDE do Visual Studio e configure-o usando páginas de propriedades. Os projetos do Visual Studio produzem programas que são executados no Windows. Para obter uma visão geral, consulte [compilando e compilando](/visualstudio/ide/compiling-and-building-in-visual-studio) na documentação do Visual Studio.

- Abra uma pasta que contenha um arquivo de CMakeLists.txt. O suporte do CMake é integrado ao Visual Studio. Você pode usar o IDE para editar, testar e depurar sem modificar os arquivos CMake de forma alguma. Isso permite que você trabalhe no mesmo projeto CMake que outras pessoas que podem estar usando editores diferentes. CMake é a abordagem recomendada para o desenvolvimento de plataforma cruzada. Para obter mais informações, consulte [projetos do cmake](cmake-projects-in-visual-studio.md).

- Abra uma pasta flexível de arquivos de origem sem arquivo de projeto. O Visual Studio usará a heurística para criar os arquivos. Essa é uma maneira fácil de compilar e executar pequenos aplicativos de console. Para obter mais informações, consulte [abrir projetos de pasta](open-folder-projects-cpp.md).

- Abra uma pasta que contenha um makefile ou qualquer outro arquivo de configuração do sistema de compilação. Você pode configurar o Visual Studio para invocar qualquer comando de Build arbitrário Adicionando arquivos JSON à pasta. Para obter mais informações, consulte [abrir projetos de pasta](open-folder-projects-cpp.md).

- Abra um Makefile do Windows no Visual Studio. Para obter mais informações, consulte [referência de NMAKE](reference/nmake-reference.md).

## <a name="msbuild-from-the-command-line"></a>MSBuild da linha de comando

Você pode invocar o MSBuild na linha de comando passando-o um arquivo. vcxproj juntamente com as opções de linha de comando. Essa abordagem requer uma boa compreensão do MSBuild e é recomendada somente quando necessário. Para mais informações, consulte [MSBuild](msbuild-visual-cpp.md).

## <a name="in-this-section"></a>Nesta seção

[Projetos do Visual Studio](creating-and-managing-visual-cpp-projects.md)\
Como criar, configurar e criar projetos C++ no Visual Studio usando seu MSBuild (sistema de compilação nativa).

[Projetos do CMake](cmake-projects-in-visual-studio.md)\
Como codificar, compilar e implantar projetos CMake no Visual Studio.

[Abrir projetos de pasta](open-folder-projects-cpp.md)\
Como usar o Visual Studio para codificar, criar e implantar projetos C++ com base em qualquer sistema de compilação arbitrário, ou sem nenhum sistema de compilação.

[Builds de versão](release-builds.md)\
Como criar e solucionar problemas de builds de versão otimizados para implantação para usuários finais.

[Usar o conjunto de ferramentas MSVC da linha de comando](building-on-the-command-line.md)\
Discute como usar o compilador C/C++ e as ferramentas de compilação diretamente da linha de comando em vez de usar o IDE do Visual Studio.

[Criando DLLs no Visual Studio](dlls-in-visual-cpp.md)\
Como criar, depurar e implantar DLLs C/C++ (bibliotecas compartilhadas) no Visual Studio.

[Walkthrough: Criando e usando uma biblioteca estática](walkthrough-creating-and-using-a-static-library-cpp.md)\
Como criar um arquivo binário **. lib** .

[Criando aplicativos isolados C/C++ e assemblies lado a lado](building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)\
Descreve o modelo de implantação de aplicativos para Windows Desktop, com base na ideia de aplicativos isolados e assemblies lado a lado.

[Configurar projetos C++ para destinos de 64 bits, x64](configuring-programs-for-64-bit-visual-cpp.md)\
Como direcionar o hardware de 64 bits x64 com as ferramentas de Build do MSVC.

[Configurar projetos C++ para processadores ARM](configuring-programs-for-arm-processors-visual-cpp.md)\
Como usar as ferramentas de Build do MSVC para direcionar o hardware ARM.

[Otimizando seu código](optimizing-your-code.md)\
Como otimizar seu código de várias maneiras, incluindo otimizações guiadas por programa.

[Configurando programas para o Windows XP](configuring-programs-for-windows-xp.md)\
Como direcionar o Windows XP com as ferramentas de Build do MSVC.

[Referência de compilação do C/C++](reference/c-cpp-building-reference.md)\
Fornece links para artigos de referência sobre compilação de programa em C++, opções de compilador e vinculador, e outras ferramentas de compilação.
