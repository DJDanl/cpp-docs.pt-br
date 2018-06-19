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
ms.openlocfilehash: 55cf6a2503367777464f09f92e3e3614c3d9f11b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32379829"
---
# <a name="setjmplongjump"></a>setjmp/longjump
Quando você incluir setjmpex.h ou setjmp.h, todas as chamadas para [setjmp](../c-runtime-library/reference/setjmp.md) ou [longjmp](../c-runtime-library/reference/longjmp.md) resultará em um desenrolamento que chama destruidores e, finalmente, chama.  Isso é diferente do x86, onde incluindo setjmp.h resultados em cláusulas finally e destruidores não está sendo chamados.  
  
 Uma chamada para `setjmp` preserva o ponteiro de pilha atual, os registros não volátil e MxCsr registra.  Chamadas para `longjmp` retornar para o mais recente `setjmp` chamar site e redefine o ponteiro de pilha, os registros não volátil e MxCsr registra, para o estado como preservado por mais recente `setjmp` chamar.  
  
## <a name="see-also"></a>Consulte também  
 [Convenção de chamada](../build/calling-convention.md)