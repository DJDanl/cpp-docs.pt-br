---
title: _bstr_t::GetAddress | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _bstr_t::GetAddress
dev_langs:
- C++
helpviewer_keywords:
- GetAddress method [C++]
ms.assetid: 09bc9180-867e-4ee5-b22a-8339dc663142
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9b3aa001270a3dc608fabf73fce28ce51eb9295e
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46031295"
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