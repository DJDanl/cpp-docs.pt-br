---
title: . DOSSEG | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: .DOSSEG
dev_langs: C++
helpviewer_keywords: .DOSSEG directive
ms.assetid: 175ad470-0a2b-4e2b-b078-65e224fec040
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 4d2156161686583ba00d357c1dbca2e2e2867e9b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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