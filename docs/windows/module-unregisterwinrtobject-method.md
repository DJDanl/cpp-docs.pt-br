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
ms.openlocfilehash: 39bb86206aec72d918df482ee1d01214b4fbb03b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46381745"
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

*Cookie*<br/>
Um ponteiro para um valor que identifica o objeto de classe cujo registro deve ser revogado.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe Module](../windows/module-class.md)