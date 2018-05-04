---
title: Trabalhando com bibliotecas de importação e exportação de arquivos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- LIB [C++], /DEF option
- import libraries
- LIB [C++], import libraries and export files
- export files
- import libraries, creating
ms.assetid: d8175596-9773-4c2f-959d-b05b065a5161
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bc2e5b6b1f2a459d7a00e48ff1aaafff38803871
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="working-with-import-libraries-and-export-files"></a>Trabalhando com bibliotecas de importação e arquivos de exportação
Você pode usar LIB com a opção /DEF para criar uma biblioteca de importação e um arquivo de exportação. Usos LINK a exportação de arquivo para criar um programa que contenha exporta (geralmente uma biblioteca de vínculo dinâmico (DLL)), e ele usa a biblioteca de importação para resolver referências a essas exportações em outros programas.  
  
 Observe que se você criar sua biblioteca de importação em uma etapa preliminar, antes de criar o. dll, você deve passar o mesmo conjunto de arquivos de objeto ao criar o arquivo. dll, conforme passado ao criar a biblioteca de importação.  
  
 Na maioria das situações, você não precisa usar LIB para criar sua biblioteca de importação. Quando você vincula um programa (um arquivo executável ou uma DLL) que contém exportações, o LINK cria automaticamente uma biblioteca de importação que descreve as exportações. Posteriormente, quando você vincula um programa que faz referência a essas exportações, especifique a biblioteca de importação.  
  
 No entanto, quando uma DLL exporta para um programa que ele também importa de, se direta ou indiretamente, você deve usar LIB para criar uma das bibliotecas de importação. Quando o LIB cria uma biblioteca de importação, ele também cria um arquivo de exportação. Ao vincular uma das DLLs, você deve usar o arquivo de exportação.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de LIB](../../build/reference/lib-reference.md)