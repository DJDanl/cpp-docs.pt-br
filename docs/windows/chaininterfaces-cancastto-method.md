---
title: 'Método chaininterfaces:: Cancastto | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::ChainInterfaces::CanCastTo
dev_langs:
- C++
helpviewer_keywords:
- CanCastTo method
ms.assetid: 8be44875-53ed-494b-91a0-0f8e399685bb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8398f0bd4d9fdc786926782b13ebcac913a6a351
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42612864"
---
# <a name="chaininterfacescancastto-method"></a>Método ChainInterfaces::CanCastTo

Indica se a ID de interface especificado pode ser convertida em cada um dos especializações definidas pelos parâmetros de modelo não padrão.

## <a name="syntax"></a>Sintaxe

```cpp
__forceinline bool CanCastTo(
   REFIID riid,
   _Deref_out_ void **ppv
);
```

### <a name="parameters"></a>Parâmetros

*riid*  
Uma ID de interface.

*ppv*  
Um ponteiro para a última ID de interface que foi convertido com êxito.

## <a name="return-value"></a>Valor de retorno

**Verdadeiro** se todas as operações de conversão for bem-sucedida; caso contrário, **falso**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Estrutura ChainInterfaces](../windows/chaininterfaces-structure.md)