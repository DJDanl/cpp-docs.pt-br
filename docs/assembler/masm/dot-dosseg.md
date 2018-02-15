---
title: .DOSSEG | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- .DOSSEG
dev_langs:
- C++
helpviewer_keywords:
- .DOSSEG directive
ms.assetid: 175ad470-0a2b-4e2b-b078-65e224fec040
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 39f02937ed1613cbd759621b2a4e75f84db918cf
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="dosseg"></a>.DOSSEG
Ordena os segmentos de acordo com a convenção de segmento de MS-DOS: código primeiro, segmentos, em seguida, não em DGROUP e, em seguida, segmentos no DGROUP.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
.DOSSEG  
  
```  
  
## <a name="remarks"></a>Comentários  
 Os segmentos em DGROUP siga esta ordem: segmentos BSS nem pilha, segmentos BSS e, finalmente, segmentos de pilha. Usado principalmente para garantir suporte CodeView em programas autônomos (MASM). Mesmo que [DOSSEG](../../assembler/masm/dosseg.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência de diretivas](../../assembler/masm/directives-reference.md)