---
title: 'Método Runtimeclass: | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- implements/Microsoft::WRL::RuntimeClass::GetRuntimeClassName
dev_langs:
- C++
helpviewer_keywords:
- GetRuntimeClassName method
ms.assetid: f6388163-fe65-4948-a4bc-ae6826f480e7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3cfe3cc4a8a304bbd04fde9e6c38e2b9170e2e73
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33892433"
---
# <a name="runtimeclassgetruntimeclassname-method"></a>Método RuntimeClass::GetRuntimeClassName

Obtém o nome de classe de tempo de execução do objeto RuntimeClass atual.

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

Um erro de asserção é emitido se &#95; &#95;WRL_STRICT&#95; &#95; ou &#95; &#95;WRL_FORCE_INSPECTABLE_CLASS_MACRO&#95; &#95; não está definido.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** implements.h

**Namespace:** Microsoft::WRL

## <a name="see-also"></a>Consulte também

[Classe RuntimeClass](../windows/runtimeclass-class.md)