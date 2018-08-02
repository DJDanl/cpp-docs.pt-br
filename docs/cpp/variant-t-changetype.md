---
title: _variant_t::ChangeType | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _variant_t::ChangeType
- _variant_t.ChangeType
dev_langs:
- C++
helpviewer_keywords:
- ChangeType method [C++]
- VARIANT object [C++], ChangeType
- VARIANT object
ms.assetid: 829d2eeb-3338-4a88-9dce-0ca145f47aac
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5f3790f4cb357ed830ba2c61b3c2906356dc64da
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39465582"
---
# <a name="varianttchangetype"></a>_variant_t::ChangeType
**Seção específica da Microsoft**  
  
 Altera o tipo dos `_variant_t` objeto a ser indicado `VARTYPE`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void ChangeType(  
   VARTYPE vartype,  
   const _variant_t* pSrc = NULL   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *VarType*  
 O `VARTYPE` para este `_variant_t` objeto.  
  
 *pSrc*  
 Um ponteiro para o objeto `_variant_t` a ser convertido. Se esse valor for NULL, a conversão é feita no lugar.  
  
## <a name="remarks"></a>Comentários  
 Essa função membro converte um `_variant_t` objeto indicado `VARTYPE`. Se *pSrc* for NULL, a conversão é feita in-loco, caso contrário `_variant_t` objeto é copiado do *pSrc* e, em seguida, convertidos.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _variant_t](../cpp/variant-t-class.md)