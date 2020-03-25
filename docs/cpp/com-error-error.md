---
title: _com_error::Error
ms.date: 11/04/2016
f1_keywords:
- _com_error::Error
- Error
helpviewer_keywords:
- Error method [C++]
ms.assetid: b53a15fd-198e-4276-afcd-13439c4807f7
ms.openlocfilehash: 8e2c52d10b15822703329dcea18944773f5784ea
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180752"
---
# <a name="_com_errorerror"></a>_com_error::Error

**Seção específica da Microsoft**

Recupera o HRESULT passado para o construtor.

## <a name="syntax"></a>Sintaxe

```
HRESULT Error( ) const throw( );
```

## <a name="return-value"></a>Valor retornado

Item HRESULT bruto passado para o construtor.

## <a name="remarks"></a>Comentários

Recupera o item de HRESULT encapsulado em um objeto `_com_error`.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_error](../cpp/com-error-class.md)
