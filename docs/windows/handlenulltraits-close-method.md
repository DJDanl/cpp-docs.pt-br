---
title: 'Método handlenulltraits:: Close | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLENullTraits::Close
dev_langs:
- C++
helpviewer_keywords:
- Close method
ms.assetid: 6fb2fa0d-df20-45dc-856f-f78497f8bdf9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1041fc03a565592784131102a48ffe2ded0e159c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46430626"
---
# <a name="handlenulltraitsclose-method"></a>Método HANDLENullTraits::Close

Fecha o identificador especificado.

## <a name="syntax"></a>Sintaxe

```cpp
inline static bool Close(
   _In_ Type h
);
```

### <a name="parameters"></a>Parâmetros

*h*<br/>
O identificador para fechar.

## <a name="return-value"></a>Valor de retorno

**Verdadeiro** se tratar *h* fechado com êxito; caso contrário, **false**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="see-also"></a>Consulte também

[Estrutura HANDLENullTraits](../windows/handlenulltraits-structure.md)