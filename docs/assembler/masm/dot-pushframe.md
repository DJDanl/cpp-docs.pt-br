---
title: .PUSHFRAME | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- .PUSHFRAME
dev_langs:
- C++
helpviewer_keywords:
- .PUSHFRAME directive
ms.assetid: 17b123d0-4c6d-4fd2-85eb-798e8ad0a73c
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 8fa9b03f1075418019f41f3d537607372bf8d498
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="pushframe"></a>.PUSHFRAME
Gera um `UWOP_PUSH_MACHFRAME` desenrolar a entrada de código. Se o valor opcional `code` for especificado, a entrada de código de desenrolamento tem um modificador de 1. Caso contrário, o modificador é 0.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
.PUSHFRAME [code]  
```  
  
## <a name="remarks"></a>Comentários  
 . PUSHFRAME permite que os usuários ml64.exe especificar como uma função de quadro esvazia e só é permitida no prólogo, que se estende do [PROC](../../assembler/masm/proc.md) declaração de quadro para o [. ENDPROLOG](../../assembler/masm/dot-endprolog.md) diretiva. Essas diretivas não geram código; Gerar apenas `.xdata` e `.pdata`. . PUSHFRAME deve ser precedido por instruções que as ações a ser organizado de fato implementam. É uma boa prática para encapsular as diretivas de liberação e o código que eles se destinam à liberação em uma macro para garantir o contrato.  
  
 Para obter mais informações, consulte [MASM para x64 (ml64.exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)