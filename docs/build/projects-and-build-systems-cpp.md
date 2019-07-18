---
title: C/C++ projetos e sistemas de compilação no Visual Studio
ms.description: Use Visual Studio to compile and build C++ projects for Windows, ARM or Linux based on any project system.
ms.date: 07/17/2019
helpviewer_keywords:
- builds [C++]
- C++ projects, building
- projects [C++], building
- builds [C++], options
- C++, build options
ms.assetid: fa6ed4ff-334a-4d99-b5e2-a1f83d2b3008
ms.openlocfilehash: 672dea77c4165ddcd84d3253525dc8c2d8be3e7c
ms.sourcegitcommit: 610751254a01cba6ad15fb1e1764ecb2e71f66bf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/18/2019
ms.locfileid: "68313184"
---
# <a name="cc-projects-and-build-systems-in-visual-studio"></a>C/C++ projetos e sistemas de compilação no Visual Studio

Você pode usar o Visual Studio para editar, compilar e compilar C++ qualquer base de código com suporte total ao IntelliSense sem a necessidade de converter esse código em um projeto do Visual Studio ou compilar com o conjunto de ferramentas MSVC. Por exemplo, você pode editar um projeto CMake de plataforma cruzada no Visual Studio em um computador Windows e compilá-lo para Linux usando o g + + em um computador Linux remoto.

## <a name="c-compilation"></a>C++ocorrida

*Criar* um programa C++ significa compilar o código-fonte de um ou mais arquivos e, em seguida, vincular esses arquivos a um arquivo executável (. exe), uma biblioteca de carregamento dinâmico (. dll) ou uma biblioteca estática (. lib). 

A C++ compilação básica envolve três etapas principais:

- O C++ pré-processador transforma todas as definições de #directives e macro em cada arquivo de origem. Isso cria uma *unidade de tradução*.
- O C++ compilador compila cada unidade de tradução em arquivos de objeto (. obj), aplicando quaisquer opções de compilador definidas.
- O *vinculador* mescla os arquivos de objeto em um único executável, aplicando as opções de vinculador que foram definidas. 

## <a name="the-msvc-toolset"></a>O conjunto de ferramentas MSVC

O compilador C++ da Microsoft, o vinculador, as bibliotecas padrão e os utilitários relacionados incluem o conjunto de ferramentas do compilador MSVC (também chamado de ferramentas ou "ferramentas de Build"). Eles estão incluídos no Visual Studio. Você também pode baixar e usar o conjunto de ferramentas como um pacote autônomo gratuitamente nas [ferramentas de Build para o local de download do Visual Studio 2019](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2019).

Você pode criar programas simples invocando o compilador MSVC (CL. exe) diretamente da linha de comando. O comando a seguir aceita um único arquivo de código-fonte e invoca o CL. exe para criar um executável chamado *Hello. exe*: 

```cmd
cl /EHsc hello.cpp
```
Observe que, aqui, o compilador (CL. exe) invoca automaticamente C++ o pré-processador e o vinculador para produzir o arquivo de saída final.  Para obter mais informações, consulte [criando na linha de comando](building-on-the-command-line.md).

## <a name="build-systems-and-projects"></a>Compilar sistemas e projetos

A maioria dos programas do mundo real usa algum tipo de *sistema de compilação* para gerenciar complexidades de compilação de vários arquivos de origem para várias configurações (por exemplo, depuração vs. versão), várias plataformas (x86, x64, ARM e assim por diante), etapas de compilação personalizadas e até mesmo várias executáveis que devem ser compilados em uma determinada ordem. As configurações são feitas em um ou mais arquivos de configuração de compilação, e o sistema de compilação aceita esse arquivo como entrada antes de invocar o compilador. O conjunto de arquivos de código-fonte e arquivos de configuração de compilação necessários para criar um arquivo executável é chamado de *projeto*. 

A lista a seguir mostra várias opções para projetos do Visual C++Studio:

- Crie um projeto do Visual Studio usando o IDE do Visual Studio e configure-o usando páginas de propriedades. Os projetos do Visual Studio produzem programas que são executados no Windows. Para obter uma visão geral, consulte [compilando e compilando](/visualstudio/ide/compiling-and-building-in-visual-studio) na documentação do Visual Studio.

