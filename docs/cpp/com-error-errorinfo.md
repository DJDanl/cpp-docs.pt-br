---
title: _com_error::ErrorInfo
ms.date: 11/04/2016
f1_keywords:
- _com_error::ErrorInfo
helpviewer_keywords:
- ErrorInfo method [C++]
ms.assetid: 071b446c-4395-4fb8-bd3d-300a8b25f5cd
ms.openlocfilehash: cedb9ccadc63166c43d980333d93a195254700d8
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180700"
---
# <a name="_com_errorerrorinfo"></a>_com_error::ErrorInfo

**Seção específica da Microsoft**

Recupera o objeto `IErrorInfo` passado para o construtor.

## <a name="syntax"></a>Sintaxe

```
IErrorInfo * ErrorInfo( ) const throw( );
```

## <a name="return-value"></a>Valor retornado

O item `IErrorInfo` bruto passado para o construtor.

## <a name="remarks"></a>Comentários

Recupera o item de `IErrorInfo` encapsulado em um objeto `_com_error` ou nulo se nenhum item de `IErrorInfo` for registrado. O chamador deve chamar `Release` no objeto retornado quando terminar de usá-lo.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_error](../cpp/com-error-class.md)
