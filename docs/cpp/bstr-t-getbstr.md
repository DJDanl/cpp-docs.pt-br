---
title: _bstr_t::GetBSTR
ms.date: 11/04/2016
f1_keywords:
- _bstr_t::GetBSTR
helpviewer_keywords:
- GetBSTR method [C++]
ms.assetid: 0c62ff16-4433-4183-a03c-d5a0a9b731ef
ms.openlocfilehash: cea3404e0732cb0e16b3fa9199ce95e3dfcc23f5
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50618043"
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

**GetBSTR** afeta todos os `_bstr_t` objetos que compartilham um `BSTR`. Mais de um `_bstr_t` podem compartilhar uma `BSTR` por meio do uso do construtor de cópia e **operador =**.

## <a name="example"></a>Exemplo

Ver [_bstr_t::Assign](../cpp/bstr-t-assign.md) para obter um exemplo de uso **GetBSTR**.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _bstr_t](../cpp/bstr-t-class.md)