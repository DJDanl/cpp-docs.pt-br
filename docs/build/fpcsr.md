---
title: FpCsr | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: dff95d5d-7589-4432-82db-64b459c24352
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9defb41a026b32acb4375185f14c903788b91a23
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="fpcsr"></a>FpCsr
O estado do registro também inclui o x87 palavra de controle FPU. A convenção de chamada impõe esse registro para ser não-volátil.  
  
 O x87 registro de palavra de controle de FPU está definido para os seguintes valores padrão no início da execução do programa:  
  
```  
FPCSR[0:6]: Exception masks all 1's (all exceptions masked)  
FPCSR[7]: Reserved - 0  
FPCSR[8:9]: Precision Control - 10B (double precision)  
FPCSR[10:11]: Rounding  control - 0 (round to nearest)  
FPCSR[12]: Infinity control - 0 (not used)  
```  
  
 Um receptor que modifica qualquer um dos campos dentro de FPCSR necessário restaurá-los antes de retornar ao chamador. Além disso, um chamador que modificou a qualquer um desses campos deve restaurá-los para seus valores padrão antes de chamar um receptor, a menos que o contrato o receptor espera que os valores modificados.  
  
 Há duas exceções às regras sobre o não-volatilidade dos sinalizadores de controle:  
  
1.  Em funções em que a finalidade documentada da função fornecida é modificar a FpCsr não volátil sinalizadores.  
  
2.  Quando é provavelmente correto que a violação dessas regras resulta em um programa que se comporta/significa que o mesmo que um programa em que essas regras não forem violadas, por exemplo, por meio de análise de programa inteiro.  
  
## <a name="see-also"></a>Consulte também  
 [Convenção de chamada](../build/calling-convention.md)