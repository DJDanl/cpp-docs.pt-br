---
title: 'Método handletraits:: Close | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleTraits::HANDLETraits::Close
dev_langs:
- C++
helpviewer_keywords:
- Close method
ms.assetid: 3c631a7c-ccce-472a-b1da-aab8fa815c13
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b1b36d4feea61e9a79978cc86dca29a7ad14846a
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42594030"
---
# <a name="handletraitsclose-method"></a>Método HANDLETraits::Close

Fecha o identificador especificado.

## <a name="syntax"></a>Sintaxe

```cpp
inline static bool Close(
   _In_ Type h
);
```

### <a name="parameters"></a>Parâmetros

*h*  
O identificador para fechar.

## <a name="return-value"></a>Valor de retorno

**Verdadeiro** se tratar *h* fechado com êxito; caso contrário, **false**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers::HandleTraits

## <a name="see-also"></a>Consulte também

[Estrutura HANDLETraits](../windows/handletraits-structure.md)