---
title: longjump setjmp
ms.date: 11/04/2016
ms.assetid: b0e21902-095d-4198-8f9a-b6326525721a
ms.openlocfilehash: 765cef3f02bed09bed0278aaeecdcdbd55d86b67
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50427892"
---
# <a name="setjmplongjump"></a>setjmp/longjump

Quando você inclui setjmpex ou setjmp, todas as chamadas para [setjmp](../c-runtime-library/reference/setjmp.md) ou [longjmp](../c-runtime-library/reference/longjmp.md) resultará em um desenrolamento que invoca os destruidores e, finalmente, chama.  Isso difere do x86, onde incluindo resultados setjmp em cláusulas finally e destruidores não está sendo invocados.

Uma chamada para `setjmp` preserva o ponteiro de pilha atual, os registros não voláteis e MxCsr registros.  Chamadas para `longjmp` volte para a mais recente `setjmp` chamar site e redefine o ponteiro de pilha, registros não voláteis e MxCsr registra, volta ao estado conforme preservado por mais recente `setjmp` chamar.

## <a name="see-also"></a>Consulte também

[Convenção de chamada](../build/calling-convention.md)