---
title: EXTERNDEF | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: EXTERNDEF
dev_langs: C++
helpviewer_keywords: EXTERNDEF directive
ms.assetid: 95a10de6-c345-4428-a2f2-90f7d411dc86
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a06378b7cf1217c01f57d7994220bfe5dd585a66
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="externdef"></a>EXTERNDEF
Define uma ou mais variáveis externas, rótulos ou símbolos chamados *nome* cujo tipo é `type`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
EXTERNDEF [[langtype]] name:type [[, [[langtype]] name:type]]...  
```  
  
## <a name="remarks"></a>Comentários  
 Se *nome* é definido no módulo, ele será tratado como [público](../../assembler/masm/public-masm.md). Se *nome* é referenciado no módulo, ele será tratado como [EXTERN](../../assembler/masm/extern-masm.md). Se *nome* não é referenciado, ele será ignorado. O `type` pode ser [ABS](../../assembler/masm/operator-abs.md), que importa *nome* como uma constante. Normalmente usado em incluem arquivos.  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)