---
title: + = _bstr_t::Operator, + | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _bstr_t::operator+
- _bstr_t::operator+=
dev_langs:
- C++
helpviewer_keywords:
- += operator [C++], appending strings
- + operator [C++], _bstr_t objects
ms.assetid: d28316ce-c2c8-4a38-bdb3-44fa4e582c44
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4a2ea7cd3b93f7445190f16a92a580fe9628a976
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942147"
---
# <a name="bstrtoperator--"></a>_bstr_t::operator +=, +
**Seção específica da Microsoft**  
  
 Acrescenta caracteres ao final do objeto `_bstr_t` ou concatena duas cadeias de caracteres.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
_bstr_t& operator+=( const _bstr_t& s1 );  
_bstr_t operator+( const _bstr_t& s1 );  
friend _bstr_t operator+( const char* s2, const _bstr_t& s1);  
friend _bstr_t operator+( const wchar_t* s3, const _bstr_t& s1);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *S1*  
 Um objeto `_bstr_t`.  
  
 *S2*  
 Uma cadeia de caracteres multibyte.  
  
 *S3*  
 Uma cadeia de caracteres Unicode.  
  
## <a name="remarks"></a>Comentários  
 Esses operadores executam a concatenação de cadeias de caracteres:  
  
-   **Operator + = (***s1***)** anexa os caracteres em encapsulado `BSTR` de *s1* ao final da deencapsuladodesteobjeto`BSTR`.      
  
-   **operador + (***s1***)** retorna o novo `_bstr_t` que é formado pela concatenação desse objeto `BSTR` com do *s1*.      
  
-   **operador + (***s2***&#124;***s1***)** retorna um novo `_bstr_t` formado pela concatenação de um cadeia de caracteres multibyte *s2*, convertido em Unicode, com o `BSTR` encapsulada na *s1*.          
  
-   **operador + (***s3* **,***s1***)** retorna um novo `_bstr_t` formado pela concatenação de uma cadeia de caracteres Unicode *s3* com o `BSTR` encapsulada na *s1*.        
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _bstr_t](../cpp/bstr-t-class.md)