---
title: setjmp longjump | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: b0e21902-095d-4198-8f9a-b6326525721a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f53160a5deeb3ea0db111fc0aae7429b19b7cc86
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45703268"
---
# <a name="setjmplongjump"></a>setjmp/longjump

Quando você inclui setjmpex ou setjmp, todas as chamadas para [setjmp](../c-runtime-library/reference/setjmp.md) ou [longjmp](../c-runtime-library/reference/longjmp.md) resultará em um desenrolamento que invoca os destruidores e, finalmente, chama.  Isso difere do x86, onde incluindo resultados setjmp em cláusulas finally e destruidores não está sendo invocados.

Uma chamada para `setjmp` preserva o ponteiro de pilha atual, os registros não voláteis e MxCsr registros.  Chamadas para `longjmp` volte para a mais recente `setjmp` chamar site e redefine o ponteiro de pilha, registros não voláteis e MxCsr registra, volta ao estado conforme preservado por mais recente `setjmp` chamar.

## <a name="see-also"></a>Consulte também

[Convenção de chamada](../build/calling-convention.md)