---
title: Operadores relacionais variant_t | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _variant_t::operator==
- _variant_t::operator!=
dev_langs: C++
helpviewer_keywords:
- '!= operator'
- relational operators [C++], _variant_t class
- operator!= [C++], variant
- operator!= [C++], relational operators
- operator != [C++], variant
- operator == [C++], variant
- operator== [C++], variant
- operator != [C++], relational operators
- == operator [C++], with specific Visual C++ objects
ms.assetid: 141bacb8-41a2-44dd-b3c0-4ad1f884f4ea
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 86ae6c517eaefc45c6fbeb5108efdf7e6b92b769
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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