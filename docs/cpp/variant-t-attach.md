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
ms.openlocfilehash: 93c4ec0b4d25f1ca0ec03d9aae1dd9e1c16b79a9
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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