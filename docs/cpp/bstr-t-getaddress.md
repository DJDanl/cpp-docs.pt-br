---
title: _bstr_t::GetAddress
ms.date: 11/04/2016
f1_keywords:
- _bstr_t::GetAddress
helpviewer_keywords:
- GetAddress method [C++]
ms.assetid: 09bc9180-867e-4ee5-b22a-8339dc663142
ms.openlocfilehash: 4d51539d2afbb2fbcc860b6c4d821df119aca418
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62393890"
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

**GetAddress** afeta todos os `_bstr_t` objetos que compartilham um `BSTR`. Mais de um `_bstr_t` podem compartilhar uma `BSTR` por meio do uso do construtor de cópia e **operador =**.

## <a name="example"></a>Exemplo

Ver [_bstr_t::Assign](../cpp/bstr-t-assign.md) para obter um exemplo usando **GetAddress**.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _bstr_t](../cpp/bstr-t-class.md)