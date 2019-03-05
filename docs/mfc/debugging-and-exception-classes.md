---
title: Classes de depuração e exceção
ms.date: 11/04/2016
f1_keywords:
- vc.classes.debug
helpviewer_keywords:
- debugging [MFC], exception classes
- debugging [MFC], classes for debugging
ms.assetid: 0d158efd-2e62-452e-9d2a-d3c30dfee7f9
ms.openlocfilehash: 328d7a38c544b56f83ea3e8b1136b1122c4dfa14
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57271405"
---
# <a name="debugging-and-exception-classes"></a>Classes de depuração e exceção

Essas classes fornecem suporte para depuração de alocação de memória dinâmica, bem como para passar informações de exceção da função de onde a exceção é gerada para a função de onde ela é capturada.

Usar as classes [CDumpContext](../mfc/reference/cdumpcontext-class.md) e [CMemoryState](../mfc/reference/cmemorystate-structure.md) durante o desenvolvimento para ajudar na depuração, conforme descrito na [Depurando aplicativos do MFC](/visualstudio/debugger/mfc-debugging-techniques). Use [CRuntimeClass](../mfc/reference/cruntimeclass-structure.md) para determinar a classe de qualquer objeto em tempo de execução, conforme descrito no artigo [acessando informações de classe de tempo de execução](../mfc/accessing-run-time-class-information.md). A estrutura usa `CRuntimeClass` para criar objetos de uma determinada classe dinamicamente.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../mfc/class-library-overview.md)
