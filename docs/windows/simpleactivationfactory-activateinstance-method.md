---
title: "Método Simpleactivationfactory: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::SimpleActivationFactory::ActivateInstance
dev_langs: C++
helpviewer_keywords: ActivateInstance method
ms.assetid: 4f836e51-5a6c-4bad-b871-9f25199298b4
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: f1e28afad17f4fdc593e6dea4bebddf27f1548f7
ms.sourcegitcommit: ca2f94dfd015e0098a6eaf5c793ec532f1c97de1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2017
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

S_OK se bem-sucedido; Caso contrário, o HRESULT que indica o erro.

## <a name="remarks"></a>Comentários

Se &#95; &#95; WRL_STRICT #95; &#95; é definido, um erro de asserção é emitido se a classe base especificada no parâmetro de modelo de classe não é derivada de [RuntimeClass](../windows/runtimeclass-class.md), ou não está configurado com o WinRt ou WinRtClassicComMix [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valor de enumeração.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft:: wrl

## <a name="see-also"></a>Consulte também

[Classe SimpleActivationFactory](../windows/simpleactivationfactory-class.md)