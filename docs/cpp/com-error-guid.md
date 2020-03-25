---
title: _com_error::GUID
ms.date: 11/04/2016
f1_keywords:
- _com_error::GUID
helpviewer_keywords:
- GUID method [C++]
ms.assetid: e84c2c23-d02e-48f8-b776-9bd6937296d2
ms.openlocfilehash: d5b05cd4e26f89d42ea23b605f5e6560795a0cfa
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180630"
---
# <a name="_com_errorguid"></a>_com_error::GUID

**Seção específica da Microsoft**

Chama a função `IErrorInfo::GetGUID`.

## <a name="syntax"></a>Sintaxe

```
GUID GUID( ) const throw( );
```

## <a name="return-value"></a>Valor retornado

Retorna o resultado de `IErrorInfo::GetGUID` para o objeto de `IErrorInfo` registrado no objeto `_com_error`. Se nenhum objeto de `IErrorInfo` for registrado, ele retornará `GUID_NULL`.

## <a name="remarks"></a>Comentários

Qualquer falha ao chamar o método `IErrorInfo::GetGUID` é ignorada.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_error](../cpp/com-error-class.md)
