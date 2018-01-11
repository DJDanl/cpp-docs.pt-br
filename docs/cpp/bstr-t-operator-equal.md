---
title: _bstr_t::Operator = | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: _bstr_t::operator=
dev_langs: C++
helpviewer_keywords:
- operator = [C++], bstr
- operator= [C++], bstr
ms.assetid: fb31bb1b-ce29-4388-b5fd-8dac830cf18a
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: ed1de7a529d8c4c1b0d7ae8623d0f1c4a58b5075
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="bstrtoperator-"></a>_bstr_t::operator =
**Seção específica da Microsoft**  
  
 Atribui um novo valor a um objeto `_bstr_t` existente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      _bstr_t& operator=(  
   const _bstr_t& s1   
) throw ( );  
_bstr_t& operator=(  
   const char* s2   
);  
_bstr_t& operator=(  
   const wchar_t* s3   
);  
_bstr_t& operator=(  
   const _variant_t& var   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *S1*  
 Um objeto `_bstr_t` a ser atribuído a um objeto existente `_bstr_t`.  
  
 *S2*  
 Uma cadeia de caracteres multibyte a ser atribuída a um objeto `_bstr_t` existente.  
  
 `s3`  
 Uma cadeia de caracteres Unicode a ser atribuída a um objeto `_bstr_t` existente.  
  
 `var`  
 Um objeto `_variant_t` a ser atribuído a um objeto existente `_bstr_t`.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="example"></a>Exemplo  
 Consulte [_bstr_t::Assign](../cpp/bstr-t-assign.md) para obter um exemplo de como usar `operator=`.  
  
## <a name="see-also"></a>Consulte também  
 [Classe _bstr_t](../cpp/bstr-t-class.md)