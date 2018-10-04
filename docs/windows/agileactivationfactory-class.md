---
title: Classe AgileActivationFactory | Microsoft Docs
ms.custom: ''
ms.date: 10/03/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::AgileActivationFactory
dev_langs:
- C++
ms.assetid: fab98f32-bb93-4c0f-badb-49fbddb194b0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 765d5c2f7157cffb685ac476eae4c5dfc88c694d
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48789274"
---
# <a name="agileactivationfactory-class"></a>Classe AgileActivationFactory

Representa um alocador de ativação de apartment amigável que implementa [FtmBase](../windows/ftmbase-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <
    typename I0 = Details::Nil,
    typename I1 = Details::Nil,
    typename I2 = Details::Nil,
    FactoryCacheFlags cacheFlagValue = FactoryCacheDefault
>
class AgileActivationFactory :
    public ActivationFactory<
        Implements<FtmBase, I0>,
        I1,
        I2,
        cacheFlagValue
    >;
```
  
## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h
  
**Namespace:** Microsoft::WRL
  
## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)<br/>
[Classe ActivationFactory](../windows/activationfactory-class.md)