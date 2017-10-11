---
title: _bstr_t::GetBSTR | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _bstr_t::GetBSTR
dev_langs:
- C++
helpviewer_keywords:
- GetBSTR method [C++]
ms.assetid: 0c62ff16-4433-4183-a03c-d5a0a9b731ef
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 376951862a82d6588221b592238c9346d31bad4d
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="bstrtgetbstr"></a>_bstr_t::GetBSTR
**Seção específica da Microsoft**  
  
 Aponta para o início do `BSTR` encapsulado por `_bstr_t`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
BSTR& GetBSTR( );  
  
```  
  
## <a name="return-value"></a>Valor de retorno  
 O início do `BSTR` encapsulado por `_bstr_t`.  
  
## <a name="remarks"></a>Comentários  
 `GetBSTR` afeta todos os objetos `_bstr_t` que compartilham um `BSTR`. Mais de um `_bstr_t` pode compartilhar um `BSTR` com o uso do construtor de cópia e de `operator=`.  
  
## <a name="example"></a>Exemplo  
 Consulte [_bstr_t::Assign](../cpp/bstr-t-assign.md) para um exemplo usando `GetBSTR`.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _bstr_t](../cpp/bstr-t-class.md)
