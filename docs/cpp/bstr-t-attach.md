---
title: _bstr_t::Attach
ms.date: 11/04/2016
f1_keywords:
- _bstr_t::Attach
helpviewer_keywords:
- Attach method [C++]
ms.assetid: 8cad867e-40fc-435b-841f-0d412c2f58d3
ms.openlocfilehash: 8601ebbea6a9ab837c07518b018e83e8c0df226d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62385057"
---
# <a name="bstrtattach"></a>_bstr_t::Attach

**Seção específica da Microsoft**

Vincula um wrapper `_bstr_t` a um `BSTR`.

## <a name="syntax"></a>Sintaxe

```
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

Ver [_bstr_t::Assign](../cpp/bstr-t-assign.md) para obter um exemplo de uso **Attach**.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _bstr_t](../cpp/bstr-t-class.md)