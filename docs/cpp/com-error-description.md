---
title: _com_error::Description
ms.date: 11/04/2016
f1_keywords:
- _com_error::Description
helpviewer_keywords:
- Description method [C++]
ms.assetid: 88191e24-4ee8-44a6-8c4c-3758e22e0548
ms.openlocfilehash: a517c40e9adfbda2d790ce41a48ccf8658bcd3e0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50544385"
---
# <a name="comerrordescription"></a>_com_error::Description

**Seção específica da Microsoft**

Chama a função `IErrorInfo::GetDescription`.

## <a name="syntax"></a>Sintaxe

```
_bstr_t Description( ) const;
```

## <a name="return-value"></a>Valor de retorno

Retorna o resultado da `IErrorInfo::GetDescription` para o `IErrorInfo` registrado no `_com_error` objeto. O `BSTR` resultante é encapsulado em um objeto `_bstr_t`. Se nenhum `IErrorInfo` é registrado, ele retornará um `_bstr_t`.

## <a name="remarks"></a>Comentários

Chamadas a `IErrorInfo::GetDescription` função e recupera `IErrorInfo` registrado no `_com_error` objeto. Qualquer falha ao chamar o `IErrorInfo::GetDescription` método é ignorado.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_error](../cpp/com-error-class.md)