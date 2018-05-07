---
title: 'Exceções: Exceções em construtores | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- constructors [MFC], exceptions
- throwing exceptions [MFC], in constructors
- exceptions [MFC], in constructors
ms.assetid: a78eae5a-5821-4b27-9478-1436320ed1e1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8336700cc0137efe3bc106871ebd76b8de7a99af
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="exceptions-exceptions-in-constructors"></a>Exceções: exceções em construtores
Ao lançar uma exceção em um construtor, limpar quaisquer objetos e as alocações de memória feitas antes de lançar a exceção, conforme explicado em [exceções: Lançando exceções das funções próprias seu](../mfc/exceptions-throwing-exceptions-from-your-own-functions.md).  
  
 Ao lançar uma exceção em um construtor, a memória para o próprio objeto já foi alocada no momento em que o construtor é chamado. Portanto, o compilador automaticamente desalocará a memória ocupada pelo objeto depois que a exceção é gerada.  
  
 Para obter mais informações, consulte [exceções: liberando objetos em exceções](../mfc/exceptions-freeing-objects-in-exceptions.md).  
  
## <a name="see-also"></a>Consulte também  
 [Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

