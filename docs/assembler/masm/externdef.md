---
title: EXTERNDEF | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- EXTERNDEF
dev_langs:
- C++
helpviewer_keywords:
- EXTERNDEF directive
ms.assetid: 95a10de6-c345-4428-a2f2-90f7d411dc86
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b010f52f91a04388f34052fcc5c374690cff13df
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32052694"
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