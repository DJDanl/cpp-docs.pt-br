---
title: _com_error::Error
ms.date: 11/04/2016
f1_keywords:
- _com_error::Error
- Error
helpviewer_keywords:
- Error method [C++]
ms.assetid: b53a15fd-198e-4276-afcd-13439c4807f7
ms.openlocfilehash: 606f553060e71ece18b3d48159ec40133be28965
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62155092"
---
# <a name="comerrorerror"></a>_com_error::Error

**Seção específica da Microsoft**

Recupera o HRESULT transmitido ao construtor.

## <a name="syntax"></a>Sintaxe

```
HRESULT Error( ) const throw( );
```

## <a name="return-value"></a>Valor de retorno

Item HRESULT bruto passado para o construtor.

## <a name="remarks"></a>Comentários

Recupera o item HRESULT encapsulado em um `_com_error` objeto.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_error](../cpp/com-error-class.md)