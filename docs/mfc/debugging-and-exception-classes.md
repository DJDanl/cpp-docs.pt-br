---
title: Classes de depuração e exceção
ms.date: 11/04/2016
f1_keywords:
- vc.classes.debug
helpviewer_keywords:
- debugging [MFC], exception classes
- debugging [MFC], classes for debugging
ms.assetid: 0d158efd-2e62-452e-9d2a-d3c30dfee7f9
ms.openlocfilehash: 6c7d1fc20556993c3c6690122786d7a767d895ad
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625932"
---
# <a name="debugging-and-exception-classes"></a>Classes de depuração e exceção

Essas classes oferecem suporte para depuração de alocação de memória dinâmica e para passar informações de exceção da função em que a exceção é gerada para a função onde ela é capturada.

Use classes [CDumpContext](reference/cdumpcontext-class.md) e [CMemoryState](reference/cmemorystate-structure.md) durante o desenvolvimento para auxiliar na depuração, conforme descrito em [Depurando aplicativos MFC](/visualstudio/debugger/mfc-debugging-techniques). Use [CRuntimeClass](reference/cruntimeclass-structure.md) para determinar a classe de qualquer objeto em tempo de execução, conforme descrito no artigo [Acessando informações de classe em tempo de execução](accessing-run-time-class-information.md). A estrutura usa `CRuntimeClass` para criar objetos de uma classe específica dinamicamente.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](class-library-overview.md)
