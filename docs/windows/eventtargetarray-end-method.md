---
title: 'Método eventtargetarray:: end | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::EventTargetArray::End
dev_langs:
- C++
helpviewer_keywords:
- End method
ms.assetid: 20c491b8-f355-4d8f-ad14-8f46121d9af6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 341333b0c4f51c42004ad638a5a8f4fcb7d7e466
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42596485"
---
# <a name="eventtargetarrayend-method"></a>Método EventTargetArray::End

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
ComPtr<IUnknown>* End();
```

## <a name="return-value"></a>Valor de retorno

O endereço do último elemento da matriz interna de manipuladores de eventos.

## <a name="remarks"></a>Comentários

Obtém o endereço do último elemento da matriz interna de manipuladores de eventos.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Classe EventTargetArray](../windows/eventtargetarray-class.md)  
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)