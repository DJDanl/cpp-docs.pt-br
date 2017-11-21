---
title: "Classes de depuração e exceção | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.classes.debug
dev_langs: C++
helpviewer_keywords:
- debugging [MFC], exception classes
- debugging [MFC], classes for debugging
ms.assetid: 0d158efd-2e62-452e-9d2a-d3c30dfee7f9
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 9fb3da38c9a17ae84c42d1a2337059a3932cbf04
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="debugging-and-exception-classes"></a>Classes de depuração e exceção
Essas classes oferecem suporte para depuração de alocação de memória dinâmica e para transmitir informações de exceção da função em que a exceção é gerada para a função em que é capturada.  
  
 Usar classes [CDumpContext](../mfc/reference/cdumpcontext-class.md) e [CMemoryState](../mfc/reference/cmemorystate-structure.md) durante o desenvolvimento para ajudar na depuração, conforme descrito em [aplicativos do MFC de depuração](/visualstudio/debugger/mfc-debugging-techniques). Use [CRuntimeClass](../mfc/reference/cruntimeclass-structure.md) para determinar a classe de qualquer objeto em tempo de execução, conforme descrito no artigo [acessando informações de classe de tempo de execução](../mfc/accessing-run-time-class-information.md). A estrutura usa `CRuntimeClass` para criar objetos de uma determinada classe dinamicamente.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)

