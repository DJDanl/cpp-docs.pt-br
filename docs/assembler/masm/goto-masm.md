---
title: GOTO (MASM) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- goto
dev_langs:
- C++
helpviewer_keywords:
- GOTO directive
ms.assetid: 6a5f73e7-6784-4eae-ac52-4fc77a7f369f
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: c86a9b5bc83110f20dccf73f51b1e1aabc693db2
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="goto-masm"></a>GOTO (MASM)
Transfere o assembly para a linha marcada **: * macrolabel*.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
GOTO   
macrolabel  
  
```  
  
## <a name="remarks"></a>Comentários  
 **GOTO** é permitida somente no [MACRO](../../assembler/masm/macro.md), [para](../../assembler/masm/for-masm.md), [FORC](../../assembler/masm/forc.md), [REPITA](../../assembler/masm/repeat.md), e **ao**blocos. O rótulo deve ser a única diretiva na linha e deve ser precedido por dois-pontos à esquerda.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)