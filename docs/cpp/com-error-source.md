---
title: _com_error::Source
ms.date: 11/04/2016
f1_keywords:
- _com_error::Source
helpviewer_keywords:
- Source method [C++]
ms.assetid: 55353741-fabc-4b0c-9787-b5a69bb189f2
ms.openlocfilehash: 43dd21297ddd54863d535402dddd59243d589eec
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180518"
---
# <a name="_com_errorsource"></a>_com_error::Source

**Seção específica da Microsoft**

Chama a função `IErrorInfo::GetSource`.

## <a name="syntax"></a>Sintaxe

```
_bstr_t Source() const;
```

## <a name="return-value"></a>Valor retornado

Retorna o resultado de `IErrorInfo::GetSource` para o objeto de `IErrorInfo` registrado no objeto `_com_error`. O `BSTR` resultante é encapsulado em um objeto `_bstr_t`. Se nenhum `IErrorInfo` for registrado, ele retornará um `_bstr_t`vazio.

## <a name="remarks"></a>Comentários

Qualquer falha ao chamar o método `IErrorInfo::GetSource` é ignorada.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_error](../cpp/com-error-class.md)
