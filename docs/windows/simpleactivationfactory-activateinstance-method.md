---
title: 'Método simpleactivationfactory:: Activateinstance | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::SimpleActivationFactory::ActivateInstance
dev_langs:
- C++
helpviewer_keywords:
- ActivateInstance method
ms.assetid: 4f836e51-5a6c-4bad-b871-9f25199298b4
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 260d7e2993bd92297167c23458d37ba80919306f
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40013379"
---
# <a name="simpleactivationfactoryactivateinstance-method"></a>Método SimpleActivationFactory::ActivateInstance

Cria uma instância da interface especificada.

## <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD( ActivateInstance )(
    _Deref_out_ IInspectable **ppvObject
);
```

### <a name="parameters"></a>Parâmetros
*ppvObject*  
Quando essa operação for concluída, ponteiro para uma instância do objeto especificado pelo `Base` parâmetro de modelo de classe.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

## <a name="remarks"></a>Comentários

Se `__WRL_STRICT__` é definido, um erro de asserção será emitido se a classe base especificada no parâmetro de modelo de classe não é derivada da [RuntimeClass](../windows/runtimeclass-class.md), ou não está configurada com o WinRt ou WinRtClassicComMix [ RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valor de enumeração.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também
 [Classe SimpleActivationFactory](../windows/simpleactivationfactory-class.md)