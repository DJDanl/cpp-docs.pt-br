---
title: . SE | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: .IF
dev_langs: C++
helpviewer_keywords: .IF directive
ms.assetid: dccc7615-8fc7-4829-9f39-0ee405f6c1e3
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2883ae63664248fdce054b39dd9291a6c1d7c431
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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