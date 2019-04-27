---
title: _com_error::ErrorInfo
ms.date: 11/04/2016
f1_keywords:
- _com_error::ErrorInfo
helpviewer_keywords:
- ErrorInfo method [C++]
ms.assetid: 071b446c-4395-4fb8-bd3d-300a8b25f5cd
ms.openlocfilehash: 59ada8a7e098e57cca5641a439365851bbae2485
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62155066"
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