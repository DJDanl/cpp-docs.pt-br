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
ms.openlocfilehash: 53fd73fc9606053dda6f8c143618373ad9bb7e4e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="varianttchangetype"></a>_variant_t::ChangeType
**Seção específica da Microsoft**  
  
 Altera o tipo do `_variant_t` objeto do tipo **VARTYPE**.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      void ChangeType(  
   VARTYPE vartype,  
   const _variant_t* pSrc = NULL   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `vartype`  
 O **VARTYPE** para este `_variant_t` objeto.  
  
 `pSrc`  
 Um ponteiro para o objeto `_variant_t` a ser convertido. Se esse valor for **nulo**, conversão é feita em vigor.  
  
## <a name="remarks"></a>Comentários  
 Esta função de membro converte um `_variant_t` objeto do tipo **VARTYPE**. Se `pSrc` é **nulo**, a conversão é feita no local, caso contrário `_variant_t` objeto é copiado do `pSrc` e, em seguida, convertida.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _variant_t](../cpp/variant-t-class.md)