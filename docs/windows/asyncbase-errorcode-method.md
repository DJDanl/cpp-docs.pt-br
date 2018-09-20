---
title: 'Método asyncbase:: ErrorCode | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- async/Microsoft::WRL::AsyncBase::ErrorCode
dev_langs:
- C++
helpviewer_keywords:
- ErrorCode method
ms.assetid: 3f5f0f69-d60a-4a67-8cc6-a55fdc89a192
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8da9da0ffbfb8291082f7f600ca72bf1937c3bfc
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46435539"
---
# <a name="asyncbaseerrorcode-method"></a>Método AsyncBase::ErrorCode

Recupera o código de erro para a operação assíncrona atual.

## <a name="syntax"></a>Sintaxe

```cpp
inline void ErrorCode(
   HRESULT *error
);
```

### <a name="parameters"></a>Parâmetros

*error*<br/>
O local em que essa operação armazena o código de erro atual.

## <a name="remarks"></a>Comentários

Esta operação é thread-safe.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** async.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe AsyncBase](../windows/asyncbase-class.md)