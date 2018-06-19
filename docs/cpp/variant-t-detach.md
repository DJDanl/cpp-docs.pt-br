---
title: _variant_t::Detach | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b53d6dc51117ffe9b82511c6084e36bc49873b88
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32421934"
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