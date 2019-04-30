---
title: 'Exceções: Exceções em construtores'
ms.date: 11/04/2016
helpviewer_keywords:
- constructors [MFC], exceptions
- throwing exceptions [MFC], in constructors
- exceptions [MFC], in constructors
ms.assetid: a78eae5a-5821-4b27-9478-1436320ed1e1
ms.openlocfilehash: 0b11f5be18879d5ad4b9e204bb02e18b4617c6b7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62405866"
---
# <a name="exceptions-exceptions-in-constructors"></a>Exceções: Exceções em construtores

Ao lançar uma exceção em um construtor, limpar quaisquer objetos e as alocações de memória feitas antes de lançar a exceção, conforme explicado em [exceções: Lançando exceções das suas próprias funções](../mfc/exceptions-throwing-exceptions-from-your-own-functions.md).

Ao lançar uma exceção em um construtor, a memória para o próprio objeto já foi alocada no momento em que o construtor é chamado. Portanto, o compilador automaticamente será desalocar a memória ocupada pelo objeto depois que a exceção é lançada.

Para obter mais informações, consulte [exceções: Liberando objetos em exceções](../mfc/exceptions-freeing-objects-in-exceptions.md).

## <a name="see-also"></a>Consulte também

[Tratamento de Exceção](../mfc/exception-handling-in-mfc.md)
