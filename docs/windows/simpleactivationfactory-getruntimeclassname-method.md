---
title: "Método Simpleactivationfactory: | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::SimpleActivationFactory::GetRuntimeClassName
dev_langs: C++
ms.assetid: 3aa07487-9a42-46f8-8893-37ba6315e50b
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 22cb09115938da3d90bbe7feac0aac490971ffd1
ms.sourcegitcommit: ca2f94dfd015e0098a6eaf5c793ec532f1c97de1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2017
---
# <a name="simpleactivationfactorygetruntimeclassname-method"></a>Método SimpleActivationFactory::GetRuntimeClassName

Obtém o nome de classe de tempo de execução de uma instância da classe especificada pelo `Base` parâmetro de modelo de classe.

## <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD( GetRuntimeClassName )(
    _Out_ HSTRING* runtimeName
);
```

### <a name="parameters"></a>Parâmetros

*runtimeName*  
Quando a operação for concluída, o nome de classe de tempo de execução.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, o HRESULT que indica o erro.

## <a name="remarks"></a>Comentários

Se &#95; &#95; WRL_STRICT #95; &#95; é definido, um erro de asserção é emitido se a classe especificada pelo `Base` parâmetro de modelo de classe não é derivado de [RuntimeClass](../windows/runtimeclass-class.md), ou não está configurado com o WinRt ou WinRtClassicComMix [ RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valor de enumeração.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft:: wrl

## <a name="see-also"></a>Consulte também

[Classe SimpleActivationFactory](../windows/simpleactivationfactory-class.md)