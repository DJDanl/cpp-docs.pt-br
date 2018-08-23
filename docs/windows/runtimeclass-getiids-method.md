---
title: 'Método runtimeclass:: Getiids | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClass::GetIids
dev_langs:
- C++
helpviewer_keywords:
- GetIids method
ms.assetid: 826a67d1-ebc4-4940-b5d5-7cd66885e4a1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: d3c16d54b08d0c687b33381107eb17be351e9d6f
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42589476"
---
# <a name="runtimeclassgetiids-method"></a>Método RuntimeClass::GetIids

Obtém uma matriz que contém a interface implementadas pelo atual de IDs **RuntimeClass** objeto.

## <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD(
   GetIids
)  
   (_Out_ ULONG *iidCount,
   _Deref_out_ _Deref_post_cap_(*iidCount) IID **iids);
```

### <a name="parameters"></a>Parâmetros

*iidCount*  
Quando essa operação for concluída, o número total de elementos na matriz *iids*.

*IIDs*  
Quando essa operação for concluída, um ponteiro para uma matriz de IDs de interface.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, E_OUTOFMEMORY.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe RuntimeClass](../windows/runtimeclass-class.md)