- Abra uma pasta que contenha um arquivo CMakeLists. txt. O suporte do CMake é integrado ao Visual Studio. Você pode usar o IDE para editar, testar e depurar sem modificar os arquivos CMake de forma alguma. Isso permite que você trabalhe no mesmo projeto CMake que outras pessoas que podem estar usando editores diferentes. CMake é a abordagem recomendada para o desenvolvimento de plataforma cruzada. Para obter mais informações, consulte [projetos do cmake](cmake-projects-in-visual-studio.md).
 
- Abra uma pasta flexível de arquivos de origem sem arquivo de projeto. O Visual Studio usará a heurística para criar os arquivos. Essa é uma maneira fácil de compilar e executar pequenos aplicativos de console. Para obter mais informações, consulte [abrir projetos de pasta](open-folder-projects-cpp.md).

- Abra uma pasta que contenha um makefile ou qualquer outro arquivo de configuração do sistema de compilação. Você pode configurar o Visual Studio para invocar qualquer comando de Build arbitrário Adicionando arquivos JSON à pasta. Para obter mais informações, consulte [abrir projetos de pasta](open-folder-projects-cpp.md).
 
- Abra um Makefile do Windows no Visual Studio. Para obter mais informações, consulte [referência de NMAKE](reference/nmake-reference.md).

## <a name="msbuild-from-the-command-line"></a>MSBuild da linha de comando 

Você pode invocar o MSBuild na linha de comando passando-o um arquivo. vcxproj juntamente com as opções de linha de comando. Essa abordagem requer uma boa compreensão do MSBuild e é recomendada somente quando absolutamente necessário. Para mais informações, consulte [MSBuild](msbuild-visual-cpp.md).

## <a name="in-this-section"></a>Nesta seção

[Projetos do Visual Studio](creating-and-managing-visual-cpp-projects.md) Como criar, configurar e compilar C++ projetos no Visual Studio usando seu MSBuild (sistema de compilação nativa).

[Projetos do cmake](cmake-projects-in-visual-studio.md) Como codificar, compilar e implantar projetos CMake no Visual Studio.

[Abrir projetos de pasta](open-folder-projects-cpp.md) Como usar o Visual Studio para codificar, compilar e implantar C++ projetos com base em qualquer sistema de compilação arbitrário ou sem sistema de compilação. Absolutamente. 

[Builds de versão](release-builds.md) Como criar e solucionar problemas de builds de versão otimizados para implantação para usuários finais.

[Uso do conjunto de ferramentas MSVC da linha de comando](building-on-the-command-line.md)<br/>
Discute como usar o C/C++ compilador e as ferramentas de compilação diretamente da linha de comando em vez de usar o IDE do Visual Studio.

[Criando DLLs no Visual Studio](dlls-in-visual-cpp.md) Como criar, depurar e implantar C/C++ DLLs (bibliotecas compartilhadas) no Visual Studio.

[Passo a passo: Criando e usando uma biblioteca](walkthrough-creating-and-using-a-static-library-cpp.md) estática como criar um arquivo binário. lib.

[Criando aplicativos CC++ /isolados e assemblies lado a lado](building-c-cpp-isolated-applications-and-side-by-side-assemblies.md) Descreve o modelo de implantação para aplicativos da área de trabalho do Windows, com base na ideia de aplicativos isolados e assemblies lado a lado.

[Configurar C++ projetos para destinos de 64 bits, x64](configuring-programs-for-64-bit-visual-cpp.md) Como direcionar o hardware de 64 bits x64 com as ferramentas de Build do MSVC.

[Configurar C++ projetos para processadores ARM](configuring-programs-for-arm-processors-visual-cpp.md) Como usar as ferramentas de Build do MSVC para direcionar o hardware ARM.

[Otimizando seu código](optimizing-your-code.md) Como otimizar seu código de várias maneiras, incluindo otimizações guiadas por programa.

[Configurando programas para o Windows XP](configuring-programs-for-windows-xp.md) Como direcionar o Windows XP com as ferramentas de Build do MSVC.

[Referência de build C/C++](reference/c-cpp-building-reference.md)<br/>
Fornece links para artigos de referência sobre compilação de programa em C++, opções de compilador e vinculador, e outras ferramentas de compilação.
