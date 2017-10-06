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
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 402d8bfeb6aea45460124bdeaaa8b3ee485df622
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
