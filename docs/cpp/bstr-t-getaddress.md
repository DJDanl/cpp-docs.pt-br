---
title: _bstr_t::GetAddress | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _bstr_t::GetAddress
dev_langs:
- C++
helpviewer_keywords:
- GetAddress method [C++]
ms.assetid: 09bc9180-867e-4ee5-b22a-8339dc663142
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: d11479a93cf19b59ae6b824f76f9b00b10fff6b2
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="bstrtgetaddress"></a>_bstr_t::GetAddress
**Seção específica da Microsoft**  
  
 Libera qualquer cadeia de caracteres existente e retorna o endereço de uma cadeia de caracteres recém-alocada.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
BSTR* GetAddress( );  
  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para o `BSTR` encapsulado por `_bstr_t`.  
  
## <a name="remarks"></a>Comentários  
 `GetAddress` afeta todos os objetos `_bstr_t` que compartilham um `BSTR`. Mais de um `_bstr_t` pode compartilhar um `BSTR` com o uso do construtor de cópia e de `operator=`.  
  
## <a name="example"></a>Exemplo  
 Consulte [_bstr_t::Assign](../cpp/bstr-t-assign.md) para um exemplo que usa `GetAddress`.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _bstr_t](../cpp/bstr-t-class.md)
