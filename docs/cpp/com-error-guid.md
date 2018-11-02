---
title: _com_error::GUID
ms.date: 11/04/2016
f1_keywords:
- _com_error::GUID
helpviewer_keywords:
- GUID method [C++]
ms.assetid: e84c2c23-d02e-48f8-b776-9bd6937296d2
ms.openlocfilehash: 905b67577a65b81be0b4d18c7513652dd8c5f055
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50661624"
---
# <a name="comerrorguid"></a>_com_error::GUID

**Seção específica da Microsoft**

Chama a função `IErrorInfo::GetGUID`.

## <a name="syntax"></a>Sintaxe

```
GUID GUID( ) const throw( );
```

## <a name="return-value"></a>Valor de retorno

Retorna o resultado da `IErrorInfo::GetGUID` para o `IErrorInfo` registrado no `_com_error` objeto. Se nenhum `IErrorInfo` é registrado, ele retorna `GUID_NULL`.

## <a name="remarks"></a>Comentários

Qualquer falha ao chamar o `IErrorInfo::GetGUID` método é ignorado.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_error](../cpp/com-error-class.md)