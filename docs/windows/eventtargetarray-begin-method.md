---
title: 'Método eventtargetarray:: begin | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::EventTargetArray::Begin
dev_langs:
- C++
helpviewer_keywords:
- Begin method
ms.assetid: 1cc7fdfd-a2c4-4b28-93cf-1c82842294ba
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 738ee52eb68cfbb03a380ffac52efdb4010b5205
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42602125"
---
# <a name="eventtargetarraybegin-method"></a>Método EventTargetArray::Begin

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
ComPtr<IUnknown>* Begin();
```

## <a name="return-value"></a>Valor de retorno

O endereço do primeiro elemento da matriz interna de manipuladores de eventos.

## <a name="remarks"></a>Comentários

Obtém o endereço do primeiro elemento da matriz interna de manipuladores de eventos.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Classe EventTargetArray](../windows/eventtargetarray-class.md)  
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)