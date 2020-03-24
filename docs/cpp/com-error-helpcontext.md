---
title: _com_error::HelpContext
ms.date: 11/04/2016
f1_keywords:
- _com_error::HelpContext
helpviewer_keywords:
- HelpContext method [C++]
ms.assetid: 160d6443-9b68-4cf5-a540-50da951a5b2b
ms.openlocfilehash: b3c79bb069ef504680e83359d6ec90c803f16d9d
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180583"
---
# <a name="_com_errorhelpcontext"></a>_com_error::HelpContext

**Seção específica da Microsoft**

Chama a função `IErrorInfo::GetHelpContext`.

## <a name="syntax"></a>Sintaxe

```
DWORD HelpContext( ) const throw( );
```

## <a name="return-value"></a>Valor retornado

Retorna o resultado de `IErrorInfo::GetHelpContext` para o objeto de `IErrorInfo` registrado no objeto `_com_error`. Se nenhum objeto de `IErrorInfo` for registrado, ele retornará um zero.

## <a name="remarks"></a>Comentários

Qualquer falha ao chamar o método `IErrorInfo::GetHelpContext` é ignorada.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_error](../cpp/com-error-class.md)
