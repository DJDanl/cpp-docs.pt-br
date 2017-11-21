---
title: + = _bstr_t::Operator, + | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _bstr_t::operator+
- _bstr_t::operator+=
dev_langs: C++
helpviewer_keywords:
- += operator [C++], appending strings
- + operator [C++], _bstr_t objects
ms.assetid: d28316ce-c2c8-4a38-bdb3-44fa4e582c44
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 503f021a9ef0f798af8d82f33dac84d3eb0ccc51
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="bstrtoperator--"></a>_bstr_t::operator +=, +
**Seção específica da Microsoft**  
  
 Acrescenta caracteres ao final do objeto `_bstr_t` ou concatena duas cadeias de caracteres.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      _bstr_t& operator+=(  
   const _bstr_t& s1   
);  
_bstr_t operator+(  
   const _bstr_t& s1   
);  
friend _bstr_t operator+(  
   const char* s2,  
   const _bstr_t& s1   
);  
friend _bstr_t operator+(  
   const wchar_t* s3,  
   const _bstr_t& s1   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *S1*  
 Um objeto `_bstr_t`.  
  
 *S2*  
 Uma cadeia de caracteres multibyte.  
  
 `s3`  
 Uma cadeia de caracteres Unicode.  
  
## <a name="remarks"></a>Comentários  
 Esses operadores executam a concatenação de cadeias de caracteres:  
  
-   **+ operador = (***s1***)** acrescenta os caracteres a encapsulada `BSTR` de *s1* ao final da encapsuladadesseobjeto`BSTR`.  
  
-   **operador + (***s1***)** retorna o novo `_bstr_t` que é formado pela concatenação do objeto `BSTR` da *s1*.  
  
-   **operador + (***s2***&#124;** *s1***)** retorna um novo `_bstr_t` que é formado pela concatenação de uma cadeia de caracteres multibyte *s2*, convertido em Unicode, com o `BSTR` encapsulada na *s1*.  
  
-   **operador + (** `s3` **,***s1***)** retorna um novo `_bstr_t` que é formado pela concatenação de uma cadeia de caracteres Unicode `s3` com o `BSTR` encapsulada na *s1*.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _bstr_t](../cpp/bstr-t-class.md)