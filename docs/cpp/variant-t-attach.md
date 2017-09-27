---
title: _variant_t::Attach | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _variant_t::Attach
- _variant_t.Attach
dev_langs:
- C++
helpviewer_keywords:
- Attach method
- VARIANT object, attach
- VARIANT object
ms.assetid: 2f02bd08-2306-4477-aa88-d2a5dee2b859
caps.latest.revision: 6
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
ms.openlocfilehash: 33e21d3bea71c80b8b60df222682fda560fbce9c
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="varianttattach"></a>_variant_t::Attach
**Seção específica da Microsoft**  
  
 Anexa uma **VARIANT** objeto para o `_variant_t` objeto.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      void Attach(  
   VARIANT& varSrc   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *varSrc*  
 Um **VARIANT** objeto a ser anexado a este `_variant_t` objeto.  
  
## <a name="remarks"></a>Comentários  
 Apropriar-se do **VARIANT** encapsulando-lo. Essa função de membro libera existente encapsulado **VARIANT**, copia fornecido **VARIANT**e define seu **VARTYPE** para `VT_EMPTY` para garantir que seu recursos apenas podem ser liberados pelo `_variant_t` destruidor.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _variant_t](../cpp/variant-t-class.md)
