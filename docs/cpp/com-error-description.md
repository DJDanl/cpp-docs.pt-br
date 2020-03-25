---
title: _com_error::Description
ms.date: 11/04/2016
f1_keywords:
- _com_error::Description
helpviewer_keywords:
- Description method [C++]
ms.assetid: 88191e24-4ee8-44a6-8c4c-3758e22e0548
ms.openlocfilehash: de2275f096fe2fde96e64cbc3034602a1fde5e88
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180765"
---
# <a name="_com_errordescription"></a>_com_error::Description

**Seção específica da Microsoft**

Chama a função `IErrorInfo::GetDescription`.

## <a name="syntax"></a>Sintaxe

```
_bstr_t Description( ) const;
```

## <a name="return-value"></a>Valor retornado

Retorna o resultado de `IErrorInfo::GetDescription` para o objeto de `IErrorInfo` registrado no objeto `_com_error`. O `BSTR` resultante é encapsulado em um objeto `_bstr_t`. Se nenhum `IErrorInfo` for registrado, ele retornará um `_bstr_t`vazio.

## <a name="remarks"></a>Comentários

Chama a função `IErrorInfo::GetDescription` e recupera `IErrorInfo` registradas no objeto `_com_error`. Qualquer falha ao chamar o método `IErrorInfo::GetDescription` é ignorada.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_error](../cpp/com-error-class.md)
