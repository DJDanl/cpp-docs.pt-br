---
title: 'Exceções: exceções em construtores'
ms.date: 11/04/2016
helpviewer_keywords:
- constructors [MFC], exceptions
- throwing exceptions [MFC], in constructors
- exceptions [MFC], in constructors
ms.assetid: a78eae5a-5821-4b27-9478-1436320ed1e1
ms.openlocfilehash: 4089f4d44f03c7de3432f137b5d28f74189e1cb9
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84624613"
---
# <a name="exceptions-exceptions-in-constructors"></a>Exceções: exceções em construtores

Ao lançar uma exceção em um construtor, Limpe quaisquer alocações de memória e objetos que você fez antes de lançar a exceção, conforme explicado em [exceções: lançar exceções de suas próprias funções](exceptions-throwing-exceptions-from-your-own-functions.md).

Ao lançar uma exceção em um construtor, a memória do objeto em si já foi alocada no momento em que o construtor é chamado. Portanto, o compilador desalocará automaticamente a memória ocupada pelo objeto depois que a exceção for gerada.

Para obter mais informações, consulte [exceções: liberando objetos em exceções](exceptions-freeing-objects-in-exceptions.md).

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](exception-handling-in-mfc.md)
