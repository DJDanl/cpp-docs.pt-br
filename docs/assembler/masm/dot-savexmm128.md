---
title: .SAVEXMM128 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- .SAVEXMM128
dev_langs:
- C++
helpviewer_keywords:
- .SAVEXMM128 directive
ms.assetid: 551eb472-b8d0-47b1-8d82-995d1f485723
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d50d4bbc7f9c89e9ef36a1dd8cf3dfeb56de79b5
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="savexmm128"></a>.SAVEXMM128
Gera um um `UWOP_SAVE_XMM128` ou um `UWOP_SAVE_XMM128_FAR` desenrolar a entrada de código para o registro XMM especificado e deslocamento usando o deslocamento de prólogo atual. MASM escolherá a codificação mais eficiente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
.savexmm128 xmmreg , offset  
```  
  
## <a name="remarks"></a>Comentários  
 . SAVEXMM128 permite que os usuários de ml64.exe especificar como uma função de quadro esvazia e só é permitida no prólogo, que se estende do [PROC](../../assembler/masm/proc.md) declaração de quadro para o [. ENDPROLOG](../../assembler/masm/dot-endprolog.md) diretiva. Essas diretivas não geram código; Gerar apenas `.xdata` e `.pdata`. . SAVEXMM128 deve ser precedido por instruções que as ações a ser organizado de fato implementam. É uma boa prática para encapsular as diretivas de liberação e o código que eles se destinam à liberação em uma macro para garantir o contrato.  
  
 `offset` deve ser um múltiplo de 16.  
  
 Para obter mais informações, consulte [MASM para x64 (ml64.exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)