---
title: _variant_t::Attach | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _variant_t::Attach
- _variant_t.Attach
dev_langs:
- C++
helpviewer_keywords:
- Attach method [C++]
- VARIANT object [C++], attach
- VARIANT object
ms.assetid: 2f02bd08-2306-4477-aa88-d2a5dee2b859
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 42c275d085434cc8077a0629429c7c0e1cbbfcc3
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942309"
---
# <a name="varianttattach"></a>_variant_t::Attach
**Seção específica da Microsoft**  
  
 Anexa uma `VARIANT` do objeto para o `_variant_t` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
void Attach(VARIANT& varSrc);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *varSrc*  
 Um `VARIANT` o objeto a ser anexado a este `_variant_t` objeto.  
  
## <a name="remarks"></a>Comentários  
 Se apropria do `VARIANT` , encapsulando-lo. Essa função de membro libera qualquer encapsulado existente `VARIANT`, em seguida, copia fornecido `VARIANT`e define seu `VARTYPE` como VT_EMPTY para garantir que seus recursos só podem ser liberados pelo `_variant_t` destruidor.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _variant_t](../cpp/variant-t-class.md)