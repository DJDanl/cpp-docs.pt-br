---
title: EXTERN (MASM) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- extern
dev_langs:
- C++
helpviewer_keywords:
- EXTERN directive
ms.assetid: 667d703d-3aaf-4139-a586-29bc5dab1aff
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7528ea78270e4976ed3b926e83fe4f9977148498
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="extern-masm"></a>EXTERN (MASM)
Define uma ou mais variáveis externas, rótulos ou símbolos chamados *nome* cujo tipo é `type`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
   EXTERN [[langtype]] name [[(altid)]] :  
type [[, [[langtype]] name [[(altid)]] :type]]...  
```  
  
## <a name="remarks"></a>Comentários  
 O `type` pode ser [ABS](../../assembler/masm/operator-abs.md), que importa *nome* como uma constante. Mesmo que [EXTRN](../../assembler/masm/extrn.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)