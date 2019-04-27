---
title: _com_error::Source
ms.date: 11/04/2016
f1_keywords:
- _com_error::Source
helpviewer_keywords:
- Source method [C++]
ms.assetid: 55353741-fabc-4b0c-9787-b5a69bb189f2
ms.openlocfilehash: 682070877f269967405677d027b20707c8366f61
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62154949"
---
# <a name="comerrorsource"></a>_com_error::Source

**Seção específica da Microsoft**

Chama a função `IErrorInfo::GetSource`.

## <a name="syntax"></a>Sintaxe

```
_bstr_t Source() const;
```

## <a name="return-value"></a>Valor de retorno

Retorna o resultado da `IErrorInfo::GetSource` para o `IErrorInfo` registrado no `_com_error` objeto. O `BSTR` resultante é encapsulado em um objeto `_bstr_t`. Se nenhum `IErrorInfo` é registrado, ele retornará um `_bstr_t`.

## <a name="remarks"></a>Comentários

Qualquer falha ao chamar o `IErrorInfo::GetSource` método é ignorado.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_error](../cpp/com-error-class.md)