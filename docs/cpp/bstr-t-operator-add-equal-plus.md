---
title: _bstr_t::operator +=, +
ms.date: 11/04/2016
f1_keywords:
- _bstr_t::operator+
- _bstr_t::operator+=
helpviewer_keywords:
- += operator [C++], appending strings
- + operator [C++], _bstr_t objects
ms.assetid: d28316ce-c2c8-4a38-bdb3-44fa4e582c44
ms.openlocfilehash: b9eddca85d66f4978e1b33299ca655cd880cf45e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80181142"
---
# <a name="_bstr_toperator--"></a>_bstr_t::operator +=, +

**Seção específica da Microsoft**

Acrescenta caracteres ao final do objeto `_bstr_t` ou concatena duas cadeias de caracteres.

## <a name="syntax"></a>Sintaxe

```
_bstr_t& operator+=( const _bstr_t& s1 );
_bstr_t operator+( const _bstr_t& s1 );
friend _bstr_t operator+( const char* s2, const _bstr_t& s1);
friend _bstr_t operator+( const wchar_t* s3, const _bstr_t& s1);
```

#### <a name="parameters"></a>parâmetros

*s1*<br/>
Um objeto `_bstr_t` .

*s2*<br/>
Uma cadeia de caracteres multibyte.

*Estado*<br/>
Uma cadeia de caracteres Unicode.

## <a name="remarks"></a>Comentários

Esses operadores executam a concatenação de cadeias de caracteres:

- **operador + = (**  *S1*  **)** Acrescenta os caracteres no `BSTR` encapsulado de *S1* ao final do `BSTR`encapsulado desse objeto.

- **operador + (**  *S1*  **)** Retorna o novo `_bstr_t` que é formado concatenando o `BSTR` do objeto com o de *S1*.

- **operador + (**  *S2*  **&#124;**  *S1*  **)** Retorna uma nova `_bstr_t` que é formada pela concatenação de uma cadeia de caracteres de vários bytes *S2*, convertida em Unicode, com o `BSTR` encapsulado em *S1*.

- **operador + (**  *S3* **,**  *S1*  **)** Retorna uma nova `_bstr_t` que é formada pela concatenação de uma cadeia de caracteres Unicode *S3* com o `BSTR` encapsulado em *S1*.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _bstr_t](../cpp/bstr-t-class.md)
