---
title: Membro de dados InvokeHelper::callback_ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- event/Microsoft::WRL::Details::InvokeHelper::callback_
dev_langs:
- C++
helpviewer_keywords:
- callback_ data member
ms.assetid: 6f0cbf6d-0448-46f8-ba71-bd6fd8702e3a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e602a8d2eef8e495ad732dcd61d0e8aa0b242130
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42600994"
---
# <a name="invokehelpercallback-data-member"></a>Membro de dados InvokeHelper::callback_

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
TCallback callback_;
```

## <a name="remarks"></a>Comentários

Representa o manipulador de eventos para chamar quando ocorre um evento.

O `TCallback` parâmetro de modelo especifica o tipo de manipulador de eventos.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Event. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Estrutura InvokeHelper](../windows/invokehelper-structure.md)  
[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)