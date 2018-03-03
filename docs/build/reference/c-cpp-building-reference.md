---
title: "Referência de build do C/C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- compiling source code [C++], additional information
- cl.exe compiler [C++], building programs
- linker [C++], building reference
- builds [C++], additional information
ms.assetid: 100b4ccf-572c-4d1f-970c-fa0bc0cc0d2d
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9e2269be27dd039357c11d38a2be83b5fc9d6504
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cc-building-reference"></a>Referência de build C/C++
Visual C++ fornece duas maneiras de criar um programa C/C++. A maneira mais fácil (e mais comum) é [de compilação no ambiente de desenvolvimento do Visual C++](../../ide/building-cpp-projects-in-visual-studio.md). A outra maneira é [de compilação em um prompt de comando usando as ferramentas de linha de comando](../../build/building-on-the-command-line.md). Em ambos os casos, você pode criar arquivos de origem usando o editor de código-fonte do Visual C++ ou um editor de terceiros de sua escolha.  
  
 Se seu programa usa um makefile em vez de um arquivo. vcxproj, você ainda pode criá-lo no ambiente de desenvolvimento, como um [projeto externo](../../ide/building-external-projects.md).  
  
## <a name="in-this-section"></a>Nesta seção  
 [Compilando um programa do C/C++](../../build/reference/compiling-a-c-cpp-program.md)  
 Descreve o compilador, que cria um arquivo de objeto que contém o código de máquina, diretivas de vinculador, seções, referências externas e nomes de função/dados.  
  
 [Vinculação](../../build/reference/linking.md)  
 Descreve o vinculador, que combina o código dos arquivos de objeto criados pelo compilador e bibliotecas vinculadas estaticamente, resolve as referências ao nome e cria um arquivo executável.  
  
 [Builds de versão](../../build/reference/release-builds.md)  
 Apresenta informações sobre por que e quando você deseja alterar de debug para um build de versão de compilação e também descreve alguns dos problemas que você pode encontrar ao alterar de debug para um build de versão.  
  
 [Otimizando seu código](../../build/reference/optimizing-your-code.md)  
 Fornece links para tópicos que abordam os mecanismos para otimização de código:  
  
 [Ferramentas de build de C/C++](../../build/reference/c-cpp-build-tools.md)  
 Fornece as seguintes ferramentas de linha de comando para exibir ou manipular a saída da compilação:  
  
 [Erros de build do C/C++](../../error-messages/compiler-errors-1/c-cpp-build-errors.md)  
 Apresenta a seção de erros de compilação na tabela de conteúdo.  
  
## <a name="related-sections"></a>Seções relacionadas  
 [Referência de pré-processador do C/C++](../../preprocessor/c-cpp-preprocessor-reference.md)  
 Discute o pré-processador, que prepara arquivos de origem para o compilador convertendo macros, operadores e diretivas.  
  
 [Noções básicas sobre etapas e eventos compilação personalizada](../../ide/understanding-custom-build-steps-and-build-events.md)  
 Descreve como personalizar o processo de compilação.  
  
 [Compilando um programa do C/C++](../../build/building-c-cpp-programs.md)  
 Fornece links para tópicos que descrevem como compilar seu programa pela linha de comando ou pelo ambiente de desenvolvimento integrado do Visual Studio.  
  
 [Definindo opções do compilador](../../build/reference/setting-compiler-options.md)  
 Descreve as opções de compilador de configuração no ambiente de desenvolvimento ou na linha de comando.  
  
 [Opções do Compilador](../../build/reference/compiler-options.md)  
 Fornece links para tópicos que abordam usando opções do compilador.  
  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)  
 Descreve as opções de vinculador configuração dentro ou fora do ambiente de desenvolvimento integrado.  
  
 [Opções do vinculador](../../build/reference/linker-options.md)  
 Fornece links para tópicos que abordam usando opções do vinculador.  
  
 [Referência de BSCMAKE](../../build/reference/bscmake-reference.md)  
 Descreve o utilitário de manutenção de informações de procura da Microsoft (BSCMAKE. EXE), que cria um arquivo de informações de procura (. bsc) de. SBR arquivos criados durante a compilação.  
  
 [Referência de LIB](../../build/reference/lib-reference.md)  
 Descreve o Gerenciador de biblioteca da Microsoft (LIB.exe), que cria e gerencia uma biblioteca de arquivos de objeto do formato de arquivo de objeto comum (COFF).  
  
 [Referência de EDITBIN](../../build/reference/editbin-reference.md)  
 Descreve o Editor de arquivo binário COFF da Microsoft (EDITBIN. EXE), que modifica os arquivos binários do formato de arquivo de objeto comum (COFF).  
  
 [Referência de DUMPBIN](../../build/reference/dumpbin-reference.md)  
 Descreve o Dumper de arquivo binário COFF da Microsoft (DUMPBIN. EXE), que exibe informações sobre os arquivos binários do formato de arquivo de objeto comum (COFF).  
  
 [Referência a NMAKE](../../build/nmake-reference.md)  
 Descreve o utilitário de manutenção do programa Microsoft (NMAKE. EXE), que é uma ferramenta que cria projetos com base em comandos contidos em um arquivo de descrição.