---
title: _bstr_t::Attach
ms.date: 11/04/2016
f1_keywords:
- _bstr_t::Attach
helpviewer_keywords:
- Attach method [C++]
ms.assetid: 8cad867e-40fc-435b-841f-0d412c2f58d3
ms.openlocfilehash: 718efb9e3dac0d776678fe9efd912a602e041659
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81749694"
---
# <a name="_bstr_tattach"></a>_bstr_t::Attach

**Específico da Microsoft**

Vincula um wrapper `_bstr_t` a um `BSTR`.

## <a name="syntax"></a>Sintaxe

```cpp
void Attach(
   BSTR s
);
```

#### <a name="parameters"></a>Parâmetros

*s*<br/>
Um `BSTR` a ser associado ou atribuído à variável `_bstr_t`.

## <a name="remarks"></a>Comentários

Se o `_bstr_t` estava associado anteriormente a outro `BSTR`, o `_bstr_t` limpará o recurso `BSTR`, se nenhuma outra variável `_bstr_t` estiver usando o `BSTR`.

## <a name="example"></a>Exemplo

Consulte [_bstr_t::Atribuir](../cpp/bstr-t-assign.md) para um exemplo usando **Anexar**.

**Fim específico da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _bstr_t](../cpp/bstr-t-class.md)
