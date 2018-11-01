---
title: Ferramentas de build da linguagem C/C++
ms.date: 11/04/2016
f1_keywords:
- c.build
helpviewer_keywords:
- builds [C++], C/C++ tools
- tools [C++], build
ms.assetid: 48d9daf4-6bbf-473a-8ce2-bf2923b69f80
ms.openlocfilehash: dd698aafca3c9bc489405e0ab9cb4dcec98a26ff
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50510078"
---
# <a name="cc-build-tools"></a>Ferramentas de build da linguagem C/C++

Visual C++ fornece as seguintes ferramentas de linha de comando para exibir ou manipular a saída da compilação:

- [BSCMAKE. EXE](../../build/reference/bscmake-reference.md) cria um arquivo de informações de procura (. bsc) que contém informações sobre os símbolos (classes, funções, dados, macros e tipos) em seu programa. Você pode exibir essas informações em janelas de navegação dentro do ambiente de desenvolvimento. (Um arquivo. bsc também pode ser criado no ambiente de desenvolvimento.)

- [LIB. EXE](../../build/reference/lib-reference.md) é usado para criar e gerenciar uma biblioteca de arquivos de objeto comum objeto COFF (File Format). Ele também pode ser usado para criar arquivos de exportação e importe as bibliotecas para referenciar definições exportadas.

- [(EDITBIN). EXE](../../build/reference/editbin-reference.md) é usada para modificar os arquivos binários de COFF.

- [OPÇÃO DUMPBIN. EXE](../../build/reference/dumpbin-reference.md) exibe informações (como uma tabela de símbolo) sobre os arquivos binários de COFF.

- [NMAKE](../../build/nmake-reference.md) lê e executa makefiles.

- [ERRLOOK](../../build/reference/value-edit-control.md), o utilitário de pesquisa de erro, recupera uma mensagem de erro do sistema ou a mensagem de erro do módulo com base no valor inserido.

## <a name="see-also"></a>Consulte também

[Referência de build C/C++](../../build/reference/c-cpp-building-reference.md)<br/>
[Nomes decorados](../../build/reference/decorated-names.md)<br/>
[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Opções do vinculador](../../build/reference/linker-options.md)