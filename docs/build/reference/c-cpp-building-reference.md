---
title: Referência de build do C/C++ - Visual Studio
description: Conteúdo de referência para ferramentas de compilação e sistema de projeto de C/C++ no Visual Studio.
ms.date: 12/10/2018
helpviewer_keywords:
- compiling source code [C++], additional information
- cl.exe compiler [C++], building programs
- linker [C++], building reference
- builds [C++], additional information
ms.assetid: 100b4ccf-572c-4d1f-970c-fa0bc0cc0d2d
ms.openlocfilehash: 4c3f7aa598a9c43af04c148ed0d4b3f555566ec7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62294753"
---
# <a name="cc-building-reference"></a>Referência de build C/C++

Visual C++ fornece duas maneiras de criar um programa C/C++. A maneira mais fácil (e mais comum) é [compilação dentro do IDE do Visual Studio](../creating-and-managing-visual-cpp-projects.md). É outra maneira [compilar em um prompt de comando usando as ferramentas de linha de comando](../building-on-the-command-line.md). Em ambos os casos, você pode criar e editar seus arquivos de origem usando o Visual Studio ou um editor de terceiros de sua escolha.

## <a name="in-this-section"></a>Nesta seção

[Referência do MSBuild para projetos C++](msbuild-visual-cpp-overview.md)

[Referência de compilador MSVC](compiling-a-c-cpp-program.md)<br/>
Descreve o compilador MSVC, que cria um arquivo de objeto que contém o código de máquina, diretivas de vinculador, seções, as referências externas e nomes de função/dados.

[Referência de vinculador MSVC](linking.md)<br/>
Descreve o vinculador, que combina o código dos arquivos de objeto criados pelo compilador e de bibliotecas estaticamente vinculadas, resolve as referências de nome e cria um arquivo executável.

[Suporte Unicode no compilador e no vinculador](unicode-support-in-the-compiler-and-linker.md)

[Ferramentas de Build do MSVC adicionais](c-cpp-build-tools.md)<br/>
Ferramentas de linha de comando adicionais para C++.

[Erros de build do C/C++](../../error-messages/compiler-errors-1/c-cpp-build-errors.md)<br/>
Apresenta a seção de erros de compilação na tabela de conteúdo.

## <a name="related-sections"></a>Seções relacionadas

[Referência de pré-processador do C/C++](../../preprocessor/c-cpp-preprocessor-reference.md)<br/>
Discute o pré-processador, que prepara arquivos de origem para o compilador, convertendo de macros, operadores e diretivas.

[Noções básicas sobre etapas e eventos compilação personalizada](../understanding-custom-build-steps-and-build-events.md)<br/>
Aborda como personalizar o processo de compilação.

[Criando um programa em C/C++](../projects-and-build-systems-cpp.md)<br/>
Fornece links para tópicos que descrevem como compilar seu programa pela linha de comando ou pelo ambiente de desenvolvimento integrado do Visual Studio.

[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
Descreve as opções de compilador de configuração no ambiente de desenvolvimento ou na linha de comando.

[Opções do compilador MSVC](compiler-options.md)<br/>
Fornece links para tópicos que abordam o uso de opções do compilador.

[Referência de vinculador MSVC](linking.md)<br/>
Descreve as opções de vinculador de configuração dentro ou fora do ambiente de desenvolvimento integrado.

[Opções de vinculador MSVC](linker-options.md)<br/>
Fornece links para tópicos que abordam o uso de opções do vinculador.

[Referência de BSCMAKE](bscmake-reference.md)<br/>
Descreve o utilitário de manutenção de informações de procura da Microsoft (BSCMAKE. EXE), que cria um arquivo de informações de procura (. bsc) do. SBR arquivos criados durante a compilação.

[Referência de LIB](lib-reference.md)<br/>
Descreve o Gerenciador de biblioteca da Microsoft (LIB.exe), que cria e gerencia uma biblioteca de arquivos de objeto comum objeto COFF (File Format).

[Referência de EDITBIN](editbin-reference.md)<br/>
Descreve o Editor de arquivo binário COFF da Microsoft (EDITBIN. EXE), que modifica os arquivos binários do Common objeto COFF (File Format).

[Referência de DUMPBIN](dumpbin-reference.md)<br/>
Descreve o Dumper de arquivo binário COFF da Microsoft (DUMPBIN. EXE), que exibe informações sobre arquivos binários do Common objeto COFF (File Format).

[Referência a NMAKE](nmake-reference.md)<br/>
Descreve o utilitário de manutenção do programa da Microsoft (NMAKE. EXE), que é uma ferramenta que compila projetos com base em comandos contidos em um arquivo de descrição.
