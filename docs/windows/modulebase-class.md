---
title: Classe ModuleBase | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::Details::ModuleBase
dev_langs:
- C++
helpviewer_keywords:
- ModuleBase class
ms.assetid: edce7591-6893-46f7-94a7-382827775548
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e6d60e5114d189ddede87899bb55fba25a296c57
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42601465"
---
# <a name="modulebase-class"></a>Classe ModuleBase

Oferece suporte a infraestrutura do WRL e não se destina a ser usado diretamente do seu código.

## <a name="syntax"></a>Sintaxe

```cpp
class ModuleBase;
```

## <a name="remarks"></a>Comentários

Representa a classe base do [módulo](../windows/module-class.md) classes.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtor ModuleBase::ModuleBase](../windows/modulebase-modulebase-constructor.md)|Inicializa uma instância da classe `Module`.|
|[Destruidor ModuleBase::~ModuleBase](../windows/modulebase-tilde-modulebase-destructor.md)|A instância atual do realiza o desligamento de `Module` classe.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Método ModuleBase::DecrementObjectCount](../windows/modulebase-decrementobjectcount-method.md)|Quando implementado, diminui o número de objetos rastreados pelo módulo.|
|[Método ModuleBase::IncrementObjectCount](../windows/modulebase-incrementobjectcount-method.md)|Quando implementado, incrementa o número de objetos controlados pelo módulo.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`ModuleBase`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Implements. h

**Namespace:** Microsoft::WRL::Details

## <a name="see-also"></a>Consulte também

[Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)