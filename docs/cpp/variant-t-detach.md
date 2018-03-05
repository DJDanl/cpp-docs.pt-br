---
title: _variant_t::Detach | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _variant_t::Detach
- _variant_t.Detach
dev_langs:
- C++
helpviewer_keywords:
- VARIANT object [C++], detatch
- Detach method [C++]
- VARIANT object
ms.assetid: c348ac08-62cf-4657-a16f-974a79c12158
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 577b4874dd6d89c0c6c60b1a7981e74944e77ba8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="varianttdetach"></a>_variant_t::Detach
**Seção específica da Microsoft**  
  
 Desanexa o encapsulada **VARIANT** objeto neste `_variant_t` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
VARIANT Detach( );  
  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O encapsulada **VARIANT**.  
  
## <a name="remarks"></a>Comentários  
 Extrai e retorna o encapsulada **VARIANT**, limpa isso `_variant_t` objeto sem destruir a ele. Remove essa função de membro a **VARIANT** de encapsulamento e define o **VARTYPE** deste `_variant_t` do objeto para `VT_EMPTY`. Cabe a você libere retornado **VARIANT** chamando o [VariantClear](http://msdn.microsoft.com/en-us/28741d81-8404-4f85-95d3-5c209ec13835) função.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _variant_t](../cpp/variant-t-class.md)