---
title: _variant_t::ChangeType | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
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
ms.openlocfilehash: 535bc332a108cf50badca116c496661b7c257bf7
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
