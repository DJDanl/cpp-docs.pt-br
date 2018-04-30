---
title: GOTO (MASM) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- goto
dev_langs:
- C++
helpviewer_keywords:
- GOTO directive
ms.assetid: 6a5f73e7-6784-4eae-ac52-4fc77a7f369f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9eecdab2fe91de0aae656b37c6fddafe658e60c0
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
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