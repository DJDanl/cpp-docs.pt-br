---
title: Projetos C/C++ e sistemas de build no Visual Studio
ms.description: Use Visual Studio to compile and build C++ projects for Windows, ARM or Linux based on any project system.
ms.date: 12/08/2018
f1_keywords:
- vcbuilding
- buildingaprogramVC
helpviewer_keywords:
- builds [C++]
- Visual C++ projects, building
- projects [C++], building
- builds [C++], options
- Visual C++, build options
ms.assetid: fa6ed4ff-334a-4d99-b5e2-a1f83d2b3008
ms.openlocfilehash: 73797f3817338c48e8ff11eaaadff71263374fd0
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64341162"
---
# <a name="cc-projects-and-build-systems-in-visual-studio"></a>Projetos C/C++ e sistemas de build no Visual Studio

Você pode usar o Visual Studio 2017 para editar, compilar e criar qualquer base com suporte total ao IntelliSense de código de C++ sem a necessidade de converter esse código em um projeto do Visual Studio ou a compilação com o conjunto de ferramentas do MSVC. Por exemplo, você pode editar um projeto de CMake de plataforma cruzada no Visual Studio em um computador Windows e compilá-lo para Linux usando g + + em um computador Linux remoto.

## <a name="c-compilation"></a>Compilação de C++

Para *build* significa que um programa C++ para compilar o código-fonte de um ou mais arquivos e, em seguida, vincular esses arquivos em um arquivo executável (.exe), uma biblioteca de carga dinâmico (. dll) ou uma biblioteca estática (. lib). 

Compilação de C++ básica envolve três etapas principais:

- O pré-processador C++ transforma todas as definições de macro e #directives em cada arquivo de origem. Isso cria uma *unidade de tradução*.
- O compilador C++ compila cada unidade de tradução em arquivos de objeto (. obj), aplicando as opções de compilador foram definidas.
- O *vinculador* mescla os arquivos de objeto em um único executável, aplicando as opções do vinculador que foram definidas. 

## <a name="the-msvc-toolset"></a>O conjunto de ferramentas do MSVC

O Microsoft C++ compilador, vinculador, bibliotecas padrão e utilitários relacionados compõem o conjunto de ferramentas de compilador MSVC (também chamado de uma cadeia de ferramentas ou "ferramentas de build"). Eles estão incluídos no Visual Studio. Você também pode baixar e usar o conjunto de ferramentas como um pacote autônomo gratuito dos [local de download de ferramentas de Build do Visual Studio 2017](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2017).

Você pode criar programas simples, invocando o compilador MSVC (cl.exe) diretamente da linha de comando. O comando a seguir aceita um arquivo de código fonte única e invoca cl.exe para compilar um executável chamado *hello.exe*: 

```cmd
cl /EHsc hello.cpp
```
Observe que o compilador (cl.exe) aqui chama automaticamente o pré-processador C++ e o vinculador para produzir o arquivo de saída final.  Para obter mais informações, consulte [compilando na linha de comando](building-on-the-command-line.md).

## <a name="build-systems-and-projects"></a>Crie sistemas e projetos

A maioria dos programas do mundo real usar alguns tipos de *sistema de compilação* para gerenciar as complexidades de vários arquivos de origem para várias configurações de compilação (ou seja, de depuração versus lançamento), várias plataformas (x86, x64, ARM, e assim por diante), compilação personalizada as etapas e até mesmo vários executáveis que devem ser compilado em uma determinada ordem. Verifique as configurações em um arquivo de configuração de build (s) e o sistema de compilação aceita como entrada desse arquivo antes de ele chamar o compilador. O conjunto de arquivos de código-fonte e arquivos de configuração de build necessários para compilar um arquivo executável é chamado um *projeto*. 

A lista a seguir mostra várias opções para projetos do Visual Studio - C++:

- criar um projeto do Visual Studio usando o IDE do Visual Studio e configurá-lo por meio de páginas de propriedade. Projetos do Visual Studio produzem programas executados no Windows. Para obter uma visão geral, consulte [compilando e criando](/visualstudio/ide/compiling-and-building-in-visual-studio) na documentação do Visual Studio.

