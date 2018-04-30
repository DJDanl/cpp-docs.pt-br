---
title: .IF | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- .IF
dev_langs:
- C++
helpviewer_keywords:
- .IF directive
ms.assetid: dccc7615-8fc7-4829-9f39-0ee405f6c1e3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7ab0e2fc510b4be8c5a9a8c0c3d0fb1c4347f0b9
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="if"></a>.IF
Gera o código que testa `condition1` (por exemplo, AX 7 >) e executa o *instruções* se a condição for true.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
   .IF condition1   
statements  
[[.ELSEIF condition2   
   statements]]  
[[.ELSE  
   statements]]  
.ENDIF  
```  
  
## <a name="remarks"></a>Comentários  
 Se um [. ELSE](../../assembler/masm/dot-else.md) segue, suas instruções é executadas se a condição original era falsa. Observe que as condições são avaliadas em tempo de execução.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)