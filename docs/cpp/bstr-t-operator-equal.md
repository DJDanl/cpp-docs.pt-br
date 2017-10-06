---
title: _bstr_t::Operator = | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _bstr_t::operator=
dev_langs:
- C++
helpviewer_keywords:
- operator = [C++], bstr
- operator= [C++], bstr
ms.assetid: fb31bb1b-ce29-4388-b5fd-8dac830cf18a
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
ms.openlocfilehash: 445c18ece9b998d5cfa75a1c9fe5bde3b60b2e52
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
