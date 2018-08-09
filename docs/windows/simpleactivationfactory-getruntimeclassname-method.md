---
title: 'Método simpleactivationfactory:: Getruntimeclassname | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::SimpleActivationFactory::GetRuntimeClassName
dev_langs:
- C++
ms.assetid: 3aa07487-9a42-46f8-8893-37ba6315e50b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1c6c6731c4c7787f3d81a4e67eac2861a46bfe1a
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39644402"
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
Quando essa operação for concluída, o nome de classe de tempo de execução.

## <a name="return-value"></a>Valor de retorno

S_OK se bem-sucedido; Caso contrário, um HRESULT que indica o erro.

## <a name="remarks"></a>Comentários

Se &#95; &#95;WRL_STRICT&#95; &#95; é definido, um erro de asserção será emitido se a classe especificada pelo `Base` parâmetro de modelo de classe não é derivado da [RuntimeClass](../windows/runtimeclass-class.md), ou não está configurada com o WinRt ou WinRtClassicComMix [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valor de enumeração.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também
 [Classe SimpleActivationFactory](../windows/simpleactivationfactory-class.md)