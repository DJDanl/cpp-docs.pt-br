---
title: _com_error::HelpFile
ms.date: 11/04/2016
f1_keywords:
- _com_error::HelpFile
helpviewer_keywords:
- HelpFile method [C++]
ms.assetid: d2d3a0a1-6b62-4d52-a818-3cfae545a4af
ms.openlocfilehash: 826ac53f001355127f16b7ad2a7583a0f8800de7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62155027"
---
# <a name="comerrorhelpfile"></a>_com_error::HelpFile

**Seção específica da Microsoft**

Chama a função `IErrorInfo::GetHelpFile`.

## <a name="syntax"></a>Sintaxe

```
_bstr_t HelpFile() const;
```

## <a name="return-value"></a>Valor de retorno

Retorna o resultado da `IErrorInfo::GetHelpFile` para o `IErrorInfo` registrado no `_com_error` objeto. O BSTR resultante é encapsulado em um objeto `_bstr_t`. Se nenhum `IErrorInfo` é registrado, ele retornará um `_bstr_t`.

## <a name="remarks"></a>Comentários

Qualquer falha ao chamar o `IErrorInfo::GetHelpFile` método é ignorado.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_error](../cpp/com-error-class.md)