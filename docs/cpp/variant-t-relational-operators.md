---
title: Operadores relacionais variant_t | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _variant_t::operator==
- _variant_t::operator!=
- _variant_t::operator!=
- _variant_t::operator==
dev_langs:
- C++
helpviewer_keywords:
- '!= operator'
- relational operators, _variant_t class
- operator!=, variant
- operator!=, relational operators
- operator !=, variant
- operator ==, variant
- operator==, variant
- operator !=, relational operators
- == operator, with specific Visual C++ objects
ms.assetid: 141bacb8-41a2-44dd-b3c0-4ad1f884f4ea
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
ms.openlocfilehash: d8bcf9550e3e3f8af1836aa3f6e8747089837142
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="variantt-relational-operators"></a>Operadores relacionais _variant_t
**Seção específica da Microsoft**  
  
 Compare dois objetos `_variant_t` em termos de igualdade ou desigualdade.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      bool operator==(  
   const VARIANT& varSrc   
) const;  
bool operator==(  
   const VARIANT* pSrc   
) const;  
bool operator!=(  
   const VARIANT& varSrc   
) const;  
bool operator!=(  
   const VARIANT* pSrc   
) const;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *varSrc*  
 Um **VARIANT** a ser comparado com o `_variant_t` objeto.  
  
 `pSrc`  
 Ponteiro para o **VARIANT** a ser comparado com o `_variant_t` objeto.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna **true** se mantém em comparação, **false** se não for.  
  
## <a name="remarks"></a>Comentários  
 Compara uma `_variant_t` do objeto com um **VARIANT**, teste de igualdade ou de desigualdade.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _variant_t](../cpp/variant-t-class.md)
