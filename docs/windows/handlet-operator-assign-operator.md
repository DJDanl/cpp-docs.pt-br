---
title: 'Handlet:: Operator operador = | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- corewrappers/Microsoft::WRL::Wrappers::HandleT::operator=
dev_langs:
- C++
helpviewer_keywords:
- operator= operator
ms.assetid: 9e42dcca-30fa-4e8b-8954-802fd64a5595
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: cf539082ef88abb5fb27f09d92b73403dc2d03a5
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42611336"
---
# <a name="handletoperator-operator"></a>Operador HandleT::operator=

Move o valor de especificado **HandleT** objeto atual **HandleT** objeto.

## <a name="syntax"></a>Sintaxe

```cpp
HandleT& operator=(
   _Inout_ HandleT&& h
);
```

### <a name="parameters"></a>Parâmetros

*h*  
Uma referência rvalue para um identificador.

## <a name="return-value"></a>Valor de retorno

Uma referência ao atual **HandleT** objeto.

## <a name="remarks"></a>Comentários

Esta operação invalida a **HandleT** objeto especificado pelo parâmetro *h*.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** corewrappers. h

**Namespace:** Microsoft::WRL::Wrappers

## <a name="see-also"></a>Consulte também

[Classe HandleT](../windows/handlet-class.md)