---
title: . SAVEREG | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: .SAVEREG
dev_langs: C++
helpviewer_keywords: .SAVEREG directive
ms.assetid: 1dbc2ef6-a197-40e7-9e55-fddcae8cef29
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: e55abe8a5661184b022fad3f6a50dc9813cae9d8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="savereg"></a>.SAVEREG
Gera um um `UWOP_SAVE_NONVOL` ou um `UWOP_SAVE_NONVOL_FAR` desenrolar a entrada de código para o registro especificado (`reg`) e deslocamento (`offset`) usando o deslocamento de prólogo atual. MASM escolherá a codificação mais eficiente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
.SAVEREG reg, offset  
```  
  
## <a name="remarks"></a>Comentários  
 . SAVEREG permite que os usuários ml64.exe especificar como uma função de quadro esvazia e só é permitida no prólogo, que se estende do [PROC](../../assembler/masm/proc.md) declaração de quadro para o [. ENDPROLOG](../../assembler/masm/dot-endprolog.md) diretiva. Essas diretivas não geram código; Gerar apenas `.xdata` e `.pdata`. . SAVEREG deve ser precedido por instruções que as ações a ser organizado de fato implementam. É uma boa prática para encapsular as diretivas de liberação e o código que eles se destinam à liberação em uma macro para garantir o contrato.  
  
 Para obter mais informações, consulte [MASM para x64 (ml64.exe)](../../assembler/masm/masm-for-x64-ml64-exe.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)