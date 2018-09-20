---
title: Referência de build do C/C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- compiling source code [C++], additional information
- cl.exe compiler [C++], building programs
- linker [C++], building reference
- builds [C++], additional information
ms.assetid: 100b4ccf-572c-4d1f-970c-fa0bc0cc0d2d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5935c0642ba0cd69992c68c521d284c3e8733ce4
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46390026"
---
# <a name="cc-building-reference"></a>Referência de build C/C++

Visual C++ fornece duas maneiras de criar um programa C/C++. A maneira mais fácil (e mais comum) é [compilação dentro do ambiente de desenvolvimento do Visual C++](../../ide/building-cpp-projects-in-visual-studio.md). É outra maneira [compilar em um prompt de comando usando as ferramentas de linha de comando](../../build/building-on-the-command-line.md). Em ambos os casos, você pode criar os arquivos de origem usando o editor de código-fonte do Visual C++ ou um editor de terceiros de sua escolha.

Se seu programa usa um makefile, em vez de um arquivo. vcxproj, você ainda pode compilá-lo no ambiente de desenvolvimento como um [projeto externo](../../ide/building-external-projects.md).

## <a name="in-this-section"></a>Nesta seção

[Compilando um programa do C/C++](../../build/reference/compiling-a-c-cpp-program.md)<br/>
Descreve o compilador, que cria um arquivo de objeto que contém o código de máquina, diretivas de vinculador, seções, as referências externas e nomes de função/dados.

[Vinculação](../../build/reference/linking.md)<br/>
Descreve o vinculador, que combina o código dos arquivos de objeto criados pelo compilador e de bibliotecas estaticamente vinculadas, resolve as referências de nome e cria um arquivo executável.

[Builds de versão](../../build/reference/release-builds.md)<br/>
Apresenta informações sobre por que e quando você vai querer alterar de uma depuração de build para um build de versão e também aborda alguns dos problemas que você pode encontrar ao mudar de uma depuração para um build de versão.

[Otimizando seu código](../../build/reference/optimizing-your-code.md)<br/>
Fornece links para tópicos que abordam os mecanismos para otimizar o código:

[Ferramentas de build de C/C++](../../build/reference/c-cpp-build-tools.md)<br/>
Fornece as ferramentas de linha de comando a seguir para exibir ou manipular a saída da compilação:

[Erros de build do C/C++](../../error-messages/compiler-errors-1/c-cpp-build-errors.md)<br/>
Apresenta a seção de erros de compilação na tabela de conteúdo.

## <a name="related-sections"></a>Seções relacionadas

[Referência de pré-processador do C/C++](../../preprocessor/c-cpp-preprocessor-reference.md)<br/>
Discute o pré-processador, que prepara arquivos de origem para o compilador, convertendo de macros, operadores e diretivas.

[Noções básicas sobre etapas e eventos compilação personalizada](../../ide/understanding-custom-build-steps-and-build-events.md)<br/>
Aborda como personalizar o processo de compilação.

[Criando um programa em C/C++](../../build/building-c-cpp-programs.md)<br/>
Fornece links para tópicos que descrevem como compilar seu programa pela linha de comando ou pelo ambiente de desenvolvimento integrado do Visual Studio.

[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
Descreve as opções de compilador de configuração no ambiente de desenvolvimento ou na linha de comando.

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
Fornece links para tópicos que abordam o uso de opções do compilador.

[Definindo opções de vinculador](../../build/reference/setting-linker-options.md)<br/>
Descreve as opções de vinculador de configuração dentro ou fora do ambiente de desenvolvimento integrado.

[Opções do vinculador](../../build/reference/linker-options.md)<br/>
Fornece links para tópicos que abordam o uso de opções do vinculador.

[Referência de BSCMAKE](../../build/reference/bscmake-reference.md)<br/>
Descreve o utilitário de manutenção de informações de procura da Microsoft (BSCMAKE. EXE), que cria um arquivo de informações de procura (. bsc) do. SBR arquivos criados durante a compilação.

[Referência de LIB](../../build/reference/lib-reference.md)<br/>
Descreve o Gerenciador de biblioteca da Microsoft (LIB.exe), que cria e gerencia uma biblioteca de arquivos de objeto comum objeto COFF (File Format).

[Referência de EDITBIN](../../build/reference/editbin-reference.md)<br/>
Descreve o Editor de arquivo binário COFF da Microsoft (EDITBIN. EXE), que modifica os arquivos binários do Common objeto COFF (File Format).

[Referência de DUMPBIN](../../build/reference/dumpbin-reference.md)<br/>
Descreve o Dumper de arquivo binário COFF da Microsoft (DUMPBIN. EXE), que exibe informações sobre arquivos binários do Common objeto COFF (File Format).

[Referência a NMAKE](../../build/nmake-reference.md)<br/>
Descreve o utilitário de manutenção do programa da Microsoft (NMAKE. EXE), que é uma ferramenta que compila projetos com base em comandos contidos em um arquivo de descrição.