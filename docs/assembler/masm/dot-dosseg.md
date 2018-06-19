---
title: .DOSSEG | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- .DOSSEG
dev_langs:
- C++
helpviewer_keywords:
- .DOSSEG directive
ms.assetid: 175ad470-0a2b-4e2b-b078-65e224fec040
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3817cfe98758faf86ea87d74e02657598c3e806b
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32054878"
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