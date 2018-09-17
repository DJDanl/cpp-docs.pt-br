---
title: Ferramentas de Build do C/C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- c.build
dev_langs:
- C++
helpviewer_keywords:
- builds [C++], C/C++ tools
- tools [C++], build
ms.assetid: 48d9daf4-6bbf-473a-8ce2-bf2923b69f80
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1a6a223e092e7ad31dd263142d2a87712eaf556b
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45726031"
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