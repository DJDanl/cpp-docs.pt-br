---
title: setjmp longjump | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: b0e21902-095d-4198-8f9a-b6326525721a
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: a3617f70e7c62e1845d8d24e11cebdd7738c507f
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="setjmplongjump"></a>setjmp/longjump
Quando você incluir setjmpex.h ou setjmp.h, todas as chamadas para [setjmp](../c-runtime-library/reference/setjmp.md) ou [longjmp](../c-runtime-library/reference/longjmp.md) resultará em um desenrolamento que chama destruidores e, finalmente, chama.  Isso é diferente do x86, onde incluindo setjmp.h resultados em cláusulas finally e destruidores não está sendo chamados.  
  
 Uma chamada para `setjmp` preserva o ponteiro de pilha atual, os registros não volátil e MxCsr registra.  Chamadas para `longjmp` retornar para o mais recente `setjmp` chamar site e redefine o ponteiro de pilha, os registros não volátil e MxCsr registra, para o estado como preservado por mais recente `setjmp` chamar.  
  
## <a name="see-also"></a>Consulte também  
 [Convenção de chamada](../build/calling-convention.md)