---
title: "Exceções: Exceções em construtores | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- constructors [MFC], exceptions
- throwing exceptions [MFC], in constructors
- exceptions [MFC], in constructors
ms.assetid: a78eae5a-5821-4b27-9478-1436320ed1e1
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 0fb42a88c60b89909f104873ff20e36192b13c69
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="exceptions-exceptions-in-constructors"></a>Exceções: exceções em construtores
Ao lançar uma exceção em um construtor, limpar quaisquer objetos e as alocações de memória feitas antes de lançar a exceção, conforme explicado em [exceções: Lançando exceções das funções próprias seu](../mfc/exceptions-throwing-exceptions-from-your-own-functions.md).  
  
 Ao lançar uma exceção em um construtor, a memória para o próprio objeto já foi alocada no momento em que o construtor é chamado. Portanto, o compilador automaticamente desalocará a memória ocupada pelo objeto depois que a exceção é gerada.  
  
 Para obter mais informações, consulte [exceções: liberando objetos em exceções](../mfc/exceptions-freeing-objects-in-exceptions.md).  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

