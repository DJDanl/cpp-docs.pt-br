---
title: _bstr_t::GetAddress
ms.date: 11/04/2016
f1_keywords:
- _bstr_t::GetAddress
helpviewer_keywords:
- GetAddress method [C++]
ms.assetid: 09bc9180-867e-4ee5-b22a-8339dc663142
ms.openlocfilehash: ca78bd1b607ba4a86bbc824887a7ec767cd5476e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80181246"
---
# <a name="_bstr_tgetaddress"></a>_bstr_t::GetAddress

**Seção específica da Microsoft**

Libera qualquer cadeia de caracteres existente e retorna o endereço de uma cadeia de caracteres recém-alocada.

## <a name="syntax"></a>Sintaxe

```
BSTR* GetAddress( );
```

## <a name="return-value"></a>Valor retornado

Um ponteiro para o `BSTR` encapsulado por `_bstr_t`.

## <a name="remarks"></a>Comentários

**GetAddress** afeta todos os objetos de `_bstr_t` que compartilham um `BSTR`. Mais de um `_bstr_t` pode compartilhar uma `BSTR` por meio do uso do construtor de cópia e do **operador =** .

## <a name="example"></a>Exemplo

Consulte [_bstr_t:: assign](../cpp/bstr-t-assign.md) para obter um exemplo usando **GetAddress**.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _bstr_t](../cpp/bstr-t-class.md)
