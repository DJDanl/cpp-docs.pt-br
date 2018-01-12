---
title: _variant_t::Attach | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _variant_t::Attach
- _variant_t.Attach
dev_langs: C++
helpviewer_keywords:
- Attach method [C++]
- VARIANT object [C++], attach
- VARIANT object
ms.assetid: 2f02bd08-2306-4477-aa88-d2a5dee2b859
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: effeaaaf3f8df9eb100d5e92e760eb439a865552
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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