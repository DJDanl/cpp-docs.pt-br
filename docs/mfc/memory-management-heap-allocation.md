---
title: 'Gerenciamento de memória: Alocação do Heap | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- memory [MFC], detecting leaks
- delete operator [MFC], using with debug MFC
- heap allocation [MFC], described
- memory allocation [MFC], heap memory
- memory leaks [MFC], detecting
- new operator [MFC], using with debug MFC
- heap allocation [MFC]
- detecting memory leaks [MFC]
ms.assetid: a5d949c6-1b79-476e-9c66-513a558203d9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 99df4a50f021e0981354a5d316606729bb824d94
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="memory-management-heap-allocation"></a>Gerenciamento de memória: alocação do heap
Heap é reservado para as necessidades de alocação de memória do programa. É uma área além do código do programa e a pilha. Programas C típicos usam as funções `malloc` e **livre** para alocar e desalocar memória de heap. A versão de depuração do MFC fornece versões modificadas dos operadores internos C++ **novo** e **excluir** aloque e desaloque objetos na memória de heap.  
  
 Quando você usa **novo** e **excluir** em vez de `malloc` e **livre**, é possível tirar proveito dos aprimoramentos de depuração de gerenciamento de memória da biblioteca de classes , que pode ser útil na detecção de vazamentos de memória. Quando você cria seu programa com a versão de lançamento do MFC, as versões padrão do **novo** e **excluir** operadores fornecem uma maneira eficiente para alocar e desalocar memória (versão de lançamento do MFC não fornece versões modificadas desses operadores).  
  
 Observe que o tamanho total dos objetos alocados no heap é limitado apenas pela memória virtual disponível de seu sistema.  
  
## <a name="see-also"></a>Consulte também  
 [Gerenciamento de memória](../mfc/memory-management.md)

