---
title: Classes de depuração e exceção | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- vc.classes.debug
dev_langs:
- C++
helpviewer_keywords:
- debugging [MFC], exception classes
- debugging [MFC], classes for debugging
ms.assetid: 0d158efd-2e62-452e-9d2a-d3c30dfee7f9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9adf6a585771336de9fb33abbebdd6bab97383ed
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="debugging-and-exception-classes"></a>Classes de depuração e exceção
Essas classes oferecem suporte para depuração de alocação de memória dinâmica e para transmitir informações de exceção da função em que a exceção é gerada para a função em que é capturada.  
  
 Usar classes [CDumpContext](../mfc/reference/cdumpcontext-class.md) e [CMemoryState](../mfc/reference/cmemorystate-structure.md) durante o desenvolvimento para ajudar na depuração, conforme descrito em [aplicativos do MFC de depuração](/visualstudio/debugger/mfc-debugging-techniques). Use [CRuntimeClass](../mfc/reference/cruntimeclass-structure.md) para determinar a classe de qualquer objeto em tempo de execução, conforme descrito no artigo [acessando informações de classe de tempo de execução](../mfc/accessing-run-time-class-information.md). A estrutura usa `CRuntimeClass` para criar objetos de uma determinada classe dinamicamente.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

