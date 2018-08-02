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
ms.openlocfilehash: 895df401ab10ae85641fd2eed9f7a9654916f33f
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39465216"
---
# <a name="varianttdetach"></a>_variant_t::Detach
**Seção específica da Microsoft**  
  
 Desanexa encapsulado `VARIANT` objeto deste `_variant_t` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
VARIANT Detach( );  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Encapsulado `VARIANT`.  
  
## <a name="remarks"></a>Comentários  
 Extrai e retorna encapsulado `VARIANT`, em seguida, limpa esse `_variant_t` objeto sem destruí-lo. Essa função membro remove os `VARIANT` do encapsulamento e define o `VARTYPE` isso `_variant_t` objeto como VT_EMPTY. Cabe a você liberar retornado `VARIANT` chamando o [VariantClear](http://msdn.microsoft.com/28741d81-8404-4f85-95d3-5c209ec13835) função.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _variant_t](../cpp/variant-t-class.md)