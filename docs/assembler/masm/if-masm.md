---
title: SE (MASM) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- if
dev_langs:
- C++
helpviewer_keywords:
- IF directive
ms.assetid: 82e43712-4f0c-4bf6-90ce-0663e81af707
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 76bf63b917a65a5a41fd261cfc861a77b0f0d16f
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="if-masm"></a>IF (MASM)
Concede o conjunto de *ifstatements* se *expression1* for true (diferente de zero) ou *elseifstatements* se *expression1* for false (0) e *expression2* é verdadeiro.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
   IF expression1  
ifstatements  
[[ELSEIF expression2  
   elseifstatements]]  
[[ELSE  
   elsestatements]]  
ENDIF  
```  
  
## <a name="remarks"></a>Comentários  
 As diretivas a seguir podem ser substituídas por [ELSEIF](../../assembler/masm/elseif-masm.md): **ELSEIFB**, **ELSEIFDEF**, **ELSEIFDIF**, **ELSEIFDIFI** , **ELSEIFE**, **ELSEIFIDN**, **ELSEIFIDNI**, **ELSEIFNB**, e **ELSEIFNDEF** . Opcionalmente, monta *elsestatements* se a expressão for falsa. Observe que as expressões são avaliadas em tempo de assembly.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)