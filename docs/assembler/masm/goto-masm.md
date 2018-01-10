---
title: GOTO (MASM) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: goto
dev_langs: C++
helpviewer_keywords: GOTO directive
ms.assetid: 6a5f73e7-6784-4eae-ac52-4fc77a7f369f
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ed7e20bb7f81b74a2f670e604e958ca02f132531
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="goto-masm"></a>GOTO (MASM)
Transfere o assembly para a linha marcada **:***macrolabel*.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
GOTO   
macrolabel  
  
```  
  
## <a name="remarks"></a>Comentários  
 **GOTO** é permitida somente no [MACRO](../../assembler/masm/macro.md), [para](../../assembler/masm/for-masm.md), [FORC](../../assembler/masm/forc.md), [REPITA](../../assembler/masm/repeat.md), e **ao**blocos. O rótulo deve ser a única diretiva na linha e deve ser precedido por dois-pontos à esquerda.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)