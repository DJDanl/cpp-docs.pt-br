---
title: _com_error::HelpFile | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::HelpFile
dev_langs:
- C++
helpviewer_keywords:
- HelpFile method [C++]
ms.assetid: d2d3a0a1-6b62-4d52-a818-3cfae545a4af
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2f40ea4dd39e88508e6e12c9d7103b7a536902d0
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46070542"
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