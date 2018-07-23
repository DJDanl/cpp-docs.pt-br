---
title: 'Método Simpleactivationfactory: | Microsoft Docs'
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
ms.openlocfilehash: e001d0269c21026bdd00abcdd4d257f11d601cf6
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33889027"
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

Se &#95; &#95;WRL_STRICT&#95; &#95; é definido, um erro de asserção é emitido se a classe especificada pelo `Base` parâmetro de modelo de classe não é derivado de [RuntimeClass](../windows/runtimeclass-class.md), ou não está configurado com o WinRt ou WinRtClassicComMix [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) valor de enumeração.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** module.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe SimpleActivationFactory](../windows/simpleactivationfactory-class.md)