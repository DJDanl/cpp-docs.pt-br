---
title: "Ferramentas de compilação do C/C++ | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- c.build
dev_langs:
- C++
helpviewer_keywords:
- builds [C++], C/C++ tools
- tools [C++], build
ms.assetid: 48d9daf4-6bbf-473a-8ce2-bf2923b69f80
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: b21ebd2adf20eb0812e9a0fb5b900e657f8eddc7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cc-build-tools"></a>Ferramentas de build da linguagem C/C++
Visual C++ fornece as seguintes ferramentas de linha de comando para exibir ou manipular a saída da compilação:  
  
-   [BSCMAKE. EXE](../../build/reference/bscmake-reference.md) cria um arquivo de informações de procura (. bsc) que contém informações sobre os símbolos (classes, funções, dados, macros e tipos) em seu programa. Você pode exibir essas informações no windows procurar no ambiente de desenvolvimento. (Um arquivo. bsc também pode ser criado no ambiente de desenvolvimento.)  
  
-   [LIB. EXE](../../build/reference/lib-reference.md) é usado para criar e gerenciar uma biblioteca de arquivos de objeto do formato de arquivo de objeto comum (COFF). Ele também pode ser usado para criar arquivos de exportação e bibliotecas de importação para referência exportada de definições.  
  
-   [EDITBIN. EXE](../../build/reference/editbin-reference.md) é usado para modificar os arquivos binários COFF.  
  
-   [DUMPBIN. EXE](../../build/reference/dumpbin-reference.md) exibe informações (como uma tabela de símbolos) sobre os arquivos binários COFF.  
  
-   [NMAKE](../../build/nmake-reference.md) lê e executa makefiles.  
  
-   [ERRLOOK](../../build/reference/value-edit-control.md), o utilitário de pesquisa de erro, recupera uma mensagem de erro do sistema ou a mensagem de erro do módulo com base no valor inserido.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de build do C/C++](../../build/reference/c-cpp-building-reference.md)   
 [Nomes decorados](../../build/reference/decorated-names.md)   
 [Opções do compilador](../../build/reference/compiler-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)