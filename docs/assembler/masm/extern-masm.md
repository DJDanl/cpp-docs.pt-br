---
title: EXTERN (MASM) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: extern
dev_langs: C++
helpviewer_keywords: EXTERN directive
ms.assetid: 667d703d-3aaf-4139-a586-29bc5dab1aff
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 814922100d34534d51abed4cb682cc4181685066
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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