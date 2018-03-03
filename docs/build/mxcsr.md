---
title: MxCsr | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: 4f3c229d-0862-4733-acc7-9ed7a0b870ce
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 7794cea8906440c0adca94791d08e3ced6af747e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mxcsr"></a>MxCsr
O estado do registro também inclui MxCsr. A convenção de chamada divide esse registro em uma parte voláteis e uma parte não volátil. A parte volátil consiste os sinalizadores de 6 status, MXCSR [0:5], enquanto o restante do registro, MXCSR [6:15] é considerado não volátil.  
  
 A parte não volátil é definida para os seguintes valores padrão no início da execução do programa:  
  
```  
MXCSR[6]         : Denormals are zeros - 0  
MXCSR[7:12]      : Exception masks all 1's (all exceptions masked)  
MXCSR[13:14]   : Rounding  control - 0 (round to nearest)  
MXCSR[15]      : Flush to zero for masked underflow - 0 (off)  
```  
  
 Um receptor que modifica qualquer um dos campos não volátil dentro MXCSR necessário restaurá-los antes de retornar ao chamador. Além disso, um chamador que modificou a qualquer um desses campos deve restaurá-los para seus valores padrão antes de chamar um receptor, a menos que o contrato o receptor espera que os valores modificados.  
  
 Há duas exceções às regras sobre o não-volatilidade dos sinalizadores de controle:  
  
-   Em funções em que a finalidade documentada da função fornecida é modificar a MxCsr não volátil sinalizadores.  
  
-   Quando é provavelmente correto que a violação dessas regras resulta em um programa que se comporta/significa que o mesmo que um programa em que essas regras não forem violadas, por exemplo, por meio de análise de programa inteiro.  
  
 Não pode ser feita nenhuma suposição sobre o estado da parte volátil de MXCSR em um limite de função, a menos que especificamente descrito na documentação de uma função.  
  
## <a name="see-also"></a>Consulte também  
 [Convenção de chamada](../build/calling-convention.md)