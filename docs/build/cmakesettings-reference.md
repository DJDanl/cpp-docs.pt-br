---
title: Referência de esquema de CMakeSettings.json
ms.date: 03/05/2019
helpviewer_keywords:
- CMake in Visual C++
ms.assetid: 444d50df-215e-4d31-933a-b41841f186f8
ms.openlocfilehash: d80829b1475e8718e1c4188ff4fb7d42a1d4b3b9
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824593"
---
# <a name="cmakesettingsjson-schema-reference"></a>Referência de esquema de CMakeSettings.json

O arquivo `cmakesettings.json` contém informações que especificam como o Visual Studio deve interagir com o CMake para compilar um projeto de uma plataforma específica. Use esse arquivo para armazenar informações como variáveis de ambiente ou argumentos para o ambiente cmake.exe.

## <a name="environments"></a>Ambientes

A matriz `environments` contém uma lista de `items` do tipo `object` que define um "ambiente". Um ambiente pode ser usado para aplicar um conjunto de variáveis a uma `configuration`. Cada item na matriz `environments` consiste em:

- `namespace`: dá um nome ao ambiente de modo que suas variáveis possam ser referenciadas de uma configuração na forma `namespace.variable`. O objeto de ambiente padrão é chamado `env` e é preenchido com determinadas variáveis de ambiente do sistema, incluindo `%USERPROFILE%`.
- `environment`: identifica exclusivamente este grupo de variáveis. Permite que o grupo seja herdado posteriormente em uma entrada `inheritEnvironments`.
- `groupPriority`: Um inteiro que especifica a prioridade dessas variáveis ao avaliá-las. Itens de maior número são avaliados primeiro.
- `inheritEnvironments`: Uma matriz de valores que especificam o conjunto de ambientes herdados por esse grupo. Qualquer ambiente personalizado pode ser usado ou use estes ambientes predefinidos:
 
  - linux_arm: direcione ao ARM Linux remotamente.
  - linux_x64: direcione ao Linux x64 remotamente.
  - linux_x86: direcione ao Linux x86 remotamente.
  - msvc_arm: direcione o Windows ARM com o compilador MSVC.
  - msvc_arm_x64: direcione o Windows ARM com o compilador MSVC de 64 bits.
  - msvc_arm64: direcione o Windows ARM64 com o compilador MSVC.
  - msvc_arm64_x64: direcione o Windows ARM64 com o compilador MSVC de 64 bits.
  - msvc_x64: direcione o Windows x64 com o compilador MSVC.
  - msvc_x64_x64: direcione o Windows x64 com o compilador MSVC de 64 bits.
  - msvc_x86: direcione o Windows x86 com o compilador MSVC.
  - msvc_x86_x64: direcione o Windows x86 com o compilador MSVC de 64 bits.

## <a name="configurations"></a>Configurações

A matriz `configurations` consiste em objetos que representam as configurações do CMake que se aplicam ao arquivo CMakeLists.txt na mesma pasta. Você pode usar esses objetos para definir várias configurações de build e alternar convenientemente entre elas no IDE. 

Um `configuration` tem estas propriedades:
- `name`: dá um nome à configuração.
- `description`: a descrição dessa configuração que será exibida nos menus.
- `generator`: especifica o gerador do CMake a ser usado para essa configuração. Pode ser um destes:

  - Visual Studio 15 2017
  - Visual Studio 15 2017 Win64
  - Visual Studio 15 2017 ARM
  - Visual Studio 14 2015
  - Visual Studio 14 2015 Win64
  - Visual Studio 14 2015 ARM
  - Unix Makefiles
  - Ninja

- `configurationType`: especifica a configuração do tipo de build para o gerador selecionado. Pode ser um destes:
 
  - Depurar
  - Versão
  - MinSizeRel
  - RelWithDebInfo
 
