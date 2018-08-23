---
title: 'Método Module:: unregisterwinrtobject | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::UnregisterWinRTObject
dev_langs:
- C++
helpviewer_keywords:
- UnregisterWinRTObject method
ms.assetid: 32334aa7-2293-40d2-9a89-4b02e2e31f3c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 88cafb7796ba0dfd1e37902821872e860ddc4baf
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42592178"
---
# <a name="moduleunregisterwinrtobject-method"></a>Método Module::UnregisterWinRTObject

Cancela o registro de um ou mais objetos de tempo de execução do Windows para que outros aplicativos não podem se conectar a eles.

## <a name="syntax"></a>Sintaxe

```cpp
virtual HRESULT UnregisterWinRTObject(
   unsigned int,
   _Inout_ WINRT_REGISTRATION_COOKIE* cookie
);
```

### <a name="parameters"></a>Parâmetros

*Cookie*  
Um ponteiro para um valor que identifica o objeto de classe cujo registro deve ser revogado.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também
[Classe Module](../windows/module-class.md)