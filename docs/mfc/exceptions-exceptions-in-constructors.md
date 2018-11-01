---
title: 'Exceções: exceções em construtores'
ms.date: 11/04/2016
helpviewer_keywords:
- constructors [MFC], exceptions
- throwing exceptions [MFC], in constructors
- exceptions [MFC], in constructors
ms.assetid: a78eae5a-5821-4b27-9478-1436320ed1e1
ms.openlocfilehash: 23d1f6a9a3c76cc9c0c1d4aebd5c0b0ea45c3154
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50472261"
---
# <a name="exceptions-exceptions-in-constructors"></a>Exceções: exceções em construtores

Ao lançar uma exceção em um construtor, limpar quaisquer objetos e as alocações de memória feitas antes de lançar a exceção, conforme explicado em [exceções: Lançando exceções das funções próprias Your](../mfc/exceptions-throwing-exceptions-from-your-own-functions.md).

Ao lançar uma exceção em um construtor, a memória para o próprio objeto já foi alocada no momento em que o construtor é chamado. Portanto, o compilador automaticamente será desalocar a memória ocupada pelo objeto depois que a exceção é lançada.

Para obter mais informações, consulte [exceções: liberando objetos em exceções](../mfc/exceptions-freeing-objects-in-exceptions.md).

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)

