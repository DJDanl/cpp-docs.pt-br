---
title: _bstr_t::Attach
ms.date: 11/04/2016
f1_keywords:
- _bstr_t::Attach
helpviewer_keywords:
- Attach method [C++]
ms.assetid: 8cad867e-40fc-435b-841f-0d412c2f58d3
ms.openlocfilehash: 3b52661097ca1feab4c8045be240e4138a0c0f21
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190620"
---
# <a name="_bstr_tattach"></a>_bstr_t::Attach

**Seção específica da Microsoft**

Vincula um wrapper `_bstr_t` a um `BSTR`.

## <a name="syntax"></a>Sintaxe

```
void Attach(
   BSTR s
);
```

#### <a name="parameters"></a>parâmetros

*s*<br/>
Um `BSTR` a ser associado ou atribuído à variável `_bstr_t`.

## <a name="remarks"></a>Comentários

Se o `_bstr_t` estava associado anteriormente a outro `BSTR`, o `_bstr_t` limpará o recurso `BSTR`, se nenhuma outra variável `_bstr_t` estiver usando o `BSTR`.

## <a name="example"></a>Exemplo

Consulte [_bstr_t:: assign](../cpp/bstr-t-assign.md) para obter um exemplo usando **Attach**.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _bstr_t](../cpp/bstr-t-class.md)
