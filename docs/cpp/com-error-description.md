---
title: _com_error::Description | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::Description
dev_langs:
- C++
helpviewer_keywords:
- Description method [C++]
ms.assetid: 88191e24-4ee8-44a6-8c4c-3758e22e0548
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 90208866ee08d6990d8f1b5322a38fbd2d63a651
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46091772"
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