- Abra uma pasta que contém um arquivo cmakelists. txt. Suporte a CMake é integrado ao Visual Studio. Você pode usar o IDE para editar, testar e depurar sem modificar os arquivos de CMake de qualquer forma. Isso permite que você trabalhe no mesmo projeto de CMake como outras pessoas, que usam diferentes editores. CMake é a abordagem recomendada para desenvolvimento de plataforma cruzada. Para obter mais informações, consulte [projetos do CMake](cmake-projects-in-visual-studio.md).
 
- Abra uma pasta flexível de arquivos de origem sem nenhum arquivo de projeto. Visual Studio usará heurística para compilar os arquivos. Isso é uma maneira fácil de compilar e executar aplicativos de console pequeno. Para obter mais informações, consulte [projetos Abrir pasta](open-folder-projects-cpp.md).

- Abra uma pasta que contém um makefile, ou qualquer outro arquivo de configuração do sistema build. Você pode configurar o Visual Studio para invocar qualquer comando de build arbitrária, adicionando arquivos JSON para a pasta. Para obter mais informações, consulte [projetos Abrir pasta](open-folder-projects-cpp.md).
 
- Abra um makefile do Windows no Visual Studio. Para obter mais informações, consulte [referência de NMAKE](reference/nmake-reference.md).

## <a name="msbuild-from-the-command-line"></a>MSBuild na linha de comando 

Você pode invocar o MSBuild na linha de comando, passando a ele um arquivo. vcxproj juntamente com as opções de linha de comando. Essa abordagem exige uma boa compreensão do MSBuild e é recomendada somente quando absolutamente necessário. Para mais informações, consulte [MSBuild](msbuild-visual-cpp.md).

## <a name="in-this-section"></a>Nesta seção

[Projetos do Visual Studio](creating-and-managing-visual-cpp-projects.md) como criar, configurar e compilar o C++ projetos no Visual Studio usando sua nativo do sistema (MSBuild) de compilação.

[Projetos CMake](cmake-projects-in-visual-studio.md) como codificar, compilar e implantar projetos do CMake no Visual Studio.

[Abrir pasta projetos](open-folder-projects-cpp.md) como usar o Visual Studio para codificar, compilar e implantar projetos do C++ com base em qualquer sistema de build arbitrária, ou nenhum sistema de compilação. Absolutamente. 

[Builds de versão](release-builds.md) como criar e solucionar problemas de versão otimizada compilações para implantação para os usuários finais.

[Uso do conjunto de ferramentas MSVC da linha de comando](building-on-the-command-line.md)<br/>
Discute como usar o compilador C/C++ e compilar ferramentas diretamente da linha de comando em vez de usar o IDE do Visual Studio.

[Criação de DLLs no Visual Studio](dlls-in-visual-cpp.md) como criar, depurar e implantar as DLLs (bibliotecas compartilhadas) do C/C++ no Visual Studio.

[Passo a passo: Criando e usando uma biblioteca estática](walkthrough-creating-and-using-a-static-library-cpp.md) como criar um arquivo binário.

[Compilando aplicativos isolados do C/C++ e Assemblies lado a lado](building-c-cpp-isolated-applications-and-side-by-side-assemblies.md) descreve o modelo de implantação para aplicativos de área de trabalho do Windows, com base na ideia de aplicativos isolados e assemblies lado a lado.

[Configurar projetos do C++ para x64 de 64 bits, destinos](configuring-programs-for-64-bit-visual-cpp.md) como destino de 64 bits x64 hardware com o MSVC ferramentas de compilação.

[Configurar projetos do C++ para processadores ARM](configuring-programs-for-arm-processors-visual-cpp.md) como usar as ferramentas de build do MSVC para destinar hardware ARM.

[Otimizando seu código](optimizing-your-code.md) como otimizar seu código de várias maneiras, incluindo as otimizações de programa interativa.

[Configurando programas para Windows XP](configuring-programs-for-windows-xp.md) como destino, ferramentas de compilação do Windows XP com o MSVC.

[Referência de build C/C++](reference/c-cpp-building-reference.md)<br/>
Fornece links para artigos de referência sobre compilação de programa em C++, opções de compilador e vinculador, e outras ferramentas de compilação.
