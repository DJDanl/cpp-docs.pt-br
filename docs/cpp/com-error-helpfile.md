---
title: _com_error::HelpFile
ms.date: 11/04/2016
f1_keywords:
- _com_error::HelpFile
helpviewer_keywords:
- HelpFile method [C++]
ms.assetid: d2d3a0a1-6b62-4d52-a818-3cfae545a4af
ms.openlocfilehash: 775adfa7d5dd5aca098edcd793c2164d65fe7efa
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190216"
---
# <a name="_com_errorhelpfile"></a>_com_error::HelpFile

**Seção específica da Microsoft**

Chama a função `IErrorInfo::GetHelpFile`.

## <a name="syntax"></a>Sintaxe

```
_bstr_t HelpFile() const;
```

## <a name="return-value"></a>Valor retornado

Retorna o resultado de `IErrorInfo::GetHelpFile` para o objeto de `IErrorInfo` registrado no objeto `_com_error`. O BSTR resultante é encapsulado em um objeto `_bstr_t`. Se nenhum `IErrorInfo` for registrado, ele retornará um `_bstr_t`vazio.

## <a name="remarks"></a>Comentários

Qualquer falha ao chamar o método `IErrorInfo::GetHelpFile` é ignorada.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_error](../cpp/com-error-class.md)
