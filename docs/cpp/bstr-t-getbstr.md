---
title: _bstr_t::GetBSTR
ms.date: 11/04/2016
f1_keywords:
- _bstr_t::GetBSTR
helpviewer_keywords:
- GetBSTR method [C++]
ms.assetid: 0c62ff16-4433-4183-a03c-d5a0a9b731ef
ms.openlocfilehash: da438c65256d9a7e5bf5b02e108fee1385171d2d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80181207"
---
# <a name="_bstr_tgetbstr"></a>_bstr_t::GetBSTR

**Seção específica da Microsoft**

Aponta para o início do `BSTR` encapsulado por `_bstr_t`.

## <a name="syntax"></a>Sintaxe

```
BSTR& GetBSTR( );
```

## <a name="return-value"></a>Valor retornado

O início do `BSTR` encapsulado por `_bstr_t`.

## <a name="remarks"></a>Comentários

**Getbstr** afeta todos os objetos de `_bstr_t` que compartilham um `BSTR`. Mais de um `_bstr_t` pode compartilhar uma `BSTR` por meio do uso do construtor de cópia e do **operador =** .

## <a name="example"></a>Exemplo

Consulte [_bstr_t:: assign](../cpp/bstr-t-assign.md) para obter um exemplo usando **getbstr**.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _bstr_t](../cpp/bstr-t-class.md)