- `inheritEnvironments`: especifica um ou mais ambientes de que essa configuração depende. Pode ser qualquer ambiente personalizado ou um dos ambientes predefinidos.
- `buildRoot`: especifica o diretório no qual o CMake gera scripts de build para o gerador escolhido. Macros com suporte incluem `${workspaceRoot}`, `${workspaceHash}`, `${projectFile}`, `${projectDir}`, `${thisFile}`, `${thisFileDir}`, `${name}`, `${generator}`, `${env.VARIABLE}`."
- `installRoot`: especifica o diretório no qual o CMake gera destinos de instalação para o gerador escolhido. Macros com suporte incluem `${workspaceRoot}`, `${workspaceHash}`, `${projectFile}`, `${projectDir}`, `${thisFile}`, `${thisFileDir}`, `${name}`, `${generator}`, `${env.VARIABLE}`."
- `cmakeCommandArgs`: especifica opções de linha de comando adicionais passadas para o CMake quando invocadas para gerar o cache."
- `cmakeToolchain`: especifica o arquivo de cadeia de ferramentas. Isso é passado para o CMake usando -DCMAKE_TOOLCHAIN_FILE."
- `buildCommandArgs`: especifica as opções de build nativas passaram para CMake depois de --build --."
- `ctestCommandArgs`: especifica opções de linha de comando adicionais passadas para CTest ao executar os testes."
- `codeAnalysisRuleset`: especifica o conjunto de regras para usar ao executar a análise de código. Esse pode ser um caminho completo ou o nome do arquivo de um arquivo de conjunto de regras instalado pelo Visual Studio."
- `intelliSenseMode`: especifica o modo usado para computar informações do IntelliSense". Pode ser um destes:
 
  - windows-msvc-x86
  - windows-msvc-x64
  - windows-msvc-arm
  - windows-msvc-arm64
  - android-clang-x86
  - android-clang-x64
  - android-clang-arm
  - android-clang-arm64
  - ios-clang-x86
  - ios-clang-x64
  - ios-clang-arm
  - ios-clang-arm64
  - windows-clang-x86
  - windows-clang-x64
  - windows-clang-arm
  - windows-clang-arm64
  - linux-gcc-x86
  - linux-gcc-x64
  - linux-gcc-arm"

- `cacheRoot`: especifica o caminho para um cache do CMake. Esse diretório deve conter um arquivo CMakeCache.txt existente.
- `remoteMachineName`: especifica o nome do computador Linux remoto que hospeda o CMake, builds e o depurador. Use o Gerenciador de Conexões para a adição de novos computadores Linux. Macros com suporte incluem `${defaultRemoteMachineName}`.
- `remoteCopySourcesOutputVerbosity`: especifica o nível de detalhes da fonte que copia a operação no computador remoto. Pode ser um entre "Normal", "Detalhado" ou "Diagnóstico".
- `remoteCopySourcesConcurrentCopies`: especifica o número de cópias simultâneas usadas durante a sincronização das fontes com o computador remoto.
- `remoteCopySourcesMethod`: especifica o método para copiar os arquivos para o computador remoto. Pode ser "rsync" ou "sftp".
- `remoteCMakeListsRoot`: especifica o diretório no computador remoto que contém o projeto do CMake. Macros com suporte incluem `${workspaceRoot}`, `${workspaceHash}`, `${projectFile}`, `${projectDir}`, `${thisFile}`, `${thisFileDir}`, `${name}`, `${generator}`, `${env.VARIABLE}`.
- `remoteBuildRoot`: especifica o diretório no computador remoto no qual o CMake gera scripts de build para o gerador escolhido. Macros com suporte incluem `${workspaceRoot}`, `${workspaceHash}`, `${projectFile}`, `${projectDir}`, `${thisFile}`, `${thisFileDir}`, `${name}`, `${generator}`, `${env.VARIABLE}`.
- `remoteInstallRoot`: especifica o diretório no computador remoto no qual o CMake gera destinos de instalação para o gerador escolhido. Macros com suporte incluem `${workspaceRoot}`, `${workspaceHash}`, `${projectFile}`, `${projectDir}`, `${thisFile}`, `${thisFileDir}`, `${name}`, `${generator}` e `${env.VARIABLE}`, em que `VARIABLE` é uma variável de ambiente definida no nível do sistema, do usuário ou da sessão.
- `remoteCopySources`: Um `boolean` que especifica se o Visual Studio deve copiar arquivos de origem para o computador remoto. O padrão é true. Defina como false se você mesmo gerenciar a sincronização de arquivos.
- `remoteCopyBuildOutput`: Um `boolean` que especifica se é preciso copiar as saídas de build do sistema remoto.
- `rsyncCommandArgs`: especifica um conjunto de opções adicionais de linha de comando passadas para rsync.
- `remoteCopySourcesExclusionList`: Um `array` que especifica uma lista de caminhos a serem excluídos ao copiar arquivos de origem: um caminho pode ter o nome de um arquivo/diretório ou um caminho relativo à raiz da cópia. Curingas \\\"*\\\" e \\\"?\\\" podem ser usados para correspondência de padrões glob.
- `cmakeExecutable`: especifica o caminho completo para o executável do programa do CMake, incluindo o nome e a extensão do arquivo.
- `remotePreGenerateCommand`: especifica o comando a ser executado antes da execução do CMake para analisar o arquivo CMakeLists.txt.
- `remotePrebuildCommand`: especifica o comando a ser executado no computador remoto antes da compilação.
- `remotePostbuildCommand`: especifica o comando a ser executado no computador remoto após a compilação.
- `variables`: Um `array` que especifica as variáveis passadas para o CMake como -Dname1=value1 -Dname2=value2 e assim por diante. 

