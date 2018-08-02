---
title: Operadores relacionais variant_t | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _variant_t::operator==
- _variant_t::operator!=
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 32f9a45fcfaaff02cfb7cf765857957f20c41ba1
ms.sourcegitcommit: 51f804005b8d921468775a0316de52ad39b77c3e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/02/2018
ms.locfileid: "39463035"
---
# <a name="variantt-relational-operators"></a>Operadores relacionais _variant_t
**Seção específica da Microsoft**  
  
 Compare dois objetos `_variant_t` em termos de igualdade ou desigualdade.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
bool operator==(  
   const VARIANT& varSrc) const;  
bool operator==(  
   const VARIANT* pSrc) const;  
bool operator!=(  
   const VARIANT& varSrc) const;  
bool operator!=(  
   const VARIANT* pSrc) const;  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *varSrc*  
 Um `VARIANT` a ser comparado com o `_variant_t` objeto.  
  
 *pSrc*  
 Ponteiro para o `VARIANT` a ser comparado com o `_variant_t` objeto.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna **verdadeira** se mantém em comparação, **falso** se não for.  
  
## <a name="remarks"></a>Comentários  
 Compara uma `_variant_t` do objeto com um `VARIANT`, testes de igualdade ou desigualdade.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _variant_t](../cpp/variant-t-class.md)