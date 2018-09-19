---
title: _com_error::ErrorInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_error::ErrorInfo
dev_langs:
- C++
helpviewer_keywords:
- ErrorInfo method [C++]
ms.assetid: 071b446c-4395-4fb8-bd3d-300a8b25f5cd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1fc2906827e6a465106a3dbdcb8b63c7b53a39ee
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46039342"
---
# <a name="comerrorerrorinfo"></a>_com_error::ErrorInfo

**Seção específica da Microsoft**

Recupera o objeto `IErrorInfo` passado para o construtor.

## <a name="syntax"></a>Sintaxe

```
IErrorInfo * ErrorInfo( ) const throw( );
```

## <a name="return-value"></a>Valor de retorno

O item `IErrorInfo` bruto passado para o construtor.

## <a name="remarks"></a>Comentários

Recupera encapsulado `IErrorInfo` de item em uma `_com_error` do objeto ou nulo se nenhum `IErrorInfo` item é registrado. O chamador deve chamar `Release` no objeto retornado quando terminar de usá-lo.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_error](../cpp/com-error-class.md)